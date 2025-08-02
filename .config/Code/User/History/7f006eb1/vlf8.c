#include <stdio.h>

int main() {
    char c;
    for (int i = 32; i <= 126; i++) {
        c = i;
        printf("%d = %c\n", i, c);
    }
    return 0;
}
