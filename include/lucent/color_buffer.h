#pragma once

#include <cstddef>
#include <cstdint>
#include <memory>

namespace lucent {

/// Represents pixel color format.
enum class PixelFormat : std::uint8_t { RGBA32 };

/// Owns memory holding pixel color data for the final rendered frame.
class ColorBuffer {
public:
    ColorBuffer(std::size_t width, std::size_t height, PixelFormat pixel_format);

    ColorBuffer(const ColorBuffer&) = delete;
    ColorBuffer& operator=(const ColorBuffer&) = delete;

    ColorBuffer(ColorBuffer&&) noexcept;
    ColorBuffer& operator=(ColorBuffer&&) noexcept;

    /// Returns pointer to memory holding pixel color data.
    ///
    /// @return Pointer to color buffer data.
    [[nodiscard]] std::uint8_t* data() const noexcept { return data_.get(); }

    /// Returns width of the color buffer.
    ///
    /// @return Width of the color buffer.
    [[nodiscard]] std::size_t width() const noexcept { return width_; }

    /// Returns height of the color buffer.
    ///
    /// @return Height of the color buffer.
    [[nodiscard]] std::size_t height() const noexcept { return height_; }

    /// Returns format of pixel color data.
    ///
    /// @return Pixel color data format.
    [[nodiscard]] PixelFormat pixelFormat() const noexcept { return pixel_format_; }

    /// Returns size of memory holding pixel color data.
    ///
    /// @return Size of the memory in bytes.
    [[nodiscard]] std::size_t size() const noexcept;

private:
    std::unique_ptr<uint8_t[]> data_;
    std::size_t width_;
    std::size_t height_;
    PixelFormat pixel_format_;
};

}  // namespace lucent
