################################
# TP N◦ 4 – Allocation dynamique & arguments de la ligne de commande
# Nicolas MAUGER
# 25/09/15
################################



# Compilation du fichiers
tp4: tp4_1.o
	gcc -Wall -Werror -W -o tp4 tp4_1.o

# Compilation tp1_1
tp4_1.o: tp4_1.c
	gcc -Wall -W -c tp4_1.c

# Faire le ménage
clean:
	rm tp4 tp4_1.o

# Grand ménage
mrproper: clean
	@ rm -rf $(EXEC) $(OBJDIR) $(BINDIR)

# Excecution tp1
exec:
	./tp4 ${ARGS}

.PHONY: run

run: exec
	@echo $(RUN_ARGS)

# Aide
help:
	@ echo ''
	@ echo 'make           Build project executable'
	@ echo 'make exec      Run projet'
	@ echo 'make ARGS="<ma chaine de caractère> <mon option>	Run projet with options'
	@ echo 'make clean     Clean objects directory'
	@ echo 'make mrproper  Remove objects and binaries directory'
	@ echo 'make help      Show this help message'
	@ echo ''
