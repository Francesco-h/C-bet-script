#ifndef schedinacalcio_h
#define schedinacalcio_h
#include "partita.h"

struct schedina_calcio{
	partita partita_giocata;
	float giocata;
	struct schedina_calcio* next;
};

typedef struct schedina_calcio* schedina_calcio;


int inserisci_schedina(schedina_calcio* schedina_calcio,partita par,float valore);
int crea_schedina_calcio(schedina_calcio* schedina_calcio);
int rimuovi_schedina_calcio(schedina_calcio* schedina_calcio,char squadra1[]);
int destroy_schedina(schedina_calcio* schedina_calcio);
void stampa_schedina(schedina_calcio schedina_calcio,float puntata);
int scrivi_schedina_file(schedina_calcio* schedc);
int leggi_schedina_calcio_file(schedina_calcio* sched);

#endif
