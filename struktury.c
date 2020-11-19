#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "struktury.h"

/*
typedef enum stan_lokalizacji stan_lokalizacji;
enum stan_lokalizacji{
    NIEODWIEDZONA,
    POWALCE,
    ODWIEDZONA
};


typedef struct lokalizacja_t lokalizacja_t;
typedef struct punkt_t punkt_t;
typedef struct postac_t postac_t;

struct punkt_t{
    int x;
    int y;
};

struct lokalizacja_t{
    punkt_t punkt;
    char *nazwa;
    stan_lokalizacji stan;

};

struct postac_t{
    char *nazwa;
    lokalizacja_t aktualna_pozycja;
    char opis[200];
    char plik[100];
};

/*

PROGRAM GLOWYN

================================*/

int main(){
    int ch;
    char buff[3][500];
    char buffer[500];
   // char calyopis[1500];
    char *calyopis=(char *)malloc(1500 * sizeof(char));

    /*------------------------------------

    Tworzenie 'obiektow' struktur lokalizacja_t,
    punkt_t, 

    -------------------------------------*/
    lokalizacja_t lazienka = {.stan=NIEODWIEDZONA, 
    .nazwa = "Lazienka"};
    punkt_t p_hol = {.x = 124, .y = 12}; punkt_t p_wych = {.x = 14, .y = 129};
    lokalizacja_t hol = {.nazwa = "Hol", .stan=NIEODWIEDZONA, .punkt = p_hol};
    lokalizacja_t wychodek = {.nazwa = "Wychodek", .stan=NIEODWIEDZONA, .punkt = p_wych};
    if(lazienka.stan == NIEODWIEDZONA){
        printf("=========Stan lokalizacji %d=========\n", lazienka.stan);
    }
    punkt_t p; p.x =7; p.y=9;
    punkt_t p2; p2.x =17; p2.y=91;

    lazienka.punkt = p;
    lazienka.zachod = &hol;
    hol.wschod = &lazienka;
    printf("Na zachod od %s jest %s\n", lazienka.nazwa, lazienka.zachod->nazwa);

    //proba stworzenia tablicy sasiadow i zapelnienia jej, lazienka.sasiedzi to tablica z **
    lazienka.sasiedzi = (lokalizacja_t **)malloc(6);
    lazienka.sasiedzi[0] = &wychodek;
    printf("Na poludnie od %s jest %s w pozycji {%d;%d}\n", lazienka.nazwa, 
    lazienka.sasiedzi[0]->nazwa, lazienka.sasiedzi[0]->punkt.x, lazienka.sasiedzi[0]->punkt.y);
    /*
    Zrobic trzeba enum z kierunkami swiata, pozniej sasiadow w petli, i pierwsze cztery
    kierunki po enumie (0,1,2,3), tak zeby zawsze byly przypisane w pierwszej kolejnosci,
    a ewentualni inni sasiedzi od 4 wbijani.

    */

    free(lazienka.sasiedzi);

    //lazienka.nazwa = "Lazienka";
    punkt_t aktualny;

    lokalizacja_t aktualnaLok;

    aktualnaLok = *lazienka.zachod;
    
    aktualny = p;
    printf("AKTUALNY %d/%d\n",aktualny.x, aktualny.y);  
    //free(aktualny); //gdyby akturalny byl pointerem
    aktualny = p2;
    printf("AKTUALNY %d/%d\n",aktualny.x,aktualny.y);    
    stan_lokalizacji stan;
    stan= NIEODWIEDZONA;
    printf("%d\n", stan);
    
    /*------------------------------------

    Tworzenie 'obiektow' struktur postac_t

    -------------------------------------*/   

    postac_t ork; ork.aktualna_pozycja = aktualnaLok; ork.nazwa = "Ork";
    char *nazwa_pliku=(char *)malloc(100 * sizeof(char));
    //strcpy(nazwa_pliku, "");
    strcat(nazwa_pliku, ork.nazwa);
    strcat(nazwa_pliku, ".txt");
    printf("%s\n", nazwa_pliku);

    FILE *plik;
    plik = fopen(nazwa_pliku, "r");

    while(fgets(buffer, 500, plik)) {
        //printf("%s", buffer);

        strcat(calyopis,buffer);
}
/*
    for(int i =0; i<3;i++){
        fgets(buff[i], 200, (FILE*)plik);
        
        //printf("%s", buff[i]);
    }
*/
    puts("\n===============CALY OPIS====================");
    printf("%s\n",calyopis);
    puts("================KONIEC OPISU================");
    char *napis=(char *)malloc(100 * sizeof(char));

    strcpy(napis, buff[0]);
    
    free(nazwa_pliku);
    strcpy(ork.opis, calyopis);
    free(calyopis);
    free(napis);
    fclose(plik);
    printf("Aktualna lokalizacja: %s w punkcie {%d,%d}\n", aktualnaLok.nazwa, aktualnaLok.punkt.x, aktualnaLok.punkt.y);
    aktualnaLok = *hol.wschod;
    printf("Aktualna lokalizacja: %s w punkcie {%d,%d}\n", aktualnaLok.nazwa, aktualnaLok.punkt.x, aktualnaLok.punkt.y);
   
    
    printf("%s, %s Znajduje sie w %s pozycja:{%d,%d}", ork.nazwa, ork.opis, ork.aktualna_pozycja.nazwa, ork.aktualna_pozycja.punkt.x, ork.aktualna_pozycja.punkt.y);
    while((ch = getchar()) != '\n');
    return 0;

}