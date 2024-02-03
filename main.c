#include <stdio.h>

#include <SDL2/SDL.h>

#define WINDOW_W 1024
#define WINDOW_H 768

int main(int argc, char *argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Couldn't initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

    struct SDL_Window *window = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_W, WINDOW_H, 0);
    if (window == NULL) {
        printf("Couldn't initialize SDL window: %s\n", SDL_GetError());
        exit(1);
    }

    struct SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Couldn't initialize SDL renderer: %s\n", SDL_GetError());
        exit(1);
    }
}
