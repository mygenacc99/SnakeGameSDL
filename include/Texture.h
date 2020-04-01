//
// Created by colab on 29/03/2020.
//

#ifndef SNAKEGAMESDL_TEXTURE_H
#define SNAKEGAMESDL_TEXTURE_H

#include "Header.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <bits/stdc++.h>

class Texture {
private:
    SDL_Texture *texture;
    int          width, height;

public:
    // Initializes variables
    Texture();

    // Deallocates memory
    ~Texture();

    // Loads image at specified path
    bool loadFromFile(std::string path);

#if defined(_SDL_TTF_H) || defined(SDL_TTF_H_)
    // Created image from font string
    bool loadFromRenderedText(std::string textureText, SDL_Color textColor);
#endif

    // Set color modulation
    void setColor(Uint8 red, Uint8 green, Uint8 blue);

    // Set blending
    void setBlendMode(SDL_BlendMode blending);

    // Renders texture at given point
    void render(int x, int y, SDL_Rect *clip = NULL, double angle = 0.0, SDL_Point *center = NULL,
                SDL_RendererFlip flip = SDL_FLIP_NONE);

    // Gets image dimensions
    int getWidth();
    int getHeight();
};

#endif // SNAKEGAMESDL_TEXTURE_H
