#include <stdio.h>

int main(void)
{
    int x;
    int y;

    printf("x: ");
    scanf("%d", &x);

    printf("y: ");
    scanf("%d", &y);

    float sum = x + y;

    printf("Sum: %i\n", sum);

    return 0;

}