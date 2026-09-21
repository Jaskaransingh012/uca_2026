// Custom Signal Handler
// Write a C program that runs an infinite loop. Customize the program so that when the user presses Ctrl+C (SIGINT), it catches the signal, prints a custom message, and keeps running. To exit the program, the user must press Ctrl+C a total of 3 times.

// You can reference this starter code

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Global variable to count signal triggers
volatile sig_atomic_t signal_count = 0;


// TODO: Write your signal handler function here
void handle_sigint(int sig) {

    printf("Custom message from handle_signit handler\n");
    signal_count++;
    if(signal_count >= 3) {
        exit(0);
    }

 }

int main() {
    // TODO: Register the signal handler.
    printf("Program running (PID: %d). Try pressing Ctrl+C...\n", getpid());
    signal(SIGINT, handle_sigint);

    while (1) {
        printf("Loop working\n");
        sleep(1);
    }

    return 0;
}
