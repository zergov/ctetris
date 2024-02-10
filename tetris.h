#ifndef TETRIS_H
#define TETRIS_H

struct tetromino_shape {
    int type;
    int cells[16][4];
};

struct tetromino_shape create_I_tetromino();
struct tetromino_shape create_J_tetromino();
struct tetromino_shape create_L_tetromino();
struct tetromino_shape create_O_tetromino();
struct tetromino_shape create_S_tetromino();
struct tetromino_shape create_T_tetromino();
struct tetromino_shape create_Z_tetromino();

struct tetromino_shape create_random_tetromino_shape();

#endif
