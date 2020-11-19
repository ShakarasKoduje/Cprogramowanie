#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h> 
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

void WypiszSasiadow(const lokalizacja_t);

int main(){
    srand(time(NULL)); //ziarno losu ;)
    int ch;
    char buff[3][500];
    char buffer[500];
   // char calyopis[1500];
    char *calyopis=(char *)malloc(1500 * sizeof(char));
    enum kierunki kierunek;
    kierunek = ZACHOD;
    //kierunek = 9;
    switch (kierunek)
    {
    case ZACHOD:
        printf("Kierunek to Zachod %d\n", kierunek);
        break;
    case 9:
        printf("Kierunek to Loch %d\n", kierunek);
        break;    
    default:
        break;
    }

    /*------------------------------------

    Tworzenie 'obiektow' struktur lokalizacja_t,
    punkt_t, 

    -------------------------------------*/
    punkt_t aktualny;
    lokalizacja_t aktualnaLok;
    
    lokalizacja_t lazienka = {.stan=NIEODWIEDZONA, .nazwa = "Lazienka"};
    lazienka.liczbaSasiadow = 6;
    punkt_t p_hol = {.x = 124, .y = 12}; punkt_t p_wych = {.x = 14, .y = 129};
    lokalizacja_t hol = {.nazwa = "Hol", .stan=NIEODWIEDZONA, .punkt = p_hol};
    lokalizacja_t wychodek = {.nazwa = "Wychodek", .stan=NIEODWIEDZONA, .punkt = p_wych};
    punkt_t p_pok = {.x = 7, .y = 7};
    lokalizacja_t pokoj = {.nazwa = "pokoj", .stan=NIEODWIEDZONA, .punkt = p_pok};
    punkt_t p_syp = {.x = 1, .y = 9};
    lokalizacja_t sypialnia = {.nazwa = "sypialnia", .stan=NIEODWIEDZONA, .punkt = p_syp};
    punkt_t p_skl = {.x = 0, .y = 12};
    lokalizacja_t skladzik = {.nazwa = "skladzik", .stan=NIEODWIEDZONA, .punkt = p_skl};
    if(lazienka.stan == NIEODWIEDZONA){
        printf("=========Stan lokalizacji %d=========\n", lazienka.stan);
    }
    punkt_t p; p.x =7; p.y=9;
    punkt_t p2; p2.x =17; p2.y=91;

    lazienka.punkt = p;
    lazienka.zachod = &hol;
    lazienka.polnoc = &hol;
    lazienka.poludnie = &wychodek;
    hol.wschod = &lazienka;
    printf("Na zachod od %s jest %s\n", lazienka.nazwa, lazienka.zachod->nazwa);

    //proba stworzenia tablicy sasiadow i zapelnienia jej, lazienka.sasiedzi to tablica z **

    lazienka.sasiedzi = (lokalizacja_t **)malloc(lazienka.liczbaSasiadow * sizeof(lokalizacja_t *));
    int i = 0;
    lazienka.sasiedzi[i] = lazienka.zachod; 
    int rozmiar = sizeof(*lazienka.sasiedzi)/sizeof(lazienka.sasiedzi[0]);
    printf("ROZMIAR TABLICY: %d\n", rozmiar);
    i++;
    lazienka.sasiedzi[i] = lazienka.poludnie;
    i++;
    lazienka.sasiedzi[i] = lazienka.polnoc;
    i++;
    lazienka.sasiedzi[i] = &pokoj;
    i++;
    lazienka.sasiedzi[i] = &sypialnia;
    i++;
    lazienka.sasiedzi[i] = &skladzik;    

   
   int wybor = 0; 


    while(1){
        WypiszSasiadow(lazienka);
        scanf("%d", &wybor); while((ch = getchar())!= '\n');
        if(wybor<lazienka.liczbaSasiadow) {
            printf("Poszedles do %d\n", wybor);
            getchar();
            printf("Poszedles do %s\n", lazienka.sasiedzi[wybor]->nazwa);
            lazienka.sasiedzi[wybor]->stan = ODWIEDZONA;
            //getchar();
            system("clear");
            break;
        }
        else if(wybor == lazienka.liczbaSasiadow){
            printf("Pozostales w %s\n", lazienka.nazwa);
            getchar();
            system("clear");
            break;            
        }
        //getchar();
        system("clear");
    }


    //aktualnaLok = *lazienka.zachod;
    if(wybor < 6){
        aktualnaLok = *lazienka.sasiedzi[wybor];
    }else{
        aktualnaLok = lazienka;
    }
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
    ork.walka = 35;
    ork.sila = 4;


    /*-------------------------------------

    Operacja na pliku z opisem (testowe)
    opis zawarty w pliku przypisywany do 
    zmiennej z nazwa postaci (w tym wypadku orka);

    -------------------------------------*/
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
    free(lazienka.sasiedzi);
    printf("Aktualna lokalizacja: %s w punkcie {%d,%d}\n", aktualnaLok.nazwa, aktualnaLok.punkt.x, aktualnaLok.punkt.y);
    //aktualnaLok = *hol.wschod;
    //printf("Aktualna lokalizacja: %s w punkcie {%d,%d}\n", aktualnaLok.nazwa, aktualnaLok.punkt.x, aktualnaLok.punkt.y);
   
    int rzut = rand()%100 +1;
    printf("\tWynik testu: %d\n", rzut);   
    int dziesiatki = (ork.walka/10 - rzut/10);
    printf("DZIESIATKI: %d\n", dziesiatki);
    if (rzut <= ork.walka){
        printf("ORK sila: %d przywalil za: %d\n", ork.sila, ork.sila+dziesiatki);
    }

    printf("%s, %s\n, ktory ma walke i %d: %s Znajduje sie w %s pozycja:{%d,%d}", ork.nazwa, ork.opis, 
                    ork.walka, (rzut <= ork.walka) ? "TRAFIL!" : "CHYBIL",
                    ork.aktualna_pozycja.nazwa, 
                    ork.aktualna_pozycja.punkt.x,ork.aktualna_pozycja.punkt.y);
    while((ch = getchar()) != '\n');
    return 0;

}

void WypiszSasiadow(const lokalizacja_t t){
    
    puts("Dokad sie udajesz? ...");
    for(int j = 0;j<t.liczbaSasiadow+1 ;j++){   
        if(j<t.liczbaSasiadow){
            printf("%d : do %s {%d;%d}\n", j, t.sasiedzi[j]->nazwa, 
                                                        t.sasiedzi[j]->punkt.x, 
                                                    t.sasiedzi[j]->punkt.y);
            }
        else{
            printf("%d : Pozostan na miejscu w %s\n", j, t.nazwa);
            }
        }

}