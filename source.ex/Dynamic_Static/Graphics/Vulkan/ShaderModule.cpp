
/*
==========================================
  Copyright (c) 2016-2018 Dynamic_Static
    Patrick Purcell
      Licensed under the MIT license
    http://opensource.org/licenses/MIT
==========================================
*/

#include "Dynamic_Static/Graphics/Vulkan/ShaderModule.hpp"
#include "Dynamic_Static/Graphics/Vulkan/Device.hpp"
#include "Dynamic_Static/Graphics/Vulkan/Pipeline.hpp"
#include "Dynamic_Static/Graphics/Vulkan/ShaderModule.Compiler.hpp"
#include "Dynamic_Static/Graphics/Vulkan/ShaderModule.Reflector.hpp"

#include <iostream>
#include <vector>

namespace Dynamic_Static {
namespace Graphics {
namespace Vulkan {

    ShaderModule::ShaderModule(
        const std::shared_ptr<Device>& device,
        VkShaderStageFlagBits stage,
        const std::string& source
    )
        : ShaderModule(device, stage, 0, source)
    {
    }

    ShaderModule::ShaderModule(
        const std::shared_ptr<Device>& device,
        VkShaderStageFlagBits stage,
        int lineOffset,
        const std::string& source
    )
        : DeviceChild(device)
        , mStage { stage }
    {
        set_name("ShaderModule");
        ShaderModule::Compiler compiler(stage, lineOffset, source);
        ShaderModule::CreateInfo createInfo { };
        createInfo.codeSize = (uint32_t)compiler.get_spirv().size_bytes();
        createInfo.pCode = compiler.get_spirv().data();
        dst_vk(vkCreateShaderModule(get_device(), &createInfo, nullptr, &mHandle));
        ShaderModule::Reflector reflector(compiler.get_spirv());
        mDescriptorSetLayoutBindings.reserve(reflector.get_descriptor_set_layout_bindings().size());
        for (auto binding : reflector.get_descriptor_set_layout_bindings()) {
            binding.stageFlags = mStage;
            mDescriptorSetLayoutBindings.push_back(binding);
        }
        mPushConstantRanges.reserve(reflector.get_push_constant_ranges().size());
        for (auto pushConstantRange : reflector.get_push_constant_ranges()) {
            pushConstantRange.stageFlags = mStage;
            mPushConstantRanges.push_back(pushConstantRange);
        }
    }

    ShaderModule::ShaderModule(
        const std::shared_ptr<Device>& device,
        ShaderModule::CreateInfo createInfo
    )
        : DeviceChild(device)
    {
        set_name("ShaderModule");
        dst_vk(vkCreateShaderModule(get_device(), &createInfo, nullptr, &mHandle));
    }

    ShaderModule::~ShaderModule()
    {
        if (mHandle) {
            vkDestroyShaderModule(get_device(), mHandle, nullptr);
        }
    }

    VkShaderStageFlagBits ShaderModule::get_stage() const
    {
        return mStage;
    }

    VkPipelineShaderStageCreateInfo ShaderModule::get_pipeline_stage_create_info() const
    {
        Pipeline::ShaderStageCreateInfo shaderStageCreateInfo { };
        shaderStageCreateInfo.stage = mStage;
        shaderStageCreateInfo.module = mHandle;
        // TODO : Need to allow other entry points besides "main"
        static const auto sMainEntryPoint = "main";
        shaderStageCreateInfo.pName = sMainEntryPoint;
        return shaderStageCreateInfo;
    }

    dst::Span<const VkDescriptorSetLayoutBinding> ShaderModule::get_descriptor_set_layout_bindings() const
    {
        return mDescriptorSetLayoutBindings;
    }

    dst::Span<const VkPushConstantRange> ShaderModule::get_push_constant_ranges() const
    {
        return mPushConstantRanges;
    }

} // namespace Vulkan
} // namespace Graphics
} // namespace Dynamic_Static
