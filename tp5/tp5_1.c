/**********************
* TP N◦ 5 – Word Count
* Nicolas MAUGER
* 09/10/15
***********************/

// nicolas.anquetil@univ-lille1.fr

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "tp5_1.h"

int traiter (int f, int *car, int *mot, int *lig);

int main(int argc,char *argv[])
{
  int fc;
  int totalc=0;
  int totalw=0;
  int totall=0;
  int i=1;
  int j=0;
  int plusieurfichier=0;
  int opC=0;
  int opW=0;
  int opL=0;
  int car=0;
  int mots=0;
  int lignes=0;

  while(i<argc && argv[i][0]=='-') {
    j=1;
    if (argv[i][1] == '\0') {
      printf("Erreur d'argument: '%s'\n", argv[i]);
      exit(1);
    }

    while(argv[i][j]!='\0') {
      if(argv[i][j] != 'l' && argv[i][j] != 'w' && argv[i][j] != 'c'){
	printf("Erreur d'argument: '%s' \n", argv[i]);
	exit(1);
      }
      if(argv[i][j] =='l'){
	opL=1;
      }
      if(argv[i][j] =='w'){
	opW=1;
      }
      if(argv[i][j] =='c'){
	opC=1;
      }
      j++;
    }    
    i++;
  }

  if(opL==0 && opW ==0 && opC==0){
    opL=1;
    opW=1;
    opC=1;
  }

  if (i == argc) {
    printf("Lecture de l'entree standard\n");
    traiter(0,&car,&mots,&lignes);
    if(opC==1){printf("Caracteres : %d  \n",car);}
    if(opW==1){printf("Mots : %d  \n",mots);}
    if(opL==1){printf("Lignes : %d  \n",lignes);}
  }
  while(i<argc){
    if((fc = open(argv[i],O_RDONLY))==-1) {
      perror(argv[i]);
    }
      
    else
      {
	printf("--%s\n",argv[i]);
	traiter(fc,&car,&mots,&lignes);
	totalc+=car;totalw+=mots;totall+=lignes;
	if(opC==1){
	  printf("Caracteres : %d  \n",car);
	}
	if(opW==1){
	  printf("Mots : %d  \n",mots);
	}
	if(opL==1){
	  printf("Lignes : %d  \n",lignes);
	}
	if(car != totalc || mots!=totalw || lignes!=totall){
	  plusieurfichier=1;
	}
	car=0;mots=0;lignes=0;
	close(fc);
      }
     
    i++;
  }
  if(plusieurfichier ==1){
    printf("Total des fichiers : Caracteres : %d / Mots : %d / Lignes : %d \n",totalc,totalw,totall);
  }
  return 0;
}

