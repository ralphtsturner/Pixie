#include "texture.h"
#include <SDL2/SDL_image.h>
#include <iostream>

Texture::Texture(SDL_Renderer* renderer)
    : mRenderer(renderer), mTexture(nullptr)
{
}

Texture::~Texture() {
    free();  // Ensure we clean up the texture
}

bool Texture::loadFromFile(const std::string& path) {
    // Free any previously loaded texture
    free();

    // Load an image from the given path using SDL_image
    SDL_Surface* surface = IMG_Load(path.c_str());
    if (!surface) {
        std::cerr << "Failed to load image: " << path 
                  << ", IMG_Error: " << IMG_GetError() << std::endl;
        return false;
    }

    // Create a texture from the loaded surface
    mTexture = SDL_CreateTextureFromSurface(mRenderer, surface);
    SDL_FreeSurface(surface);  // We can free the surface after creating the texture

    if (!mTexture) {
        std::cerr << "Failed to create texture from " << path 
                  << ", SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}

void Texture::render(int x, int y, int w, int h) {
    if (!mTexture) {
        // No texture loaded; optionally log or early return
        return;
    }
    SDL_Rect dstRect = { x, y, w, h };
    SDL_RenderCopy(mRenderer, mTexture, nullptr, &dstRect);
}

void Texture::free() {
    if (mTexture) {
        SDL_DestroyTexture(mTexture);
        mTexture = nullptr;
    }
}