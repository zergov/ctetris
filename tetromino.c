#include <stdlib.h>

#include "tetris.h"

struct tetromino_shape create_random_tetromino_shape() {
    int tetromino_type = rand() % 7;

    switch (tetromino_type) {
        case 0: return create_I_tetromino();
        case 1: return create_J_tetromino();
        case 2: return create_L_tetromino();
        case 3: return create_O_tetromino();
        case 4: return create_S_tetromino();
        case 5: return create_T_tetromino();
        case 6: return create_Z_tetromino();
        default: return create_I_tetromino();
    };
}

struct tetromino_shape create_I_tetromino() {
    struct tetromino_shape shape = {
        2,
        {
            {0, 2, 0, 0},
            {0, 2, 0, 0},
            {0, 2, 0, 0},
            {0, 2, 0, 0},

            {0, 0, 0, 0},
            {2, 2, 2, 2},
            {0, 0, 0, 0},
            {0, 0, 0, 0},

            {0, 0, 2, 0},
            {0, 0, 2, 0},
            {0, 0, 2, 0},
            {0, 0, 2, 0},

            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {2, 2, 2, 2},
            {0, 0, 0, 0},
        }
    };

    return shape;
}

struct tetromino_shape create_J_tetromino() {
    struct tetromino_shape shape = {
        3,
        {
            {0, 0, 0, 0},
            {0, 0, 3, 0},
            {0, 0, 3, 0},
            {0, 3, 3, 0},

            {0, 0, 0, 0},
            {3, 0, 0, 0},
            {3, 3, 3, 0},
            {0, 0, 0, 0},

            {0, 3, 3, 0},
            {0, 3, 0, 0},
            {0, 3, 0, 0},
            {0, 0, 0, 0},

            {0, 0, 0, 0},
            {0, 3, 3, 3},
            {0, 0, 0, 3},
            {0, 0, 0, 0},
        }
    };

    return shape;
}

struct tetromino_shape create_L_tetromino() {
    struct tetromino_shape shape = {
        4,
        {
            {0, 0, 0, 0},
            {0, 4, 0, 0},
            {0, 4, 0, 0},
            {0, 4, 4, 0},

            {0, 0, 0, 0},
            {4, 4, 4, 0},
            {4, 0, 0, 0},
            {0, 0, 0, 0},

            {0, 4, 4, 0},
            {0, 0, 4, 0},
            {0, 0, 4, 0},
            {0, 0, 0, 0},

            {0, 0, 0, 0},
            {0, 0, 0, 4},
            {0, 4, 4, 4},
            {0, 0, 0, 0},
        }
    };

    return shape;
}

struct tetromino_shape create_O_tetromino() {
    struct tetromino_shape shape = {
        5,
        {
            {0, 0, 0, 0},
            {0, 5, 5, 0},
            {0, 5, 5, 0},
            {0, 0, 0, 0},

            {0, 0, 0, 0},
            {0, 5, 5, 0},
            {0, 5, 5, 0},
            {0, 0, 0, 0},

            {0, 0, 0, 0},
            {0, 5, 5, 0},
            {0, 5, 5, 0},
            {0, 0, 0, 0},

            {0, 0, 0, 0},
            {0, 5, 5, 0},
            {0, 5, 5, 0},
            {0, 0, 0, 0},
        }
    };

    return shape;
}

struct tetromino_shape create_S_tetromino() {
    struct tetromino_shape shape = {
        6,
        {
            {0, 0, 0, 0},
            {0, 0, 6, 6},
            {0, 6, 6, 0},
            {0, 0, 0, 0},

            {0, 0, 0, 0},
            {0, 6, 0, 0},
            {0, 6, 6, 0},
            {0, 0, 6, 0},

            {0, 0, 0, 0},
            {0, 6, 6, 0},
            {6, 6, 0, 0},
            {0, 0, 0, 0},

            {0, 6, 0, 0},
            {0, 6, 6, 0},
            {0, 0, 6, 0},
            {0, 0, 0, 0},
        }
    };

    return shape;
}

// written by my girlfriend <3
struct tetromino_shape create_T_tetromino() {
    struct tetromino_shape shape = {
        7,
        {
            {0, 0, 0, 0},
            {0, 0, 7, 0},
            {0, 7, 7, 7},
            {0, 0, 0, 0},

            {0, 0, 0, 0},
            {0, 7, 0, 0},
            {0, 7, 7, 0},
            {0, 7, 0, 0},

            {0, 0, 0, 0},
            {7, 7, 7, 0},
            {0, 7, 0, 0},
            {0, 0, 0, 0},

            {0, 0, 7, 0},
            {0, 7, 7, 0},
            {0, 0, 7, 0},
            {0, 0, 0, 0},
        }
    };

    return shape;
}

struct tetromino_shape create_Z_tetromino() {
    struct tetromino_shape shape = {
        8,
        {
            {0, 0, 0, 0},
            {0, 8, 8, 0},
            {0, 0, 8, 8},
            {0, 0, 0, 0},

            {0, 0, 0, 0},
            {0, 0, 8, 0},
            {0, 8, 8, 0},
            {0, 8, 0, 0},

            {0, 0, 0, 0},
            {8, 8, 0, 0},
            {0, 8, 8, 0},
            {0, 0, 0, 0},

            {0, 0, 8, 0},
            {0, 8, 8, 0},
            {0, 8, 0, 0},
            {0, 0, 0, 0},
        }
    };

    return shape;
}
