#pragma once

#include <vector>
#include <cstdint>

struct FrameBuffer {
    std::vector<uint8_t> data;
};

void print_frame_buffer(const FrameBuffer& frame_buffer);
