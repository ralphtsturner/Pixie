#include "render.h"

Render::Render(SDL_Renderer* renderer)
    : mRenderer(renderer)
{
}

void Render::setDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    SDL_SetRenderDrawColor(mRenderer, r, g, b, a);
}

void Render::clear() {
    SDL_RenderClear(mRenderer);
}

void Render::present() {
    SDL_RenderPresent(mRenderer);
}