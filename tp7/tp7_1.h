/**********************
* TP N◦ 7 – Impélentation de la commande find
* Nicolas MAUGER
* 20/11/15
***********************/

enum
{
	NAME,
	TYPE,
	EXEC,
	EMPTY,
	NEWER,
	INVALID,
};

typedef struct
{
	int type ;
	union
	{
		const char *motif;
		const char *chemin ;
		char type_fichier;
	} operande ;
} expression ;

void traiter_fichier(const char *chemin);
void parcourir_repertoire(const char *chemin);
int nom_correspond(const char *chemin, const char *motif);
int type_correspond(const struct stat *buf, char type);
int estVide(const struct stat *buf);
int estValide(const char *chemin);

/*
int executable(const struct stat *buf);
int vide(const struct stat *buf);
int plus_recent(const struct stat *buf, const char *fichier_reference);
*/