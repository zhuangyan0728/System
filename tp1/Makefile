# Makefile Generique
# Create by Ekinoks
# Edit by Nicolas Mauger
 
EXT = c
CXX = gcc
EXEC = exe
DEBUG = yes
 
CXXFLAGS = -Wall -W -Werror -pedantic 
LDFLAGS = 
 
 
OBJDIR = obj
SRC = $(wildcard *.$(EXT))
OBJ = $(SRC:.$(EXT)=.o)
OBJ := $(addprefix $(OBJDIR)/, $(OBJ))
 
all: $(EXEC)

#cree automatiquement le repertoire obj 
$(EXEC): $(OBJ)
	mkdir -p $(OBJDIR)
	@$(CXX) -o $@ $^ $(LDFLAGS)
 
$(OBJDIR)/%.o: %.$(EXT)
	@$(CXX) -o $@ -c $< $(CXXFLAGS)

clean:
	@rm -rf $(OBJDIR)/*.o
	@rm -f $(EXEC)

mrproper: clean
	@ rm -rf $(EXEC) $(OBJDIR) $(BINDIR)
 
install: $(EXEC)
	@cp $(EXEC) /usr/bin/

help:
	@ echo 'Usage :'
	@ echo 'make           Build project executable'
	@ echo 'make all       Build project executable'
	@ echo 'make clean     Clean objects directory'
	@ echo 'make mrproper  Remove objects and binaries directory'
	@ echo 'make help      Show this help message'
	@ echo ''



#########################
#     Ancien fichier    #
#########################
## Compilation des 3 fichiers
#tp1: tp1_1.o tp1_2.o tp1_3.o
#	gcc -Wall -Werror -W -o tp1 tp1_1.o tp1_2.o tp1_3.o
#
## Compilation tp1_1
#tp1_1.o: tp1_1.c
#	gcc -Wall -Werror -W -c tp1_1.c
#
## Compilation tp1_2
#tp1_2.o: tp1_2.c
#	gcc -Wall -Werror -W -c tp1_2.c
#
# Compilation tp1_3
#tp1_3.o: tp1_3.c
#	gcc -Wall -Werror -W -c tp1_3.c
#
## Faire le ménage
#clean:
#	rm tp1 tp1_1.o tp1_2.o tp1_3.o

## Excecution tp1
#exec:
#	./tp1
