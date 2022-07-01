#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "partita.h"
#include "schedinacalcio.h"


int assegna_nomi_squadre(partita* part,char squadra1[],char squadra2[]){
		if ((*part)==NULL) return 1;
		strcpy((*part)-> squadra_1,squadra1);
		strcpy((*part)-> squadra_2,squadra2);
		return 0;
}

int assegna_quote(partita* part,float val1,float val2,float valx){
	if (part==NULL) return 1;
	(*part)->val_1=val1;
	(*part)->val_x=valx;
	(*part)->val_2=val2;
	return 0;
}

int crea_partita(partita* part,char squadra1[],char squadra2[],float val1,float val2,float valx){
	int test;
	partita new_part;
	new_part=(partita)malloc(sizeof(struct partita));
	if (new_part == NULL) return 1;
	test=assegna_nomi_squadre(&new_part,squadra1,squadra2);
	if(test==1) return 1;
	test=assegna_quote(&new_part,val1,val2,valx);	
	if(test==1) return 1;
	(*part)=new_part;
	return 0;
}

int cancella_partita(partita* part){
	if(part==NULL)return 1;
	partita q = (*part);
	free(q);
	return 0;	
	
}

void stampa_partita(partita part){
	printf("\n\t%s - %s \n1- %.2f    x- %.2f    2- %.2f",part->squadra_1,part->squadra_2,part->val_1,part->val_x,part->val_2);
}

int scrivi_partita_schedine_file(partita* part,FILE* file){
	partita r;
	r= *part;
	fprintf(file,"%s %s %f %f %f ",r->squadra_1,r->squadra_2,r->val_1,r->val_2,r->val_x);
	return 0;
}

int leggi_partita_schedina_file(partita* part, FILE* file){
	partita r;
	r=(partita)malloc(sizeof(struct partita));
	fscanf(file,"%s %s %f %f %f ",&r->squadra_1,&r->squadra_2,&r->val_1,&r->val_2,&r->val_x) ;
	(*part) = r;
	return 0;
}
 




