#include "headers.h"

int crea_schedina_f1(schedina_f1* schedina){
	(*schedina)=NULL;
	return 0;
}

int destroy_schedina_f1(schedina_f1* schedina){
	schedina_f1 p;
	while(*schedina != NULL){
        	p = *schedina;
        	elimina_pilota(&(p->pil));
        	*schedina = (*schedina)->next;
        	free(p);
    }
}

void stampa_schedina_f1(schedina_f1 schedina,float puntata){
	float vincita=1;
	if(schedina==NULL) return ;
	while(schedina != NULL){
		vincita=vincita*(schedina->quota);
		stampa_pilota(schedina->pil);
		schedina=schedina->next;
	}
	printf("\n\tpuntata : %.2f \n\tvincita= %.2f\n",puntata,vincita*puntata);
}

int aggiungi_schedina_f1(schedina_f1* schedina,int valore,pilota pilot){
	if (schedina==NULL)return 1;
	int test;
	schedina_f1 p;
	schedina_f1 new_schedina_f1 = (schedina_f1)malloc(sizeof(struct schedina_f1));
	if (new_schedina_f1==NULL)return 1;
	test=crea_pilota(&(new_schedina_f1)->pil,pilot->nome,pilot->val_vittoria);
	if(test==1) return 1;
	new_schedina_f1-> quota = valore;
	new_schedina_f1->next= NULL;
	if((*schedina)==NULL){
		(*schedina)=new_schedina_f1;
		return 0;
	}
	
	p=*schedina;
	while(p->next != NULL)
		p = p-> next;
	
	p->next = new_schedina_f1;
	return 0;
}

int elimina_schedina_f1(schedina_f1* schedina,char winner[]){
	if ((*schedina)==NULL)return 1;
	schedina_f1 q = (*schedina);
	schedina_f1 r = (*schedina);
	while((q != NULL) && (strcmp(winner,q->pil->nome))){
		r = q;
		q = q->next;
	}
	if (q == NULL){
		printf("non esiste\n");
		return 0;
	}	
	if (q == *schedina){
		(*schedina) = (*schedina)->next;
	}
	else
		r -> next = q -> next;
	elimina_pilota(&q->pil);
	free(q);
	return 0;	
}



int scrivi_schedina_f1_file(schedina_f1* sched){
	schedina_f1 r;
	r = *sched; 
	FILE* file;
	FILE* file1;
	if((file = fopen("file/saves/schedinaf1.bin","w"))==NULL){
    		printf("\nerrore nell'apertura del file\n");
    		return 1;
    	}
    	if((file1 = fopen("file/saves/piloti_schedina.bin","w"))==NULL){
    		printf("\nerrore nell'apertura del file\n");
    		return 1;
    	}
	while(r != NULL){
		fprintf(file,"%d ",r->quota);
		scrivi_piloti_schedine_file(&(r->pil),file1);
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



int leggi_schedina_f1_file(schedina_f1* sched){
	int test,gioc;
	FILE* file;
	FILE* file1;
	if((file=fopen("file/saves/schedinaf1.bin","r"))==NULL){
		printf("\n errore nell'apertura del file\n");
		return 0;
	}
	
	if((file1=fopen("file/saves/piloti_schedina.bin","r"))==NULL){
		printf("\n errore nell'apertura del file\n");
		return 0;
	}
	
	schedina_f1 p;
	schedina_f1 new_sched;
	
	
	while(fscanf(file,"%d ",&gioc) != EOF){
	
	new_sched =(schedina_f1)malloc(sizeof(struct schedina_f1));
 	if(new_sched == NULL)return 1;
 	
	new_sched->quota=gioc;
 	
	test=leggi_piloti_schedina_file(&(new_sched)->pil,file1);
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



 

