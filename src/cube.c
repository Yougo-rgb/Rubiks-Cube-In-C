#define FACE_STICKER_NUMBER 9

typedef struct
{
    char u_face[FACE_STICKER_NUMBER];
    char r_face[FACE_STICKER_NUMBER];
    char f_face[FACE_STICKER_NUMBER];
    char d_face[FACE_STICKER_NUMBER];
    char l_face[FACE_STICKER_NUMBER];
    char b_face[FACE_STICKER_NUMBER];
} Cube;

void turn_f_face(Cube *cube)
{
    char temp;

    // // Rotate F face
    // temp = cube->f_face[1];
    // cube->f_face[1] = cube->f_face[2];
    // // The other pieces

    // Rotate corners face only

    temp = cube->f_face[0];
    cube->f_face[0] = cube->f_face[2];

    temp = cube->f_face[2];
    cube->f_face[0] = cube->f_face[2];

    // Rotate edges face only

    // Rotate layer corners

    // Rotate layer edges
}
/*
Corner layer permutation for F move
u6 => -6 => r0; u8 => -2 => r6;
r0 => +2 => d2; r6 => -6 => d0;
d2 => +6 => l8; d0 => +2 => l2;
l8 => -2 => u6; l2 => +6 => u8;
F : u6 -> r0 -> d2 -> l8 -> u6;
F' : u8 -> r6 -> d0 -> l2 -> u8;
*/