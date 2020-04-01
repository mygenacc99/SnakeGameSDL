//
// Created by colab on 29/03/2020.
//

#include "Texture.h"

Texture::Texture(SDL_Renderer* renderer) {
    this->renderer = renderer;
    texture        = nullptr;
    width          = 0;
    height         = 0;
}

Texture::~Texture() { free(); }

void Texture::free() {
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
        width   = 0;
        height  = 0;
    }
}

bool Texture::loadFromFile(std::string path) {
    // Get rid of preexisting texture
    free();

    SDL_Texture* newTexture = nullptr;

    // Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr) {
        std::cout << "Unable to load image " << path << "! SDL_image Error: " << IMG_GetError() << std::endl;
    } else {
        // Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if (newTexture == nullptr) {
            std::cout << "Unable to create texture from " << path << "!SDL Error: " << SDL_GetError() << std::endl;
        } else {
            // Get image dimensions
            width  = loadedSurface->w;
            height = loadedSurface->h;
        }

        // Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    // Return success
    texture = newTexture;
    return texture != nullptr;
}

bool Texture::loadFromFileWithColorKey(std::string path, int red, int green, int blue) {
    // Get rid of preexisting texture
    free();

    SDL_Texture* newTexture = nullptr;

    // Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr) {
        std::cout << "Unable to load image " << path << "! SDL_image Error: " << IMG_GetError() << std::endl;
    } else {
        //Color key image
        SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, red, green, blue ) );


        // Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if (newTexture == nullptr) {
            std::cout << "Unable to create texture from " << path << "!SDL Error: " << SDL_GetError() << std::endl;
        } else {
            // Get image dimensions
            width  = loadedSurface->w;
            height = loadedSurface->h;
        }

        // Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    // Return success
    texture = newTexture;
    return texture != nullptr;
}


#if defined(_SDL_TTF_H) || defined(SDL_TTF_H_)
// Created image from font string
bool Texture::loadFromRenderedText(std::string textureText, SDL_Color textColor) {}
#endif

void Texture::setColor(Uint8 red, Uint8 green, Uint8 blue) {}

void Texture::setBlendMode(SDL_BlendMode blending) {}

void Texture::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip) {
    // Set rendering space and render to screen
    SDL_Rect renderQuad = {x, y, width, height};

    // Set clip rendering dimensions
    if (clip != nullptr){
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;

    }

    // Render to screen
    SDL_RenderCopyEx(renderer, texture, clip, &renderQuad, angle, center, flip);
}

int Texture::getWidth() { return this->width; }

int Texture::getHeight() { return this->height; }

