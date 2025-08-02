#include <stdio.h>

int main(void)
{
    int x;
    int y;

    printf("x: ");
    scanf("%lf", &x);
    printf("y: ");
    scanf("%lf", &y);

    float sum = x + y;

    printf("%lf", sum);

}