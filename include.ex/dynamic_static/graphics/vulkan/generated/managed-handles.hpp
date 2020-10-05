
/*
==========================================
    Copyright (c) 2020 Dynamic_Static
    Patrick Purcell
        Licensed under the MIT license
    http://opensource.org/licenses/MIT
==========================================
*/

#pragma once

#include "dynamic_static/graphics/vulkan/detail/managed.hpp"
#include "dynamic_static/graphics/vulkan/detail/managed-handle.hpp"
#include "dynamic_static/graphics/vulkan/generated/managed-structures.hpp"
#include "dynamic_static/graphics/vulkan/defines.hpp"

#include <memory>

namespace dst {
namespace vk {

#ifdef VK_ENABLE_BETA_EXTENSIONS
template <>
class BasicManagedVkAccelerationStructureKHR
    : public detail::BasicManaged<VkAccelerationStructureKHR>
{
public:
    BasicManagedVkAccelerationStructureKHR() = default;
    #ifdef VK_ENABLE_BETA_EXTENSIONS
    static VkResult create(const Managed<VkDevice>& device, const VkAccelerationStructureCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, Managed<VkAccelerationStructureKHR>* pAccelerationStructure);
    #endif // VK_ENABLE_BETA_EXTENSIONS
    virtual ~BasicManaged() override;
    template <typename T> inline const T& get() const { static_assert(false && "The requested object type cannot be accessed from a Managed<VkAccelerationStructureKHR>"); };
    template <> const VkAccelerationStructureKHR& get<VkAccelerationStructureKHR>() const;
    template <> const VkObjectType& get<VkObjectType>() const;
    template <> const Managed<VkDevice>& get<Managed<VkDevice>>() const;
    #ifdef VK_ENABLE_BETA_EXTENSIONS
    template <> const Managed<VkAccelerationStructureCreateInfoKHR>& get<Managed<VkAccelerationStructureCreateInfoKHR>>() const;
    #endif // VK_ENABLE_BETA_EXTENSIONS

protected:
    class ControlBlock;
    std::shared_ptr<ControlBlock> mspControlBlock;
};
#endif // VK_ENABLE_BETA_EXTENSIONS


template <>
class BasicManagedVkBuffer
    : public detail::BasicManaged<VkBuffer>
{
public:
    BasicManagedVkBuffer() = default;
    static VkResult create(const Managed<VkDevice>& device, const VkBufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, Managed<VkBuffer>* pBuffer);
    virtual ~BasicManaged() override;
    template <typename T> inline const T& get() const { static_assert(false && "The requested object type cannot be accessed from a Managed<VkBuffer>"); };
    template <> const VkBuffer& get<VkBuffer>() const;
    template <> const VkObjectType& get<VkObjectType>() const;
    template <> const Managed<VkDevice>& get<Managed<VkDevice>>() const;
    template <> const Managed<VkBufferCreateInfo>& get<Managed<VkBufferCreateInfo>>() const;

protected:
    class ControlBlock;
    std::shared_ptr<ControlBlock> mspControlBlock;
};

template <>
class BasicManagedVkBufferView
    : public detail::BasicManaged<VkBufferView>
{
public:
    BasicManagedVkBufferView() = default;
    static VkResult create(const Managed<VkDevice>& device, const VkBufferViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, Managed<VkBufferView>* pView);
    virtual ~BasicManaged() override;
    template <typename T> inline const T& get() const { static_assert(false && "The requested object type cannot be accessed from a Managed<VkBufferView>"); };
    template <> const VkBufferView& get<VkBufferView>() const;
    template <> const VkObjectType& get<VkObjectType>() const;
    template <> const Managed<VkDevice>& get<Managed<VkDevice>>() const;
    template <> const Managed<VkBufferViewCreateInfo>& get<Managed<VkBufferViewCreateInfo>>() const;

protected:
    class ControlBlock;
    std::shared_ptr<ControlBlock> mspControlBlock;
};

template <>
class BasicManagedVkCommandBuffer
    : public detail::BasicManaged<VkCommandBuffer>
{
public:
    BasicManagedVkCommandBuffer() = default;
    static VkResult allocate(const Managed<VkDevice>& device, const VkCommandBufferAllocateInfo* pAllocateInfo, Managed<VkCommandBuffer>* pCommandBuffers);
    virtual ~BasicManaged() override;
    template <typename T> inline const T& get() const { static_assert(false && "The requested object type cannot be accessed from a Managed<VkCommandBuffer>"); };
    template <> const VkCommandBuffer& get<VkCommandBuffer>() const;
    template <> const VkObjectType& get<VkObjectType>() const;
    template <> const Managed<VkCommandPool>& get<Managed<VkCommandPool>>() const;
    template <> const Managed<VkCommandBufferAllocateInfo>& get<Managed<VkCommandBufferAllocateInfo>>() const;

protected:
    class ControlBlock;
    std::shared_ptr<ControlBlock> mspControlBlock;
};

template <>
class BasicManagedVkCommandPool
    : public detail::BasicManaged<VkCommandPool>
{
public:
    BasicManagedVkCommandPool() = default;
    static VkResult create(const Managed<VkDevice>& device, const VkCommandPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, Managed<VkCommandPool>* pCommandPool);
    virtual ~BasicManaged() override;
    template <typename T> inline const T& get() const { static_assert(false && "The requested object type cannot be accessed from a Managed<VkCommandPool>"); };
    template <> const VkCommandPool& get<VkCommandPool>() const;
    template <> const VkObjectType& get<VkObjectType>() const;
    template <> const Managed<VkDevice>& get<Managed<VkDevice>>() const;
    template <> const Managed<VkCommandPoolCreateInfo>& get<Managed<VkCommandPoolCreateInfo>>() const;

protected:
    class ControlBlock;
    std::shared_ptr<ControlBlock> mspControlBlock;
};

template <>
class BasicManagedVkDebugReportCallbackEXT
    : public detail::BasicManaged<VkDebugReportCallbackEXT>
{
public:
    BasicManagedVkDebugReportCallbackEXT() = default;
    static VkResult create(const Managed<VkInstance>& instance, const VkDebugReportCallbackCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, Managed<VkDebugReportCallbackEXT>* pCallback);
    virtual ~BasicManaged() override;
    template <typename T> inline const T& get() const { static_assert(false && "The requested object type cannot be accessed from a Managed<VkDebugReportCallbackEXT>"); };
    template <> const VkDebugReportCallbackEXT& get<VkDebugReportCallbackEXT>() const;
    template <> const VkObjectType& get<VkObjectType>() const;
    template <> const Managed<VkInstance>& get<Managed<VkInstance>>() const;
    template <> const Managed<VkDebugReportCallbackCreateInfoEXT>& get<Managed<VkDebugReportCallbackCreateInfoEXT>>() const;

protected:
    class ControlBlock;
    std::shared_ptr<ControlBlock> mspControlBlock;
};

template <>
class BasicManagedVkDebugUtilsMessengerEXT
    : public detail::BasicManaged<VkDebugUtilsMessengerEXT>
{
public:
    BasicManagedVkDebugUtilsMessengerEXT() = default;
    static VkResult create(const Managed<VkInstance>& instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, Managed<VkDebugUtilsMessengerEXT>* pMessenger);
    virtual ~BasicManaged() override;
    template <typename T> inline const T& get() const { static_assert(false && "The requested object type cannot be accessed from a Managed<VkDebugUtilsMessengerEXT>"); };
    template <> const VkDebugUtilsMessengerEXT& get<VkDebugUtilsMessengerEXT>() const;
    template <> const VkObjectType& get<VkObjectType>() const;
    template <> const Managed<VkInstance>& get<Managed<VkInstance>>() const;
    template <> const Managed<VkDebugUtilsMessengerCreateInfoEXT>& get<Managed<VkDebugUtilsMessengerCreateInfoEXT>>() const;

protected:
    class ControlBlock;
    std::shared_ptr<ControlBlock> mspControlBlock;
};

#ifdef VK_ENABLE_BETA_EXTENSIONS
template <>
class BasicManagedVkDeferredOperationKHR
    : public detail::BasicManaged<VkDeferredOperationKHR>
{
public:
    BasicManagedVkDeferredOperationKHR() = default;
    #ifdef VK_ENABLE_BETA_EXTENSIONS
    static VkResult create(const Managed<VkDevice>& device, const VkAllocationCallbacks* pAllocator, Managed<VkDeferredOperationKHR>* pDeferredOperation);
    #endif // VK_ENABLE_BETA_EXTENSIONS
    virtual ~BasicManaged() override;
    template <typename T> inline const T& get() const { static_assert(false && "The requested object type cannot be accessed from a Managed<VkDeferredOperationKHR>"); };
    template <> const VkDeferredOperationKHR& get<VkDeferredOperationKHR>() const;
    template <> const VkObjectType& get<VkObjectType>() const;
    template <> const Managed<VkDevice>& get<Managed<VkDevice>>() const;

protected:
    class ControlBlock;
    std::shared_ptr<ControlBlock> mspControlBlock;
};
#endif // VK_ENABLE_BETA_EXTENSIONS

template <>
class BasicManagedVkDescriptorPool
    : public detail::BasicManaged<VkDescriptorPool>
{
public:
    BasicManagedVkDescriptorPool() = default;
    static VkResult create(const Managed<VkDevice>& device, const VkDescriptorPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, Managed<VkDescriptorPool>* pDescriptorPool);
    virtual ~BasicManaged() override;
    template <typename T> inline const T& get() const { static_assert(false && "The requested object type cannot be accessed from a Managed<VkDescriptorPool>"); };
    template <> const VkDescriptorPool& get<VkDescriptorPool>() const;
    template <> const VkObjectType& get<VkObjectType>() const;
    template <> const Managed<VkDevice>& get<Managed<VkDevice>>() const;
    template <> const Managed<VkDescriptorPoolCreateInfo>& get<Managed<VkDescriptorPoolCreateInfo>>() const;

protected:
    class ControlBlock;
    std::shared_ptr<ControlBlock> mspControlBlock;
};

template <>
class BasicManagedVkDescriptorSet
    : public detail::BasicManaged<VkDescriptorSet>
{
public:
    BasicManagedVkDescriptorSet() = default;
    static VkResult allocate(const Managed<VkDevice>& device, const VkDescriptorSetAllocateInfo* pAllocateInfo, Managed<VkDescriptorSet>* pDescriptorSets);
    virtual ~BasicManaged() override;
    template <typename T> inline const T& get() const { static_assert(false && "The requested object type cannot be accessed from a Managed<VkDescriptorSet>"); };
    template <> const VkDescriptorSet& get<VkDescriptorSet>() const;
    template <> const VkObjectType& get<VkObjectType>() const;
    template <> const Managed<VkDescriptorPool>& get<Managed<VkDescriptorPool>>() const;
    template <> const Managed<VkDescriptorSetAllocateInfo>& get<Managed<VkDescriptorSetAllocateInfo>>() const;

protected:
    class ControlBlock;
    std::shared_ptr<ControlBlock> mspControlBlock;
};

template <>
class BasicManagedVkDescriptorSetLayout
    : public detail::BasicManaged<VkDescriptorSetLayout>
{
public:
    BasicManagedVkDescriptorSetLayout() = default;
    static VkResult create(const Managed<VkDevice>& device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, Managed<VkDescriptorSetLayout>* pSetLayout);
    virtual ~BasicManaged() override;
    template <typename T> inline const T& get() const { static_assert(false && "The requested object type cannot be accessed from a Managed<VkDescriptorSetLayout>"); };
    template <> const VkDescriptorSetLayout& get<VkDescriptorSetLayout>() const;
    template <> const VkObjectType& get<VkObjectType>() const;
    template <> const Managed<VkDevice>& get<Managed<VkDevice>>() const;
    template <> const Managed<VkDescriptorSetLayoutCreateInfo>& get<Managed<VkDescriptorSetLayoutCreateInfo>>() const;

protected:
    class ControlBlock;
    std::shared_ptr<ControlBlock> mspControlBlock;
};

template <>
class BasicManagedVkDescriptorUpdateTemplate
    : public detail::BasicManaged<VkDescriptorUpdateTemplate>
{
public:
    BasicManagedVkDescriptorUpdateTemplate() = default;
    static VkResult create(const Managed<VkDevice>& device, const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, Managed<VkDescriptorUpdateTemplate>* pDescriptorUpdateTemplate);
    virtual ~BasicManaged() override;
    template <typename T> inline const T& get() const { static_assert(false && "The requested object type cannot be accessed from a Managed<VkDescriptorUpdateTemplate>"); };
    template <> const VkDescriptorUpdateTemplate& get<VkDescriptorUpdateTemplate>() const;
    template <> const VkObjectType& get<VkObjectType>() const;
    template <> const Managed<VkDevice>& get<Managed<VkDevice>>() const;
    template <> const Managed<VkDescriptorUpdateTemplateCreateInfo>& get<Managed<VkDescriptorUpdateTemplateCreateInfo>>() const;

protected:
    class ControlBlock;
    std::shared_ptr<ControlBlock> mspControlBlock;
};


template <>
class BasicManagedVkDevice
    : public detail::BasicManaged<VkDevice>
{
public:
    BasicManagedVkDevice() = default;
    static VkResult create(const Managed<VkPhysicalDevice>& physicalDevice, const VkDeviceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, Managed<VkDevice>* pDevice);
    virtual ~BasicManaged() override;
    template <typename T> inline const T& get() const { static_assert(false && "The requested object type cannot be accessed from a Managed<VkDevice>"); };
    template <> const VkDevice& get<VkDevice>() const;
    template <> const VkObjectType& get<VkObjectType>() const;
    template <> const Managed<VkPhysicalDevice>& get<Managed<VkPhysicalDevice>>() const;
    template <> const Managed<VkDeviceCreateInfo>& get<Managed<VkDeviceCreateInfo>>() const;

protected:
    class ControlBlock;
    std::shared_ptr<ControlBlock> mspControlBlock;
};

template <>
class BasicManagedVkDeviceMemory
    : public detail::BasicManaged<VkDeviceMemory>
{
public:
    BasicManagedVkDeviceMemory() = default;
    static VkResult allocate(const Managed<VkDevice>& device, const VkMemoryAllocateInfo* pAllocateInfo, const VkAllocationCallbacks* pAllocator, Managed<VkDeviceMemory>* pMemory);
    virtual ~BasicManaged() override;
    template <typename T> inline const T& get() const { static_assert(false && "The requested object type cannot be accessed from a Managed<VkDeviceMemory>"); };
    template <> const VkDeviceMemory& get<VkDeviceMemory>() const;
    template <> const VkObjectType& get<VkObjectType>() const;
    template <> const Managed<VkDevice>& get<Managed<VkDevice>>() const;
    template <> const Managed<VkMemoryAllocateInfo>& get<Managed<VkMemoryAllocateInfo>>() const;

protected:
    class ControlBlock;
    std::shared_ptr<ControlBlock> mspControlBlock;
};

template <>
class BasicManagedVkDisplayKHR
    : public detail::BasicManaged<VkDisplayKHR>
{
public:
    BasicManagedVkDisplayKHR() = default;
    virtual ~BasicManaged() override;
    template <typename T> inline const T& get() const { static_assert(false && "The requested object type cannot be accessed from a Managed<VkDisplayKHR>"); };
    template <> const VkDisplayKHR& get<VkDisplayKHR>() const;
    template <> const VkObjectType& get<VkObjectType>() const;
    template <> const Managed<VkPhysicalDevice>& get<Managed<VkPhysicalDevice>>() const;

protected:
    class ControlBlock;
    std::shared_ptr<ControlBlock> mspControlBlock;
};

template <>
class BasicManagedVkDisplayModeKHR
    : public detail::BasicManaged<VkDisplayModeKHR>
{
public:
    BasicManagedVkDisplayModeKHR() = default;
    static VkResult create(const Managed<VkPhysicalDevice>& physicalDevice, const Managed<VkDisplayKHR>& display, const VkDisplayModeCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, Managed<VkDisplayModeKHR>* pMode);
    virtual ~BasicManaged() override;
    template <typename T> inline const T& get() const { static_assert(false && "The requested object type cannot be accessed from a Managed<VkDisplayModeKHR>"); };
    template <> const VkDisplayModeKHR& get<VkDisplayModeKHR>() const;
    template <> const VkObjectType& get<VkObjectType>() const;
    template <> const Managed<VkDisplayKHR>& get<Managed<VkDisplayKHR>>() const;
    template <> const Managed<VkDisplayModeCreateInfoKHR>& get<Managed<VkDisplayModeCreateInfoKHR>>() const;

protected:
    class ControlBlock;
    std::shared_ptr<ControlBlock> mspControlBlock;
};

template <>
class BasicManagedVkEvent
    : public detail::BasicManaged<VkEvent>
{
public:
    BasicManagedVkEvent() = default;
    static VkResult create(const Managed<VkDevice>& device, const VkEventCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, Managed<VkEvent>* pEvent);
    virtual ~BasicManaged() override;
    template <typename T> inline const T& get() const { static_assert(false && "The requested object type cannot be accessed from a Managed<VkEvent>"); };
    template <> const VkEvent& get<VkEvent>() const;
    template <> const VkObjectType& get<VkObjectType>() const;
    template <> const Managed<VkDevice>& get<Managed<VkDevice>>() const;
    template <> const Managed<VkEventCreateInfo>& get<Managed<VkEventCreateInfo>>() const;

protected:
    class ControlBlock;
    std::shared_ptr<ControlBlock> mspControlBlock;
};

template <>
class BasicManagedVkFence
    : public detail::BasicManaged<VkFence>
{
public:
    BasicManagedVkFence() = default;
    static VkResult create(const Managed<VkDevice>& device, const VkFenceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, Managed<VkFence>* pFence);
    virtual ~BasicManaged() override;
    template <typename T> inline const T& get() const { static_assert(false && "The requested object type cannot be accessed from a Managed<VkFence>"); };
    template <> const VkFence& get<VkFence>() const;
    template <> const VkObjectType& get<VkObjectType>() const;
    template <> const Managed<VkDevice>& get<Managed<VkDevice>>() const;
    template <> const Managed<VkFenceCreateInfo>& get<Managed<VkFenceCreateInfo>>() const;

protected:
    class ControlBlock;
    std::shared_ptr<ControlBlock> mspControlBlock;
};

template <>
class BasicManagedVkFramebuffer
    : public detail::BasicManaged<VkFramebuffer>
{
public:
    BasicManagedVkFramebuffer() = default;
    static VkResult create(const Managed<VkDevice>& device, const VkFramebufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, Managed<VkFramebuffer>* pFramebuffer);
    virtual ~BasicManaged() override;
    template <typename T> inline const T& get() const { static_assert(false && "The requested object type cannot be accessed from a Managed<VkFramebuffer>"); };
    template <> const VkFramebuffer& get<VkFramebuffer>() const;
    template <> const VkObjectType& get<VkObjectType>() const;
    template <> const Managed<VkDevice>& get<Managed<VkDevice>>() const;
    template <> const Managed<VkFramebufferCreateInfo>& get<Managed<VkFramebufferCreateInfo>>() const;

protected:
    class ControlBlock;
    std::shared_ptr<ControlBlock> mspControlBlock;
};

template <>
class BasicManagedVkImage
    : public detail::BasicManaged<VkImage>
{
public:
    BasicManagedVkImage() = default;
    static VkResult create(const Managed<VkDevice>& device, const VkImageCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, Managed<VkImage>* pImage);
    virtual ~BasicManaged() override;
    template <typename T> inline const T& get() const { static_assert(false && "The requested object type cannot be accessed from a Managed<VkImage>"); };
    template <> const VkImage& get<VkImage>() const;
    template <> const VkObjectType& get<VkObjectType>() const;
    template <> const Managed<VkDevice>& get<Managed<VkDevice>>() const;
    template <> const Managed<VkImageCreateInfo>& get<Managed<VkImageCreateInfo>>() const;

protected:
    class ControlBlock;
    std::shared_ptr<ControlBlock> mspControlBlock;
};

template <>
class BasicManagedVkImageView
    : public detail::BasicManaged<VkImageView>
{
public:
    BasicManagedVkImageView() = default;
    static VkResult create(const Managed<VkDevice>& device, const VkImageViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, Managed<VkImageView>* pView);
    virtual ~BasicManaged() override;
    template <typename T> inline const T& get() const { static_assert(false && "The requested object type cannot be accessed from a Managed<VkImageView>"); };
    template <> const VkImageView& get<VkImageView>() const;
    template <> const VkObjectType& get<VkObjectType>() const;
    template <> const Managed<VkDevice>& get<Managed<VkDevice>>() const;
    template <> const Managed<VkImageViewCreateInfo>& get<Managed<VkImageViewCreateInfo>>() const;

protected:
    class ControlBlock;
    std::shared_ptr<ControlBlock> mspControlBlock;
};

template <>
class BasicManagedVkIndirectCommandsLayoutNV
    : public detail::BasicManaged<VkIndirectCommandsLayoutNV>
{
public:
    BasicManagedVkIndirectCommandsLayoutNV() = default;
    static VkResult create(const Managed<VkDevice>& device, const VkIndirectCommandsLayoutCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, Managed<VkIndirectCommandsLayoutNV>* pIndirectCommandsLayout);
    virtual ~BasicManaged() override;
    template <typename T> inline const T& get() const { static_assert(false && "The requested object type cannot be accessed from a Managed<VkIndirectCommandsLayoutNV>"); };
    template <> const VkIndirectCommandsLayoutNV& get<VkIndirectCommandsLayoutNV>() const;
    template <> const VkObjectType& get<VkObjectType>() const;
    template <> const Managed<VkDevice>& get<Managed<VkDevice>>() const;
    template <> const Managed<VkIndirectCommandsLayoutCreateInfoNV>& get<Managed<VkIndirectCommandsLayoutCreateInfoNV>>() const;

protected:
    class ControlBlock;
    std::shared_ptr<ControlBlock> mspControlBlock;
};

template <>
class BasicManagedVkInstance
    : public detail::BasicManaged<VkInstance>
{
public:
    BasicManagedVkInstance() = default;
    static VkResult create(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, Managed<VkInstance>* pInstance);
    virtual ~BasicManaged() override;
    template <typename T> inline const T& get() const { static_assert(false && "The requested object type cannot be accessed from a Managed<VkInstance>"); };
    template <> const VkInstance& get<VkInstance>() const;
    template <> const VkObjectType& get<VkObjectType>() const;
    template <> const Managed<VkInstanceCreateInfo>& get<Managed<VkInstanceCreateInfo>>() const;

protected:
    class ControlBlock;
    std::shared_ptr<ControlBlock> mspControlBlock;
};

template <>
class BasicManagedVkPerformanceConfigurationINTEL
    : public detail::BasicManaged<VkPerformanceConfigurationINTEL>
{
public:
    BasicManagedVkPerformanceConfigurationINTEL() = default;
    virtual ~BasicManaged() override;
    template <typename T> inline const T& get() const { static_assert(false && "The requested object type cannot be accessed from a Managed<VkPerformanceConfigurationINTEL>"); };
    template <> const VkPerformanceConfigurationINTEL& get<VkPerformanceConfigurationINTEL>() const;
    template <> const VkObjectType& get<VkObjectType>() const;
    template <> const Managed<VkDevice>& get<Managed<VkDevice>>() const;

protected:
    class ControlBlock;
    std::shared_ptr<ControlBlock> mspControlBlock;
};

template <>
class BasicManagedVkPhysicalDevice
    : public detail::BasicManaged<VkPhysicalDevice>
{
public:
    BasicManagedVkPhysicalDevice() = default;
    virtual ~BasicManaged() override;
    template <typename T> inline const T& get() const { static_assert(false && "The requested object type cannot be accessed from a Managed<VkPhysicalDevice>"); };
    template <> const VkPhysicalDevice& get<VkPhysicalDevice>() const;
    template <> const VkObjectType& get<VkObjectType>() const;
    template <> const Managed<VkInstance>& get<Managed<VkInstance>>() const;

protected:
    class ControlBlock;
    std::shared_ptr<ControlBlock> mspControlBlock;
};

template <>
class BasicManagedVkPipeline
    : public detail::BasicManaged<VkPipeline>
{
public:
    BasicManagedVkPipeline() = default;
    static VkResult create(const Managed<VkDevice>& device, const Managed<VkPipelineCache>& pipelineCache, uint32_t createInfoCount, const VkComputePipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, Managed<VkPipeline>* pPipelines);
    static VkResult create(const Managed<VkDevice>& device, const Managed<VkPipelineCache>& pipelineCache, uint32_t createInfoCount, const VkGraphicsPipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, Managed<VkPipeline>* pPipelines);
    #ifdef VK_ENABLE_BETA_EXTENSIONS
    static VkResult create(const Managed<VkDevice>& device, const Managed<VkPipelineCache>& pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoKHR* pCreateInfos, const VkAllocationCallbacks* pAllocator, Managed<VkPipeline>* pPipelines);
    #endif // VK_ENABLE_BETA_EXTENSIONS
    static VkResult create(const Managed<VkDevice>& device, const Managed<VkPipelineCache>& pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoNV* pCreateInfos, const VkAllocationCallbacks* pAllocator, Managed<VkPipeline>* pPipelines);
    virtual ~BasicManaged() override;
    template <typename T> inline const T& get() const { static_assert(false && "The requested object type cannot be accessed from a Managed<VkPipeline>"); };
    template <> const VkPipeline& get<VkPipeline>() const;
    template <> const VkObjectType& get<VkObjectType>() const;
    template <> const Managed<VkDevice>& get<Managed<VkDevice>>() const;
    template <> const Managed<VkComputePipelineCreateInfo>& get<Managed<VkComputePipelineCreateInfo>>() const;
    template <> const Managed<VkGraphicsPipelineCreateInfo>& get<Managed<VkGraphicsPipelineCreateInfo>>() const;
    #ifdef VK_ENABLE_BETA_EXTENSIONS
    template <> const Managed<VkRayTracingPipelineCreateInfoKHR>& get<Managed<VkRayTracingPipelineCreateInfoKHR>>() const;
    #endif // VK_ENABLE_BETA_EXTENSIONS
    template <> const Managed<VkRayTracingPipelineCreateInfoNV>& get<Managed<VkRayTracingPipelineCreateInfoNV>>() const;

protected:
    class ControlBlock;
    std::shared_ptr<ControlBlock> mspControlBlock;
};

template <>
class BasicManagedVkPipelineCache
    : public detail::BasicManaged<VkPipelineCache>
{
public:
    BasicManagedVkPipelineCache() = default;
    static VkResult create(const Managed<VkDevice>& device, const VkPipelineCacheCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, Managed<VkPipelineCache>* pPipelineCache);
    virtual ~BasicManaged() override;
    template <typename T> inline const T& get() const { static_assert(false && "The requested object type cannot be accessed from a Managed<VkPipelineCache>"); };
    template <> const VkPipelineCache& get<VkPipelineCache>() const;
    template <> const VkObjectType& get<VkObjectType>() const;
    template <> const Managed<VkDevice>& get<Managed<VkDevice>>() const;
    template <> const Managed<VkPipelineCacheCreateInfo>& get<Managed<VkPipelineCacheCreateInfo>>() const;

protected:
    class ControlBlock;
    std::shared_ptr<ControlBlock> mspControlBlock;
};

template <>
class BasicManagedVkPipelineLayout
    : public detail::BasicManaged<VkPipelineLayout>
{
public:
    BasicManagedVkPipelineLayout() = default;
    static VkResult create(const Managed<VkDevice>& device, const VkPipelineLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, Managed<VkPipelineLayout>* pPipelineLayout);
    virtual ~BasicManaged() override;
    template <typename T> inline const T& get() const { static_assert(false && "The requested object type cannot be accessed from a Managed<VkPipelineLayout>"); };
    template <> const VkPipelineLayout& get<VkPipelineLayout>() const;
    template <> const VkObjectType& get<VkObjectType>() const;
    template <> const Managed<VkDevice>& get<Managed<VkDevice>>() const;
    template <> const Managed<VkPipelineLayoutCreateInfo>& get<Managed<VkPipelineLayoutCreateInfo>>() const;

protected:
    class ControlBlock;
    std::shared_ptr<ControlBlock> mspControlBlock;
};

template <>
class BasicManagedVkPrivateDataSlotEXT
    : public detail::BasicManaged<VkPrivateDataSlotEXT>
{
public:
    BasicManagedVkPrivateDataSlotEXT() = default;
    static VkResult create(const Managed<VkDevice>& device, const VkPrivateDataSlotCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, Managed<VkPrivateDataSlotEXT>* pPrivateDataSlot);
    virtual ~BasicManaged() override;
    template <typename T> inline const T& get() const { static_assert(false && "The requested object type cannot be accessed from a Managed<VkPrivateDataSlotEXT>"); };
    template <> const VkPrivateDataSlotEXT& get<VkPrivateDataSlotEXT>() const;
    template <> const VkObjectType& get<VkObjectType>() const;
    template <> const Managed<VkDevice>& get<Managed<VkDevice>>() const;
    template <> const Managed<VkPrivateDataSlotCreateInfoEXT>& get<Managed<VkPrivateDataSlotCreateInfoEXT>>() const;

protected:
    class ControlBlock;
    std::shared_ptr<ControlBlock> mspControlBlock;
};

template <>
class BasicManagedVkQueryPool
    : public detail::BasicManaged<VkQueryPool>
{
public:
    BasicManagedVkQueryPool() = default;
    static VkResult create(const Managed<VkDevice>& device, const VkQueryPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, Managed<VkQueryPool>* pQueryPool);
    virtual ~BasicManaged() override;
    template <typename T> inline const T& get() const { static_assert(false && "The requested object type cannot be accessed from a Managed<VkQueryPool>"); };
    template <> const VkQueryPool& get<VkQueryPool>() const;
    template <> const VkObjectType& get<VkObjectType>() const;
    template <> const Managed<VkDevice>& get<Managed<VkDevice>>() const;
    template <> const Managed<VkQueryPoolCreateInfo>& get<Managed<VkQueryPoolCreateInfo>>() const;

protected:
    class ControlBlock;
    std::shared_ptr<ControlBlock> mspControlBlock;
};

template <>
class BasicManagedVkQueue
    : public detail::BasicManaged<VkQueue>
{
public:
    BasicManagedVkQueue() = default;
    virtual ~BasicManaged() override;
    template <typename T> inline const T& get() const { static_assert(false && "The requested object type cannot be accessed from a Managed<VkQueue>"); };
    template <> const VkQueue& get<VkQueue>() const;
    template <> const VkObjectType& get<VkObjectType>() const;
    template <> const Managed<VkDevice>& get<Managed<VkDevice>>() const;

protected:
    class ControlBlock;
    std::shared_ptr<ControlBlock> mspControlBlock;
};

template <>
class BasicManagedVkRenderPass
    : public detail::BasicManaged<VkRenderPass>
{
public:
    BasicManagedVkRenderPass() = default;
    static VkResult create(const Managed<VkDevice>& device, const VkRenderPassCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, Managed<VkRenderPass>* pRenderPass);
    static VkResult create(const Managed<VkDevice>& device, const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, Managed<VkRenderPass>* pRenderPass);
    virtual ~BasicManaged() override;
    template <typename T> inline const T& get() const { static_assert(false && "The requested object type cannot be accessed from a Managed<VkRenderPass>"); };
    template <> const VkRenderPass& get<VkRenderPass>() const;
    template <> const VkObjectType& get<VkObjectType>() const;
    template <> const Managed<VkDevice>& get<Managed<VkDevice>>() const;
    template <> const Managed<VkRenderPassCreateInfo>& get<Managed<VkRenderPassCreateInfo>>() const;
    template <> const Managed<VkRenderPassCreateInfo2>& get<Managed<VkRenderPassCreateInfo2>>() const;

protected:
    class ControlBlock;
    std::shared_ptr<ControlBlock> mspControlBlock;
};

template <>
class BasicManagedVkSampler
    : public detail::BasicManaged<VkSampler>
{
public:
    BasicManagedVkSampler() = default;
    static VkResult create(const Managed<VkDevice>& device, const VkSamplerCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, Managed<VkSampler>* pSampler);
    virtual ~BasicManaged() override;
    template <typename T> inline const T& get() const { static_assert(false && "The requested object type cannot be accessed from a Managed<VkSampler>"); };
    template <> const VkSampler& get<VkSampler>() const;
    template <> const VkObjectType& get<VkObjectType>() const;
    template <> const Managed<VkDevice>& get<Managed<VkDevice>>() const;
    template <> const Managed<VkSamplerCreateInfo>& get<Managed<VkSamplerCreateInfo>>() const;

protected:
    class ControlBlock;
    std::shared_ptr<ControlBlock> mspControlBlock;
};

template <>
class BasicManagedVkSamplerYcbcrConversion
    : public detail::BasicManaged<VkSamplerYcbcrConversion>
{
public:
    BasicManagedVkSamplerYcbcrConversion() = default;
    static VkResult create(const Managed<VkDevice>& device, const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, Managed<VkSamplerYcbcrConversion>* pYcbcrConversion);
    virtual ~BasicManaged() override;
    template <typename T> inline const T& get() const { static_assert(false && "The requested object type cannot be accessed from a Managed<VkSamplerYcbcrConversion>"); };
    template <> const VkSamplerYcbcrConversion& get<VkSamplerYcbcrConversion>() const;
    template <> const VkObjectType& get<VkObjectType>() const;
    template <> const Managed<VkDevice>& get<Managed<VkDevice>>() const;
    template <> const Managed<VkSamplerYcbcrConversionCreateInfo>& get<Managed<VkSamplerYcbcrConversionCreateInfo>>() const;

protected:
    class ControlBlock;
    std::shared_ptr<ControlBlock> mspControlBlock;
};


template <>
class BasicManagedVkSemaphore
    : public detail::BasicManaged<VkSemaphore>
{
public:
    BasicManagedVkSemaphore() = default;
    static VkResult create(const Managed<VkDevice>& device, const VkSemaphoreCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, Managed<VkSemaphore>* pSemaphore);
    virtual ~BasicManaged() override;
    template <typename T> inline const T& get() const { static_assert(false && "The requested object type cannot be accessed from a Managed<VkSemaphore>"); };
    template <> const VkSemaphore& get<VkSemaphore>() const;
    template <> const VkObjectType& get<VkObjectType>() const;
    template <> const Managed<VkDevice>& get<Managed<VkDevice>>() const;
    template <> const Managed<VkSemaphoreCreateInfo>& get<Managed<VkSemaphoreCreateInfo>>() const;

protected:
    class ControlBlock;
    std::shared_ptr<ControlBlock> mspControlBlock;
};

template <>
class BasicManagedVkShaderModule
    : public detail::BasicManaged<VkShaderModule>
{
public:
    BasicManagedVkShaderModule() = default;
    static VkResult create(const Managed<VkDevice>& device, const VkShaderModuleCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, Managed<VkShaderModule>* pShaderModule);
    virtual ~BasicManaged() override;
    template <typename T> inline const T& get() const { static_assert(false && "The requested object type cannot be accessed from a Managed<VkShaderModule>"); };
    template <> const VkShaderModule& get<VkShaderModule>() const;
    template <> const VkObjectType& get<VkObjectType>() const;
    template <> const Managed<VkDevice>& get<Managed<VkDevice>>() const;
    template <> const Managed<VkShaderModuleCreateInfo>& get<Managed<VkShaderModuleCreateInfo>>() const;

protected:
    class ControlBlock;
    std::shared_ptr<ControlBlock> mspControlBlock;
};

template <>
class BasicManagedVkSurfaceKHR
    : public detail::BasicManaged<VkSurfaceKHR>
{
public:
    BasicManagedVkSurfaceKHR() = default;
    #ifdef VK_USE_PLATFORM_ANDROID_KHR
    static VkResult create(const Managed<VkInstance>& instance, const VkAndroidSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, Managed<VkSurfaceKHR>* pSurface);
    #endif // VK_USE_PLATFORM_ANDROID_KHR
    #ifdef VK_USE_PLATFORM_DIRECTFB_EXT
    static VkResult create(const Managed<VkInstance>& instance, const VkDirectFBSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, Managed<VkSurfaceKHR>* pSurface);
    #endif // VK_USE_PLATFORM_DIRECTFB_EXT
    static VkResult create(const Managed<VkInstance>& instance, const VkDisplaySurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, Managed<VkSurfaceKHR>* pSurface);
    static VkResult create(const Managed<VkInstance>& instance, const VkHeadlessSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, Managed<VkSurfaceKHR>* pSurface);
    #ifdef VK_USE_PLATFORM_IOS_MVK
    static VkResult create(const Managed<VkInstance>& instance, const VkIOSSurfaceCreateInfoMVK* pCreateInfo, const VkAllocationCallbacks* pAllocator, Managed<VkSurfaceKHR>* pSurface);
    #endif // VK_USE_PLATFORM_IOS_MVK
    #ifdef VK_USE_PLATFORM_FUCHSIA
    static VkResult create(const Managed<VkInstance>& instance, const VkImagePipeSurfaceCreateInfoFUCHSIA* pCreateInfo, const VkAllocationCallbacks* pAllocator, Managed<VkSurfaceKHR>* pSurface);
    #endif // VK_USE_PLATFORM_FUCHSIA
    #ifdef VK_USE_PLATFORM_MACOS_MVK
    static VkResult create(const Managed<VkInstance>& instance, const VkMacOSSurfaceCreateInfoMVK* pCreateInfo, const VkAllocationCallbacks* pAllocator, Managed<VkSurfaceKHR>* pSurface);
    #endif // VK_USE_PLATFORM_MACOS_MVK
    #ifdef VK_USE_PLATFORM_METAL_EXT
    static VkResult create(const Managed<VkInstance>& instance, const VkMetalSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, Managed<VkSurfaceKHR>* pSurface);
    #endif // VK_USE_PLATFORM_METAL_EXT
    #ifdef VK_USE_PLATFORM_GGP
    static VkResult create(const Managed<VkInstance>& instance, const VkStreamDescriptorSurfaceCreateInfoGGP* pCreateInfo, const VkAllocationCallbacks* pAllocator, Managed<VkSurfaceKHR>* pSurface);
    #endif // VK_USE_PLATFORM_GGP
    #ifdef VK_USE_PLATFORM_VI_NN
    static VkResult create(const Managed<VkInstance>& instance, const VkViSurfaceCreateInfoNN* pCreateInfo, const VkAllocationCallbacks* pAllocator, Managed<VkSurfaceKHR>* pSurface);
    #endif // VK_USE_PLATFORM_VI_NN
    #ifdef VK_USE_PLATFORM_WAYLAND_KHR
    static VkResult create(const Managed<VkInstance>& instance, const VkWaylandSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, Managed<VkSurfaceKHR>* pSurface);
    #endif // VK_USE_PLATFORM_WAYLAND_KHR
    #ifdef VK_USE_PLATFORM_WIN32_KHR
    static VkResult create(const Managed<VkInstance>& instance, const VkWin32SurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, Managed<VkSurfaceKHR>* pSurface);
    #endif // VK_USE_PLATFORM_WIN32_KHR
    #ifdef VK_USE_PLATFORM_XCB_KHR
    static VkResult create(const Managed<VkInstance>& instance, const VkXcbSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, Managed<VkSurfaceKHR>* pSurface);
    #endif // VK_USE_PLATFORM_XCB_KHR
    #ifdef VK_USE_PLATFORM_XLIB_KHR
    static VkResult create(const Managed<VkInstance>& instance, const VkXlibSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, Managed<VkSurfaceKHR>* pSurface);
    #endif // VK_USE_PLATFORM_XLIB_KHR
    virtual ~BasicManaged() override;
    template <typename T> inline const T& get() const { static_assert(false && "The requested object type cannot be accessed from a Managed<VkSurfaceKHR>"); };
    template <> const VkSurfaceKHR& get<VkSurfaceKHR>() const;
    template <> const VkObjectType& get<VkObjectType>() const;
    template <> const Managed<VkInstance>& get<Managed<VkInstance>>() const;
    #ifdef VK_USE_PLATFORM_ANDROID_KHR
    template <> const Managed<VkAndroidSurfaceCreateInfoKHR>& get<Managed<VkAndroidSurfaceCreateInfoKHR>>() const;
    #endif // VK_USE_PLATFORM_ANDROID_KHR
    #ifdef VK_USE_PLATFORM_DIRECTFB_EXT
    template <> const Managed<VkDirectFBSurfaceCreateInfoEXT>& get<Managed<VkDirectFBSurfaceCreateInfoEXT>>() const;
    #endif // VK_USE_PLATFORM_DIRECTFB_EXT
    template <> const Managed<VkDisplaySurfaceCreateInfoKHR>& get<Managed<VkDisplaySurfaceCreateInfoKHR>>() const;
    template <> const Managed<VkHeadlessSurfaceCreateInfoEXT>& get<Managed<VkHeadlessSurfaceCreateInfoEXT>>() const;
    #ifdef VK_USE_PLATFORM_IOS_MVK
    template <> const Managed<VkIOSSurfaceCreateInfoMVK>& get<Managed<VkIOSSurfaceCreateInfoMVK>>() const;
    #endif // VK_USE_PLATFORM_IOS_MVK
    #ifdef VK_USE_PLATFORM_FUCHSIA
    template <> const Managed<VkImagePipeSurfaceCreateInfoFUCHSIA>& get<Managed<VkImagePipeSurfaceCreateInfoFUCHSIA>>() const;
    #endif // VK_USE_PLATFORM_FUCHSIA
    #ifdef VK_USE_PLATFORM_MACOS_MVK
    template <> const Managed<VkMacOSSurfaceCreateInfoMVK>& get<Managed<VkMacOSSurfaceCreateInfoMVK>>() const;
    #endif // VK_USE_PLATFORM_MACOS_MVK
    #ifdef VK_USE_PLATFORM_METAL_EXT
    template <> const Managed<VkMetalSurfaceCreateInfoEXT>& get<Managed<VkMetalSurfaceCreateInfoEXT>>() const;
    #endif // VK_USE_PLATFORM_METAL_EXT
    #ifdef VK_USE_PLATFORM_GGP
    template <> const Managed<VkStreamDescriptorSurfaceCreateInfoGGP>& get<Managed<VkStreamDescriptorSurfaceCreateInfoGGP>>() const;
    #endif // VK_USE_PLATFORM_GGP
    #ifdef VK_USE_PLATFORM_VI_NN
    template <> const Managed<VkViSurfaceCreateInfoNN>& get<Managed<VkViSurfaceCreateInfoNN>>() const;
    #endif // VK_USE_PLATFORM_VI_NN
    #ifdef VK_USE_PLATFORM_WAYLAND_KHR
    template <> const Managed<VkWaylandSurfaceCreateInfoKHR>& get<Managed<VkWaylandSurfaceCreateInfoKHR>>() const;
    #endif // VK_USE_PLATFORM_WAYLAND_KHR
    #ifdef VK_USE_PLATFORM_WIN32_KHR
    template <> const Managed<VkWin32SurfaceCreateInfoKHR>& get<Managed<VkWin32SurfaceCreateInfoKHR>>() const;
    #endif // VK_USE_PLATFORM_WIN32_KHR
    #ifdef VK_USE_PLATFORM_XCB_KHR
    template <> const Managed<VkXcbSurfaceCreateInfoKHR>& get<Managed<VkXcbSurfaceCreateInfoKHR>>() const;
    #endif // VK_USE_PLATFORM_XCB_KHR
    #ifdef VK_USE_PLATFORM_XLIB_KHR
    template <> const Managed<VkXlibSurfaceCreateInfoKHR>& get<Managed<VkXlibSurfaceCreateInfoKHR>>() const;
    #endif // VK_USE_PLATFORM_XLIB_KHR

protected:
    class ControlBlock;
    std::shared_ptr<ControlBlock> mspControlBlock;
};

template <>
class BasicManagedVkSwapchainKHR
    : public detail::BasicManaged<VkSwapchainKHR>
{
public:
    BasicManagedVkSwapchainKHR() = default;
    static VkResult create(const Managed<VkDevice>& device, uint32_t swapchainCount, const VkSwapchainCreateInfoKHR* pCreateInfos, const VkAllocationCallbacks* pAllocator, Managed<VkSwapchainKHR>* pSwapchains);
    static VkResult create(const Managed<VkDevice>& device, const VkSwapchainCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, Managed<VkSwapchainKHR>* pSwapchain);
    virtual ~BasicManaged() override;
    template <typename T> inline const T& get() const { static_assert(false && "The requested object type cannot be accessed from a Managed<VkSwapchainKHR>"); };
    template <> const VkSwapchainKHR& get<VkSwapchainKHR>() const;
    template <> const VkObjectType& get<VkObjectType>() const;
    template <> const Managed<VkDevice>& get<Managed<VkDevice>>() const;
    template <> const Managed<VkSurfaceKHR>& get<Managed<VkSurfaceKHR>>() const;
    template <> const Managed<VkSwapchainCreateInfoKHR>& get<Managed<VkSwapchainCreateInfoKHR>>() const;

protected:
    class ControlBlock;
    std::shared_ptr<ControlBlock> mspControlBlock;
};

template <>
class BasicManagedVkValidationCacheEXT
    : public detail::BasicManaged<VkValidationCacheEXT>
{
public:
    BasicManagedVkValidationCacheEXT() = default;
    static VkResult create(const Managed<VkDevice>& device, const VkValidationCacheCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, Managed<VkValidationCacheEXT>* pValidationCache);
    virtual ~BasicManaged() override;
    template <typename T> inline const T& get() const { static_assert(false && "The requested object type cannot be accessed from a Managed<VkValidationCacheEXT>"); };
    template <> const VkValidationCacheEXT& get<VkValidationCacheEXT>() const;
    template <> const VkObjectType& get<VkObjectType>() const;
    template <> const Managed<VkDevice>& get<Managed<VkDevice>>() const;
    template <> const Managed<VkValidationCacheCreateInfoEXT>& get<Managed<VkValidationCacheCreateInfoEXT>>() const;

protected:
    class ControlBlock;
    std::shared_ptr<ControlBlock> mspControlBlock;
};

} // namespace vk
} // namespace dst
