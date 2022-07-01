#include "headers.h"
//fatto
int crea_campionato(campionato* campionato){
	*campionato=NULL;
	return 0;
	
}

int inserisci_campionato(campionato* campio, char nome[]){
	int test;
	campionato p;
	campionato new_campionato;
	new_campionato =(campionato)malloc(sizeof(struct campionato));
 	if(new_campionato == NULL)return 1;
 	strcpy(new_campionato->nome_campionato, nome);
 	test=crea_partite(&new_campionato->lista_partite);
 	if(test==1)return 1;
	 	
 	new_campionato->next = NULL;
 	if(*campio == NULL){
 		(*campio)=new_campionato;
 		return 0;
	 }

	 p=*campio;
	 while(p -> next != NULL)
		p = p -> next;
	p->next=new_campionato;
	return 0;
 }
 
 void stampa_campionato(campionato campio){
 	campionato s;
 	s= campio;
 	while(s != NULL){
	 	printf("\n");
 		printf("\t%s",s->nome_campionato);
 		stampa_partite(s->lista_partite);
 		printf("\n");
 		s = s-> next;
	 } 
	 	
 }
 
 int cancella_campionato(campionato* campio, char nome[]){
 	if(campio == NULL) return 1;
	campionato q = (*campio);
 	campionato r = (*campio);
 	while((q != NULL) && (strcmp(nome,q->nome_campionato))){
 		r = q;
		q = q->next;
 	}
 	if (q == NULL){
		printf("\nnon esiste\n");
		return 0;
	}
	if (q == (*campio)){
		(*campio) = (*campio) -> next;
	}
	else
		r -> next = q -> next;
	destroy_partite(&q->lista_partite);
	free(q);
	return 0;
}
 

int destroy_campionato(campionato* campio){
    while(*campio != NULL){
        campionato p = *campio;
        destroy_partite(&p->lista_partite);
        *campio = (*campio)->next;
        free(p);
    }
} 
 
 
 
int inserisci_partite_post(campionato* camp,float val1,float val2,float valx, char squadra1[],char squadra2[],char nome[]){
		if (camp==NULL)return 1;
		int test;
		campionato r;
		r = *camp;
		while( (r != NULL) && strcmp((r->nome_campionato),nome)){
			r=r->next;
		}
		if(r==NULL){
			printf("\nnon trovato\n");
			return 0;
		}
		test = inserisci_partite(&(r->lista_partite),squadra1,squadra2,val1,val2,valx);
		if (test==1)
			return 1;
		return 0;
}

int rimuovi_partite_post(campionato* camp,char nome_c[],char nome_s[]){
	if (camp==NULL) return 1;
	int test;
	campionato r;
	r=*camp;
	while((r != NULL) && strcmp((r->nome_campionato), nome_c)){
		r=r->next;
	}
	if(r==NULL){
			printf("\ncampionato non trovato\n");
			return 0;
	}
	
	test= cancella_partite(&(r->lista_partite),nome_s);
	if (test==1)
		return 1;
	return 0;

}

int modifica_nome_squad(campionato* camp,char sq1[],char sq2[],char sqc[],char nome_c[]){
	if (camp==NULL) return 1;
	int test;
	campionato r;
	r=*camp;
	partite c;
	while((r != NULL) && strcmp((r->nome_campionato), nome_c)){
		r=r->next;
	}
	if(r==NULL){
			printf("\ncampionato non trovato\n");
			return 0;
	}
	c=(r->lista_partite);
	
	while((c != NULL) && strcmp((c->par->squadra_1),sqc)){
		c=c->next;
	}
	if(c==NULL){
		printf("\npartita non trovata\n");
		return 0;
	}
	test=assegna_nomi_squadre(&(c->par),sq1,sq2);
	if(test==1) return 1;
}

int modifica_quote_squad(campionato* camp,char sq1[],char nome_c[],float val1, float val2, float valx){
	if (camp==NULL) return 1;
	int test;
	campionato r;
	r=*camp;
	partite c;
	while((r != NULL) && strcmp((r->nome_campionato), nome_c)){
		r=r->next;
	}
	if(r==NULL){
			printf("\ncampionato non trovato\n");
			return 0;
	}
	c=(r->lista_partite);
	
	while((c != NULL) && strcmp((c->par->squadra_1),sq1)){
		c=c->next;
	}
	if(c==NULL){
		printf("\npartita non trovata\n");
		return 0;
	}
	test=assegna_quote(&(c->par),val1,val2,valx);
	if (test==1) return 1;
}
 
int destroy_partite_post(campionato* camp,char nome_c[]){
	if (camp==NULL) return 1;
	int test;
	campionato r;
	r=*camp;
	while((r != NULL) && strcmp((r->nome_campionato), nome_c)){
		r=r->next;
	}
	if(r==NULL){
			printf("\ncampionato non trovato\n");
			return 0;
	}
	test=destroy_partite(&(r->lista_partite));
	if (test==1) return 1;
}

void stampa_campionato_nomi(campionato campio){
 	int i=1;
 	campionato s;
 	s= campio;
 	while(s != NULL){
	 	printf("\n");
 		printf("%d)%s",i,s->nome_campionato);
 		i++;
 		s = s-> next;
	 }
	 printf("\n"); 
	 	
 }

int stampa_campionato_partite(campionato campio,char nome_camp[]){
 	campionato s;
 	s= campio;
 	while(s != NULL && strcmp(s->nome_campionato,nome_camp)){
 		s = s-> next;
	} 
	if(s==NULL){
		printf("\ncampionato non trovato\n");
		return 1;
	}
	stampa_partite(s->lista_partite);
 	printf("\n");
 	return 0;
	 	
}


int inserire_scommessa_calcio(campionato* camp,schedina_calcio* sched,char nome_camp[],char gioc,char nome_sq[]){
	if (camp==NULL)
		return 1;
	partite f;
	campionato r;
	r = *camp;
	while( r != NULL &&  strcmp(r->nome_campionato,nome_camp)){
		r=r->next;
	}
	if(r==NULL){
		printf("\ncampionato non trovato\n");
		return 2;
	}
	f=r->lista_partite;
	while( f != NULL &&  strcmp(f->par->squadra_1,nome_sq)){
		f=f->next;
	}
	if(f==NULL){
		printf("\npartita non trovata\n");
		return 2;
	}
	switch(gioc){
		case '1':
			inserisci_schedina(sched,f->par,f->par->val_1);
			break;	
		case '2':
			inserisci_schedina(sched,f->par,f->par->val_2);
			break;
		case 'x':
			inserisci_schedina(sched,(f->par),(f->par->val_x));
			break;
	}
}

int scrivi_campionato_file(campionato* camp){
	campionato r;
	r = *camp; 
	FILE* file;
	FILE* file1;
	if((file = fopen("file/saves/campionato.bin","w"))==NULL){
    		printf("\nerrore nell'apertura del file\n");
    		return 1;
    	}
    	if((file1 = fopen("file/saves/partite.bin","w"))==NULL){
    		printf("\nerrore nell'apertura del file\n");
    		return 1;
    	}
	while(r != NULL){
		fprintf(file,"%s ",r->nome_campionato);
		scrivi_partite_file(&r->lista_partite,file1);
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

int leggi_campionato_file(campionato* campio){
	int test;
	char nom[20];
	FILE* file;
	FILE* file1;
	if((file=fopen("file/saves/campionato.bin","r"))==NULL){
		printf("\n errore nell'apertura del file\n");
		return 0;
	}
	
	if((file1=fopen("file/saves/partite.bin","r"))==NULL){
		printf("\n errore nell'apertura del file\n");
		return 0;
	}
	
	campionato p;
	campionato new_campionato;
	
	
	while(fscanf(file,"%s",&nom) != EOF){
	
	new_campionato =(campionato)malloc(sizeof(struct campionato));
 	if(new_campionato == NULL)return 1;
 	
 	strcpy(new_campionato->nome_campionato,nom);
 	
 	test=crea_partite(&new_campionato->lista_partite);
 	if(test==1)return 1;
 	
	test=inserisci_partite_file(&new_campionato->lista_partite,file1);
	if(test==1) return 1;
	 	
 	new_campionato->next = NULL;
 	if(*campio == NULL){
 		(*campio)=new_campionato;
	 }
	else{
		p=*campio;
		while(p -> next != NULL)
			p = p -> next;
		p->next=new_campionato;
		}
	}
	fclose(file1);
	fclose(file);
	return 0;
	
 }



 
