
/*
==========================================
    Copyright (c) 2017 Dynamic_Static 
    Licensed under the MIT license
    http://opensource.org/licenses/MIT
==========================================
*/

#include "Dynamic_Static/Graphics/Vulkan/Buffer.hpp"
#include "Dynamic_Static/Graphics/Vulkan/Device.hpp"
#include "Dynamic_Static/Graphics/Vulkan/PhysicalDevice.hpp"
#include "Dynamic_Static/Graphics/Vulkan/Memory.hpp"

namespace Dynamic_Static {
namespace Graphics {
namespace Vulkan {

    Buffer::Buffer(
        const std::shared_ptr<Device>& device,
        const Info& info,
        VkMemoryPropertyFlags memoryPropertyFlags
    )
        : DeviceChild(device)
    {
        initialize(info, memoryPropertyFlags);
    }

    Buffer::~Buffer()
    {
        if (mHandle) {
            mMemory.reset();
            vkDestroyBuffer(device(), mHandle, nullptr);
        }
    }

    VkMemoryRequirements Buffer::memory_requirements() const
    {
        VkMemoryRequirements memoryRequirements;
        vkGetBufferMemoryRequirements(device(), mHandle, &memoryRequirements);
        return memoryRequirements;
    }

    std::shared_ptr<Memory> Buffer::memory()
    {
        return mMemory;
    }

    const std::shared_ptr<Memory>& Buffer::memory() const
    {
        return mMemory;
    }

    void* Buffer::mapped_ptr()
    {
        return mMemory->mapped_ptr();
    }

    void* Buffer::map()
    {
        return mMemory->map();
    }

    void Buffer::unmap()
    {
        mMemory->unmap();
    }

    void Buffer::initialize(const Info& info, VkMemoryPropertyFlags memoryPropertyFlags)
    {
        validate(vkCreateBuffer(DeviceChild::device(), &info, nullptr, &mHandle));
        name("Buffer");

        auto memoryRequirements = memory_requirements();
        auto memoryTypeIndex = device().physical_device().find_memory_type_index(
            memoryRequirements.memoryTypeBits,
            memoryPropertyFlags
        );

        // TODO : This is a lousy way to be using memory, we should be binding several
        //        related buffers to a single allocation and ensuring that our offsets
        //        are aligned to memoryRequirements.alignment.
        // TODO : Buffer shouldn't own a particular Memory allocation.
        //        http://gpuopen.com/vulkan-device-memory/
        //        https://twitter.com/axelgneiting/status/756218806570147840
        size_t offset = 0;
        Memory::Info memoryInfo;
        memoryInfo.memoryTypeIndex = static_cast<uint32_t>(memoryTypeIndex);
        memoryInfo.allocationSize = memoryRequirements.size;
        mMemory = device().allocate<Memory>(memoryInfo);
        validate(vkBindBufferMemory(device(), mHandle, *mMemory, static_cast<VkDeviceSize>(offset)));
    }

} // namespace Vulkan
} // namespace Graphics
} // namespace Dynamic_Static