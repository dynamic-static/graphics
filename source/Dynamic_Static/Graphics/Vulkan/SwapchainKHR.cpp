
#if 0
/*
==========================================
    Copyright (c) 2017 Dynamic_Static
    Licensed under the MIT license
    http://opensource.org/licenses/MIT
==========================================
*/

#include "Dynamic_Static/Graphics/Vulkan/SwapchainKHR.hpp"
#include "Dynamic_Static/Core/Algorithm.hpp"
#include "Dynamic_Static/Core/ToString.hpp"
#include "Dynamic_Static/Graphics/Vulkan/Device.hpp"
#include "Dynamic_Static/Graphics/Vulkan/Image.hpp"
#include "Dynamic_Static/Graphics/Vulkan/Image.View.hpp"
#include "Dynamic_Static/Graphics/Vulkan/Semaphore.hpp"
#include "Dynamic_Static/Graphics/Vulkan/SurfaceKHR.hpp"

#include <limits>

namespace Dynamic_Static {
namespace Graphics {
namespace Vulkan {

    SwapchainKHR::SwapchainKHR(
        const std::shared_ptr<Device>& device,
        const std::shared_ptr<SurfaceKHR>& surface
    )
        : DeviceChild(device)
        , mSurface { surface }
    {
        create_swap_chain();
        mSurface->on_resized = std::bind(&SwapchainKHR::on_surface_resized, this, std::placeholders::_1);
        name("SwapchainKHR");
    }

    SwapchainKHR::~SwapchainKHR()
    {
        destroy_swap_chain();
    }

    SurfaceKHR& SwapchainKHR::surface()
    {
        assert(mSurface);
        return *mSurface;
    }

    const SurfaceKHR& SwapchainKHR::surface() const
    {
        assert(mSurface);
        return *mSurface;
    }

    bool SwapchainKHR::valid() const
    {
        auto currentExtent = extent();
        return !!mHandle && currentExtent.width && currentExtent.height;
    }

    VkFormat SwapchainKHR::format() const
    {
        return surface().format().format;
    }

    VkExtent2D SwapchainKHR::extent() const
    {
        return surface().capabilities().currentExtent;
    }

    const std::vector<std::unique_ptr<Image>>& SwapchainKHR::images() const
    {
        return mImages;
    }

    void SwapchainKHR::update()
    {
        if (mUpdate) {
            mUpdate = false;
            destroy_swap_chain();
            create_swap_chain();
        }
    }

    size_t SwapchainKHR::next_image(const Semaphore& semaphore)
    {
        uint32_t imageIndex = 0;
        if (valid()) {
            validate(
                vkAcquireNextImageKHR(
                    device(),
                    mHandle,
                    std::numeric_limits<uint64_t>::max(),
                    semaphore,
                    VK_NULL_HANDLE,
                    &imageIndex
                )
            );
        }

        return static_cast<size_t>(imageIndex);
    }

    void SwapchainKHR::create_swap_chain()
    {
        assert(mSurface);
        auto extent = mSurface->capabilities().currentExtent;
        if (extent.width && extent.height) {
            uint32_t min = mSurface->capabilities().minImageCount;
            uint32_t max = mSurface->capabilities().maxImageCount;
            uint32_t imageCount = max ? dst::clamp(min + 1, min, max) : min + 1;

            // TODO : Make configurable...right now we're using VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT which
            //        allows us to render directly into the image, and VK_IMAGE_TRANSFER_DST_BIT which
            //        allows us to use a memory operation to transfer a rendered image into the SwapChain.

            // NOTE : Usage flags define how a given Image may be used in Vulkan.  If we want an image to
            //        be sampled, it must be created with "SAMPLED" usage.  If the Image should be used as
            //        a depth render target, it must be created with "DEPTH and STENCIL" usgae.  An Image
            //        without proper usage enabled cannot be used for a given purpose or the results of
            //        such operations will be undefined.

            // NOTE : For a SwapChain, we want to render (in most cases) into the Image (use it as a render target),
            //        so we must specify "COLOR ATTACHMENT" usage with VK_IMAGE_COLOR_ATTACHMENT_BIT.  In Vulkan this
            //        usage is always available for SwapChains, so we can always set it without any other checks.  For
            //        any other usage we must ensure it's supported...we can do this with the "supportedUsageFlags"
            //        member of our Surface's Capabilities structure.

            VkImageUsageFlags usage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
            if (mSurface->capabilities().supportedUsageFlags & VK_IMAGE_USAGE_TRANSFER_DST_BIT) {
                usage |= VK_IMAGE_USAGE_TRANSFER_DST_BIT;
            }

            // FROM : I Am Graphics And So Can You :: Part 3
            //        https://www.fasterthan.life/blog/2017/7/12/i-am-graphics-and-so-can-you-part-3-breaking-ground
            //
            //        // Moment of truth.  If the graphics queue family and present queue family don't match
            //        // then we need to create the swapchain with different information.
            //        if ( vkcontext.graphicsFamilyIdx != vkcontext.presentFamilyIdx ) {
            //            uint32 indices[] = { (uint32)vkcontext.graphicsFamilyIdx, (ui9nt32)vkcontext.presentFamily };
            //
            //            // There are only two sharing modes.  This is the one to use
            //            // if images are not exclusive to one queue.
            //            info.imageSharingMode = VK_SHARING_MODE_CONCURRENT;
            //            info.queueFamilyIndexCount = 2;
            //            info.pQueueFamilyIndices = indices;
            //        } else {
            //            // If the indices are the same, then the queue can have exclusive
            //            // access to the images.
            //            info.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
            //        }

            VkSwapchainCreateInfoKHR info { };
            info.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
            info.surface = *mSurface;
            info.minImageCount = imageCount;
            info.imageFormat = mSurface->format().format;
            info.imageColorSpace = mSurface->format().colorSpace;
            info.imageExtent = mSurface->capabilities().currentExtent;
            // NOTE : This is the number of views in this SwapChain, 1 for mono, 2 for stereo, etc.
            info.imageArrayLayers = 1;
            info.imageUsage = usage;
            info.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
            info.queueFamilyIndexCount = 0;
            info.pQueueFamilyIndices = nullptr;
            info.preTransform = mSurface->transform_flags();
            // NOTE : Defines how blending should be performed with other windows in the system.
            info.compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
            info.presentMode = mSurface->present_mode();
            // NOTE : Setting clipped to true will discard pixels that are obscured by other windows.
            //        This should be false only if we need to read back this SwapchainKHR's contents.
            info.clipped = VK_TRUE;
            info.oldSwapchain = VK_NULL_HANDLE;
            validate(vkCreateSwapchainKHR(device(), &info, nullptr, &mHandle));

            validate(vkGetSwapchainImagesKHR(device(), mHandle, &imageCount, nullptr));
            std::vector<VkImage> imageHandles(imageCount);
            validate(vkGetSwapchainImagesKHR(device(), mHandle, &imageCount, imageHandles.data()));
            for (const auto& handle : imageHandles) {
                std::unique_ptr<Image> image(new Image(*this, handle));
                image->create<Image::View>();
                image->name("SwapchainKHR Image " + dst::to_string(mImages.size()));
                mImages.push_back(std::move(image));
            }
        }
    }

    void SwapchainKHR::destroy_swap_chain()
    {
        if (mHandle) {
            device().wait_idle();
            mImages.clear();
            vkDestroySwapchainKHR(device(), mHandle, nullptr);
            mHandle = VK_NULL_HANDLE;
        }
    }

    void SwapchainKHR::on_surface_resized(const SurfaceKHR& surface)
    {
        mUpdate = true;
        on_resized(*this);
    }

} // namespace Vulkan
} // namespace Graphics
} // namespace Dynamic_Static
#endif
