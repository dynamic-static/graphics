
/*
==========================================
  Copyright (c) 2016-2018 Dynamic_Static
    Patrick Purcell
      Licensed under the MIT license
    http://opensource.org/licenses/MIT
==========================================
*/

#include "Dynamic_Static/Graphics/Vulkan/RenderPass.hpp"
#include "Dynamic_Static/Graphics/Vulkan/Device.hpp"

namespace Dynamic_Static {
namespace Graphics {
namespace Vulkan {

    RenderPass::RenderPass(
        const std::shared_ptr<Device>& device,
        RenderPass::CreateInfo createInfo
    )
        : DeviceChild(device)
    {
        set_name("RenderPass");
        dst_vk(vkCreateRenderPass(get_device(), &createInfo, nullptr, &mHandle));
        mAttachmentDescriptions.reserve(createInfo.attachmentCount);
        for (uint32_t i = 0; i < createInfo.attachmentCount; ++i) {
            mAttachmentDescriptions.push_back(createInfo.pAttachments[i]);
        }
    }

    RenderPass::~RenderPass()
    {
        if (mHandle) {
            vkDestroyRenderPass(get_device(), mHandle, nullptr);
        }
    }

    const std::vector<VkAttachmentDescription>& RenderPass::get_attachment_descriptions() const
    {
        return mAttachmentDescriptions;
    }

} // namespace Vulkan
} // namespace Graphics
} // namespace Dynamic_Static