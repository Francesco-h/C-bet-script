#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "campionato.h"
#include "partite.h"
#include "partita.h"
#include "schedinacalcio.h"

int crea_schedina_calcio(schedina_calcio* schedina_cal){
	*schedina_cal=NULL;
	return 0;
}

int destroy_schedina(schedina_calcio* sched){
	schedina_calcio p;
	while(*sched != NULL){
        	p = *sched;
        	cancella_partita(&(*sched)->partita_giocata);
        	*sched = (*sched)->next;
        	free(p);
    }	
}

void stampa_schedina(schedina_calcio schedina_calcio,float puntata){
	float vincita=1;
	if(schedina_calcio==NULL)return ;
	while(schedina_calcio!=NULL){
		vincita=vincita*(schedina_calcio->giocata);
		stampa_partita(schedina_calcio->partita_giocata);
		schedina_calcio=schedina_calcio->next;
	}
	
	printf("\n\n\tpuntata=%.2f \n\tvincita= %.2f\n",puntata,vincita*puntata);
}

int inserisci_schedina(schedina_calcio* schedina_calc,partita par,float valore){
	if (schedina_calc==NULL)return 1;
	int test;
	schedina_calcio p;
	schedina_calcio new_schedina_calcio;
	new_schedina_calcio= (schedina_calcio)malloc(sizeof(struct schedina_calcio));
	if (new_schedina_calcio==NULL)return 1;
	
	crea_partita(&(new_schedina_calcio->partita_giocata),par->squadra_1,par->squadra_2,par->val_1,par->val_2,par->val_x);
	
	new_schedina_calcio->giocata = valore;
	new_schedina_calcio->next= NULL;
	if(*schedina_calc==NULL){
		*schedina_calc=new_schedina_calcio;
		return 0;
	}
	
	p=*schedina_calc;
	while(p->next != NULL)
		p = p -> next;
	
	p->next = new_schedina_calcio;
	return 0;
}

int rimuovi_schedina_calcio(schedina_calcio* schedina_calc,char squad[]){
	if (schedina_calc==NULL)return 1;
	schedina_calcio q = *schedina_calc;
	schedina_calcio r = *schedina_calc;
	while((q != NULL) && (strcmp(squad,q->partita_giocata->squadra_1))){
		r = q;
		q = q->next;
	}
	if (q == NULL){
		printf("non esiste\n");
		return 0;
	}	
	if (q == *schedina_calc){
		(*schedina_calc) = (*schedina_calc) -> next;
	}
	else
		r -> next = q -> next;
        cancella_partita(&q->partita_giocata);
	free(q);
	return 0;	
}

int scrivi_schedina_file(schedina_calcio* schedc){
	schedina_calcio r;
	r = *schedc; 
	FILE* file;
	FILE* file1;
	if((file = fopen("file/saves/schedinacalcio.bin","w"))==NULL){
    		printf("\nerrore nell'apertura del file\n");
    		return 1;
    	}
    	if((file1 = fopen("file/saves/partite_schedina.bin","w"))==NULL){
    		printf("\nerrore nell'apertura del file\n");
    		return 1;
    	}
	while(r != NULL){
		fprintf(file,"%f ",r->giocata);
		scrivi_partita_schedine_file(&(r->partita_giocata),file1);
		r = r->next;
	}
	if (fwrite != 0){
		fclose(file);
		fclose(file1);
		return 0;
	}
	else{
		fclose(file);
		fclose(file1);
		return 1;
	}



}

int leggi_schedina_calcio_file(schedina_calcio* sched){
	int test;
	float gioc;
	FILE* file;
	FILE* file1;
	if((file=fopen("file/saves/schedinacalcio.bin","r"))==NULL){
		printf("\n errore nell'apertura del file\n");
		return 0;
	}
	
	if((file1=fopen("file/saves/partite_schedina.bin","r"))==NULL){
		printf("\n errore nell'apertura del file\n");
		return 0;
	}
	
	schedina_calcio p;
	schedina_calcio new_sched;
	
	
	while((fscanf(file,"%f ",&gioc)) != EOF){
	
	new_sched =(schedina_calcio)malloc(sizeof(struct schedina_calcio));
 	if(new_sched == NULL)return 1;
 	
	new_sched->giocata=gioc;
 	
	test=leggi_partita_schedina_file(&(new_sched->partita_giocata),file1);
	if(test==1) return 1;
	 	
 	new_sched->next = NULL;
 	if(*sched == NULL){
 		(*sched)=new_sched;
	 }
	else{
		p=*sched;
		while(p -> next != NULL)
			p = p -> next;
		p->next=new_sched;
		}
	}
	fclose(file1);
	fclose(file);
	return 0;
	
 }



 

