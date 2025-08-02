// input.c
#include "input.h"
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

static struct termios original;

void configurarModoTerminal() {
    struct termios novo;

    tcgetattr(STDIN_FILENO, &original);
    novo = original;
    novo.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &novo);
}

void resetarModoTerminal() {
    tcsetattr(STDIN_FILENO, TCSANOW, &original);
}

int kbhit() {
    struct termios oldt, newt;
    int oldf;
    int ch;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}