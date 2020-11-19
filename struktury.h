#include<stdio.h>
#include "enumy.h"
/*
typedef enum stan_lokalizacji stan_lokalizacji;
enum stan_lokalizacji{
    NIEODWIEDZONA,
    POWALCE,
    ODWIEDZONA
};
*/
/*=================== 
deklaracja struktur
====================*/
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