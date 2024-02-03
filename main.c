#include <stdio.h>

#include <SDL2/SDL.h>

#define WINDOW_W 1024
#define WINDOW_H 768
#define BOARD_W 12
#define BOARD_H 22
#define CELL_SIZE 30

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

    // From the tetris wikipedia (https://en.wikipedia.org/wiki/Tetris)
    // The board is 12 x 22. The edge is grayed out, and act as a wall.
    //
    // 0: empty space
    // 1: wall
    int board[BOARD_H][BOARD_W] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    };

    int colors[2][3] = {
        {0, 0, 0},          // empty spaces are black
        {128, 128, 128},    // walls are gray
    };

    struct SDL_Rect cell;
    cell.w = CELL_SIZE;
    cell.h = CELL_SIZE;

    while (1) {
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    exit(0);
                    break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);

        int x_padding = (WINDOW_W / 2) - ((BOARD_W / 2) * CELL_SIZE);
        int y_padding = (WINDOW_H / 2) - ((BOARD_H / 2) * CELL_SIZE);

        for (int i = 0; i < BOARD_H; i++) {
            for (int j = 0; j < BOARD_W; j++) {
                int cell_type = board[i][j];

                cell.x = x_padding + j * cell.w;
                cell.y = y_padding + i * cell.h;

                int r = colors[cell_type][0];
                int g = colors[cell_type][1];
                int b = colors[cell_type][2];

                SDL_SetRenderDrawColor(renderer, r, g, b, 0);
                SDL_RenderFillRect(renderer, &cell);
            }
        }

        SDL_RenderPresent(renderer);
    }
}
