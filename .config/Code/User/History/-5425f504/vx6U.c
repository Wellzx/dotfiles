#include <stdio.h>
#include <string.h>

int main(void)
{
    int age;
    char name[50];

    printf("Type your name: ");
    scanf("%s", name);

    printf("Type your age: ");
    scanf("%d", &age);

    if (age >= 18)
    {
        printf("%s is an adult. \n", name);
    }
    else
    {
        printf("%s is not an adult. \n", name);
    }

    return 0;
    
}