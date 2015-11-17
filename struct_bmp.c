#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

/* 16/32 bits integers */
typedef unsigned short uint16;
typedef unsigned int uint32;

/* Header of the file */
typedef struct
{
    uint16 signature;
    uint32 taille_fichier;
    uint32 reserve;
    uint32 offset_donnees;
} entete_fichier;

/* Header of the bitmap */
typedef struct
{
    uint32 taille_entete;
    uint32 largeur;
    uint32 hauteur;
    uint16 nombre_plans;
    uint16 profondeur;
    uint32 compression;
    uint32 taille_donnees_image;
    uint32 resolution_horizontale;
    uint32 resolution_verticale;
    uint32 taille_palette; /* en nombre de couleurs */
    uint32 nombre_de_couleurs_importantes; /* 0 */
} entete_bitmap;


/* Headers */
typedef struct
{
    entete_fichier fichier;
    entete_bitmap bitmap;
} entete_bmp;


void fatal_error(const char *);


int main(int argc, const char *argv[])
{
    entete_bmp bmp;
    int fd;
    int ret;

    if (argc < 2)
    {
        printf("Wrong number of parameters\n");
        printf("Usage: %s <bmp file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Opening the file */
    if ((fd = open(argv[1], O_RDONLY)) == -1)
        fatal_error("open error");


    /* Reading from the file, directly into the structure */
    if ((ret = read(fd, &bmp, sizeof(entete_bmp))) == -1)
        fatal_error("read error");

    /* Displaying basic data about the bmp file */
    printf("-------- BMP FILE INFO -------------\n");
    printf("Signature: %d\n", bmp.fichier.signature);
    printf("Taille: %d\n", bmp.fichier.taille_fichier);
    printf("Resolution image: %dx%x\n", bmp.bitmap.largeur, bmp.bitmap.hauteur);
    printf("Nombre de plans: %d\n", bmp.bitmap.nombre_plans);
    printf("Profondeur: %d\n", bmp.bitmap.profondeur);


    /* Displaying basic data about structures */
    printf("-------- STRUCTURES INFO -------------\n");
    printf("sizeof(entete_bmp): %d\n", (int)sizeof(entete_bmp));
    printf("sizeof(entete_fichier): %d\n", (int)sizeof(entete_fichier));
    printf("sizeof(entete_bitmap): %d\n", (int)sizeof(entete_bitmap));

    return EXIT_SUCCESS;
}

void fatal_error(const char * message)
{
    perror(message);
    exit(EXIT_FAILURE);
}

