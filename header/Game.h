//
// Created by colab on 29/03/2020.
//

#ifndef SNAKEGAMESDL_GAME_H
#define SNAKEGAMESDL_GAME_H


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <bits/stdc++.h>
#include "Header.h"


class Game {
public:
    Game();
    void Run();
private:
    SDL_Window* window = NULL;
    SDL_Renderer* render = NULL;
    bool quit = false;
};


#endif //SNAKEGAMESDL_GAME_H
