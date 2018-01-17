#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Tipo_zona{cucina,soggiorno,rimessa,strada,lungo_lago,uscita_campeggio};
enum Tipo_oggetto{cianfrusaglia,bende,coltello,pistola,benzina,adrenalina};
enum Stato_giocatore{morto,ferito,vivo};

typedef struct zona{
enum Tipo_zona zona;
enum Tipo_oggetto oggetto;
struct zona* zona_successiva;
}Zona;

typedef struct giocatore{
enum Stato_giocatore stato;
struct zona* posizione;
int zaino[6];
}Giocatore;

static void ins_zona();
void crea_mappa();
static void canc_zona();
static void chiudi_mappa();
void gioca();
void termina_gioco();  
static void avanza();
static void mostra_oggetto();
static void prendi_oggetto();
static void cura();
static void usa_adrenalina();    