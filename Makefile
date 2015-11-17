#########################################
# Nicolas MAUGER
# 31/10/15
#########################################

CC = gcc
CFLAGS = -W -Wall -Werror -ansi
LDFLAGS = 

SRC = $(wildcard *.c)
OBJS = $(SRC:.c=.o)
AOUT = prog

all : $(AOUT) exe

prog : $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

exe : 
	./prog

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clear :
	@rm *.o

clean : clear
	@rm $(AOUT)

help : 
	@echo 'Makefile de Nicolas Mauger, 31/10/15'
	@echo ''
	@echo 'make			build the projecct'
	@echo 'make prog 	build the project'
	@echo 'make exe		execute the project'
	@echo 'make all 	build & execute the project'
	@echo 'make clear	remove objects'
	@echo 'make clean	remove objects & executable'
	@echo 'make help 	open this help'
	@echo ''
