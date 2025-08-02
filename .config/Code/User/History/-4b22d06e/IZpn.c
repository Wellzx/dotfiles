#include <stdio.h>

int main(void)
{
    int dollars = 1;
    char response;

    while (1)
    {
        printf("Here's $%i. Double it and give it to the next person? (y/n): ", dollars);

        scanf("%c", &response);

        if(response == 'y' || response == 'n')
        {
            dollars *= 2;
        }
        else if (response != 'y' || 'n')
        {
            printf("Only yes or no are accepted\n");
        }
        
        {
            break;
        }
    }

    printf("Here's $%i.\n", dollars);

    return 0;
    
}