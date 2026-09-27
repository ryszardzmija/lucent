#include "framebuffer.h"

int main() {
    FrameBuffer frame_buffer;

    for (int i = 0; i < 100; i++) {
        frame_buffer.data.push_back(i % 10);
    }

    print_frame_buffer(frame_buffer);

    return 0;
}
