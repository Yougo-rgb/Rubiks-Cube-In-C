#include <ctype.h>
#include "cube.h"

void input_to_move(char c, Cube *cube)
{
    c = tolower((unsigned char)c);

    if (c == 'j')
    {
        turn_face_clockwise('U', cube);
    }
    else if (c == 'f')
    {
        turn_face_counter_clockwise('U', cube);
    }
    else if (c == 'i')
    {
        turn_face_clockwise('R', cube);
    }
    else if (c == 'k')
    {
        turn_face_counter_clockwise('R', cube);
    }
    else if (c == 'h')
    {
        turn_face_clockwise('F', cube);
    }
    else if (c == 'g')
    {
        turn_face_counter_clockwise('F', cube);
    }
    else if (c == 's')
    {
        turn_face_clockwise('D', cube);
    }
    else if (c == 'l')
    {
        turn_face_counter_clockwise('D', cube);
    }
    else if (c == 'd')
    {
        turn_face_clockwise('L', cube);
    }
    else if (c == 'e')
    {
        turn_face_counter_clockwise('L', cube);
    }
    else if (c == 'w')
    {
        turn_face_clockwise('B', cube);
    }
    else if (c == 'o')
    {
        turn_face_counter_clockwise('B', cube);
    }
    return;
}
