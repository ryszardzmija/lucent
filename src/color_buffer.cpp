#include <lucent/color_buffer.h>

#include <cassert>
#include <utility>

namespace lucent {

namespace {

constexpr std::size_t getPixelSize(PixelFormat pixel_format) {
    switch (pixel_format) {
        case PixelFormat::RGBA32:
            return 4zu;
    }
    assert(false && "Unhandled PixelFormat enum value");
    std::unreachable();
}

}  // namespace

ColorBuffer::ColorBuffer(std::size_t width, std::size_t height, PixelFormat pixel_format)
    : data_(std::make_unique<uint8_t[]>(width * height * getPixelSize(pixel_format))),
      width_(width),
      height_(height),
      pixel_format_(pixel_format) {}

ColorBuffer::ColorBuffer(ColorBuffer&& other) noexcept
    : data_(std::move(other.data_)),
      width_(other.width_),
      height_(other.height_),
      pixel_format_(other.pixel_format_) {}

ColorBuffer& ColorBuffer::operator=(ColorBuffer&& other) noexcept {
    if (&other != this) {
        data_ = std::move(other.data_);
        width_ = other.width_;
        height_ = other.height_;
        pixel_format_ = other.pixel_format_;
    }

    return *this;
}

std::size_t ColorBuffer::size() const noexcept {
    return width_ * height_ * getPixelSize(pixel_format_);
}

}  // namespace lucent
