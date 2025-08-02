#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void print_row(int spaces, int hashes);

int main(void)
{
    const int height = 4;
    for (int i = 1; i <= height; i++)
    {
        int spaces = height - i;
        int hashes = i;
        print_row(spaces, hashes);
    }

}

void print_row(int spaces, int hashes)
{
    for(int i = 0; i < spaces; i++)
    {
        printf(" ");
    }

    for (int i = 0; i < hashes; i++)
    {
        printf("#");
    }

    printf("\n");
    
}