#include <stdio.h>
#include <unistd.h>

struct stock {
    int bread;
    int tomato;
    int cheese;
    int ham;
};

int pizza_ready(struct stock *s);
int create_consumer(int fd[2]);
int create_producer(int fd[2], int ingredient, int delay);
int init_producers(int fd[2], int pid_producers[4]);

int pizza_ready(struct stock *s) {
    if(s.bread >= 1 && s.tomato >= 3 && s.cheese >= 2 && s.ham >= 2) {
        s.bread -= 1;
        s.tomato -= 3;
        s.cheese -= 2;
        s.ham -= 2;
        return 0;
    }
    return -1;
}

int create_consumer(int fd[2]) {
    pid_t pid;
    int buff[4];

    int ret = pipe(fd);
    if(ret < 0) {
        exit(-1);
    }

    pid = fork();

    if(pid == 0){
        /* child process */
        sleep(1000);
    } else {
        /* parent process */
        read(fd[0], buff, 15);
        printf("Kowabunga");
    }
    return 0;
}

int create_producer(int fd[2], int ingredient, int delay) {
    pid_t pid;

    int ret = pipe(fd);

    if(ret < 0){
        exit(-1);
    }

    pid = fork();

    if(pid == 0){
        /* child process */
        sleep(delay);
        write(fd[1], &(ingredient), sizeof(int));
    } else {
        /* parent procee */
    }

    return 0;
}

int init_producers(int fd[2], int pid_producers[4]){
    
    return 0;
}

int main(int argc, char *argv[]) {
    struct stock monStock;
    monStock.bread = 10;
    monStock.tomato = 10;
    monStock.cheese = 10;
    monStock.ham = 10;
    return 0;
}
