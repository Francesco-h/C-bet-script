#include "headers.h"
//fatto
int crea_gara(gara* gara){
	*gara=NULL;
	return 0;
}

int inserisci_gara(gara* race,char nome[]){
	srand(time(NULL));
	int test,valore;
	gara p;
	gara new_gara = (gara)malloc(sizeof(struct gara));
	if (new_gara == NULL) return 1;
	
	test=crea_piloti(&(new_gara->piloti_gara));
	if (test==1) return 1;
	
	
	new_gara->next=NULL;
	strcpy(new_gara->nome_gp,nome);
	if(*race==NULL){
 		*race=new_gara;
 		return 0;
	 }

	 p=*race;
	 while(p->next != NULL)
		p = p->next;

	p->next=new_gara;
	return 0;
	
}

void stampa_gara(gara race){
	while(race != NULL){
		printf("\n\t\tgara :%s",race->nome_gp);
		printf("\n");
		stampa_piloti(race->piloti_gara);
		race=race->next;
	}	
}



void stampa_gara_piloti(gara race,char nome_race[]){
	gara p;
	p = race;
	while(p != NULL && strcmp(p->nome_gp,nome_race)){
		p=p->next;		
	}
	if(p==NULL){
		printf("\ngara non trovata\n");
		return;
	}
	stampa_piloti(p->piloti_gara);
	return ;
}


void stampa_gara_nomi(gara race){
	int i=1;
	printf("\n");
	while(race != NULL){
		printf("\n%d)%s",i,race->nome_gp);
		i++;
		race=race->next;
	}	
	printf("\n");
}


int destroy_gara(gara* race){
    while(*race != NULL){
        gara p = *race;
        destroy_piloti(&((*race)->piloti_gara));
        *race = (*race)->next;
        free(p);
    }
} 
 

int elimina_gara(gara* race,char nome[]){
	if(race == NULL) return 1;
	gara q = *race;
 	gara r = *race;
 	while((q != NULL) && (strcmp(nome,q->nome_gp))){
 		r = q;
		q = q->next;
 	}
 	if (q == NULL){
		printf("non esiste");
		return 0;
	}
	if (q == *race){
		(*race) = (*race) -> next;
	}
	else
		r -> next = q -> next;
	destroy_piloti(&(q->piloti_gara));
	free(q);
	return 0;
}


int inserisci_pilota_post(gara* race,char nome_race[],char nome_pil[],int val){
	int test;
	if (race==NULL) return 1;
	gara r;
	r = *race;
	while( (r != NULL) && strcmp((r->nome_gp),nome_race)){
		r=r->next;
	}
	if (r==NULL){
		printf("\nla gara non esiste\n");
		return 0;
	}
	test=aggiungi_piloti(&(r->piloti_gara),nome_pil,val);
	if (test==1)
		return 1;
	return 0;
}


int rimuovi_pilota_post(gara* race,char nome_race[],char nome_pil[]){
	int test;
	if (race==NULL) return 1;
	gara r;
	r = *race;
	while( (r != NULL) && strcmp((r->nome_gp),nome_race)){
		r=r->next;
	}
	if (r==NULL){
		printf("\nla gara non esiste\n");
		return 0;
	}
	test=elimina_piloti(&(r->piloti_gara),nome_pil);
	if (test==1) 
		return 2;
	return 0;

}


int modifica_pilota_valutazione(gara* race,char nome_race[],char nome_pil[],int val){
	int test;
	if (race==NULL) return 1;
	gara r;
	r = *race;
	piloti f;
	while( (r != NULL) && strcmp((r->nome_gp),nome_race)){
		r=r->next;
	}
	if (r==NULL){
		printf("\nla gara non esiste\n");
		return 0;
	}
	f= r->piloti_gara;
	while(f != NULL && strcmp((f->pil->nome),nome_pil)){
		f=f->next;
	}
	if (f==NULL){
		printf("\npilota non esiste\n");
		return 0;
	}
	
	test=assegna_valutazione(&(f->pil),val);
	if(test==1)
		return 1;
	return 0;

}


int modifica_pilota_nome(gara* race,char nome_race[],char nome_pil[],char nuovo_nome[]){
	int test;
	if (race==NULL) return 1;
	gara r;
	r = *race;
	piloti f;
	while( (r != NULL) && strcmp((r->nome_gp),nome_race)){
		r=r->next;
	}
	if (r==NULL){
		printf("\nla gara non esiste\n");
		return 0;
	}
	f= r->piloti_gara;
	while(f != NULL && strcmp((f->pil->nome),nome_pil)){
		f=f->next;
	}
	if (f==NULL){
		printf("\npilota non esiste\n");
		return 0;
	}
	
	test=assegna_nome_pilota(&(f->pil),nuovo_nome);

	if(test==1)
		return 1;
	return 0;

}


int destroy_ricerca(gara* race,char nome_race[]){
	int test;
	if (race==NULL) return 1;
	gara r;
	r = *race;
	piloti f;
	while( (r != NULL) && strcmp((r->nome_gp),nome_race)){
		r=r->next;
	}
	if (r==NULL){
		printf("\nla gara non esiste\n");
		return 0;
	}
	test=destroy_piloti(&(r->piloti_gara));
	if (test==1) 
		return 1;
	return 0;

}


int inserire_scommessa_f1(gara* race,schedina_f1* schedf1,char nome_gp[],char nome_pil[]){
	int test;
	gara p;
	piloti f;
	p = *race;
	while(p != NULL && strcmp(p->nome_gp,nome_gp)){
		p=p->next;		
	}
	if(p==NULL){
			
		printf("\ngara non trovata\n");
		return 0;
	}
	f=p->piloti_gara;
	while(f != NULL && strcmp(f->pil->nome,nome_pil)){
		f=f->next;
	}
	if(f==NULL){
		printf("\npilota non trovato\n");
		return 0;
	}
	test=aggiungi_schedina_f1(schedf1,f->pil->val_vittoria,f->pil);
	if(test==1)
		return 1;
	return 0;
}
	
	
int scrivi_gara_file(gara* race){
	int test;
	FILE* file;
	FILE* file1;
	if((file=fopen("file/saves/gara.bin","w")) == NULL){
		printf("\nerrore nell'apertura del file\n");
		return 1;
	 }
	 if((file1=fopen("file/saves/piloti.bin","w")) == NULL){
		printf("\nerrore nell'apertura del file\n");
		return 1;
	 }
	 gara r;
	 r = (*race);
	 while(r != NULL){
		fprintf(file,"%s ", r->nome_gp);
		test=scrivi_piloti_file(&(r->piloti_gara),file1);
		if (test==1)
			return 1;
		r=r->next;
	 }
	fclose(file);
	fclose(file1);
}



int leggi_gara_file(gara* race){
	int test;
	char nom[20];
	FILE* file;
	FILE* file1;
	if((file=fopen("file/saves/gara.bin","r"))==NULL){
		printf("\n errore nell'apertura del file\n");
		return 0;
	}
	
	if((file1=fopen("file/saves/piloti.bin","r"))==NULL){
		printf("\n errore nell'apertura del file\n");
		return 0;
	}
	
	gara p;
	gara new_gara;
	
	
	while(fscanf(file,"%s",&nom) != EOF){
	
	new_gara =(gara)malloc(sizeof(struct gara));
 	if(new_gara == NULL)return 1;
 	
 	strcpy(new_gara->nome_gp,nom);
 	
 	test=crea_piloti(&new_gara->piloti_gara);
 	if(test==1)return 1;
 	
	test=inserisci_piloti_file(&new_gara->piloti_gara,file1);
	if(test==1) return 1;
	 	
 	new_gara->next = NULL;
 	if(*race == NULL){
 		(*race)=new_gara;
	 }
	else{
		p=*race;
		while(p -> next != NULL)
			p = p -> next;
		p->next=new_gara;
		}
	}
	fclose(file1);
	fclose(file);
	return 0;
	
 }




