
/*
==========================================
  Copyright (c) 2016-2018 Dynamic_Static
    Patrick Purcell
      Licensed under the MIT license
    http://opensource.org/licenses/MIT
==========================================
*/

#pragma once

#include "Dynamic_Static/Graphics/Vulkan/CommandPoolChild.hpp"
#include "Dynamic_Static/Graphics/Vulkan/Defines.hpp"
#include "Dynamic_Static/Graphics/Vulkan/Object.hpp"

#include <memory>

namespace Dynamic_Static {
namespace Graphics {
namespace Vulkan {

    /*
    * Provides high level control over a Vulkan command buffer.
    */
    class CommandBuffer final
        : public Object<VkCommandBuffer>
        , public SharedObject<CommandBuffer>
        , public CommandPoolChild
    {
    public:
        /*
        * Configuration parameters for CommandBuffer allocation.
        */
        struct AllocateInfo final
            : public VkCommandBufferAllocateInfo
        {
            /*
            * Constructs an instance of CommandBuffer::AllocateInfo.
            */
            AllocateInfo()
            {
                sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
                pNext = nullptr;
                commandPool = VK_NULL_HANDLE;
                level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
                commandBufferCount = 1;
                static_assert(
                    sizeof(CommandBuffer::AllocateInfo) == sizeof(VkCommandBufferAllocateInfo),
                    "sizeof(CommandBuffer::AllocateInfo) != sizeof(VkCommandBufferAllocateInfo)"
                );
            }
        };

    private:
        /*
        * Constructs an instance of CommandBuffer.
        * @param [in] device This CommandBuffer's CommandPool
        * @param [in] allocateInfo This CommandBuffer's CommandBuffer::AllocateInfo
        */
        CommandBuffer(
            const std::shared_ptr<CommandPool>& commandPool,
            CommandBuffer::AllocateInfo allocateInfo = { }
        );

    public:
        /*
        * Destroys this instance of CommandBuffer.
        */
        ~CommandBuffer();

    private:
        friend class CommandPool;
    };

} // namespace Vulkan
} // namespace Graphics
} // namespace Dynamic_Static