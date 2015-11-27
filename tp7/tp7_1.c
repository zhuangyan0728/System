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
		DIR *fichier = opendir(chemin);
		struct dirent *lecture; //pas sur que c'est un pointeur
		while(lecture = readdir(fichier) != NULL){
			traiter_fichier(readdir(fichier)).d_name);
			if(lecture.d_type == DT_DIR)
				parcourir_repertoire(fichier);
		}
	}else{
		printf("Le chemin passé en paramètre n'est pas valide.\n");
		exit(EXIT_FAILURE);
	}
}

/* Not yet implemented */
int estValide(char *chemin){
	struct dirent *lecture;
	lecture = readdir(fichier);
	if(lecture.d_type == DT_DIR || lecture.d_type == DT_REG){
		return 1;
	}else{
		return -1;
	}
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