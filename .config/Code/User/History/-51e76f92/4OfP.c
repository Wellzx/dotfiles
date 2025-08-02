#include <stdio.h>

int main()
{
    int x;
    int y;

    printf("What's x? \n");
    scanf("%d", &x);
    printf("What's y? \n");
    scanf("%d", &y);

    if (x > y)
    {
        printf("x is less than y\n");
    }
    else if (x < y)
    {
        printf("x is greater than y\n");
    }
    else if (x == y)
    {
        printf("x is equal to y\n");
    }

}