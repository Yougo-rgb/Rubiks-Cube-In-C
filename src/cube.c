#include "cube.h"
#include <stdio.h>

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

void print_facelet(Cube *cube)
{
    const char *faces[] = {"U", "R", "F", "D", "L", "B"};
    printf("===CUBE STATE===\n");
    for (int f = 0; f < 6; f++)
    {
        printf("%s: %.9s\n", faces[f], &cube->stickers[f * 9]);
    }
    printf("================\n");
}
