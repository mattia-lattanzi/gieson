#include "gamelib.h"

int main()
{

    int azione;
   
    
    
    printf("       BENVENUTO NEL GIOCO,premi invio per continuare\n");
    getchar();
    printf("       SEI PRONTO A SOPRAVVIVERE??premi invio per continuare\n");
    getchar();
    printf("LIKE TRASYMENO....\n");
    getchar();   
    printf("È venerdì 13 giugno 1980 ed un gruppo di studenti universitari del Corso di Laurea in Informatica si trasferiscono in vacanza al “Campeggio Lake Trasymeno”, che sta per riaprire. Ventitre anni prima, infatti, nello stesso campeggio, un ragazzino di nome Gieson era annegato per colpa della negligenza di un programmatore: a causa di un segmentation fault nel suo programma di noleggio delle barche, alla famiglia di Gieson era stata affidata una barca con un motore difettoso. Gieson però infesta ancora il campeggio, e nutre vendetta nei confronti degli informatici poco attenti che hanno seguito il corso di Programmazione I giocando a League of Legends. . . Giacomo e Marzia, entrambi studenti del primo anno, rimangono isolati dagli altri quando. . . \n");
    getchar();  
    printf("Inserire 1 o 2 o 3 in base all'azione che si vuole scegliere\n");
	printf("1) Crea mappa\n");
	printf("2) Gioca\n");
	printf("3) Termina il gioco\n");
    

    do
	{
        scanf("%d",&azione);
        if(azione !=1 && azione !=2 && azione !=3)
        printf("Errore valore non valido\n");
        else
        {
            switch(azione)
            {
                case 1:
                printf("Crea mappa\n");
                crea_mappa();
                break;

                case 2:
                printf("Gioca\n");    
                break;

                case 3:
                printf("Termina Gioco\n");
                break;
            }
        }
    }
    while(1);
}
    

