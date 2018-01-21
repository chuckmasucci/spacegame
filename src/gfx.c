#include <dbg.h>
#include "gfx.h"

int initializeGfx() {
    int init = SDL_Init(SDL_INIT_VIDEO);
    check(init >= 0, "Could not initialize SDL: %s", SDL_GetError());

    IMG_Init(IMG_INIT_PNG);

    window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
    check(window != NULL, "Could not create window: %s", SDL_GetError());

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    check(renderer != NULL, "Could not create renderer: %s", SDL_GetError());

    return 0;

error:
    SDL_Quit();
    log_err("SDL Error: Shutdown");

    return -1;
}

int clear() {
    int renderClear = SDL_RenderClear(renderer);
    check(renderClear == 0, "Could not set texture: %s", SDL_GetError());

    return 0;

error:
    SDL_Quit();
    log_err("SDL Error: Shutdown");

    return -1;
}

int setTexture(SDL_Renderer *renderer, SDL_Texture *texture, SDL_Rect *srcRect, SDL_Rect *destRect, int flip) {
    int renderCopy = (!flip) ? SDL_RenderCopy(renderer, texture, srcRect, destRect) : SDL_RenderCopyEx(renderer, texture, srcRect, destRect, 0, NULL, SDL_FLIP_VERTICAL);
    check(renderCopy == 0, "Could not set texture: %s", SDL_GetError());

    return 0;

error:
    SDL_Quit();
    log_err("SDL Error: Shutdown");

    return -1;
}

void present() {
    SDL_RenderPresent(renderer);
}

void destroyGfx()
{
    SDL_DestroyWindow(window);
}
