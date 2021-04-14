#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

struct termios orig_termios;

void disable_raw_mode()
{
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void enable_raw_mode()
{
    tcgetattr(STDIN_FILENO, &orig_termios);
    atexit(disable_raw_mode);

    struct termios raw = orig_termios;

    //ECHO is a bitflag, defined as 00000000000000000000000000001000 in binary
    //we use the bitwise-NOT operator (~) on this value to get 11111111111111111111111111110111
    //We then bitwise-AND this value with the flags field, 
    // which forces the fourth bit in the flags field to become 0
    // and causes every other bit to retain its current value
    raw.c_lflag &= ~(ECHO | ICANON);

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int main()
{
    enable_raw_mode();
    
    char c;

    // iscntrl() tests whether a character is a control character.
    // Control characters are nonprintable characters that we don’t want to print to the screen.
    while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q') {
        if (iscntrl(c))
            printf("%d\n", c);
        else
            printf("%d ('%c')\n", c, c);
    }
    return 0;
}