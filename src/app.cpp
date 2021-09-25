#include <taxi/app.h>
#include <taxi/config.h>
#include <stdio.h>
#include "SDL.h"

using namespace Taxi;

void App::init() {
    // Initialize SDL
    if (SDL_Init( SDL_INIT_VIDEO ) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }
}

bool App::run(Config config) {
    // Create Window
    SDL_Window* window = NULL;
    window = SDL_CreateWindow(config.name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, config.width, config.height, SDL_WINDOW_SHOWN);
    if(window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    // Poll for events and wait till user closes window
    bool quit = false;
    SDL_Event currentEvent;
    while(!quit) {
        while(SDL_PollEvent(&currentEvent) != 0) {
            if(currentEvent.type == SDL_QUIT) {
                quit = true;
            }
        }
        // TODO: Some on frame function
        SDL_Delay(1000/config.framerate);
    }

    // Free up window
    SDL_DestroyWindow(window);
    // Shutdown SDL
    SDL_Quit();

    return true;
}