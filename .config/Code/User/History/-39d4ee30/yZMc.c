#include <stdio.h>

void print_colum(int height);

int main(void)
{
    int h;
    printf("Height: ");
    scanf("%d\n", &h);
    print_colum(h);
    
}

void print_colum(int height)
{
    for (int i = 0; i < height; i++)
    {
        printf("#\n");
    }
    
}