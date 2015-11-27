/**********************
* TP N◦ 7 – Impélentation de la commande find
* Nicolas MAUGER
* 20/11/15
***********************/
#include "tp7_1.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>


/*
opendir
closedir
readdir
stat
lstat
*/

int main (/*int argc, char **argv*/) {
	parcourir_repertoire(".");
	return 1;
}

void traiter_fichier(const char *chemin) {
	printf("%s\n", chemin);
	exit(1);
}

void parcourir_repertoire(const char *chemin) {
	if(estValide(chemin)){

	}else{
		exit(EXIT_FAILURE);
	}

}

/* Not yet implemented */
int estValide(char *chemin){
	DIR *fichier = opendir(chemin);
	while(){
		
	}
	return 1;
}




































/*
void parcourir_repertoire(const char *chemin){
	DIR * folder = opendir(chemin);
	struct dirent *stuct_dir;
	while((stuct_dir = readdir(folder)) != NULL){
		printf("%s\n", stuct_dir->d_name);

	}
}
*/