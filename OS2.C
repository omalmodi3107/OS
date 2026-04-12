#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>   // Needed for wait()

int main() {
    pid_t pid;
    int i, sum = 0;

    pid = fork();   // create child process

    if (pid < 0) {
        perror("Fork failed");   // better error message
        return 1;
    }

    // Child process
    if (pid == 0) {
        printf("Child Process (0 to 15)\n");
        for (i = 0; i <= 15; i++) {
            if (i % 2 == 0) {
                sum += i;
            }
        }
        printf("Sum of even numbers (0–15) = %d\n", sum);
    }

    // Parent process
    else {
        wait(NULL);  // wait for child to finish
        sum = 0;
        printf("Parent Process (15 to 29)\n");
        for (i = 15; i <= 29; i++) {
            if (i % 2 == 0) {
                sum += i;
            }
        }
        printf("Sum of even numbers (15–29) = %d\n", sum);
    }

    return 0;
}