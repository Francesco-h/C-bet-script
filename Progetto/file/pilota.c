#include "headers.h"
//fatto
int assegna_nome_pilota(pilota* pilo, char name[]){
	if(pilo==NULL) return 1;
	strcpy((*pilo)->nome,name);
	return 0;
}

int assegna_valutazione(pilota* pilo, int valutazione){
	int test;
	if(pilo==NULL) return 1;
	(*pilo)->val_vittoria=valutazione;
	return 0;
}

int crea_pilota(pilota* pilot, char name[], int valutazione){
	int test;
	pilota pilo;
	pilo=(pilota)malloc(sizeof(struct pilota));
	if(pilo==NULL) return 1;
	test=assegna_nome_pilota(&pilo,name);
	if(test==1) return 1;
	test=assegna_valutazione(&pilo,valutazione);
	if(test==1) return 1;
	(*pilot)=pilo;
	return 0;
}

void stampa_pilota(pilota pilo){
	if(pilo==NULL) return;
	printf("\n\tnome: %s \t\t quota: %i\n",pilo->nome,pilo->val_vittoria);
}

int elimina_pilota(pilota* pilo){
	pilota q;
	q=(*pilo);
	if(q==NULL) return 1;
	free(q);
	return 0;
}

int scrivi_piloti_schedine_file(pilota* pil,FILE* file){
	pilota r;
	r=(*pil);
	fprintf(file,"%s %d ",r->nome,r->val_vittoria);
	return 0;
}


int leggi_piloti_schedina_file(pilota* pil,FILE* file){
	pilota r;
	r=(pilota)malloc(sizeof(struct pilota));
	fscanf(file,"%s %d ",&r->nome,&r->val_vittoria);
	(*pil)=r;
	return 0;
}
