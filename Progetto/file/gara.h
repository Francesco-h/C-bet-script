#ifndef GARA_H
#define GARA_H
#include "headers.h"

struct gara{
	char nome_gp[20];
	piloti piloti_gara;
	struct gara* next;
};

typedef struct gara* gara;

int crea_gara(gara* gara);
int inserisci_gara(gara* gara,char nome[]);
int elimina_gara(gara* gara,char nome[]);
int destroy_gara(gara* gara);
void stampa_gara(gara gara);
int inserisci_pilota_post(gara* race,char nome_race[],char nome_pil[],int val);
int rimuovi_pilota_post(gara* race,char nome_race[],char nome_pil[]);
int modifica_pilota_valutazione(gara* race,char nome_race[],char nome_pil[],int val);
int modifica_pilota_nome(gara* race,char nome_race[],char nome_pil[],char nuovo_nome[]);
int destroy_ricerca(gara* race,char nome_race[]);
void stampa_gara_nomi(gara gara);
void stampa_gara_piloti(gara race,char nome_gp[]);
int inserire_scommessa_f1(gara* race,schedina_f1* schedf1,char nome_gp[],char nome_pil[]);
int scrivi_gara_file(gara* race);
int leggi_gara_file(gara* race);

#endif

