struct tetromino_shape {
    int type;
    int cells[16][4];
};

const struct tetromino_shape TETROMINO_I_SHAPE = {
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

const struct tetromino_shape TETROMINO_J_SHAPE = {
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

const struct tetromino_shape TETROMINO_L_SHAPE = {
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

const struct tetromino_shape TETROMINO_O_SHAPE = {
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

const struct tetromino_shape TETROMINO_S_SHAPE = {
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

// written by my girlfriend <3
const struct tetromino_shape TETROMINO_T_SHAPE = {
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

const struct tetromino_shape TETROMINO_Z_SHAPE = {
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
