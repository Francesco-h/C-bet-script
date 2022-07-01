#ifndef PILOTI_H
#define PILOTI_H

struct piloti{
	pilota pil;
	struct piloti* next;
};

typedef struct piloti* piloti;

int crea_piloti(piloti* piloti);
int aggiungi_piloti(piloti* piloti, char name[],int val);
int elimina_piloti(piloti* piloti,char name[]);
int destroy_piloti(piloti* piloti);
void stampa_piloti(piloti piloti);
int scrivi_piloti_file(piloti* pilo, FILE* file);

#endif
