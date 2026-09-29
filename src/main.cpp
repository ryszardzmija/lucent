#include <SDL3/SDL.h>

#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <cstring>

#include <lucent/color_buffer.h>

namespace {

void fillColorBufferBrightPastelBlue(std::uint8_t* buf, std::size_t size) {
    constexpr std::uint8_t bright_pastel_blue_blue = 237;
    constexpr std::uint8_t bright_pastel_blue_red = 155;
    constexpr std::uint8_t bright_pastel_blue_green = 184;
    constexpr std::uint8_t bright_pastel_blue_alpha = 255;

    for (std::size_t i = 0; i < size; i += 4) {
        *(buf + i) = bright_pastel_blue_red;
        *(buf + i + 1) = bright_pastel_blue_green;
        *(buf + i + 2) = bright_pastel_blue_blue;
        *(buf + i + 3) = bright_pastel_blue_alpha;
    }
}

}  // namespace

int main() {
    constexpr int window_width = 640;
    constexpr int window_height = 480;

    lucent::ColorBuffer color_buffer(window_width, window_height, lucent::PixelFormat::RGBA32);

    fillColorBufferBrightPastelBlue(color_buffer.data(), color_buffer.size());

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("%s", "SDL initialization failed");
        return EXIT_FAILURE;
    }

    SDL_Window* window = nullptr;
    if (window =
            SDL_CreateWindow("Render Window", window_width, window_height, SDL_WINDOW_RESIZABLE);
        !window) {
        SDL_Log("%s: %s", "SDL window creation failed", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    SDL_Surface* draw_surface = nullptr;
    if (draw_surface = SDL_CreateSurface(window_width, window_height, SDL_PIXELFORMAT_RGBA32);
        !draw_surface) {
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

    std::memcpy(draw_surface->pixels, color_buffer.data(), color_buffer.size());

    SDL_BlitSurface(draw_surface, nullptr, window_surface, nullptr);

    if (!SDL_UpdateWindowSurface(window)) {
        SDL_Log("%s", "SDL failed to update window surface");
    }

    SDL_Delay(5000);

    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}
