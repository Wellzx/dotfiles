#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "input.h"

#define HEIGHT 20
#define WIDTH 40

int main()
{
    char screen[HEIGHT][WIDTH];

    int personX = 2;
    int personY = HEIGHT - 2;

    configurarModoTerminal();
    atexit(resetarModoTerminal);

    while (1)
    {
        if (kbhit())
        {
            char tecla = getchar();
            if (tecla == 'a' && personX > 0) personX--;
            if (tecla == 'd' && personX < WIDTH - 1 ) personX++;
            if (tecla == 'q') break;
        }
        
        for (int y = 0; y < HEIGHT; y++)
        {
            for (int x = 0; x < WIDTH; x++)
            {
                screen[y][x] = ' ';
            }
        }

        for (int x = 0; x < WIDTH; x++)
        {
            screen[HEIGHT - 1][x] = '#';
        }
        

        screen[personY][personX] = 'M';

        system("clear");
        
        for (int y = 0; y < HEIGHT; y++)
        {
            for (int x = 0; x < WIDTH; x++)
            {

                printf("%c", screen[y][x]);
            }
            printf("\n");
        }
        usleep(150000);
    }
    return 0;
}