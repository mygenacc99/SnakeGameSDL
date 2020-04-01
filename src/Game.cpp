//
// Created by colab on 29/03/2020.
//

#include "../include/Game.h"

Game::Game() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Unable to initialze SDL! SDL_Error: " << SDL_GetError() << std::endl;
        quit = true;
    } else {
        // Set texture filtering to linear
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
            printf("Warning: Linear texture filtering not enabled!\n");
        }

        // Create window
        window = SDL_CreateWindow("SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                        SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == nullptr) {
            std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
            quit = true;
        } else {
            // Create renderer for window
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if (renderer == nullptr) {
                std::cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
            } else {
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags)) {
                    std::cout << "SDL_image could not initialized! SDL_image error: " << IMG_GetError() << std::endl;
                }
            }
        }
    }

    // Create texture and load media
    bkgTexture = new Texture(renderer);
    bkgTexture->loadFromFile("../media/grass.jpg");
    snake = new Snake(renderer);
    apple = new Apple(renderer);

}

void Game::Run() {
    SDL_Event e;
    Uint32 frameStart;
    int frameTime;

    while (!quit) {
        frameStart = SDL_GetTicks();


        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_q) {
                quit = true;
            }
            snake->handle(e);
        }
        bkgTexture->render(0,0);

        if (snake->checkApple(apple)){
            score++;
        }
        else
        {
            snake->move();
        }
        if (snake->checkSelfEat()){
            quit = true;
        }
        apple->render();
        snake->render();



        SDL_RenderPresent( renderer);
        SDL_RenderClear( renderer );
        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }

    }
}

Game::~Game() {
    std::cout << "You got " << score << " apple" << (score > 1 ? "s" :"") << "!\n";
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    renderer = nullptr;
    window   = nullptr;

    IMG_Quit();
    SDL_Quit();

}
