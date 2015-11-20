/**********************
* TP N◦ 4 – Allocation dynamique & arguments de la ligne de commande
* Nicolas MAUGER
* 25/09/15
***********************/

#include <stdio.h>
#include <ctype.h> //Pas utile?
#include <stdlib.h>
#include <string.h>

/** On déclare les fonction ici pour éviter werror*/
char * miroir (const char *s);
char * saisie ();


/** On veux saisieir une chaine de caractères avec des options de retour */
int main(int argc, char * argv[]){                                             
	
	int i;                                                                        
	int m=0;                                                                      
	int s=0;                                                                      
	int error=0;                                                                  
	int arg;                                                                 
	
	if (argc <2){                                                                 
		printf("mauvaise utilisation \n"); // pas assez d'arguments                                  
		error=1;                                                                     
	}	                                                                            
	else{	                                                                        
		for (i=1; i<argc; i++){                                                      
			if (argv[i][0]=='-'){                                                       
				
				if (strchr(argv[i],(int)'m')!=NULL){		                                  
					m=1;                                                                      
				}                                                                          
				if (strchr(argv[i],(int)'s')!=NULL){                                       
					s=1;                                                                      
				}                                                                          
			}                                                                           
			else{                                                          
				arg++;                                                                     
			}		                                                                        	                                                                          
		}                                          
		if ((s==0 && m==0) ){  
			
			printf("mauvaise utilisation \n");                                          
		}		                                                                          
		else if (m==1 && s==0){                                                      
			if (arg==0 || arg >1){                              
				printf("mauvaise utilisation \n");                                         
			}                                                                           
			else{                                                                       
				for (i=1; i<argc; i++){                                                    
					if(argv[i][0]!='-' && error==0){                                          
						char * mir = miroir(argv[i]);                                            
						printf("%s \n",mir);                                                     
						error=1;                                                                 
					}                                                                         
					else if (error==1){                                                            
						//printf("mauvaise utilisation \n");                                       
					}                                                                         
				}                                                                          
			}                                                                           
		}                                                                            
		else if (s==1){                                                              
			if (arg==0){                                                                
				char * sai = saisie();                                                     
				if (m==1){                                                                 
					char * mir = miroir (sai);                                                
					printf("%s \n",mir);                                                      
				}                                                                          
				else{                                                                      
					printf("%s \n",sai);                                                      
				}                                                                          
			}                                                                           
			else{                                                                       
				printf("mauvaise utilisation \n");                                         
			}                                                                           
		}                                                                            
	}                                                                             
	return 0;                                                                     
}  

/** Fonction qui retourne un pointeur sur une nouvelle chaîne contenant le miroir de la chaîne passée en paramètre ou NULL si la mémoire est insuffisante */
char * miroir (const char *s){
	int i; 
	int len = strlen(s);
	char * t = (char*) malloc ((len+1) * sizeof(char));

	if (t == NULL){
		return NULL;
	}
	for (i = 0; i <len ;++i){
		t[i]=s[len-1-i];
	}
	t[len] = '\0';
	return t;
}

/** Fonction qui saisie les caractère un par un, alloue l'espace mémoire suffisant, et retourne la chaine de caractère */
char * saisie (){
	char * saisie = NULL;	
	//int f = 0;
	int i = 0;
	int len = 10;
	int nbr_caracter;
	
	nbr_caracter = getchar();
	saisie = (char*) malloc(len*sizeof(char));
	if (saisie == NULL){
		return NULL;
	}
	while( ! isspace(nbr_caracter)){
		if(len==i){
			len+=10;
			saisie = (char*) realloc(saisie, len*sizeof(char));
			if (saisie == NULL){
				return NULL;
			}
		}
		saisie[i]=nbr_caracter;
		i++;
		nbr_caracter=getchar();
	}
	saisie = (char*) realloc (saisie, (i+1)*sizeof(char));
	saisie[i] = '\0';
	//f = strlen(saisie);
	//printf("Il y a %d caracteres.",f);		
	return saisie;
}