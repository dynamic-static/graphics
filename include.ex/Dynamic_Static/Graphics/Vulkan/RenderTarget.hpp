
/*
==========================================
  Copyright (c) 2016-2018 Dynamic_Static
    Patrick Purcell
      Licensed under the MIT license
    http://opensource.org/licenses/MIT
==========================================
*/

#pragma once

#include "Dynamic_Static/Graphics/Vulkan/Defines.hpp"

#include <memory>
#include <vector>

namespace dst {
namespace gfx {
namespace vk {

    /*!
    Provides high level control over a Vulkan render target.
    */
    class RenderTarget final
        : NonCopyable
    {
    private:
        std::shared_ptr<RenderPass> mRenderPass;
        std::vector<std::shared_ptr<Image>> mAttachments;
        std::shared_ptr<Framebuffer> mFramebuffer;
        std::vector<VkClearValue> mClearValues;

    public:
        /*!
        Constructs an instance of RenderTarget.
        @param [in] renderPass This RenderTarget's RenderPass
        @param [in] createInfo This RenderTarget's VkExtent2D
        */
        RenderTarget(
            const std::shared_ptr<RenderPass>& renderPass,
            const VkExtent2D& extent
        );

    public:
        /*!
        Gets this RenderTarget's RenderPass.
        @return This RenderTarget's RenderPass
        */
        RenderPass& get_render_pass();

        /*!
        Gets this RenderTarget's RenderPass.
        @return This RenderTarget's RenderPass
        */
        const RenderPass& get_render_pass() const;

        /*!
        Gets this RenderTarget's attachment Images.
        @return This RenderTarget's attachment Images
        */
        dst::Span<const std::shared_ptr<Image>> get_attachments() const;

        /*!
        Gets this RenderTarget's Framebuffer.
        @return This RenderTarget's Framebuffer
        */
        Framebuffer& get_framebuffer();

        /*!
        Gets this RenderTarget's Framebuffer.
        @return This RenderTarget's Framebuffer
        */
        const Framebuffer& get_framebuffer() const;

        /*!
        Gets this RenderTarget's extent.
        @return This RenderTarget's extent
        */
        VkExtent2D get_extent() const;

        /*!
        Gets a VkViewport that covers this entire RenderTarget.
        @return A VkViewport that covers this entire RenderTarget
        */
        VkViewport get_viewport() const;

        /*!
        Gets a scissor VkRect2D that covers this entire RenderTarget.
        @return A scissor VkRect2D that covers this entire RenderTarget
        */
        VkRect2D get_scissor() const;

        /*!
        Gets this RenderTarget's VkClearValues.
        @return This RenderTarget's VkClearValues
        */
        dst::Span<VkClearValue> get_clear_values();

        /*!
        Gets this RenderTarget's VkClearValues.
        @return This RenderTarget's VkClearValues
        */
        dst::Span<const VkClearValue> get_clear_values() const;

        /*!
        Gets this RenderTarget's VkRenderPassBeginInfo.
        @return This RenderTarget's VkRenderPassBeginInfo
        */
        VkRenderPassBeginInfo get_render_pass_begin_info() const;
    };

} // namespace vk
} // namespace gfx
} // namespace dst
