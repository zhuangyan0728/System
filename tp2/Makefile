# Compilation des 3 fichiers
tp1: tp1_1.o
	gcc -Wall -Werror -W -o tp1 tp1_1.o

# Compilation tp1_1
tp1_1.o: tp1_1.c
	gcc -Wall -W -c tp1_1.c

# Faire le ménage
clean:
	rm tp1 tp1_1.o

# Excecution tp1
exec:
	./tp1