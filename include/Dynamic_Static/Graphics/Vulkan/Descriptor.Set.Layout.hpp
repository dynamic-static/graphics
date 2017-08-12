
/*
==========================================
    Copyright (c) 2017 Dynamic_Static 
    Licensed under the MIT license
    http://opensource.org/licenses/MIT
==========================================
*/

#pragma once

#include "Dynamic_Static/Graphics/Vulkan/Descriptor.Set.hpp"
#include "Dynamic_Static/Graphics/Vulkan/Defines.hpp"
#include "Dynamic_Static/Graphics/Vulkan/DeviceChild.hpp"
#include "Dynamic_Static/Graphics/Vulkan/Object.hpp"

namespace Dynamic_Static {
namespace Graphics {
namespace Vulkan {

    /**
     * Provides high level control over a Vulkan Descriptor Set Layout.
     */
    class Descriptor::Set::Layout final
        : public Object<VkDescriptorSetLayout>
        , public detail::DeviceChild
    {
        friend class Device;

    public:
        /**
         * Configuration paramaters for Descriptor::Set::Layout construction.
         */
        struct Info final
            : public VkDescriptorSetLayoutCreateInfo
        {
            /**
             * Constructs an instance of Descriptor::Set::Layout::Info with default paramaters.
             */
            Info()
            {
                sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
                pNext = nullptr;
                flags = 0;
                bindingCount = 0;
                pBindings = nullptr;
            }
        };

    private:
        Layout(const std::shared_ptr<Device>& device, const Info& info);

    public:
        /**
         * Destroys this instance of Descriptor::Set::Layout.
         */
        ~Layout();
    };

} // namespace Vulkan
} // namespace Graphics
} // namespace Dynamic_Static