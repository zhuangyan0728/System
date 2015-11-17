/**********************
* TP N◦ 6 – Lecture de fichiers BMP
* Nicolas MAUGER
* 16/10/15
***********************/

typedef unsigned short uint16;
typedef unsigned int uint32;

typedef struct
{
	uint16 signature;

	uint32 taille_fichier;
	uint32 reserve;
	uint32 offset_donnees;
} entete_fichier;
	
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

	typedef struct
{
	entete_fichier fichier;
	entete_bitmap bitmap;
} entete_bmp;

int open(const char *pathname, int flags);
int open(const char *pathname, int flags, mode_t mode);
int read(int fd, void *buf, int count);

int lire_deux_octets(int fd, uint16 *val);
int lire_quatre_octets(int fd, uint32 *val);
void lire_entete(int de, entete_bmp *entete);

void ecrire_deux_octets(int fd, uint16 val);
void ecrire_quatres_octets(int fd, uint32 val);
void ecrire_entete(int vers, entete_bmp *entete);

int verifier_entete(entete_bmp *entete);

void moitie(entete_bmp *entete, unsigned char *pixel, int sup);
void rouge(entete_bmp *entete, unsigned char *pixels);
void negatif(entete_bmp *entete, unsigned char *pixels);
void noir_et_blanc(entete_bmp *entete, unsigned char *pixels);
void sepia(entete_bmp *entete, unsigned char *pixels);

unsigned char* allouer_pixels(entete_bmp *entete);
int lire_pixels(int de, entete_bmp *entete, unsigned char *pixels);
int ecrire_pixels(int vers, entete_bmp *entete, unsigned char *pixels);

int copier_bmp(int de, int vers);
void fatal_error(const char *); /* Idee de max */