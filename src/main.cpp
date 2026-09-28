#include <cstdlib>
#include <cstdint>

#include <SDL3/SDL.h>

void fillSurfaceBrightPastelBlue(void* buf, int size) {
    constexpr uint8_t bright_pastel_blue_blue = 237;
    constexpr uint8_t bright_pastel_blue_red = 155;
    constexpr uint8_t bright_pastel_blue_green = 184;

    const auto byte_buf_ptr = static_cast<uint8_t*>(buf);

    for (int i = 0; i < size; i++) {
        uint8_t* red = byte_buf_ptr + i * 3;
        uint8_t* green = byte_buf_ptr + i * 3 + 1;
        uint8_t* blue = byte_buf_ptr + i * 3 + 2;

        *red = bright_pastel_blue_red;
        *green = bright_pastel_blue_green;
        *blue = bright_pastel_blue_blue;
    }
}

int main() {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("%s", "SDL initialization failed");
        return EXIT_FAILURE;
    }

    constexpr int window_width = 640;
    constexpr int window_height = 480;

    SDL_Window* window = nullptr;
    if (window = SDL_CreateWindow("Render Window", window_width, window_height, SDL_WINDOW_RESIZABLE); !window) {
        SDL_Log("%s: %s", "SDL window creation failed", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }


    SDL_Surface* draw_surface = nullptr;
    if (draw_surface = SDL_CreateSurface(window_width, window_height, SDL_PIXELFORMAT_RGB24); !draw_surface) {
        SDL_Log("%s: %s", "SDL draw surface creation failed", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return EXIT_FAILURE;
    }

    SDL_Surface* window_surface = nullptr;
    if (window_surface = SDL_GetWindowSurface(window); !window_surface) {
        SDL_Log("%s: %s", "SDL window surface retrieval failed", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return EXIT_FAILURE;
    }

    fillSurfaceBrightPastelBlue(draw_surface->pixels, draw_surface->w * draw_surface->h);

    SDL_BlitSurface(draw_surface, nullptr, window_surface, nullptr);

    if (!SDL_UpdateWindowSurface(window)) {
        SDL_Log("%s", "SDL failed to update window surface");
    }

    SDL_Delay(5000);

    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}
