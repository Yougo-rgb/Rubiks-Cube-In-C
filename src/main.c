#include <stdio.h>
#include "cube.h"
#include "input.h"

#include <stdio.h>

void clear_screen(void)
{
    printf("\x1b[2J\x1b[H");
    fflush(stdout);
}

void display_ui(Cube *cube)
{
    printf("Rubik's Cube\n");
    printf("\nControls:\n"
           " - 'j' / 'f' : U  / U' (Up)\n"
           " - 'i' / 'k' : R  / R' (Right)\n"
           " - 'h' / 'g' : F  / F' (Front)\n"
           " - 's' / 'l' : D  / D' (Down)\n"
           " - 'd' / 'e' : L  / L' (Left)\n"
           " - 'w' / 'o' : B  / B' (Back)\n"
           " - 'q'       : Exit\n\n");
    print_facelet(cube);
}

int main()
{
    char option;
    Cube my_cube;
    init_cube(&my_cube);

    display_ui(&my_cube);

    while (1)
    {
        scanf(" %c", &option);
        clear_screen();

        if (option == 'q' || option == 'Q')
        {
            break;
        }
        else
        {
            input_to_move(option, &my_cube);
        }

        display_ui(&my_cube);
    }

    return 0;
}