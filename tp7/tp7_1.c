/**********************
* TP N◦ 7 – Impélentation de la commande find
* Nicolas MAUGER
* 20/11/15
**********************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

#include "tp7_1.h"
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
		struct dirent *lecture; /* pas sur que c'est un pointeur */
		while((lecture = readdir(fichier)) != NULL){
			traiter_fichier(readdir(fichier).d_name);
			void DT_DIR;
			if(lecture->d_type == DT_DIR){
				parcourir_repertoire(fichier);
			}
		}
	}else{
		printf("Le chemin passé en paramètre n'est pas valide.\n");
		exit(EXIT_FAILURE);
	}
}

int nom_correspond(const char *chemin, const char *motif){
	return strcmp(motif, chemin);
}

int type_correspond(const struct stat *buf, char type){
	return (buf->st_mode == type ? 1 : -1);
}

int estVide(const struct stat *buf) {
	return (buf == NULL ? 1 : -1);
}

int estValide(char *chemin){
	struct dirent *lecture;
	DIR *fichier = opendir(chemin);
	lecture = readdir(fichier);
	return(lecture->d_type == DT_DIR || lecture->d_type == DT_REG?1:-1);	
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
