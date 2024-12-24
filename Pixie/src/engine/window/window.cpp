#include "window.h"
#include <SDL2/SDL_image.h>
#include <iostream>

Window::Window(const std::string& title, int width, int height)
    : title(title)
    , width(width)
    , height(height)
    , running(true)
    , window(nullptr)
    , renderer(nullptr)
{
}

Window::~Window() {
    // Destroy renderer and window
    if (renderer) {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }
    if (window) {
        SDL_DestroyWindow(window);
        window = nullptr;
    }

    // Shut down SDL_image
    IMG_Quit();

    // Shut down SDL
    SDL_Quit();
}

bool Window::init() {
    // Initialize SDL core
    if (!initSDL()) {
        return false;
    }

    // Initialize SDL_image
    if (!initSDLImage()) {
        return false;
    }

    return true;
}

bool Window::initSDL() {
    // Initialize core SDL (video, etc.)
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL failed to initialize: " << SDL_GetError() << std::endl;
        return false;
    }

    // Create the SDL window
    window = SDL_CreateWindow(
        title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_SHOWN
    );
    if (!window) {
        std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
        return false;
    }

    // Create the SDL renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Failed to create renderer: " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}

bool Window::initSDLImage() {
    // We’ll initialize PNG support (you can add JPG, TIF, WEBP flags if needed)
    int imgFlags = IMG_INIT_PNG;
    if ((IMG_Init(imgFlags) & imgFlags) != imgFlags) {
        std::cerr << "SDL_image failed to initialize PNG support: "
                  << IMG_GetError() << std::endl;
        return false;
    }
    return true;
}

void Window::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running = false;
        }
        // Add additional event handling here as needed
    }
}

bool Window::isRunning() const {
    return running;
}

void Window::clear() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void Window::present() {
    SDL_RenderPresent(renderer);
}

SDL_Renderer* Window::getRenderer() const {
    return renderer;
}