#include<stdio.h>
#include<stdlib.h>
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
    char *opis;
    stan_lokalizacji stan;
    lokalizacja_t *zachod;
    lokalizacja_t *wschod;
    lokalizacja_t *poludnie;
    lokalizacja_t *polnoc;
    int liczbaSasiadow;
    lokalizacja_t **sasiedzi;

};

struct postac_t{
    char *nazwa;
    char nazwa2[100];
    lokalizacja_t aktualna_pozycja;
    char opis[500];

    char plik[100];
    int walka;
    int sila;
    int wytrzymalosc;
    int zywotnosc;
    
};

