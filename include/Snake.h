//
// Created by colab on 30/03/2020.
//

#ifndef SNAKEGAMESDL_SNAKE_H
#define SNAKEGAMESDL_SNAKE_H

#include "Header.h"
#include "SnakeCell.h"
#include "Texture.h"
#include "Apple.h"
// Sprite's length

enum SNAKESPRITE { STAIL = 0, SROUND = 1, SBODY = 2, SHEAD = 3 };

enum DIRECT { RIGHT = 0, UP = 90, LEFT = 180, DOWN = 270 };

class Snake {
public:
    // Snake's sheet texture
    Texture* snakeSpriteTexture = nullptr;
    // Clip of each part of snake
    SDL_Rect snakeSpriteClips[4];

    std::vector<SnakeCell> cells;

    int velocity  = 30;

    // Constructor
    Snake(SDL_Renderer* renderer, std::string path = "../media/snake.png");

    // Handle the event
    void handle(SDL_Event event);

    // Calculate position of snake after each frame
    void move();

    // Render snake to screen
    void render();

    bool checkApple(Apple* apple);

};

#endif // SNAKEGAMESDL_SNAKE_H
