// SDL2 Library
#include <SDL2/SDL.h>

// C++ Libraries
#include <vector>
#include <iostream>

// SDL Classes
#include "SDL/Window.hpp"
#include "SDL/Render.hpp"

// Game Objects
#include "Game/Piece.hpp"
#include "Game/Board.hpp"

// Custom Components
#include "Components/Draw.hpp"
#include "Game/EventHandler.hpp"

int main (int argc, char **argv)
{
    // Initialize all SDL Video
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "Could not initialize SDL Video: " << SDL_GetError() << std::endl;
        return 1; 
    }

    // Initialize SDL window and renderer.
    const WindowObject win = WindowObject();
    const RendererObject ren = RendererObject(win.pSDL_Window);

    if (win.pSDL_Window == NULL || ren.pSDL_Renderer == NULL)
    {
        return 1;
    }

    bool gameIsRunning = true;
    SDL_Event event;

    // Game loop
    while (gameIsRunning && SDL_PollEvent(&event))
    {
        // Do game stuff!
    }
    
    SDL_Quit();

    return 0;
}
