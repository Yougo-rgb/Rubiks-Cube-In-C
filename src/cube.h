/*
All 12 stickers around a specific face
Edge permutation, index: 1, 4, 7, 10
Corner A permutation index: 0, 3, 6, 9
Corner B permutation index: 2, 5, 8, 11
*/
#define F_FACE_LAYER_STICKER {U6, U7, U8, R0, R3, R6, D2, D1, D0, L8, L5, L2}
#define R_FACE_LAYER_STICKER {U8, U5, U2, B0, B3, B6, D8, D5, D2, F8, F5, F2}
#define U_FACE_LAYER_STICKER {B2, B1, B0, R2, R1, R0, F2, F1, F0, L2, L1, L0}
#define D_FACE_LAYER_STICKER {F6, F7, F8, R6, R7, R8, B6, B7, B8, L6, L7, L8}
#define L_FACE_LAYER_STICKER {U0, U3, U6, F0, F3, F6, D0, D3, D6, B8, B5, B2}
#define B_FACE_LAYER_STICKER {U2, U1, U0, L0, L3, L6, D6, D7, D8, R8, R5, R2}

#define FACE_STICKER_NUMBER 9

extern const int layer_stickers[6][12];

typedef struct
{
    char stickers[54];
} Cube;

enum kociemba
{
    // U Face, 0 to 9
    U0 = 0,
    U1 = 1,
    U2 = 2,
    U3 = 3,
    U4 = 4,
    U5 = 5,
    U6 = 6,
    U7 = 7,
    U8 = 8,

    // R face, 10 to 17
    R0 = 9,
    R1 = 10,
    R2 = 11,
    R3 = 12,
    R4 = 13,
    R5 = 14,
    R6 = 15,
    R7 = 16,
    R8 = 17,

    // F face, 18 to 26
    F0 = 18,
    F1 = 19,
    F2 = 20,
    F3 = 21,
    F4 = 22,
    F5 = 23,
    F6 = 24,
    F7 = 25,
    F8 = 26,

    // D face, 27 to 35
    D0 = 27,
    D1 = 28,
    D2 = 29,
    D3 = 30,
    D4 = 31,
    D5 = 32,
    D6 = 33,
    D7 = 34,
    D8 = 35,

    // L face, 36 to 44
    L0 = 36,
    L1 = 37,
    L2 = 38,
    L3 = 39,
    L4 = 40,
    L5 = 41,
    L6 = 42,
    L7 = 43,
    L8 = 44,

    // FB face, 45 to 53
    B0 = 45,
    B1 = 46,
    B2 = 47,
    B3 = 48,
    B4 = 49,
    B5 = 50,
    B6 = 51,
    B7 = 52,
    B8 = 53
};

void turn_face_counter_clockwise(char face, Cube *cube);
void turn_face_clockwise(char face, Cube *cube);
void init_cube(Cube *cube);
void print_facelet(Cube *cube);