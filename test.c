#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

// Signal handler
void handle_signal(int sig) {
    if (sig == SIGINT) {
        printf("\nCaught SIGINT (Ctrl+C). Not quitting!\n");
    } else if (sig == SIGTSTP) {
        printf("\nCaught SIGTSTP (Ctrl+Z). Not stopping!\n");
    }
    fflush(stdout);  // flush output so it prints immediately
}

int main() {
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = handle_signal;
    sa.sa_flags = SA_RESTART;   // ensures scanf continues after signal

    // Register handler for Ctrl+C
    sigaction(SIGINT, &sa, NULL);
    // Register handler for Ctrl+Z
    sigaction(SIGTSTP, &sa, NULL);

    printf("Running... press Ctrl+C or Ctrl+Z\n");

    char command[100];
    int i = 0;

    while (1) {
        printf("msh>%d ", i++);
        fflush(stdout);

        if (scanf("%99s", command) == 1) {
            printf("You entered: %s\n", command);
        }
    }

    return 0;
}
