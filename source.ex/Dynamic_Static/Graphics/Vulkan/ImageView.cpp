
/*
==========================================
  Copyright (c) 2016-2018 Dynamic_Static
    Patrick Purcell
      Licensed under the MIT license
    http://opensource.org/licenses/MIT
==========================================
*/

#include "Dynamic_Static/Graphics/Vulkan/ImageView.hpp"
#include "Dynamic_Static/Graphics/Vulkan/Device.hpp"
#include "Dynamic_Static/Graphics/Vulkan/Image.hpp"

namespace dst {
namespace gfx {
namespace vk {
    ImageView::ImageView(Image* image)
        : ImageView(
            image,
            [this, image]
            {
                assert(image);
                auto imageFormat = image->get_format();
                auto imageCreateFlags = image->get_create_flags();
                auto imageLayerCount = image->get_array_layer_count();
                auto imageUsageFlags = image->get_usage_flags();
                ImageView::CreateInfo createInfo { };
                createInfo.image = *image;
                createInfo.format = imageFormat;
                createInfo.subresourceRange.levelCount = image->get_mip_level_count();
                createInfo.subresourceRange.layerCount = imageLayerCount;
                switch (imageFormat) {
                    case VK_FORMAT_D16_UNORM:
                    case VK_FORMAT_X8_D24_UNORM_PACK32:
                    case VK_FORMAT_D32_SFLOAT:
                        createInfo.subresourceRange.aspectMask |= VK_IMAGE_ASPECT_DEPTH_BIT;
                        break;
                    case VK_FORMAT_S8_UINT:
                    case VK_FORMAT_D16_UNORM_S8_UINT:
                    case VK_FORMAT_D24_UNORM_S8_UINT:
                    case VK_FORMAT_D32_SFLOAT_S8_UINT:
                        createInfo.subresourceRange.aspectMask |= VK_IMAGE_ASPECT_DEPTH_BIT | VK_IMAGE_ASPECT_STENCIL_BIT;
                        break;
                    default:
                        createInfo.subresourceRange.aspectMask |= VK_IMAGE_ASPECT_COLOR_BIT;
                        break;
                }
                switch (image->get_type()) {
                    case VK_IMAGE_TYPE_1D: {
                        createInfo.viewType = imageLayerCount == 1 ? VK_IMAGE_VIEW_TYPE_1D : VK_IMAGE_VIEW_TYPE_1D_ARRAY;
                    } break;
                    case VK_IMAGE_TYPE_2D: {
                        createInfo.viewType = imageLayerCount == 1 ? VK_IMAGE_VIEW_TYPE_2D : VK_IMAGE_VIEW_TYPE_2D_ARRAY;
                        if (imageCreateFlags & VK_IMAGE_CREATE_CUBE_COMPATIBLE_BIT) {
                            if (imageLayerCount == 6) {
                                createInfo.viewType = VK_IMAGE_VIEW_TYPE_CUBE;
                            } else
                            if (imageLayerCount % 6 == 0) {
                                createInfo.viewType = VK_IMAGE_VIEW_TYPE_CUBE_ARRAY;
                            }
                        }
                    } break;
                    case VK_IMAGE_TYPE_3D: {
                        createInfo.viewType = VK_IMAGE_VIEW_TYPE_3D;
                        if (imageCreateFlags & VK_IMAGE_CREATE_2D_ARRAY_COMPATIBLE_BIT &&
                            !(imageCreateFlags & VK_IMAGE_CREATE_SPARSE_BINDING_BIT) &&
                            !(imageCreateFlags & VK_IMAGE_CREATE_SPARSE_RESIDENCY_BIT) &&
                            !(imageCreateFlags & VK_IMAGE_CREATE_SPARSE_ALIASED_BIT)) {
                            if (imageLayerCount == 1) {
                                createInfo.viewType = VK_IMAGE_VIEW_TYPE_2D;
                            } else {
                                createInfo.viewType = VK_IMAGE_VIEW_TYPE_2D_ARRAY;
                            }
                        }
                    } break;
                    default:break;
                }
                return createInfo;
            }()
        )
    {
    }

    ImageView::ImageView(
        Image* image,
        const ImageView::CreateInfo& createInfo
    )
        : ImageChild(image)
        , mCreateInfo { createInfo }
    {
        set_name(get_image().get_name() + " ImageView");
        mCreateInfo.image = get_image();
        dst_vk(vkCreateImageView(get_image().get_device(), &createInfo, nullptr, &mHandle));
    }

    ImageView::ImageView(ImageView&& other)
        : Object(std::move(other))
        , ImageChild(std::move(other))
    {
    }

    ImageView::~ImageView()
    {
        if (mHandle) {
            vkDestroyImageView(get_image().get_device(), mHandle, nullptr);
        }
    }

    ImageView& ImageView::operator=(ImageView&& other)
    {
        if (this != &other) {
            Object::operator=(std::move(other));
            ImageChild::operator=(std::move(other));
        }
        return *this;
    }

    VkImageViewCreateFlags ImageView::get_create_flags() const
    {
        return mCreateInfo.flags;
    }

    VkImageViewType ImageView::get_type() const
    {
        return mCreateInfo.viewType;
    }

    VkFormat ImageView::get_format() const
    {
        return mCreateInfo.format;
    }

    VkComponentMapping ImageView::get_component_mapping() const
    {
        return mCreateInfo.components;
    }

    VkImageSubresourceRange ImageView::get_subresource_range() const
    {
        return mCreateInfo.subresourceRange;
    }

} // namespace vk
} // namespace gfx
} // namespace dst
