#include "cube.h"
#include <stdio.h>

#define COLOR_U "\x1b[1;37m"
#define COLOR_F "\x1b[0;32m"
#define COLOR_R "\x1b[0;31m"
#define COLOR_D "\x1b[1;33m"
#define COLOR_L "\x1b[38;5;208m"
#define COLOR_B "\x1b[0;34m"
#define COLOR_RES "\x1b[0m"

const int layer_stickers[6][12] = {
    U_FACE_LAYER_STICKER,
    R_FACE_LAYER_STICKER,
    F_FACE_LAYER_STICKER,
    D_FACE_LAYER_STICKER,
    L_FACE_LAYER_STICKER,
    B_FACE_LAYER_STICKER};

void init_cube(Cube *cube)
{
    const char colors[6] = {'U', 'R', 'F', 'D', 'L', 'B'};
    for (int f = 0; f < 6; f++)
    {
        for (int i = 0; i < 9; i++)
        {
            cube->stickers[f * 9 + i] = colors[f];
        }
    }
}

void turn_face_counter_clockwise(char face, Cube *cube)
{
    char temp;
    const int *layer;
    int face_start_sticker;

    switch (face)
    {
    case 'U':
        layer = layer_stickers[0];
        face_start_sticker = U0;
        break;
    case 'R':
        layer = layer_stickers[1];
        face_start_sticker = R0;
        break;
    case 'F':
        layer = layer_stickers[2];
        face_start_sticker = F0;
        break;
    case 'D':
        layer = layer_stickers[3];
        face_start_sticker = D0;
        break;
    case 'L':
        layer = layer_stickers[4];
        face_start_sticker = L0;
        break;
    case 'B':
        layer = layer_stickers[5];
        face_start_sticker = B0;
        break;
    default:
        return;
    }

    // Chosen face corner permutation
    temp = cube->stickers[face_start_sticker];
    cube->stickers[face_start_sticker] = cube->stickers[face_start_sticker + 2];
    cube->stickers[face_start_sticker + 2] = cube->stickers[face_start_sticker + 8];
    cube->stickers[face_start_sticker + 8] = cube->stickers[face_start_sticker + 6];
    cube->stickers[face_start_sticker + 6] = temp;

    // Chosen face edge permutation
    temp = cube->stickers[face_start_sticker + 1];
    cube->stickers[face_start_sticker + 1] = cube->stickers[face_start_sticker + 5];
    cube->stickers[face_start_sticker + 5] = cube->stickers[face_start_sticker + 7];
    cube->stickers[face_start_sticker + 7] = cube->stickers[face_start_sticker + 3];
    cube->stickers[face_start_sticker + 3] = temp;

    // Chosen face edge layer permutation
    temp = cube->stickers[layer[1]];
    cube->stickers[layer[1]] = cube->stickers[layer[4]];
    cube->stickers[layer[4]] = cube->stickers[layer[7]];
    cube->stickers[layer[7]] = cube->stickers[layer[10]];
    cube->stickers[layer[10]] = temp;

    // Chosen face corner layer permutation
    temp = cube->stickers[layer[0]];
    cube->stickers[layer[0]] = cube->stickers[layer[3]];
    cube->stickers[layer[3]] = cube->stickers[layer[6]];
    cube->stickers[layer[6]] = cube->stickers[layer[9]];
    cube->stickers[layer[9]] = temp;

    temp = cube->stickers[layer[2]];
    cube->stickers[layer[2]] = cube->stickers[layer[5]];
    cube->stickers[layer[5]] = cube->stickers[layer[8]];
    cube->stickers[layer[8]] = cube->stickers[layer[11]];
    cube->stickers[layer[11]] = temp;
}

void turn_face_clockwise(char face, Cube *cube)
{
    turn_face_counter_clockwise(face, cube);
    turn_face_counter_clockwise(face, cube);
    turn_face_counter_clockwise(face, cube);
}

const char *get_color(char sticker)
{
    switch (sticker)
    {
    case 'U':
        return COLOR_U;
    case 'F':
        return COLOR_F;
    case 'R':
        return COLOR_R;
    case 'D':
        return COLOR_D;
    case 'L':
        return COLOR_L;
    case 'B':
        return COLOR_B;
    default:
        return COLOR_RES;
    }
};

// TODO Use render.c to make a 3D cube instead
void print_facelet(Cube *cube)
{
    const char *s = cube->stickers;
    int l_offset = 27;
    int f_offset = 9;
    int b_offset = 36;

    printf("===CUBE STATE===\n");
    // U face
    for (int i = 0; i <= 6; i += 3)
    {
        printf("         [%s%c" COLOR_RES "][%s%c" COLOR_RES "][%s%c" COLOR_RES "]\n",
               get_color(s[i]), s[i],
               get_color(s[i + 1]), s[i + 1],
               get_color(s[i + 2]), s[i + 2]);
    }
    // L, F, R, B faces
    for (int i = 9; i <= 15; i += 3)
    {
        printf("[%s%c" COLOR_RES "][%s%c" COLOR_RES "][%s%c" COLOR_RES "]",
               get_color(s[i + l_offset]), s[i + l_offset],
               get_color(s[i + l_offset + 1]), s[i + l_offset + 1],
               get_color(s[i + l_offset + 2]), s[i + l_offset + 2]);

        printf("[%s%c" COLOR_RES "][%s%c" COLOR_RES "][%s%c" COLOR_RES "]",
               get_color(s[i + f_offset]), s[i + f_offset],
               get_color(s[i + f_offset + 1]), s[i + f_offset + 1],
               get_color(s[i + f_offset + 2]), s[i + f_offset + 2]);

        printf("[%s%c" COLOR_RES "][%s%c" COLOR_RES "][%s%c" COLOR_RES "]",
               get_color(s[i]), s[i],
               get_color(s[i + 1]), s[i + 1],
               get_color(s[i + 2]), s[i + 2]);

        printf("[%s%c" COLOR_RES "][%s%c" COLOR_RES "][%s%c" COLOR_RES "]\n",
               get_color(s[i + b_offset]), s[i + b_offset],
               get_color(s[i + b_offset + 1]), s[i + b_offset + 1],
               get_color(s[i + b_offset + 2]), s[i + b_offset + 2]);
    }
    // D face
    for (int i = 27; i <= 33; i += 3)
    {
        printf("         [%s%c" COLOR_RES "][%s%c" COLOR_RES "][%s%c" COLOR_RES "]\n",
               get_color(s[i]), s[i],
               get_color(s[i + 1]), s[i + 1],
               get_color(s[i + 2]), s[i + 2]);
    }
    printf("================\n");
}
