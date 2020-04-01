//
// Created by colab on 29/03/2020.
//

#ifndef SNAKEGAMESDL_GAME_H
#define SNAKEGAMESDL_GAME_H

#include "Header.h"
#include "Snake.h"
#include "Texture.h"

class Game {
public:
    Game();
    ~Game();
    void Run();
    void handleEvents();

private:
    SDL_Window*   window   = nullptr;
    SDL_Renderer* renderer = nullptr;

    Texture* bkgTexture = nullptr;
    Snake*   snake      = nullptr;

    int FPS = 3;
    int frameDelay = 1000/FPS;
    bool quit = false;
};

#endif // SNAKEGAMESDL_GAME_H
