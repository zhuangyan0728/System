/**********************
* TP N◦ 6 – Lecture de fichiers BMP
* Nicolas MAUGER
* 16/10/15
***********************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "tp6_1.h"

int main(void)
{
	/* oui */

}

int lire_deux_octets(int fd, uint16 *val)
{
	return read(fd, val, sizeof(uint16));
}

int lire_quatre_octets(int fd, uint32 *val)
{	
	return read(fd, val, sizeof(uint32));
}

int lire_entete(int de, entete_bmp *entete)
{
	lire_deux_octets(de, &(entete->fichier.signature));
	lire_quatre_octets(de, &(entete->fichier.taille_fichier));
	lire_quatre_octets(de, &(entete->fichier.reserve));
	lire_quatre_octets(de, &(entete->fichier.offset_donnees));

	lire_quatre_octets(de, &(entete->bitmap.taille_entete));
	lire_quatre_octets(de, &(entete->bitmap.largeur));
    lire_quatre_octets(de, &(entete->bitmap.hauteur));

	lire_deux_octets(de, &(entete->bitmap.nombre_plans));
	lire_deux_octets(de, &(entete->bitmap.profondeur));

	lire_quatre_octets(de, &(entete->bit.compression));
	lire_quatre_octets(de, &(entete->fichier.taille_donnees_image));
	lire_quatre_octets(de, &(entete->fichier.resolution_horizontale));
	lire_quatre_octets(de, &(entete->fichier.resolution_verticale));
	lire_quatre_octets(de, &(entete->fichier.taille_palette)); /* en nombre de couleurs */
	lire_quatre_octets(de, &(entete->fichier.nombre_de_couleurs_importantes)); /* 0 */
}

int ecrire_deux_octets(int fd, uint16 val)
{
	return write(fd, val, sizeof(uint16));
}

int ecrire_quatre_octets(int fd, uint32 val)
{
	return write(fd, val, sizeof(uint32));
}

int ecrire_entete(int vers, entete_bmp *entete)
{
	ecrire_deux_octets(de, (entete->fichier.signature));
	ecrire_quatre_octets(de, (entete->fichier.taille_fichier));
	ecrire_quatre_octets(de, (entete->fichier.reserve));
	ecrire_quatre_octets(de, (entete->fichier.offset_donnees));

	ecrire_quatre_octets(de, (entete->bitmap.taille_entete));
	ecrire_quatre_octets(de, (entete->bitmap.largeur));
	ecrire_quatre_octets(de, (entete->bitmap.hauteur));

	ecrire_deux_octets(de, (entete->bitmap.nombre_plans));
	ecrire_deux_octets(de, (entete->bitmap.profondeur));

	ecrire_quatre_octets(de, (entete->bitmap.taille_donnees_image));
	ecrire_quatre_octets(de, (entete->bitmap.resolution_horizontale));
	ecrire_quatre_octets(de, (entete->bitmap.resolution_verticale));
	ecrire_quatre_octets(de, (entete->bitmap.taille_palette));
	ecrire_quatre_octets(de, (entete->bitmap.nombre_de_couleurs_importantes));
}

int verifier_entete(entete_bmp *entete)
{
	return (entete->bitmap.profondeur==24 ? 1 : 0 );
}

unsigned char* allouer_pixels(entete_bmp *entete)
{
	return malloc(sizeof(char) * (entete->bitmap.resolution_horizontale * bitmap.resolution_verticale * 3));
}

int lire_pixels(int de, entete_bmp *entete, unsigned char *pixels)
{
	/* return read(de, pixels, entete->oui...); */
}

int copier_bmp(int de, int vers)
{
	entete_bmp entete;
	unsigned char *pixels;
	/* lecture du fichier source */
	lire_entete(de, &entete);
	pixels = allouer_pixels(&entete);
	lire_pixels(de, &entete, pixels);
	/* écriture du fichier destination */
	ecrire_entete(vers, &entete);
	ecrire_pixels(vers, &entete, pixels);
	/* on libère les pixels */
	free(pixels);
	return 1; /* on a réussi */
}

