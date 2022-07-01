#ifndef campionato_h
#define campionato_h
#include "schedinacalcio.h"
#include "headers.h"
struct campionato{
	char nome_campionato[20];
	partite lista_partite;
	struct campionato* next;
};
typedef struct campionato* campionato;

int inserisci_campionato(campionato* campio,char nome[]);
int crea_campionato(campionato* campionato);
void stampa_campionato(campionato campionato);
int cancella_campionato(campionato* campio,char nome[]);
int destroy_campionato(campionato* campio);
int inserisci_partite_post(campionato* camp,float val1,float val2,float valx, char squadra1[],char squadra2[],char nome[]);
int rimuovi_partite_post(campionato* camp,char nome_c[],char nome_s[]);
int modifica_nome_squad(campionato* camp,char sq1[],char sq2[],char sqc[],char nome_c[]);
int modifica_quote_squad(campionato* camp,char sq1[],char nome_c[],float val1, float val2, float valx);
int destroy_partite_post(campionato* camp,char nome_c[]);
void stampa_campionato_nomi(campionato campio);
int inserire_scommessa_calcio(campionato* camp,schedina_calcio* sched,char nome_camp[],char gioc,char nome_sq[]);
int stampa_campionato_partite(campionato campio,char nome_camp[]);
int scrivi_campionato_file(campionato* camp);
int leggi_campionato_file(campionato* camp);

#endif
