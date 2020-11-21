#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "postaci.h"

int main(){

    postac_t p;
    //p.nazwa2 = "Ork";
    //p.nazwa = (char*)malloc(100*sizeof(char));
    //strcpy(p.nazwa, "Ork ");
    strcpy(p.nazwa2, "Ork ");
    char *index;
    int liczba = 100;

    sprintf(index, "%d", liczba);
    strcat(p.nazwa2, index);
    //strcat(p.nazwa, index);
    printf("%s %s ", index, p.nazwa2);

    //free(p.nazwa);

    return 0;
}