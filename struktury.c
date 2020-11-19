#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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

};

struct postac_t{
    char *nazwa;
    lokalizacja_t aktualna_pozycja;
    char opis[200];
    char plik[100];
};


int main(){
    int ch;
    char buff[3][500];
    char buffer[500];
   // char calyopis[1500];
    char *calyopis=(char *)malloc(1500 * sizeof(char));
    lokalizacja_t lazienka;
    punkt_t p; p.x =7; p.y=9;
    lazienka.punkt = p;
    lazienka.nazwa = "Lazienka";
    
    stan_lokalizacji stan;
    stan= NIEODWIEDZONA;
    printf("%d\n", stan);
    
   

    postac_t ork; ork.aktualna_pozycja = lazienka; ork.nazwa = "Ork";
    char *nazwa_pliku=(char *)malloc(100 * sizeof(char));
    strcpy(nazwa_pliku, "");
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
    printf("%s w punkcie {%d,%d}\n", lazienka.nazwa, lazienka.punkt.x, lazienka.punkt.y);
    printf("%s, %s Znajduje sie w %s pozycja:{%d,%d}", ork.nazwa, ork.opis, ork.aktualna_pozycja.nazwa, ork.aktualna_pozycja.punkt.x, ork.aktualna_pozycja.punkt.y);
    while((ch = getchar()) != '\n');
    return 0;

}