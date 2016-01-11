#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid;
    int mypipe[2];
    char buf[20];

    int ret = pipe(mypipe);

    if(ret < 0) {
        perror("Pipe error.");
        exit(1);
    }

    pid = fork();

    if(pid == 0) {
        /* child process */
        write(mypipe[1], "Hello World!", 13);
    } else {
        /* parent process */
        read(mypipe[0], buf, 15);
        printf("buf: %s\n",buf);
    }

     return 0;
}
