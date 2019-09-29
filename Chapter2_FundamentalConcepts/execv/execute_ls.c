#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    // Each process is named by a process ID number, a value of type pid_d
    pid_t pid; 
    char *const parmList[] = {"/bin/ls", "-l", "/home/rahul", NULL};
    pid = fork();

    if (pid == -1)
        perror("fork error");
    else if (pid == 0) {
        execv("/bin/ls", parmList);
        printf("Return not expected. Must be an execv error.n");
    }
}
