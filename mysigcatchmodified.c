#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int count = 0; //counts the signals caught

void sign_funct(int sign) {
    if (sign == SIGINT) {
        count++;
        printf("Caught a SIGINT #%d\n", count);

        if (count == 2) {
            signal(SIGINT, SIG_DFL);
            printf("About to restore default behavior for SIGINT\n");
        }
    }
}

int main() {
    if (signal(SIGINT, sign_funct) == SIG_ERR) {
        fprintf(stderr, "Did not caught a SIGINT\n");
        return 1;
    }

    //In order to keep runnning until getting second signal
    while (1) {
       
    }

    return 0;
}

