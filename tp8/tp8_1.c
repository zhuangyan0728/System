/**************
 * Tp 8 =)
 * Nicolas Mauger 18/12/15
 * ***********/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "tp8_1.h"

int main(/*  char ** args  */) {
    affiche_prompt();
    return 0;
}

void affiche_prompt() {
    char hostname[50];
    char isme[1024];
    /* hostname[49] = '\0';*/
    isme[1023] = '\0';
    /* gethostname ne marche pas en ansi */
    gethostname(hostname, 50);
    getcwd(isme, 1023);
    printf("%s@%s %s $ ",getenv("USER"),hostname,isme);  
}

void execute_ligne_commande() {
   /* I must use the execvp function */
    execvp(,ligne_commande())
}
