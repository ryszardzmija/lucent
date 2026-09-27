#include "framebuffer.h"

#include <print>

void print_frame_buffer(const FrameBuffer& frame_buffer) {
    for (const auto elem : frame_buffer.data) {
        std::print("{} ", elem);
    }
}
