//Francesco Corrieri 527755 Ver 5.0

#include "headers.h"


int main(){
	srand(time(NULL));
	int test,scelta,flag,c,ciclo=1,valp,i;
	float puntata_calcio=1,puntata_f1=1,val1,val2,valx;
	FILE* file_puntata;
	if((file_puntata=fopen("file/saves/puntata.bin","r"))!=NULL){
		fscanf(file_puntata,"%f %f",&puntata_calcio,&puntata_f1);
		fclose(file_puntata);
	}		

	char nome_camp[20],nome_race[20],nome_pil[10],nome_par[4],squadra1[4],squadra2[4];
	
	gara race;
	test= crea_gara(&race);
	if(test==1)
		return 2;
	test=leggi_gara_file(&race);
	if (test==1)
		return 4;
	
	campionato camp;
	test = crea_campionato(&camp);
	if (test==1)
		return 2;
		
	test=leggi_campionato_file(&camp);
	if (test==1)
		return 4;
	
    
	schedina_f1 sched1;
	test=crea_schedina_f1(&sched1);
	if (test==1)
		return 2;
	test=leggi_schedina_f1_file(&sched1);
	if(test==1)
		return 4;
	
	schedina_calcio schedc;
	test=crea_schedina_calcio(&schedc);
	if (test==1)
		return 2;
		
	test=leggi_schedina_calcio_file(&schedc);
	if(test==1)
		return 4;
	
	while(ciclo == 1){
		printf("\t_______________________________\n");
		printf("\t|                             |\n");
		printf("\t|                             |\n");
		printf("\t|     Scommesse da Ciccio     |\n");
		printf("\t|                             |\n");
		printf("\t|_____________________________|\n");
	
	
	
	
		printf("\t________________________________\n");
		printf("\t|                              |\n");
		printf("\t|  1)modifica calcio           |\n\t|  2)modifica f1               |\n\t|  3)prosegui per scommettere  |\n\t|  4)esci                      |\n");
		printf("\t|______________________________|\n");
		scanf("%d",&scelta);
		
		
		
		switch(scelta){
			//calcio
			case 1:
				printf("\t__________________________\n");
				printf("\t|                         |\n");				
				printf("\t|  1)modifica campionato  |\n\t|  2)modifica partita     |\n");
				printf("\t|_________________________|\n");
				scanf("%d",&scelta);
				flag=1;
				break;
			//f1
			case 2:
				printf("\t__________________________\n");
				printf("\t|                         |\n");				
				printf("\t|  1)modifica gp          |\n\t|  2)modifica pilota      |\n");
				printf("\t|_________________________|\n");
				scanf("%d",&scelta);
				flag=2;
				break;
			
			
			
			case 3:
				printf("\t__________________________\n");
				printf("\t|                         |\n");				
				printf("\t|  1)calcio               |\n\t|  2)f1                   |\n\t|  3)schedine attuali     |\n");
				printf("\t|_________________________|\n");
				scanf("%d",&scelta);
				flag=3;
				break;
				
			case 4: 
				if((file_puntata=fopen("file/saves/puntata.bin","w"))!=NULL){
					fprintf(file_puntata,"%f %f",puntata_calcio,puntata_f1);
					fclose(file_puntata);
				}	
				
				test=scrivi_gara_file(&race);
				if (test==1)
					return 4;

				test=scrivi_campionato_file(&camp);
				if (test==1)
					return 4;
				test=scrivi_schedina_file(&schedc);
				if (test==1)
					return 4;
				test=scrivi_schedina_f1_file(&sched1);
				if (test==1)
					return 4;
				destroy_schedina_f1(&sched1);
				destroy_schedina(&schedc);
				destroy_gara(&race);
				destroy_campionato(&camp);
				return 0;
			default: 	
				printf("\t ____________________\n");
				printf("\t|                    |\n");
				printf("\t|  selezione errata  |\n");
				printf("\t|                    |\n");
				printf("\t|____________________|\n");
				return 1 ;
			}
		
		
		
		switch(flag){
			//calcio
			case 1:
				switch(scelta){
					//campionato
					case 1:
						printf("\n\t___________________________\n");
						printf("\t|                          |\n");
						printf("\t|  1)aggiungi campionato   |\n\t|  2)rimuovi campionato    |\n\t|  3)distruggi campionati  |\n\t|  4)stampa campionati     |\n");
						printf("\t|                          |\n");
						printf("\t|__________________________|\n");
						scanf("%d",&scelta);
						flag=1;
						break;
					//partita
					case 2:
						printf("\n\t _______________________");
						printf("\n\t|                       |\n");
						printf("\t|  1)aggiungi partita   |\n\t|  2)rimuovi partita    |\n\t|  3)modifica squadre   |\n\t|  4)modifica quote     |\n\t|  5)distruggi partite  |\n");
						printf("\t|_______________________|\n");
						scanf("%d",&scelta);
						flag=2;
						break;
					default :
						printf("\t ____________________\n");
						printf("\t|                    |\n");
						printf("\t|  selezione errata  |\n");
						printf("\t|                    |\n");
						printf("\t|____________________|\n");
						return 1;
					}
					break;
			
			
			
			//f1
			case 2:
				switch(scelta){
					case 1:
						printf("\n\t _______________________");
						printf("\n\t|                       |\n");
						printf("\t|  1)aggiungi gp        |\n\t|  2)rimuovi gp         |\n\t|  3)distruggi gp       |\n\t|  4)stampa gp          |\n");
						printf("\t|_______________________|\n");
						scanf("%d",&scelta);
						flag=3;
						break;

					case 2:
						printf("\n\t _____________________________");
						printf("\n\t|                            |\n");
						printf("\t|  1)aggiungi pilota         |\n\t|  2)rimuovi pilota          |\n\t|  3)modifica nome pilota    |\n\t|  4)modifica quota pilota   |\n\t|  5)distruggi piloti        |\n");
						printf("\t|____________________________|\n");
						scanf("%d",&scelta);
						flag=4;
						break;
				}
				break;
			
			//scommesse
			case 3:
				switch(scelta){
					//calcio
					case 1:	
						char gioc;
						stampa_campionato_nomi(camp);
						printf("\ninserire nome campionato da giocare: \n");
						
						do {
        						c = getchar();
    						} while (c != '\n' && c != EOF);
						
						scanf("%s",&nome_camp);
						test=stampa_campionato_partite(camp,nome_camp);
						if(test==1){
							flag=5;
							break;
						}
						printf("inserire nome della squadra 1 che si vuole giocare\n");
						scanf("%s",&nome_par);
						do {
        						c = getchar();
    						} while (c != '\n' && c != EOF);
    						
    						printf("\ninserire valore della giocata (1-2-x)\n");
    						scanf("%c",&gioc);
    						test=inserire_scommessa_calcio(&camp,&schedc,nome_camp,gioc,nome_par);
    						if (test==1)
    							return 3;
    							
    						flag=5;
    						break;
    						
    					//f1
    					case 2:
    						stampa_gara_nomi(race);
    						
    						printf("\ninserire nome gp da giocare: \n");
						
						do {
        						c = getchar();
    						} while (c != '\n' && c != EOF);
						
						scanf("%s",&nome_race);
						stampa_gara_piloti(race,nome_race);
    						
    						printf("inserire nome del pilota da giocare\n");
						scanf("%s",&nome_pil);
    						test=inserire_scommessa_f1(&race,&sched1,nome_race,nome_pil);
    						if (test==1)
    							return 3;
    						stampa_schedina_f1(sched1,puntata_f1);
    						flag=6;
    						break;
    					
    					
    					
    					case 3:
    						printf("\t _______________________________\n");
						printf("\t|                               |\n");
						printf("\t|  1)stampa schedina calcio     |\n");
						printf("\t|  2)stampa schedina f1         |\n");
						printf("\t|  3)modifica puntata calcio    |\n");						
						printf("\t|  4)modifica puntata f1        |\n");
						printf("\t|  5)cancella schedina calcio   |\n");
						printf("\t|  6)cancella schedina f1       |\n");
						printf("\t|  7)distruggi schedina calcio  |\n");
						printf("\t|  8)distruggi schedina f1      |\n");																		
						printf("\t|_______________________________|\n");
    						flag=5;
    						scanf("%d",&scelta);
    						break;
    				}
    				break;
    						
			
			
			
			
			
				default: 	
					printf("\t ____________________\n");
					printf("\t|                    |\n");
					printf("\t|  selezione errata  |\n");
					printf("\t|                    |\n");
					printf("\t|____________________|\n");
					return 1 ;
				}
		
		
		switch(flag){
			//campionato
			case 1:
				switch(scelta){
					//inserire campionato
					case 1:
						printf("\ninserire nome campionato: \n");
						
						do {
        						c = getchar();
    						} while (c != '\n' && c != EOF);
						
						scanf("%s",&nome_camp);
						test = inserisci_campionato(&camp, nome_camp);
						for (i=0;i<5;i++){
						
							printf("\ninserire nome squadra 1:\n");
							scanf("%s",&squadra1);
		  					printf("\ninserire nome squadra 2:\n");
							scanf("%s",&squadra2);
							
							val1= (float)rand()/(float)(RAND_MAX/4.0);
							val2= (float)rand()/(float)(RAND_MAX/4.0);
							valx= (float)rand()/(float)(RAND_MAX/4.0);
							
							test=inserisci_partite_post(&camp,val1+1,val2+1,valx+1,squadra1,squadra2,nome_camp);
							if(test==1)
								return 2;
						}
						break;
					//elimina campionato
					case 2:	
						stampa_campionato_nomi(camp);
						printf("\n\ninserire nome campionato da eliminare: \n");
						do {
        						c = getchar();
    						} while (c != '\n' && c != EOF);
    						scanf("%s",&nome_camp);
    						test=cancella_campionato(&camp,nome_camp);
    						if (test==1)
							return 3;
    						break;
    					//destroy campionati
    					case 3:
    						test=destroy_campionato(&camp);
						if (test==1)
							return 3;
						break;
					case 4:
						stampa_campionato(camp);
						break;
					default: 	
						printf("\t ____________________\n");
						printf("\t|                    |\n");
						printf("\t|  selezione errata  |\n");
						printf("\t|                    |\n");
						printf("\t|____________________|\n");
						return 1 ;
					}
					break;
			
			//partite
			case 2:
				switch (scelta){
						//aggiungi partite
						case 1:


							
							stampa_campionato_nomi(camp);
							printf("\n\ninserire nome campionato dove inserire la partita:\n");


							do {
        							c = getchar();
    							} while (c != '\n' && c != EOF);
    							scanf("%s",&nome_camp);
    							
    							stampa_campionato_partite(camp,nome_camp);
    							printf("\ninserire nome squadra 1\n");
    							scanf("%s",&squadra1);
    							do {
        							c = getchar();
    							} while (c != '\n' && c != EOF);

							
							printf("\ninserire nome squadra 2\n");
    							scanf("%s",&squadra2);
    							do {
        							c = getchar();
    							} while (c != '\n' && c != EOF);
						
							
							val1= (float)rand()/(float)(RAND_MAX/4.0);
							val2= (float)rand()/(float)(RAND_MAX/4.0);
							valx= (float)rand()/(float)(RAND_MAX/4.0);
							
							test=inserisci_partite_post(&camp,val1+1,val2+1,valx+1,squadra1,squadra2,nome_camp);
							if (test==1) 
								return 3;
							break;
						//rimuovi partite
						
						case 2:
							stampa_campionato_nomi(camp);
							printf("\n\ninserire nome del campionato della partita da eliminare\n");

							do {
        							c = getchar();
    							} while (c != '\n' && c != EOF);
							scanf("%s",&nome_camp);
    							stampa_campionato_partite(camp,nome_camp);
    							printf("\ninserisci nome della squadra 1 della partita da eliminare\n");
							scanf("%s",&nome_par);
    							do {
        							c = getchar();
    							} while (c != '\n' && c != EOF);
    							
    							
    							test=rimuovi_partite_post(&camp,nome_camp,nome_par);
    							if(test==1) return 3;
    							stampa_campionato(camp);
    							break;
    							
    							
    						//modifica squadre
    						case 3:
    							char sqc[4];
    							stampa_campionato_nomi(camp);
    							printf("\ninserire nome del campionato della partita da modificare\n");

							do {
        							c = getchar();
    							} while (c != '\n' && c != EOF);
							scanf("%s",&nome_camp);
							stampa_campionato_partite(camp,nome_camp);
							printf("\ninserisci nome della squadra 1 della partita da modificare\n");
    							scanf("%s",&sqc);
    							do {
        							c = getchar();
    							} while (c != '\n' && c != EOF);
    							
    							printf("inserisci la nuova squadra 1\n");
    							scanf("%s",&squadra1);
    							do {
        							c = getchar();
    							} while (c != '\n' && c != EOF);
    							
    							printf("inserisci la nuova squadra 2\n");
    							scanf("%s",&squadra2);
    							do {
        							c = getchar();
    							} while (c != '\n' && c != EOF);
							test=modifica_nome_squad(&camp,squadra1,squadra2,sqc,nome_camp);
							if (test==1) return 3;
							break;
							
						//modifica valutazioni
						case 4:
							stampa_campionato_nomi(camp);
    							printf("\ninserire nome del campionato della partita da modificare\n");

							do {
        							c = getchar();
    							} while (c != '\n' && c != EOF);
							scanf("%s",&nome_camp);
							stampa_campionato_partite(camp,nome_camp);
							printf("\ninserisci nome della squadra 1 della partita da modificare\n");
    							scanf("%s",&nome_par);
    							do {
        							c = getchar();
    							} while (c != '\n' && c != EOF);
    							
    							printf("inserisci le nuove quote (tutte nella stessa riga separate da uno spazio 1-x-2)\n");
    							scanf("%f %f %f",&val1,&val2,&valx);
    							test=modifica_quote_squad(&camp,nome_par,nome_camp,val1,valx,val2);
    							if(test==1) return 3;
    							break;
    							
    						//destroy_partite
    						case 5:
    							stampa_campionato_nomi(camp);
    							printf("\ninserire nome del campionato delle partite da distruggere\n");

							do {
        							c = getchar();
    							} while (c != '\n' && c != EOF);
							scanf("%s",&nome_camp);
							test=destroy_partite_post(&camp,nome_camp);
							if (test==1) return 3;
							break;
    							
					}
					break;
			//gare
			case 3:		
				switch (scelta){
					//aggiungi gp
					case 1:	
						printf("\ninserire nome gp: \n");
						
						do {
        						c = getchar();
    						} while (c != '\n' && c != EOF);
						
						scanf("%s",&nome_race);
																			
						test=inserisci_gara(&race,nome_race);
						if (test==1) 
							return 2;
							
						for(i=0;i<5;i++){
							printf("\ninserire nome pilota: \n");
						scanf("%s",&nome_pil);
						valp= rand() % 12;
						
						test=inserisci_pilota_post(&race,nome_race,nome_pil,valp+1);
						if (test==1)
							return 2;
						
						}
						break;
					//rimuovi gp
					case 2:
						stampa_gara_nomi(race);
						printf("\ninserire nome gp: \n");
						
						do {
        						c = getchar();
    						} while (c != '\n' && c != EOF);
						
						scanf("%s",&nome_race);
						test=elimina_gara(&race,nome_race);
						if(test==1)
							return 2;
						break;
					
					case 3:
						test=destroy_gara(&race);
						if(test==1)
							return 2;
						break;
					case 4:
						stampa_gara(race);
						break;
					default: 	
						printf("\t ____________________\n");
						printf("\t|                    |\n");
						printf("\t|  selezione errata  |\n");
						printf("\t|                    |\n");
						printf("\t|____________________|\n");
						return 1 ;
				
				}
				break;
			//piloti
			case 4:
				switch(scelta){
					//aggiungi pilota post
					case 1:
						valp= rand() % 12;
						stampa_gara_nomi(race);
						printf("\ninserire nome gp: \n");
						
						do {
        						c = getchar();
    						} while (c != '\n' && c != EOF);
						
						scanf("%s",&nome_race);
						stampa_gara_piloti(race,nome_race);
						printf("inserire nome pilota da aggiungere\n");
						
    						scanf("%s",&nome_pil);
    						test=inserisci_pilota_post(&race,nome_race,nome_pil,valp+1);
    						if (test==1) 
    							return 2;
    						break;
					//rimuovi pilota
					case 2:
						stampa_gara_nomi(race);
						printf("\ninserire nome gp del pilota da eliminare: \n");
						
						do {
        						c = getchar();
    						} while (c != '\n' && c != EOF);
						
						scanf("%s",&nome_race);
						stampa_gara_piloti(race,nome_race);
						printf("inserire nome pilota da rimuovere\n");
						
    						scanf("%s",&nome_pil);
    						test=rimuovi_pilota_post(&race,nome_race,nome_pil);
    						if (test==1) 
    							return 2;
    						break;
    					//modifica nome
    					case 3:	
    						char nuovo_nome[10];
    						stampa_gara_nomi(race);
    						printf("\ninserire nome del gp del pilota da modificare:\n");
						do {
        						c = getchar();
    						} while (c != '\n' && c != EOF);
						
						scanf("%s",&nome_race);
						stampa_gara_piloti(race,nome_race);
						printf("inserire nome pilota da modificare\n");
						
						scanf("%s",&nome_pil);

						printf("\ninserire nuovo nome\n");
						scanf("%s",&nuovo_nome);

						test=modifica_pilota_nome(&race,nome_race,nome_pil,nuovo_nome);
						if(test==1)
							return 2;
						break;
					//modifica valore
					case 4:
						stampa_gara_nomi(race);
						printf("\ninserire nome del gp:\n");
						do {
        						c = getchar();
    						} while (c != '\n' && c != EOF);
						
						scanf("%s",&nome_race);
						stampa_gara_piloti(race,nome_race);
						printf("inserire nome pilota da modificare\n");
						
						scanf("%s",&nome_pil);
						
						printf("\ninserire nuovo valore\n");
						scanf("%i", &valp);
					
						test=modifica_pilota_valutazione(&race,nome_race,nome_pil,valp+1);
						if(test==1)
							return 2;
						break;
					
					//distruggi piloti
					case 5:
						stampa_gara_nomi(race);
						printf("\ninserire nome del gp con i piloti da distruggere:\n");
						do {
        						c = getchar();
    						} while (c != '\n' && c != EOF);
						
						scanf("%s",&nome_race);
						test=destroy_ricerca(&race,nome_race);
						if (test==1)
							return 1;
						break;
						
					
					default: 	
						printf("\t ____________________\n");
						printf("\t|                    |\n");
						printf("\t|  selezione errata  |\n");
						printf("\t|                    |\n");
						printf("\t|____________________|\n");
						return 1 ;
				
				}
				break;
				
			case 5:
				switch(scelta){
					case 1:
						stampa_schedina(schedc,puntata_calcio);
						break;
					case 2: 
						stampa_schedina_f1(sched1,puntata_f1);
						break;
					case 3:
						printf("\nvalore attuale: %.2f\ninserire nuovo valore: \n",puntata_calcio);
						scanf("%f",&puntata_calcio);
						break;
					case 4:
						printf("\nvalore attuale: %.2f\ninserire nuovo valore: \n",puntata_f1);
						scanf("%f",&puntata_f1);
						break;	
					case 5:
						printf("\ninserire squadra 1 della giocata da eliminare\n");
							do {
        							c = getchar();
    							} while (c != '\n' && c != EOF);
							scanf("%s",&nome_par);
							test=rimuovi_schedina_calcio(&schedc,nome_par);
							if (test==1) 
								return 2;	
							break;
					case 6: 
						printf("\ninserire nome del pilota della giocata eliminare\n");
						do {
        							c = getchar();
    							} while (c != '\n' && c != EOF);
							scanf("%s",&nome_pil);
							test=elimina_schedina_f1(&sched1,nome_pil);
							if(test==1) 
								return 2;
							break;
					case 7:
						destroy_schedina(&schedc);
						break;
					case 8:
						destroy_schedina_f1(&sched1);
						break;
							
							
				}
				break;			
			
			case 6:
				break;
			
			default: 	
						printf("\t ____________________\n");
						printf("\t|                    |\n");
						printf("\t|  selezione errata  |\n");
						printf("\t|                    |\n");
						printf("\t|____________________|\n");
						return 1 ;
			}
			
	}

	return 0;
}
	
	
	
