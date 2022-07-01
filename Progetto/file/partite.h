#ifndef partite_h
#define partite_h
#include "campionato.h"
#include <stdio.h>
struct partite{
	partita par;
	struct partite* next;
};
typedef struct partite* partite;


int inserisci_partite(partite* partite,char squadra1[],char squadra2[],float val1,float val2,float valx);
int crea_partite(partite* partite);
void stampa_partite(partite partite);
int cancella_partite(partite* partite,char squadra1[]);
int destroy_partite(partite* partite);
int scrivi_partite_file(partite* par,FILE* file);
int inserisci_partite_file(partite* part, FILE* file);

#endif
