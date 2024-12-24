#ifndef RENDER_H
#define RENDER_H

#include <SDL2/SDL.h>

class Render {
public:
    // Pass in the SDL_Renderer from Window
    Render(SDL_Renderer* renderer);
    ~Render() = default;

    void setDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    void clear();
    void present();

private:
    SDL_Renderer* mRenderer;
};

#endif // RENDER_H