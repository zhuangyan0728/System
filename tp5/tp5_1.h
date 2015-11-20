/**********************
* TP N◦ 5 – Word Count
* Nicolas MAUGER
* 09/10/15
***********************/

#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

#define BUFFER 80

int traiter (int f, int *car, int *mots, int *lig) 
{
	char buf[BUFFER];
	int n;
	int i=0;
	int mot=0;

	*car = 0;
	*lig = 0;
	*mots = 0;

	while((n=read(f,buf,BUFFER*sizeof(char)))>0) {
		while(i<n) {
			if(! mot && !isspace(buf[i])){
				(*mots)++;
			}
			if (isspace(buf[i])) {
				mot=0;
			}
			else {
				mot=1;
			}
			if(buf[i] == '\n') {
				(*lig)++;
			}
			(*car)++;
			i++;
		}
		i=0;
	}
	return 0;
}