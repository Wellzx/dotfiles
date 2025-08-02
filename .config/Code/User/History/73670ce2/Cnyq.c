#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define HEIGHT 5
#define WIDTH 20

int main()
{
    char screen[HEIGHT][WIDTH];

    int personX = 2;
    int personY = HEIGHT - 1;

    while (1)
    {
        for (int y = 0; y < HEIGHT; y++)
        {
            for (int x = 0; x < WIDTH; x++)
            {
                screen[y][x] = ' ';
            }
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