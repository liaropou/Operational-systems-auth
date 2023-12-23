#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sign_funct(int sign) {
    if (sign == SIGINT) {
        printf("SIGINT signal caught!\n");
        exit(0);
    }
}

int main() {
    if (signal(SIGINT, sign_funct) == SIG_ERR) {
        fprintf(stderr, "Unable to register SIGINT handler\n");
        return 1;
    }

    //In order to keep runnning until getting second signal
    while (1) {

    }

    return 0;
}

