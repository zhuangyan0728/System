/**********************
* TP N◦ 4 – Allocation dynamique & arguments de la ligne de commande
* Nicolas MAUGER
* 25/09/15
***********************/

#include <stdio.h>                                                             
//#include "malloc.h"                                                            
#include <string.h>                                                            
#include <stdlib.h>                                                            
                                                                               
int main(int argc, char * argv[]){                                             
	                                                                              
	int i;                                                                        
	int m=0;                                                                      
	int s=0;                                                                      
	int error=0;                                                                  
	int arg;                                                                      
	                                                                              
	if (argc <2){                                                                 
		printf("Pas assez d'arguments! \n");                                           
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
                                         
			printf("Mauvaise utilisation \n");                                          
		}		                                                                          
		else if (m==1 && s==0){                                                      
			if (arg==0 || arg >1){                              
				printf("Mauvaise utilisation \n");                                         
			}                                                                           
			else{                                                                       
				for (i=1; i<argc; i++){                                                    
					if(argv[i][0]!='-' && error==0){                                          
						char * mir = miroir(argv[i]);                                            
						printf("%s \n",mir);                                                     
						error=1;                                                                 
					}                                                                         
					else if (error==1){                                                            
						printf("Mauvaise utilisation \n");                                       
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
				printf("Mauvaise utilisation \n");                                         
			}                                                                           
		}                                                                            
	}                                                                             
	return 0;                                                                     
}  
