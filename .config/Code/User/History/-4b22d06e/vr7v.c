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

    printf("Sum: %d/n", (int) sum);

    return 0;

}