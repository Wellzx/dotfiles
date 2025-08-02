#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define HEIGHT 5
#define WIDTH 20

int main(){
    char screen[HEIGHT][WIDTH];

    int personX = 2;
    int personY = HEIGHT - 1;

    while (1) {
        for (int y = 0; y < HEIGHT; y++){
            for (int x = 0; x < WIDTH; x++){
                screen[x][y] = ' ';
            }
            
        }

    screen[personX][personY] = 'M';

    system("clear");
    for (int y = 0; y < HEIGHT; y++){
        for (int x = 0; x < WIDTH; x++){

            printf("%c", screen[x][y]);
        }
        printf("\n");
    }

   }   return 0;
    
}