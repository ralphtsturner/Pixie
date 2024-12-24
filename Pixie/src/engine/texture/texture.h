#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL2/SDL.h>
#include <string>

class Texture {
public:
    // Construct with the SDL_Renderer pointer
    explicit Texture(SDL_Renderer* renderer);
    ~Texture();

    // Loads an image file (PNG, JPG, etc.) from disk
    bool loadFromFile(const std::string& path);

    // Renders at (x, y) with width = w and height = h
    void render(int x, int y, int w, int h);

    // Optional: unload the current texture if you need to reload or switch
    void free();

private:
    SDL_Renderer* mRenderer;
    SDL_Texture* mTexture;
};

#endif // TEXTURE_H