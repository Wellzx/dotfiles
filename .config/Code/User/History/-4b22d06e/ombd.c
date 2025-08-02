#include <stdio.h>

int main(void)
{
    int dollars = 1;
    while (dollars)
    {
        printf("Here's $%i. Double it and give it to the next person? ", dollars);
        scanf("%i", &dollars);
    }
    

}