#include <stdio.h>
#include <string.h>

int main(void)
{
    int age;
    char name[50];

    printf("Type your name: ");
    fgets(name, sizeof(name), stdin);

    name[strspn(name, "\n")] = 0;

    printf("Type your age: ");
    scanf("%d", &age);

    if (age >= 18)
    {
        printf(name, "%s is an adult. \n");
    }
    else
    {
        printf(name, "%s is not an adult. \n");
    }

    printf("--- All Datas ---\n");
    printf("Name: %s\n", name);
    printf("Age: %d\n", age);

    return 0;
    
}