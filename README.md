# Rubik's cube in C in the terminal

Below is my analysis and approach to code this project.

## Cube structure

I chose to follow the Kociemba way to represent the cube.

It uses a char array of length 54 where each char represents a facelet, sometimes in the code I refer to them as sticker.

The order for the facelets is U R F D L B, so when the cube is solved the array looks like this:

```txt
UUUUUUUUURRRRRRRRRFFFFFFFFFDDDDDDDDDLLLLLLLLLBBBBBBBBB
```

To visualize those faclets, here is a the unfolded cube:

```txt
         [U][U][U]
         [U][U][U]
         [U][U][U]
[L][L][L][F][F][F][R][R][R][B][B][B]
[L][L][L][F][F][F][R][R][R][B][B][B]
[L][L][L][F][F][F][R][R][R][B][B][B]
         [D][D][D]
         [D][D][D]
         [D][D][D]
```

Same but with the index instead of the letter:

```txt
            [00][01][02]
            [03][04][05]
            [06][07][08]
[36][37][38][18][19][20][09][10][11][45][46][47]
[39][40][41][21][22][23][12][13][14][48][49][50]
[42][43][44][24][25][26][15][16][17][51][52][53]
            [27][28][29]
            [30][31][32]
            [33][34][35]

```

And finally, to help me understand the permutation while doing a move, I used this version because it was easier to visualize:

```txt
            [U0][U1][U2]
            [U3][U4][U5]
            [U6][U7][U8]
[L0][L1][L2][F0][F1][F2][R0][R1][R2][B0][B1][B2]
[L3][L4][L5][F3][F4][F5][R3][R4][R5][B3][B4][B5]
[L6][L7][L8][F6][F7][F8][R6][R7][R8][B6][B7][B8]
            [D0][D1][D2]
            [D3][D4][D5]
            [D6][D7][D8]

```

## Permutation logic

### The data used to perform a move on the 12 stickers around a given face

- Edge permutation index: 1, 4, 7, 10
- Corner A permutation index: 0, 3, 6, 9
- Corner B permutation index: 2, 5, 8, 11

```txt
F: [U6, U7, U8, R0, R3, R6, D2, D1, D0, L8, L5, L2]
R: [U8, U5, U2, B0, B3, B6, D8, D5, D2, F8, F5, F2]
U: [B2, B1, B0, R2, R1, R0, F2, F1, F0, L2, L1, L0]
D: [F6, F7, F8, R6, R7, R8, B6, B7, B8, L6, L7, L8]
L: [U0, U3, U6, F0, F3, F6, D0, D3, D6, B8, B5, B2]
B: [U2, U1, U0, L0, L3, L6, D6, D7, D8, R8, R5, R2]
```

### F Move Example:

#### Corner layer permutation

F : u8 -> r6 -> d0 -> l2 -> u8;

```txt
u8 => -2 => r6;
r6 => -6 => d0;
d0 => +2 => l2;
l2 => +6 => u8;
```

F' : u6 -> l8 -> d2 -> r0 -> u6;

```txt
u6 => +2 => l8;
l8 => -6 => d2;
d2 => -2 => r0;
r0 => +6 => u6;
```

#### Edge layer permutation

```txt
u7 => -4 => r3;
r3 => -2 => d1;
d1 => +4 => l5;
l5 => +2 => u7;
```

#### Corner F face

```txt
f0 => +2 => f2;
f2 => +6 => f8;
f8 => -2 => f6;
f6 => -6 => f0;
```

#### Edge F face

```txt
f1 => +4 => f5;
f5 => +2 => f7;
f7 => -4 => f3;
f3 => -2 => f1;
```

## Controls

These are based on the controls in [csTimer](https://cstimer.net):

```txt
- 'j' / 'f' : U / U' (Up)
- 'i' / 'k' : R / R' (Right)
- 'h' / 'g' : F / F' (Front)
- 's' / 'l' : D / D' (Down)
- 'd' / 'e' : L / L' (Left)
- 'w' / 'o' : B / B' (Back)
- 'q' : Exit
```

## Compiling

```bash
gcc .\src\main.c .\src\cube.c .\src\input.c -I.\include -o .\output\rubiks_cube.exe
```
