#include <stdio.h>
#include "cube.h"

int main()
{
    char option;
    Cube my_cube;
    init_cube(&my_cube);
    while (1)
    {
        printf("Rubik's Cube\n");

        printf("Select an option\n");
        printf("\n - 'i' to check the cube; \n - 'u' to turn U face clockwise, \n - 'z' to turn U face counter clockwise, \n - 'q' to exit\n");
        scanf(" %c", &option);

        printf("\n-- Option: %c --\n", option);

        if (option == 'i' || option == 'I')
        {
            print_facelet(&my_cube);
        }
        else if (option == 'u' || option == 'U')
        {
            turn_face_clockwise('U', &my_cube);
        }
        else if (option == 'z' || option == 'Z')
        {
            turn_face_counter_clockwise('U', &my_cube);
        }
        else if (option == 'q' || option == 'Q')
        {
            break;
        }
        else
        {
            printf("Use valid command\n");
            continue;
        }
    }

    return 0;
}