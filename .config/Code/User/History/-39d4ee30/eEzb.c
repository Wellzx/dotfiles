#include <stdio.h>

int main(void)
{
    char buffer[100];
    printf("type some number: ")
    fgets(buffer, sizeof(buffer), stdin);
    
}