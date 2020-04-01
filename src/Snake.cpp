//
// Created by colab on 30/03/2020.
//

#include <Snake.h>

#include "Snake.h"

Snake::Snake(SDL_Renderer* renderer, std::string path) {
    snakeSpriteTexture = new Texture(renderer);
    snakeSpriteTexture->loadFromFileWithColorKey(path , 255, 255, 255);

    snakeSpriteClips[0].x = 0;
    snakeSpriteClips[0].y = 0;
    snakeSpriteClips[0].w = SPLENX;
    snakeSpriteClips[0].h = SPLENY;

    for (int i = 1; i < 4; i++){
        snakeSpriteClips[i].x = snakeSpriteClips[i-1].x + SPLENX;
        snakeSpriteClips[i].y = 0;
        snakeSpriteClips[i].w = SPLENX;
        snakeSpriteClips[i].h = SPLENY;
    }

    SnakeCell tail = SnakeCell(0, 0 , STAIL, 0);
    cells.push_back(tail);
    SnakeCell body = SnakeCell(60, 0 , SBODY, 0);
    cells.push_back(body);
    SnakeCell body1 = SnakeCell(120, 0 , SBODY, 0);
    cells.push_back(body1);
    SnakeCell head = SnakeCell(180, 0 , SHEAD, 0);
    cells.push_back(head);
}



void Snake::render() {
    for (int i = 0; i < cells.size(); i++){
        snakeSpriteTexture->render(cells[i].posX, cells[i].posY, &snakeSpriteClips[cells[i].state], cells[i].angle);
    }
}

void Snake::move() {
    // Move body
    for(int i = 0; i < cells.size() - 2; i++){
        cells[i] = cells[i+1];
    }

    // Move head
    if (cells.back().angle == RIGHT){
        int angle = cells.back().angle - 0;
        if (angle == 0){
            *(cells.end()-2) = cells.back();
            (cells.end()-2)->state = SBODY;
            (cells.end()-2)->angle = 0;
        }

        cells.back().posX += velocity;
    }

    // Set tail
    cells[0].state = STAIL;

}
