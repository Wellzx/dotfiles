#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 20

int grid[HEIGHT][WIDTH];
int temp[HEIGHT][WIDTH];

void initGrid() {
    srand(time(NULL));
    for (int y = 0; y < HEIGHT; y++)
        for (int x = 0; x < WIDTH; x++)
            grid[y][x] = rand() % 2;
}

int countNeighbors(int y, int x) {
    int count = 0;
    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++)
            if (i != 0 || j != 0)
                count += grid[(y + i + HEIGHT) % HEIGHT][(x + j + WIDTH) % WIDTH];
    return count;
}

void updateGrid() {
    for (int y = 0; y < HEIGHT; y++)
        for (int x = 0; x < WIDTH; x++) {
            int neighbors = countNeighbors(y, x);
            if (grid[y][x] == 1)
                temp[y][x] = (neighbors == 2 || neighbors == 3) ? 1 : 0;
            else
                temp[y][x] = (neighbors == 3) ? 1 : 0;
        }

    for (int y = 0; y < HEIGHT; y++)
        for (int x = 0; x < WIDTH; x++)
            grid[y][x] = temp[y][x];
}

void displayGrid() {
    printf("\033[H"); // Move o cursor pro topo
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++)
            printf(grid[y][x] ? "█" : " ");
        printf("\n");
    }
    fflush(stdout);
}

int main() {
    system("clear");
    initGrid();
    while (1) {
        displayGrid();
        updateGrid();
        usleep(100000); // 100ms
    }
    return 0;
}