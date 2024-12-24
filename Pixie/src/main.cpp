#include "engine/window/window.h"
#include "engine/render/render.h"
#include "engine/texture/texture.h"

#include "engine/util/types.h"
#include <iostream>

int main(int argc, char* argv[]) {
    Window window("Pixel Engine", 800, 600);

    // Initialize SDL and SDL_image inside Window::init()
    if (!window.init()) {
        std::cerr << "Failed to initialize window!" << std::endl;
        return -1;
    }

    // Create the Render object using the Window's SDL_Renderer
    Render renderer(window.getRenderer());

    // Create a Texture object, passing it the same SDL_Renderer
    Texture myTexture(window.getRenderer());

    // Attempt to load an image file (e.g., PNG) from disk
    if (!myTexture.loadFromFile("assets/farmer1.png")) {
        std::cerr << "Failed to load texture from file!" << std::endl;
    }

    // Main game loop
    while (window.isRunning()) {
        // Handle events (close window, etc.)
        window.handleEvents();

        // Clear the screen with a chosen draw color (e.g., red)
        renderer.setDrawColor(RED);
        renderer.clear();

        // Render the loaded texture at (x, y) = (100, 100) with size 64x64
        myTexture.render(100, 100, 64, 64);

        // Present the rendered frame
        renderer.present();
    }

    return 0;
}