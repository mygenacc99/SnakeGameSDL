//
// Created by colab on 01/04/2020.
//

#include "Apple.h"
Apple::Apple(SDL_Renderer* renderer) {
    appleTexture = new Texture(renderer);
    appleTexture->loadFromFileWithColorKey("../media/apple.png", 255, 255, 255);
    srand (time(nullptr));
    randomPos();
}
void Apple::randomPos() {
    posX = (rand()%((SCREEN_WIDTH-SPLEN)/SPLEN) + 1) * SPLEN;
    posY = (rand()%((SCREEN_HEIGHT-SPLEN)/SPLEN) + 1) * SPLEN;
}
void Apple::render() {
    appleTexture->render(posX, posY);
}
