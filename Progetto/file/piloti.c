#include "headers.h"
//fatto


int crea_piloti(piloti* piloti){
	*piloti=NULL;
	return 0;	
}

 int elimina_piloti(piloti* pilo, char nome[]){
 	if(pilo == NULL) return 1;
	piloti q = (*pilo);
 	piloti r = (*pilo);
 	while((q != NULL) && (strcmp(nome,q->pil->nome))){
 		r = q;
		q = q->next;
 	}
 	if (q == NULL){
		printf("non esiste\n");
		return 0;
	}
	if (q == *pilo){
		(*pilo) = (*pilo) -> next;
	}
	else
		r -> next = q -> next;
	elimina_pilota(&(q->pil));
	free(q);
	return 0;
}



int aggiungi_piloti(piloti* pilo,char name[],int val){
	int test;
	piloti p;
	piloti new_piloti;
	new_piloti =(piloti)malloc(sizeof(struct piloti));
 	if(new_piloti == NULL)return 1;
 	
 	test=crea_pilota(&(new_piloti->pil),name,val);
 	if(test==1)return 1;
    
	new_piloti->next = NULL;
 
	 if((*pilo)==NULL){
 		(*pilo)=new_piloti;
 		return 0;
	 }

	 p=*pilo;
	 while(p->next != NULL)
		p = p->next;

	p->next=new_piloti;
	return 0;
}

int destroy_piloti(piloti* pilo){
	if(pilo==NULL) return 1;
	while(*pilo != NULL){
        	piloti p = *pilo;
        	elimina_pilota(&((*pilo)->pil));
        	*pilo = (*pilo)->next;
        	free(p);
	}
	return 0;
}

void stampa_piloti(piloti pilo){
	
	
	while(pilo != NULL){
		stampa_pilota(pilo->pil);
		pilo=pilo->next;
	}
}

int scrivi_piloti_file(piloti* pilo, FILE* file){
	piloti r;
	r=(*pilo);
	while(r != NULL){
		fprintf(file,"%s %d ",r->pil->nome,r->pil->val_vittoria);
		r=r->next;
	}
	return 0;
}


int inserisci_piloti_file(piloti* pilo,FILE* file){
	int i=0,test;	
	char nome[10];
	int val;
	piloti p;
	piloti new_piloti;
	while(i<5 && (fscanf(file,"%s %d",&nome,&val) != EOF)){
		i++;
		new_piloti = (piloti)malloc(sizeof(struct piloti));
		if (new_piloti==NULL)return 1;
		test=crea_pilota(&new_piloti->pil,nome,val);
		if(test==1)return 1;
		new_piloti->next= NULL;
		if(*pilo==NULL){
			(*pilo)=new_piloti;
		}
		else{
		p=*pilo;
		while(p->next != NULL)
			p = p-> next;
		
		p->next = new_piloti;
		}
	}
	return 0;




}

