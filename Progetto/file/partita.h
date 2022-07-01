#ifndef partita_h
#define partita_h
#include <stdio.h>
struct partita{
	char squadra_1[4];
	char squadra_2[4];
	float val_1,val_2,val_x;
};

typedef struct partita* partita;

int crea_partita(partita* partita,char squadra1[],char squadra2[],float val1,float val2,float valx);
int assegna_nomi_squadre(partita* partita,char squadra1[],char squadra2[]);
int assegna_quote(partita* partita, float val1,float val2,float valx);
int cancella_partita(partita* partita);
void stampa_partita(partita partita);
int scrivi_partita_schedine_file(partita* part,FILE* file);
int leggi_partita_schedina_file(partita* part,FILE* file);

#endif
