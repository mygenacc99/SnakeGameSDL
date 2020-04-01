//
// Created by colab on 30/03/2020.
//

#include <Snake.h>

#include "Snake.h"

Snake::Snake(SDL_Renderer* renderer, std::string path)
{
    snakeSpriteTexture = new Texture(renderer);
    snakeSpriteTexture->loadFromFileWithColorKey(path, 255, 255, 255);

    snakeSpriteClips[0].x = 0;
    snakeSpriteClips[0].y = 0;
    snakeSpriteClips[0].w = SPLEN;
    snakeSpriteClips[0].h = SPLEN;

    for (int i = 1; i < 4; i++) {
        snakeSpriteClips[i].x = snakeSpriteClips[i - 1].x + SPLEN;
        snakeSpriteClips[i].y = 0;
        snakeSpriteClips[i].w = SPLEN;
        snakeSpriteClips[i].h = SPLEN;
    }

    SnakeCell tail = SnakeCell(-velocity, 0, STAIL, RIGHT);
    cells.push_back(tail);
    SnakeCell body = SnakeCell(0, 0, SBODY, RIGHT);
    cells.push_back(body);
    SnakeCell body1 = SnakeCell(velocity, 0, SBODY, RIGHT);
    cells.push_back(body1);
    SnakeCell head = SnakeCell(2*velocity, 0, SHEAD, RIGHT);
    cells.push_back(head);
}

void Snake::render()
{
    for (int i = 0; i < cells.size() ; i++) {
        if (cells[i].state == SROUND){
            snakeSpriteTexture->render(cells[i].posX, cells[i].posY, &snakeSpriteClips[cells[i].state],
                                       cells[i].roundAngle);
        }
        else{
            snakeSpriteTexture->render(cells[i].posX, cells[i].posY, &snakeSpriteClips[cells[i].state],
                                       -cells[i].angle);
        }

    }
}

void Snake::move()
{
    // Move body
    for (int i = 0; i < cells.size() - 1; i++) {
        cells[i] = cells[i + 1];
    }

    // If turn around. We set SHEAD to SROUND at handle(). Now we set it back.
    if (cells.back().state == SHEAD) {
        (cells.end() - 2)->state = SBODY;
    }
    else {
        cells.back().state = SHEAD;
    }

    // Move head
    switch (cells.back().angle) {
    case RIGHT:
        cells.back().posX += velocity;
        break;
    case LEFT:
        cells.back().posX -= velocity;
        break;
    case UP:
        cells.back().posY -= velocity;
        break;
    case DOWN:
        cells.back().posY += velocity;
        break;
    }

    // Set tail
    cells[0].state = STAIL;
}

void Snake::handle(SDL_Event event)
{
    switch (event.key.keysym.sym) {
    case SDLK_h:
    case SDLK_LEFT:
        if (cells.back().angle == UP) {
            cells.back().state = SROUND;
            cells.back().roundAngle = 0;
        }
        else if (cells.back().angle == DOWN) {
            cells.back().state = SROUND;
            cells.back().roundAngle = 90;
        }

        if (cells.back().angle != RIGHT){
            cells.back().angle = LEFT;
        }
        break;

    case SDLK_j:
    case SDLK_DOWN:
        if (cells.back().angle == LEFT) {
            cells.back().state = SROUND;
            cells.back().roundAngle = 270;
        }
        else if (cells.back().angle == RIGHT) {
            cells.back().state = SROUND;
            cells.back().roundAngle = 0;
        }
        if (cells.back().angle != UP){
            cells.back().angle = DOWN;
        }
        break;

    case SDLK_k:
    case SDLK_UP:
        if (cells.back().angle == LEFT) {
            cells.back().state = SROUND;
            cells.back().roundAngle = 180;
        }
        else if (cells.back().angle == RIGHT) {
            cells.back().state = SROUND;
            cells.back().roundAngle = 90;
        }
        if (cells.back().angle != DOWN){
            cells.back().angle = UP;
        }
        break;

    case SDLK_l:
    case SDLK_RIGHT:
        if (cells.back().angle == UP) {
            cells.back().state = SROUND;
            cells.back().roundAngle = 270;
        }
        else if (cells.back().angle == DOWN) {
            cells.back().state = SROUND;
            cells.back().roundAngle = 180;
        }
        if (cells.back().angle != LEFT){
            cells.back().angle = RIGHT;
        }
        break;
    }
}
bool Snake::checkApple(Apple* apple) {
    if(cells.back().posX == apple->posX && cells.back().posY == apple->posY){
        apple->randomPos();

        SnakeCell sc;
        sc = cells[0];
        this->move();
        cells[0].state = SBODY;
        cells.insert(cells.begin(), sc);

        return true;
    }
    return false;
}
