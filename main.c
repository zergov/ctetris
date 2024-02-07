#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#include <SDL2/SDL.h>

#include "tetris.h"

#define WINDOW_W 1024
#define WINDOW_H 768
#define BOARD_W 12
#define BOARD_H 22
#define CELL_SIZE 30

struct tetromino {
    int x, y;
    int rotation;
    bool active;
    struct tetromino_shape shape;
};

bool is_board_valid(int board[BOARD_H][BOARD_W], struct tetromino tetromino) {
    int shape_cell;
    int board_i;
    int board_j;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            shape_cell = tetromino.shape.cells[i + 4*tetromino.rotation][j];
            if (shape_cell != 0) {
                board_i = i + tetromino.y;
                board_j = j + tetromino.x;

                if (board_j < 0 || board_j >= BOARD_W || board_i < 0 || board_i >= BOARD_H)
                    return false;

                if (board[board_i][board_j] != 0) {
                    return false;
                }
            }
        }
    }

    return true;
}

bool try_move_tetromino_down(int board[BOARD_H][BOARD_W], struct tetromino tetromino) {
    tetromino.y += 1;
    return is_board_valid(board, tetromino);
}

int main(int argc, char *argv[]) {
    srand(time(NULL));

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
        {1, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 1},
        {1, 0, 0, 6, 6, 0, 0, 4, 5, 5, 3, 1},
        {1, 0, 6, 6, 7, 7, 7, 4, 5, 5, 3, 1},
        {1, 2, 2, 2, 2, 7, 0, 4, 4, 3, 3, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    };

    int colors[9][3] = {
        {0, 0, 0},          // empty spaces are BLACK
        {128, 128, 128},    // walls are GRAY
        {64, 224, 208},     // I shapes are TURQUOISE
        {0, 0, 255},        // J shapes are BLUE
        {255, 165, 0},      // L shapes are ORANGE
        {255, 255, 0},      // O shapes are YELLOW
        {0, 255, 0},        // S shapes are GREEN
        {128, 0, 128},      // T shapes are PURPLE
        {255, 0, 0},        // Z shapes are RED
    };

    int x_padding = (WINDOW_W / 2) - ((BOARD_W / 2) * CELL_SIZE);
    int y_padding = (WINDOW_H / 2) - ((BOARD_H / 2) * CELL_SIZE);

    struct SDL_Rect cell;
    cell.w = CELL_SIZE;
    cell.h = CELL_SIZE;

    struct tetromino_shape tetrominos[7] = {
        TETROMINO_I_SHAPE,
        TETROMINO_J_SHAPE,
        TETROMINO_L_SHAPE,
        TETROMINO_O_SHAPE,
        TETROMINO_S_SHAPE,
        TETROMINO_T_SHAPE,
        TETROMINO_Z_SHAPE,
    };

    struct tetromino tetromino;
    tetromino.active = true;
    tetromino.rotation = 0;
    tetromino.x = 6;
    tetromino.y = 0;
    tetromino.shape = tetrominos[rand() % 7];

    uint64_t now = SDL_GetTicks64();
    uint64_t tick_time = 500; // milliseconds
    uint64_t tick_timeout = now + tick_time;

    bool user_pressed_rotation;
    bool user_pressed_left;
    bool user_pressed_right;

    while (1) {
        user_pressed_rotation = false;
        user_pressed_left = false;
        user_pressed_right = false;

        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    exit(0);
                    break;

                case SDL_KEYDOWN:
                    if (event.key.repeat != 0) break;

                    switch (event.key.keysym.scancode) {
                        case SDL_SCANCODE_SPACE:
                            user_pressed_rotation = true;
                            break;
                        case SDL_SCANCODE_LEFT:
                            user_pressed_left = true;
                            break;
                        case SDL_SCANCODE_RIGHT:
                            user_pressed_right = true;
                            break;
                        default:
                            break;
                    }
                    break;
            }
        }

        now = SDL_GetTicks64();

        // update game state
        if (now >= tick_timeout) {
            tick_timeout = now + tick_time;

            if (try_move_tetromino_down(board, tetromino)) {
                tetromino.y += 1;
            } else {
                tetromino.active = false;
            }
        }

        if (tetromino.active) {
            if (user_pressed_left)
                tetromino.x -= 1;

            if (user_pressed_right)
                tetromino.x += 1;

            if (user_pressed_rotation)
                tetromino.rotation = (tetromino.rotation + 1) % 4;
        }

        // render game state
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);

        for (int i = 0; i < BOARD_H; i++) {
            for (int j = 0; j < BOARD_W; j++) {
                cell.x = x_padding + j * cell.w;
                cell.y = y_padding + i * cell.h;

                int cell_type = board[i][j];
                int r = colors[cell_type][0];
                int g = colors[cell_type][1];
                int b = colors[cell_type][2];

                SDL_SetRenderDrawColor(renderer, r, g, b, 0);
                SDL_RenderFillRect(renderer, &cell);

                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
                SDL_RenderDrawRect(renderer, &cell);
            }
        }

        int r = colors[tetromino.shape.type][0];
        int g = colors[tetromino.shape.type][1];
        int b = colors[tetromino.shape.type][2];

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int shape_cell = tetromino.shape.cells[i + 4*tetromino.rotation][j];
                if (shape_cell != 0) {
                    cell.x = (tetromino.x * cell.w) + x_padding + j * cell.w;
                    cell.y = (tetromino.y * cell.h) + y_padding + i * cell.h;

                    SDL_SetRenderDrawColor(renderer, r, g, b, 0);
                    SDL_RenderFillRect(renderer, &cell);
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
                    SDL_RenderDrawRect(renderer, &cell);
                }
            }
        }

        SDL_RenderPresent(renderer);
    }
}
