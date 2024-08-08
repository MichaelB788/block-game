#include <SDL2/SDL.h>
#include <iostream>

SDL_Window sdl_window::window = NULL;

int sdl_window::init()
{
    // Initialize SDL video subsystem. If failed, print error message.
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    
    // Create the SDL Window object, and store it in pointer variable win. The variable MUST point to SDL_Window.
    window = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_RESIZABLE);
    
    // Checks to see if the window was not created successfully.
    if ( window == NULL ){ std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl; }

    //Hack to get window to stay up
    SDL_Event e; bool quit = false;
    while( quit == false ){ 
        while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; }
    }

    SDL_DestroyWindow(window);
    return 0;
}
