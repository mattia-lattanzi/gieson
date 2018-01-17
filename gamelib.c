//LATTANZI MATTIA MATR:300746 Versione non definitiva del progetto.
#include "gamelib.h"


static struct zona* prima_zona = NULL;
static struct zona* ultima_zona = NULL;  
static Giocatore *current_player;
static short ch_p= 0; 
static Giocatore marzia = {
    .stato = vivo,
    .posizione = NULL,
    .zaino[adrenalina] = 2
};
static Giocatore giacomo ={
    .stato = vivo,
    .posizione = NULL,
    .zaino[coltello]=1
};
    
static int mappa = 0;
int pos_iniziale;
static struct oggetto* scanner_zone = NULL;
static struct oggetto* primo_oggetto = NULL; 
    
    
//prima parte
 void crea_mappa()
 {//menu di selezione mappa   
    short azione=0;
    int torna = 0;
    do
    {
        do
        {
            printf("Inserire 1 o 2 o 3 o 4 in base all'azione che si vuole scegliere\n "); 
            printf("1 Inserisci Zona \n 2 Cancella Zona \n 3 Stampa Mappa\n 4 Chiudi Mappa\n");
            scanf("%hd", &azione);
        }
        while(azione < 1 || azione > 4);

        switch(azione){
                    case 1:
                        {
                            ins_zona();
                        }                        
                        break;
                    case 2:
                        if(ch_p == 0){
                            //canc_zona();
                        }
                        else{
                            printf("La mappa non e' piu' modificabile!\n");
                        }
                        break;
                    case 3:
                        //stampa_mappa();
                        break;
                    case 4:
                        chiudi_mappa();
                        break;
                    default:
                        printf("Valore non riconosciuto! Inserisci un nuovo valore\n");
                        break;
                }

        while(azione != 5);
    }while(torna = 0);
    return;
 }


static void ins_zona()
{
	
		int random = 0;
    
   
	    int numero_zone;
        printf("Inserire il numero delle zone: ");
        scanf("%d", &numero_zone);
        int contatore_zone = 0;
    
	do
    {       
	    printf("Inserisci il tipo di zona: \n 0. cucina \n 1. soggiorno \n 2. rimessa \n 3. strada \n 4. lungo_lago\n 5. uscita_campeggio\n");//consente di inserire il tipo di zona che si vuole avere
        Zona* nuova_zona = (Zona*)malloc(sizeof(Zona));
	    scanf("%u", &(nuova_zona->zona));
        
        if(nuova_zona->zona < 0 || nuova_zona->zona > 5)
        {														
	        printf("Valore non riconosciuto!\n");	        
	    }
        
        nuova_zona->zona_successiva = NULL;
        
        if(prima_zona == NULL) //creazione prima struct mappa
        {	   
           prima_zona = nuova_zona;
           ultima_zona=prima_zona;  // ultima_zona = mappa;
           printf("Zona inserita\n");
        }
        else  //crezione zone successive alla prima    
		{
            ultima_zona->zona_successiva = nuova_zona;
		    ultima_zona = ultima_zona->zona_successiva;
            printf("Zona inserita\n");
	        
        }
        random = 1 + rand() % 100;      
	    printf("oggetto inserito random\n");
	    
            switch(nuova_zona->zona)
            {
                    
                case 0: //cucina
                   // printf("cucina\n");
                    if(random < 30)
                    {
                        //printf("random %d\n",random);
                        nuova_zona->oggetto = cianfrusaglia;
                    }
                    if(random > 30 && random < 50)
                    {
                        //printf("random %d\n",random);
                        nuova_zona->oggetto = bende;
                    }
                    if(random > 50 && random < 90)
                    {
                       // printf("random %d\n",random);
                       nuova_zona->oggetto = coltello;
                    }
                    else
                    {
                        //printf("random %d\n",random);
                        nuova_zona->oggetto = adrenalina;
                    }
                    break; //fare tutti i case in base alla zona
                case 1://soggiorno
                    if(random < 20)
                    {
                        nuova_zona->oggetto = cianfrusaglia;
                    }
                    if(random > 20 && random < 30)
                    {
                        nuova_zona->oggetto = bende;
                    }
                    if(random > 30 && random < 40)
                    {    
                        nuova_zona->oggetto = coltello;
                    }
                    if(random > 40 && random < 70)
                    {   
                        nuova_zona->oggetto = pistola;
                    }
                    else 
                    {   
                        nuova_zona->oggetto = adrenalina; 
                    }
                    break;
                case 2://rimessa
                    if(random<20)
                    {
                        nuova_zona->oggetto = cianfrusaglia;
                    }
                    if(random > 20 && random < 30)
                    {
                        nuova_zona->oggetto = bende;
                    }
                    if(random > 30 && random < 60) 
                    {    
                        nuova_zona->oggetto = coltello;
                    }
                    if(random > 60 && random < 90)
                    {
                        nuova_zona->oggetto = benzina;
                    }
                    else
                    {
                        nuova_zona->oggetto = adrenalina;
                    }
                    break;
                case 3://strada
                    if(random<80)
                    {
                        nuova_zona->oggetto = cianfrusaglia;
                    }
                    if(random > 80 && random < 90)
                    {
                        nuova_zona->oggetto = coltello;
                    }
                    else
                    {
                       nuova_zona->oggetto = benzina;
                    }
                    break;
                case 4://lungo_lago
                    if(random<70)
                    {
                        nuova_zona->oggetto = cianfrusaglia;
                    }
                    if(random > 70 && random < 80)
                    {
                        nuova_zona->oggetto = coltello;
                    }
                    else    
                    {
                        nuova_zona->oggetto = benzina;
                    }
                    break;
                case 5://uscita_campeggio
                    if(random<90)
                    {
                        nuova_zona->oggetto = cianfrusaglia;
                    }
                    else
                    {
                        nuova_zona->oggetto = coltello;
                    }
                    break;
            }            
	   
        contatore_zone++;
	}while(contatore_zone < numero_zone);
    crea_mappa();
}
    
static void canc_zona()// Funzione Void di tipo static che consente di cancellare l'ultima zona inserita.
{
    struct zona* point = prima_zona;
	struct zona* temp = point;
	
	if(prima_zona == NULL){
		printf("La lista delle zone e' vuota!\n");
	}
	else{
    	while(point->zona_successiva){
			temp= point; //temp punterà alla penultima zona della lista.
        	point= point->zona_successiva;
    	}
  
    	free(ultima_zona);
    	ultima_zona = temp;
		ultima_zona -> zona_successiva = NULL;
		
	}
}

 static void stampa_mappa()
 {// Consente di stampare  tutte le caratteristiche della mappa 
	 system("clear");
    if(prima_zona == NULL){
        
        printf(">$ Non è presente alcuna zona, il percorso è vuoto....\n");
        
    }else{
        struct zona * point=prima_zona;//puntatore usato per scorrere la lista
         do
            {
                switch(point->zona){
                    case 0:
                        printf("Tipo zona: cucina");
                        break;
                    case 1:
                        printf("Tipo zona: soggiorno");
                        break;
                    case 2:
                        printf("Tipo zona: rimessa");
                        break;
                    case 3:
                        printf("Tipo zona: strada");
                        break;
                    case 4:
                        printf("Tipo zona: lungo_lago");
                        break;
                    case 5:
                        printf("Tipo zona: uscita_campeggio");
                    default:
                        printf("Errore!");
                        break;
                }
                point = point->zona_successiva;
            }while(point!=NULL);	
		}
     return;
	}
        
static void chiudi_mappa() //Chiude la mappa e torna al menu principale.
{ 
	return;
    int main();
}


