#include "bmp.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void fatal_error(const char *);


int main(int argc, const char *argv[])
{

    int fd;
    int lol=0;

    if (argc < 2)
    {
        printf("Wrong number of parameters\n");
        printf("Usage: %s <bmp file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fd = open(argv[1], O_RDONLY)) == -1){
        fatal_error("open error");
	}
    if (( lol = open("file.bmp", O_WRONLY | O_CREAT, 0666)) == -1)
        fatal_error("open error");


copier_bmp(fd,lol);


  
close(fd);
close(lol);
    return EXIT_SUCCESS;
}

void fatal_error(const char * message)
{
    perror(message);
    exit(EXIT_FAILURE);
}

