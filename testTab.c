#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h> 

//#include "struktury.h"
#include "postaci.h"

int main(){
    srand(time(NULL)); //ziarno losu ;)




    postac_t **postaci;
    postaci = (postac_t**)malloc(3*sizeof(postac_t*));
    char str[25];
    char str2[50];
    char ork[50];
    char ogr[50];
    int index = 0;
    strcpy(ork, "Ork ");
    strcpy(ogr, "Ogr ");
    postac_t *wrogowie = (postac_t*)malloc(3*sizeof(postac_t));


    for(int i=0; i<3; i++){
        
        postac_t p1 = {.sila = rand()%100+1};

        wrogowie[i] = p1; 
        wrogowie[i].nazwa = (char*)malloc(100*sizeof(char));
        strcpy(wrogowie[i].nazwa, ogr);     
        strcpy(wrogowie[i].nazwa2, ork);
        snprintf(str2, sizeof(str2),"%d", i);
        strcat(wrogowie[i].nazwa, str2);
        strcat(wrogowie[i].nazwa2, str2);
        
        printf("wrog: %s o sile %d \t" , wrogowie[i].nazwa2, wrogowie[i].sila);
        printf("wrog: %s o sile %d \t" , wrogowie[i].nazwa, wrogowie[i].sila);
        puts(" ");

    }

    free(wrogowie);


    
    index = 0;
    
    for(int i=0; i<3;i++){

        postaci[i] = (postac_t*)malloc(6*sizeof(postac_t));
        printf("\nwiersz %d \n", i);
        for(int j=0; j< 6; j++){            

            postac_t p={.sila = rand()%100+1};

            strcpy(p.nazwa2, "Ork ");
            snprintf(str, sizeof(str), "%d", index++);
            strcat(p.nazwa2, str);
            postaci[i][j] = p;

            printf("\tpostac %s o sile: %d",postaci[i][j].nazwa2, postaci[i][j].sila);
        }
        puts(" ");
        
    }

    for(int i=0; i<3; i++) free(postaci[i]); //zwolnienie wierszy
    free(postaci); //zwolnienie tablicy
    return 0;
}
