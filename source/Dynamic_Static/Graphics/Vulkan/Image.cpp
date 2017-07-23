
/*
================================================================================

  MIT License

  Copyright (c) 2016 Dynamic_Static

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.

================================================================================
*/

#include "Dynamic_Static/Graphics/Vulkan/Image.hpp"
#include "Dynamic_Static/Graphics/Vulkan/Device.hpp"
#include "Dynamic_Static/Graphics/Vulkan/SwapchainKHR.hpp"

namespace Dynamic_Static {
namespace Graphics {
namespace Vulkan {

    Image::Image(SwapchainKHR& swapchain, VkImage handle)
        : mSwapchain { &swapchain }
        , mDevice { swapchain.device().shared() }
        , mFormat { swapchain.format() }
    {
        assert(handle);
        mHandle = handle;
    }

    Image::~Image()
    {
        // NOTE : If this Image belongs to a SwapchainKHR, the Vulkan resource
        //        will be destroyed along with the SwapchainKHR that owns it.
        if (mHandle && !mSwapchain) {
        }
    }

    Device& Image::device()
    {
        assert(mDevice);
        return *mDevice;
    }

    const Device& Image::device() const
    {
        assert(mDevice);
        return *mDevice;
    }

    VkFormat Image::format() const
    {
        return mFormat;
    }

    const std::vector<std::unique_ptr<Image::View>>& Image::views() const
    {
        return mViews;
    }

} // namespace Vulkan
} // namespace Graphics
} // namespace Dynamic_Static