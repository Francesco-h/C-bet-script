#include "headers.h"
//fatto
int crea_partite(partite* partite){
	*partite=NULL;
	return 0;
}

int inserisci_partite(partite* part,char squadra1[],char squadra2[],float val1, float val2,float valx){
	if (part==NULL)return 1;
	int test;
	partite p;
	partite new_partite;
	new_partite = (partite)malloc(sizeof(struct partite));
	if (new_partite==NULL)return 1;
	test=crea_partita(&new_partite->par,squadra1,squadra2,val1,val2,valx);
	if(test==1)return 1;
	new_partite->next= NULL;
	if(*part==NULL){
		(*part)=new_partite;
		return 0;
	}
	
	p=*part;
	while(p->next != NULL)
		p = p-> next;
	
	p->next = new_partite;
	return 0;
}


void stampa_partite(partite part){
	partite q;
	q=part;
	while(q != NULL){
		stampa_partita(q->par);
		q=q->next;
	}
}

int cancella_partite(partite* part,char squadra1[]){
	if (part==NULL)return 1;
	partite q = *part;
	partite r = *part;
	while((q != NULL) && (strcmp(squadra1,q->par->squadra_1))){
		r = q;
		q = q->next;
	}
	if (q == NULL){
		printf("non esiste");
		return 0;
	}	
	if (q == *part){
		(*part) = (*part) -> next;
	}
	else
		r -> next = q -> next;
	cancella_partita(&q->par);
	free(q);
	return 0;	
}

int destroy_partite(partite* part){
	while(*part != NULL){
        	partite p = *part;
        	cancella_partita(&((*part)->par));
        	*part = (*part)->next;
        	free(p);
    }
}

int scrivi_partite_file(partite* par,FILE* file){
	partite r;
	r=(*par);
	while(r != NULL){
		fprintf(file,"%s %s %f %f %f ",r->par->squadra_1,r->par->squadra_2,r->par->val_1,r->par->val_2,r->par->val_x);
		r=r->next;
	}
	return 0;
}

int inserisci_partite_file(partite* part, FILE* file){
	int i=0;	
	char squadra1[4],squadra2[4];
	float val1,val2,valx;
	while(i<5 && (fscanf(file,"%s %s %f %f %f",&squadra1,&squadra2,&val1,&val2,&valx) != EOF)){
		i++;
		if (part==NULL)return 1;
		int test;
		partite p;
		partite new_partite;
		new_partite = (partite)malloc(sizeof(struct partite));
		if (new_partite==NULL)return 1;
		test=crea_partita(&new_partite->par,squadra1,squadra2,val1,val2,valx);
		if(test==1)return 1;
		new_partite->next= NULL;
		if(*part==NULL){
			(*part)=new_partite;
		}
		else{
		p=*part;
		while(p->next != NULL)
			p = p-> next;
		
		p->next = new_partite;
		}
	}
	return 0;
}	
		
	
	

	
	
	
	
	




