########################
# TP N◦ 5 – Word Count
# Nicolas MAUGER
# 09/10/15
########################



# Compilation du fichiers
tp5: tp5_1.o
	gcc -Wall -Werror -W -o tp5 tp5_1.o

# Compilation tp1_1
tp5_1.o: tp5_1.c
	gcc -Wall -W -c tp5_1.c

# Faire le ménage
clean:
	rm tp5 tp5_1.o

# Grand ménage
mrproper: clean
	@ rm -rf $(EXEC) $(OBJDIR) $(BINDIR)

# Excecution tp1
exec:
	./tp5 ${ARGS}

.PHONY: run

run: exec
	@echo $(RUN_ARGS)

# Aide
help:
	@ echo ''
	@ echo 'make           Build project executable'
	@ echo 'make exec      Run projet'
	@ echo 'make ARGS=	<ma chaine de caractère> <mon option> Run projet with options'
	@ echo 'make clean     Clean objects directory'
	@ echo 'make mrproper  Remove objects and binaries directory'
	@ echo 'make help      Show this help message'
	@ echo ''