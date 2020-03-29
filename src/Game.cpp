//
// Created by colab on 29/03/2020.
//

#include "../header/Game.h"

Game::Game() {
    // Initialize SDL
    if ( SDL_Init(SDL_INIT_VIDEO) < 0 ) {
        std::cout << "Unable to initialze SDL! SDL_Error: " << SDL_GetError() << std::endl;
        quit = true;
    } else {
        // Set texture filtering to linear
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        {
            printf("Warning: Linear texture filtering not enabled!\n");
        }

        // Create window
        this->window = SDL_CreateWindow("SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                        SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if ( window == nullptr ) {
            std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
            quit = true;
        }
        else {
            // Create render for window
            render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (render == nullptr){
                std::cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
            }
            else{
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags)){
                    std::cout << "SDL_image could not initialized! SDL_image error: " << IMG_GetError() << std::endl;
                }
            }
        }
    }

}

void Game::Run() {
    SDL_Event e;
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_q){
                quit = true;
            }
        }
    }
}
