#include <stdio.h>

void print_row(int n);

int main()
{
    const int n = 3;
    for (int i = 0; i < n; i++)
    {
        print_row(i + 1);
    }

}

void print_row(int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}