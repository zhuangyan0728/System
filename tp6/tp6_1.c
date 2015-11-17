/**********************
* TP N◦ 6 – Lecture de fichiers BMP
* Nicolas MAUGER
* 16/10/15
***********************/

#include "tp6_1.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h> // pour 'O_RDOLNLY, O_WRONLY & O_CREATE'
#include <ctype.h>
#include <unistd.h>

int main(int argc, const char **argv)
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
	if (( lol = open("lena.bmp", O_WRONLY | O_CREAT, 0666)) == -1){
		fatal_error("open error");
	}

	copier_bmp(fd,lol);
	close(fd);
	close(lol);
	return EXIT_SUCCESS;
}

void lire_deux_octets(int fd, uint16 *val){
	int ret = read(fd, val, sizeof(uint16));
	if (ret != sizeof(uint16))
		exit(EXIT_FAILURE);
}

void lire_quatre_octets(int fd, uint32 *val){
	int ret = read(fd, val, sizeof(uint32));
	if (ret != sizeof(uint32))
		exit(EXIT_FAILURE);
}

void lire_entete(int de, entete_bmp *entete){
	lire_deux_octets(de, &(entete->fichier.signature));
	lire_quatre_octets(de, &(entete->fichier.taille_fichier));
	lire_quatre_octets(de, &(entete->fichier.reserve));
	lire_quatre_octets(de, &(entete->fichier.offset_donnees));
	lire_quatre_octets(de, &(entete->bitmap.taille_entete));
	lire_quatre_octets(de, &(entete->bitmap.largeur));
	lire_quatre_octets(de, &(entete->bitmap.hauteur));
	lire_deux_octets(de, &(entete->bitmap.nombre_plans));
	lire_deux_octets(de, &(entete->bitmap.profondeur));
	lire_quatre_octets(de, &(entete->bitmap.taille_donnees_image));
	lire_quatre_octets(de, &(entete->bitmap.resolution_horizontale));
	lire_quatre_octets(de, &(entete->bitmap.resolution_verticale));
	lire_quatre_octets(de, &(entete->bitmap.taille_palette));
	lire_quatre_octets(de, &(entete->bitmap.nombre_de_couleurs_importantes));
}

void ecrire_deux_octets(int fd, uint16 val){
	int ret = write(fd, &(val), sizeof(uint16));
	if (ret != sizeof(uint16))
		exit(EXIT_FAILURE);
}

void ecrire_quatre_octets(int fd, uint32 val){
	int ret = write(fd, &(val), sizeof(uint32));
	if (ret != sizeof(uint32))
		exit(EXIT_FAILURE);
}

void ecrire_entete(int vers, entete_bmp *entete){
	ecrire_deux_octets(vers, entete->fichier.signature);
	ecrire_quatre_octets(vers, entete->fichier.taille_fichier);
	ecrire_quatre_octets(vers, entete->fichier.reserve);
	ecrire_quatre_octets(vers, entete->fichier.offset_donnees);
	ecrire_quatre_octets(vers, entete->bitmap.taille_entete);
	ecrire_quatre_octets(vers, entete->bitmap.largeur);
	ecrire_quatre_octets(vers, entete->bitmap.hauteur);
	ecrire_deux_octets(vers, entete->bitmap.nombre_plans);
	ecrire_deux_octets(vers, entete->bitmap.profondeur);
	ecrire_quatre_octets(vers, entete->bitmap.taille_donnees_image);
	ecrire_quatre_octets(vers, entete->bitmap.resolution_horizontale);
	ecrire_quatre_octets(vers, entete->bitmap.resolution_verticale);
	ecrire_quatre_octets(vers, entete->bitmap.taille_palette);
	ecrire_quatre_octets(vers, entete->bitmap.nombre_de_couleurs_importantes);
}

int verifier_entete(entete_bmp *entete){
	return (entete->bitmap.profondeur==24 ? 1 : 0);
}

unsigned char* allouer_pixels(entete_bmp *entete){
	return malloc(entete->bitmap.largeur * entete->bitmap.hauteur * entete->bitmap.profondeur / 8);
}

int lire_pixels(int de, entete_bmp *entete, unsigned char *pixels){
	return read(de, pixels, entete->bitmap.largeur*entete->bitmap.hauteur*entete->bitmap.profondeur/8*sizeof(char));
}

int ecrire_pixels(int vers, entete_bmp *entete, unsigned char *pixels){
	return write(vers, pixels, entete->bitmap.largeur*entete->bitmap.hauteur*entete->bitmap.profondeur/8*sizeof(char));
}

int copier_bmp(int de, int vers){
	unsigned char *pixels;	
	entete_bmp entete;
	/* lecture du fichier source */
	lire_entete(de, &entete);
	pixels = allouer_pixels(&entete);
	lire_pixels(de, &entete, pixels);
	/* écriture du fichier destination */	
	rouge(&entete, pixels);
	negatif(&entete, pixels);
	moitie(&entete, pixels,1);
	sepia(&entete, pixels);
	noir_et_blanc(&entete, pixels);
	ecrire_entete(vers, &entete);
	ecrire_pixels(vers, &entete, pixels);	
	/* on libère les pixels */
	free(pixels);
	return 1; /* on a réussi */
}

void rouge(entete_bmp *entete, unsigned char *pixels){
	int i;
	int j;
	for (i=0; i<(int)entete->bitmap.hauteur; i++){
		for (j=0; j<(int)entete->bitmap.largeur; j++){
			pixels[1]=0;/*bleu*/
			pixels[2]=0;/*vert*/
			/*pixels[3] rouge*/
			pixels+=3;
		}
		if (entete->bitmap.largeur*(entete->bitmap.profondeur/8*sizeof(char))%4!=0)
			pixels+=4-(entete->bitmap.largeur*(entete->bitmap.profondeur/8*sizeof(char))%4);
	}
}
void negatif(entete_bmp *entete, unsigned char *pixels){
	int i;
	int j;
	for (i=0; i<(int)entete->bitmap.hauteur; i++){
		for (j=0; j<(int)entete->bitmap.largeur; j++){
			pixels[0]=~pixels[0];
			pixels[1]=~pixels[1];
			pixels[2]=~pixels[2];
			pixels+=3;
		}
		if (entete->bitmap.largeur*(entete->bitmap.profondeur/8*sizeof(char))%4!=0)
			pixels+=4-(entete->bitmap.largeur*(entete->bitmap.profondeur/8*sizeof(char))%4);
	}
}
void noir_et_blanc(entete_bmp *entete, unsigned char *pixels){
	int i;
	int j;
	int temp;
	for (i=0; i<(int)entete->bitmap.hauteur; i++){
		for (j=0; j<(int)entete->bitmap.largeur; j++){
			temp = (pixels[0]+pixels[1]+pixels[2])/3;
			pixels[0]=temp;
			pixels[1]=temp;
			pixels[2]=temp;
			pixels+=3;
		}
		if (entete->bitmap.largeur*(entete->bitmap.profondeur/8*sizeof(char))%4!=0)
			pixels+=4-(entete->bitmap.largeur*(entete->bitmap.profondeur/8*sizeof(char))%4);
	}
}

void moitie(entete_bmp *entete, unsigned char *pixels, int sup){
	int n = 0;
	if (sup==0){
		entete->bitmap.hauteur=(int)(entete->bitmap.hauteur/2);
		entete->bitmap.taille_donnees_image=(int)(entete->bitmap.taille_donnees_image/2);	
	}
	else{
		n = ((entete->bitmap.largeur*entete->bitmap.hauteur*entete->bitmap.profondeur/8*sizeof(char))+(entete->bitmap.hauteur*(4-(entete->bitmap.largeur*(entete->bitmap.profondeur/8*sizeof(char))%4))))/2;
		memcpy(pixels, pixels+n, n);
		entete->bitmap.hauteur=(int)(entete->bitmap.hauteur/2);
		entete->bitmap.taille_donnees_image=(int)(entete->bitmap.taille_donnees_image/2);
	}
}

void sepia(entete_bmp *entete, unsigned char *pixels)
{
	int i;
	int j;
	for (i=0; i<(int)entete->bitmap.hauteur/3; i++){
		for (j=0; j<(int)entete->bitmap.largeur/3; j++){
			pixels[0]= 0;
			pixels[1]= 0;
			pixels+=3;
		}
		for (j=0; j<(int)entete->bitmap.largeur/3; j++){
			pixels[0]= 0;
			pixels[2]= 0;
			pixels+=3;
		}	
		for (j=0; j<(int)entete->bitmap.largeur/3; j++){

			pixels[1]= 0;
			pixels[2]= 0;
			pixels+=3;		
		}
		if (entete->bitmap.largeur*(entete->bitmap.profondeur/8*sizeof(char))%4!=0)
			pixels+=4-(entete->bitmap.largeur*(entete->bitmap.profondeur/8*sizeof(char))%4);
	}
	for (i=0; i<(int)entete->bitmap.hauteur/3; i++){
		for (j=0; j<(int)entete->bitmap.largeur/3; j++){
			pixels[1]= 0;
			pixels[2]= 0;
			pixels+=3;
		}
		for (j=0; j<(int)entete->bitmap.largeur/3; j++){
			pixels[0]= 0;
			pixels[1]= 0;
			pixels+=3;
		}	
		for (j=0; j<(int)entete->bitmap.largeur/3; j++){
			pixels[0]= 0;
			pixels[2]= 0;
			pixels+=3;

		}
		if (entete->bitmap.largeur*(entete->bitmap.profondeur/8*sizeof(char))%4!=0)
			pixels+=4-(entete->bitmap.largeur*(entete->bitmap.profondeur/8*sizeof(char))%4);
	}
	for (i=0; i<(int)entete->bitmap.hauteur/3; i++){
		for (j=0; j<(int)entete->bitmap.largeur/3; j++){
			pixels[0]= 0;
			pixels[2]= 0;
			pixels+=3;
		}
		for (j=0; j<(int)entete->bitmap.largeur/3; j++){
			
			pixels[1]= 0;
			pixels[2]= 0;
			pixels+=3;
		}	
		for (j=0; j<(int)entete->bitmap.largeur/3; j++){
			pixels[0]= 0;
			pixels[1]= 0;
			pixels+=3;		
		}
		if (entete->bitmap.largeur*(entete->bitmap.profondeur/8*sizeof(char))%4!=0)
			pixels+=4-(entete->bitmap.largeur*(entete->bitmap.profondeur/8*sizeof(char))%4);
	}
}

void fatal_error(const char * message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

