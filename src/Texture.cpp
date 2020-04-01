//
// Created by colab on 29/03/2020.
//

#include <Texture.h>

Texture::Texture() {
  texture = nullptr;
  width   = 0;
  height  = 0;
}

Texture::~Texture() {}

bool Texture::loadFromFile(std::string path) { return false; }

#if defined(_SDL_TTF_H) || defined(SDL_TTF_H_)
// Created image from font string
bool Texture::loadFromRenderedText(std::string textureText, SDL_Color textColor) {}
#endif

void Texture::setColor(Uint8 red, Uint8 green, Uint8 blue) {}

void Texture::setBlendMode(SDL_BlendMode blending) {}

void Texture::render(int x, int y, SDL_Rect *clip, double angle, SDL_Point *center, SDL_RendererFlip flip) {}

int Texture::getWidth() { return this->width; }

int Texture::getHeight() { return this->height; }
