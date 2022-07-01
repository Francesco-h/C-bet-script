#ifndef PILOTA_H
#define PILOTA_H

struct pilota{
	char nome[10];
	int val_vittoria;
};

typedef struct pilota* pilota;

int crea_pilota(pilota* pilota, char name[], int valutazione);
void stampa_pilota(pilota pilota);
int elimina_pilota(pilota* pilota);
int assegna_nome_pilota(pilota* pilota, char name[]);
int assegna_valutazione(pilota* pilota, int valutazione);
int scrivi_piloti_schedine_file(pilota* pil,FILE* file);
int leggi_piloti_schedina_file(pilota* pil,FILE* file);

#endif
