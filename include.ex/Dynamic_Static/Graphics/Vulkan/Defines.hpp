
/*
==========================================
  Copyright (c) 2016-2018 Dynamic_Static
    Patrick Purcell
      Licensed under the MIT license
    http://opensource.org/licenses/MIT
==========================================
*/

#pragma once

#include "Dynamic_Static/Graphics/Defines.hpp"

#ifdef DYNAMIC_STATIC_WINDOWS
#define VK_USE_PLATFORM_WIN32_KHR
#endif
#include "vulkan/vulkan.h"

#include <iostream>
#include <string>

#define DYNAMIC_STATIC_ASSERT_ON_VK_ERROR
#define DYNAMIC_STATIC_VALIDATE_VK_CALLS
#ifdef DYNAMIC_STATIC_VALIDATE_VK_CALLS
#define dst_vk(VK_CALL) \
dst::gfx::vk::validate_vk_result(VK_CALL, dst_file_line, #VK_CALL)
#else
#define dst_vk(VK_CALL) \
VK_CALL
#endif

namespace dst {
namespace gfx {
namespace vk {

    class Application;
    class Buffer;
    class BufferView;
    class CommandBuffer;
    class CommandPool;
    class CommandPoolChild;
    class DebugReportCallbackEXT;
    class DescriptorPool;
    class DescriptorPoolChild;
    class DescriptorSet;
    class DescriptorSetLayout;
    class Device;
    class DeviceMemory;
    class DeviceMemoryResource;
    class DeviceChild;
    class Fence;
    class Framebuffer;
    class Image;
    class ImageChild;
    class ImageView;
    class Instance;
    class InstanceChild;
    class Mesh;
    class PhysicalDevice;
    class PhysicalDeviceChild;
    class Pipeline;
    class PipelineLayout;
    class Queue;
    class QueueFamily;
    class RenderPass;
    class RenderTarget;
    class Sampler;
    class Semaphore;
    class ShaderModule;
    class SurfaceKHR;
    class SurfaceKHRChild;
    class SwapchainKHR;

    /*!
    TODO : Documentation.
    */
    inline std::string to_string(VkShaderStageFlagBits shaderStageFlagBits)
    {
        switch (shaderStageFlagBits) {
            case VK_SHADER_STAGE_VERTEX_BIT:                  return "VK_SHADER_STAGE_VERTEX_BIT";
            case VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT:    return "VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT";
            case VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT: return "VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT";
            case VK_SHADER_STAGE_GEOMETRY_BIT:                return "VK_SHADER_STAGE_GEOMETRY_BIT";
            case VK_SHADER_STAGE_FRAGMENT_BIT:                return "VK_SHADER_STAGE_FRAGMENT_BIT";
            case VK_SHADER_STAGE_COMPUTE_BIT:                 return "VK_SHADER_STAGE_COMPUTE_BIT";
            case VK_SHADER_STAGE_ALL_GRAPHICS:                return "VK_SHADER_STAGE_ALL_GRAPHICS";
            case VK_SHADER_STAGE_ALL:                         return "VK_SHADER_STAGE_ALL";
            default:                                          return "VK_SHADER_STAGE_UNKNOWN";
        }
    }

    /*!
    TODO : Documentation.
    */
    inline std::string to_string(VkResult result)
    {
        switch (result) {
            case VK_SUCCESS:                        return "VK_SUCCESS";
            case VK_NOT_READY:                      return "VK_NOT_READY";
            case VK_TIMEOUT:                        return "VK_TIMEOUT";
            case VK_EVENT_SET:                      return "VK_EVENT_SET";
            case VK_EVENT_RESET:                    return "VK_EVENT_RESET";
            case VK_INCOMPLETE:                     return "VK_INCOMPLETE";
            case VK_ERROR_OUT_OF_HOST_MEMORY:       return "VK_ERROR_OUT_OF_HOST_MEMORY";
            case VK_ERROR_OUT_OF_DEVICE_MEMORY:     return "VK_ERROR_OUT_OF_DEVICE_MEMORY";
            case VK_ERROR_INITIALIZATION_FAILED:    return "VK_ERROR_INITIALIZATION_FAILED";
            case VK_ERROR_DEVICE_LOST:              return "VK_ERROR_DEVICE_LOST";
            case VK_ERROR_MEMORY_MAP_FAILED:        return "VK_ERROR_MEMORY_MAP_FAILED";
            case VK_ERROR_LAYER_NOT_PRESENT:        return "VK_ERROR_LAYER_NOT_PRESENT";
            case VK_ERROR_EXTENSION_NOT_PRESENT:    return "VK_ERROR_EXTENSION_NOT_PRESENT";
            case VK_ERROR_FEATURE_NOT_PRESENT:      return "VK_ERROR_FEATURE_NOT_PRESENT";
            case VK_ERROR_INCOMPATIBLE_DRIVER:      return "VK_ERROR_INCOMPATIBLE_DRIVER";
            case VK_ERROR_TOO_MANY_OBJECTS:         return "VK_ERROR_TOO_MANY_OBJECTS";
            case VK_ERROR_FORMAT_NOT_SUPPORTED:     return "VK_ERROR_FORMAT_NOT_SUPPORTED";
            case VK_ERROR_SURFACE_LOST_KHR:         return "VK_ERROR_SURFACE_LOST_KHR";
            case VK_ERROR_NATIVE_WINDOW_IN_USE_KHR: return "VK_ERROR_NATIVE_WINDOW_IN_USE_KHR";
            case VK_SUBOPTIMAL_KHR:                 return "VK_SUBOPTIMAL_KHR";
            case VK_ERROR_OUT_OF_DATE_KHR:          return "VK_ERROR_OUT_OF_DATE_KHR";
            case VK_ERROR_INCOMPATIBLE_DISPLAY_KHR: return "VK_ERROR_INCOMPATIBLE_DISPLAY_KHR";
            case VK_ERROR_VALIDATION_FAILED_EXT:    return "VK_ERROR_VALIDATION_FAILED_EXT";
            case VK_ERROR_INVALID_SHADER_NV:        return "VK_ERROR_INVALID_SHADER_NV";
            default:                                return "VK_RESULT_UNKNOWN";
        }
    }

    /*!
    TODO : Documentation.
    */
    inline VkResult validate_vk_result(
        VkResult vkResult,
        const char* message,
        const char* vkCall
    )
    {
        switch (vkResult) {
            case VK_SUCCESS:
            case VK_NOT_READY:
            case VK_TIMEOUT:
            case VK_EVENT_SET:
            case VK_EVENT_RESET:
            case VK_INCOMPLETE:
            case VK_SUBOPTIMAL_KHR: break;
            default:
            {
                std::cerr
                    << "Vulkan Error [" << std::to_string((int)vkResult) << ":" << to_string(vkResult) << "]\n"
                    << "    " << message << "\n"
                    << "    " << vkCall << "\n"
                    << std::endl;
                #ifdef DYNAMIC_STATIC_ASSERT_ON_VK_ERROR
                assert(false && "Vulkan Error");
                #endif
            } break;
        }
        return vkResult;
    }

    /*!
    TODO : Documentation.
    */
    inline bool operator==(const VkExtent2D& lhs, const VkExtent2D& rhs)
    {
        return
            lhs.width == rhs.width &&
            lhs.height == rhs.height;
    }

    /*!
    TODO : Documentation.
    */
    inline VkImageAspectFlags get_aspect_mask(VkFormat format)
    {
        VkImageAspectFlags aspectMask = 0;
        switch (format) {
            case VK_FORMAT_D16_UNORM:
            case VK_FORMAT_X8_D24_UNORM_PACK32:
            case VK_FORMAT_D32_SFLOAT:
                aspectMask = VK_IMAGE_ASPECT_DEPTH_BIT;
                break;

            case VK_FORMAT_D16_UNORM_S8_UINT:
            case VK_FORMAT_D24_UNORM_S8_UINT:
            case VK_FORMAT_D32_SFLOAT_S8_UINT:
                aspectMask = VK_IMAGE_ASPECT_DEPTH_BIT | VK_IMAGE_ASPECT_STENCIL_BIT;
                break;

            case VK_FORMAT_S8_UINT:
                aspectMask = VK_IMAGE_ASPECT_STENCIL_BIT;
                break;

            default:
                aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
                break;
        }
        return aspectMask;
    }

} // namespace vk
} // namespace gfx
namespace vk = gfx::vk;
} // namespace dst
