#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <string>

class Window {
public:
    Window(const std::string& title, int width, int height);
    ~Window();

    bool init();                // Single function to initialize SDL, SDL_image, etc.
    void handleEvents();
    bool isRunning() const;

    void clear();
    void present();

    // Expose the SDL_Renderer for other engine modules
    SDL_Renderer* getRenderer() const;

private:
    // Private helper functions for specific subsystems
    bool initSDL();
    bool initSDLImage(); // If you want to load PNG, JPEG, etc.

private:
    std::string title;
    int width;
    int height;
    bool running;

    SDL_Window* window;
    SDL_Renderer* renderer;
};

#endif // WINDOW_H