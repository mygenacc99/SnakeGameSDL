//
// Created by colab on 29/03/2020.
//

#ifndef SNAKEGAMESDL_TEXTURE_H
#define SNAKEGAMESDL_TEXTURE_H

#include "Header.h"

class Texture {
private:
    SDL_Renderer* renderer;
    SDL_Texture*  texture;
    int           width, height;

public:
    // Initializes variables
    Texture(SDL_Renderer* renderer);

    // Deallocates memory
    ~Texture();

    // Free
    void free();

    // Loads image at specified path
    bool loadFromFile(std::string path);

    bool loadFromFileWithColorKey(std::string path, int red, int green, int blue);

#if defined(_SDL_TTF_H) || defined(SDL_TTF_H_)
    // Created image from font string
    bool loadFromRenderedText(std::string textureText, SDL_Color textColor);
#endif

    // Set color modulation
    void setColor(Uint8 red, Uint8 green, Uint8 blue);

    // Set blending
    void setBlendMode(SDL_BlendMode blending);

    // Renders texture at given point
    void render(int x, int y, SDL_Rect* clip = nullptr, double angle = 0.0, SDL_Point* center = nullptr,
                SDL_RendererFlip flip = SDL_FLIP_NONE);

    // Gets image dimensions
    int getWidth();
    int getHeight();
};

#endif // SNAKEGAMESDL_TEXTURE_H
