#ifndef SCHEDINAF1_H
#define SCHEDINAF1_H

struct schedina_f1{
	pilota pil;
	int quota;
	struct schedina_f1* next;
};

typedef struct schedina_f1* schedina_f1;

int crea_schedina_f1(schedina_f1* schedina_f1);
int aggiungi_schedina_f1(schedina_f1* schedina_f1,int valore,pilota pil);
int elimina_schedina_f1(schedina_f1* schedina_f1,char winner[]);
int destroy_schedina_f1(schedina_f1* schedina_f1);
void stampa_schedina_f1(schedina_f1 schedina_f1,float puntata);
int scrivi_schedina_f1_file(schedina_f1* sched);
int leggi_schedina_f1_file(schedina_f1* sched);

#endif
