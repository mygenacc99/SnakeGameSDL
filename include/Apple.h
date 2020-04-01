//
// Created by colab on 01/04/2020.
//

#ifndef SNAKEGAMESDL_APPLE_H
#define SNAKEGAMESDL_APPLE_H
#include "Header.h"
#include "Texture.h"
#include <time.h>

class Apple{
public:
    int posX, posY;
    Texture* appleTexture = nullptr;
    Apple(SDL_Renderer* renderer);
    void randomPos();

    void render();
};
#endif // SNAKEGAMESDL_APPLE_H
