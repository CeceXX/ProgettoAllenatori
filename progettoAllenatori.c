/*
    Gruppo 1: Progetto Allenatori
    Risorse: - Paolo Valeri
             - Gianluca Tesi
             - Elis Belletta
             - Cesare de Cal
    Consegnare entro: Domenica 3 Aprile 2016
 */

#include <stdio.h>
#define numeroMassimoSoci 100
#define numeroMassimoAllenatori 100

int acquisisciNumeroCompresoTraValori(int inserimentoMinimoConsentito, int inserimentoMassimoConsentito) {
    int inserimento;
    scanf("%d", &inserimento);
    while ((inserimento < inserimentoMinimoConsentito) || (inserimento > inserimentoMassimoConsentito)) {
        printf("'%d' non e' un inserimento valido. Inserisci un valore compreso tra %d e %d: ", inserimento, inserimentoMinimoConsentito, inserimentoMassimoConsentito);
        scanf("%d", &inserimento);
    }
    return inserimento;
}

int numeroSoci = 0;
int numeroAllenatori = 0;

// Gianluca Tesi: Creazione struct Soci
struct Socio {
    char nome[80];
    char cognome[80];
    char luogoNascita[80];
    char dataNascita[80];
    char indirizzo[80];
	int numeroTessera;
	int annoIscrizione;
	int ultimoAnnoPagamento;
	int quotaVersata;
	int codiceAllenatore;
};

// Paolo Valeri: Creazione struct Allenatori
struct Allenatore {
    char cognome[80];
    char nome[80];
	int codiceAllenatore;
	int pagaOraria;
	int oreEffettuate;
};


// Paolo Valeri: Inserimento allenatore
void inserireNuovoAllenatore(struct Allenatore insiemeAllenatori[]) {
    printf("Inserisci nome: ");
    scanf("%s", insiemeAllenatori[numeroAllenatori].nome);
    printf("Inserisci cognome: ");
    scanf("%s", insiemeAllenatori[numeroAllenatori].cognome);
    printf("Inserisci codice dell'allenatore: ");
    scanf("%d", &insiemeAllenatori[numeroAllenatori].codiceAllenatore);
    printf("Inserisci paga oraria: ");
    scanf("%d", &insiemeAllenatori[numeroAllenatori].pagaOraria);
    printf("Inserisci ore effettuate: ");
    scanf("%d", &insiemeAllenatori[numeroAllenatori].oreEffettuate);
    numeroAllenatori++;
}

void modificareDatiSocioConNomeCognome(struct Socio insiemeSoci[], int numeroSoci) {
    char nome[100], cognome[100];
    printf("Inserisci nome: ");
    scanf("%s", nome);
    printf("Inserisci cognome: ");
    scanf("%s", cognome);
    
}

// Cesare de Cal: Funzione main
void mostraMenuStatistiche(struct Socio insiemeSoci[], struct Allenatore insiemeAllenatori[]) {
    printf("--------------------------------------------------------------------------------------\n");
    printf("1. Stampare quanti sono i soci che hanno pagato nell'anno corrente e l'incasso totale.");
    printf("2. Stampare il socio che ha pagato la quota minore.");
    printf("--------------------------------------------------------------------------------------\n");
    printf("Seleziona opzione menu: ");
    int scelta = acquisisciNumeroCompresoTraValori(1, 7);
    switch (scelta) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            break;
    }
}

// Cesare de Cal: Funzione main
void mostraMenuAllenatori(struct Allenatore insiemeAllenatori[]) {
    printf("---------------------------------------------------------------------------\n");
    printf("1. Inserire un nuovo allenatore\n");
    printf("2. Modificare i dati di un allenatore già presente inseriti nome e cognome\n");
    printf("3. Eliminare un allenatore inseriti nome e cognome\n");
    printf("4. Visualizzare i dati di tutti gli allenatori\n");
    printf("---------------------------------------------------------------------------\n");
    printf("Seleziona un'opzione del menu: ");
    int scelta = acquisisciNumeroCompresoTraValori(1, 4);
    switch (scelta) {
        case 1:
            inserireNuovoAllenatore(insiemeAllenatori);
             break;
        case 2:
            break;
        case 3:
            break;
        default:
            break;
    }
}

// Paolo Valeri: Inserimento socio
void inserireNuovoSocio(struct Socio insiemeSoci[]) {
    printf("Inserisci nome: ");
    scanf("%s", insiemeSoci[numeroSoci].nome);
    printf("Inserisci cognome: ");
    scanf("%s", insiemeSoci[numeroSoci].cognome);
    printf("Inserisci luogo di nascita: ");
    scanf("%s", insiemeSoci[numeroSoci].luogoNascita);
    printf("Inserisci data di nascita: ");
    scanf("%s", insiemeSoci[numeroSoci].dataNascita);
    printf("Inserisci indirizzo: ");
    scanf("%s", insiemeSoci[numeroSoci].indirizzo);
    printf("Inserisci numero tessera: ");
    scanf("%d", &insiemeSoci[numeroSoci].numeroTessera);
    printf("Inserisci anno iscrizione: ");
    scanf("%d", &insiemeSoci[numeroSoci].annoIscrizione);
    printf("Inserisci ultimo anno pagamento: ");
    scanf("%d", &insiemeSoci[numeroSoci].ultimoAnnoPagamento);
    printf("Inserisci quota versata: ");
    scanf("%d", &insiemeSoci[numeroSoci].quotaVersata);
    printf("Inserisci codice dell'allenatore: ");
    scanf("%d", &insiemeSoci[numeroSoci].codiceAllenatore);
    numeroSoci++;
}

void visualizzaDatiSoci(struct Socio insiemeSoci[]) {
    if (numeroSoci == 0) {
        printf("Non ci sono soci da visualizzare.\n");
        return;
    }
    printf("****************** Elenco Soci ******************\n");
    int i;
    for (i = 0; i < numeroSoci; i++) {
        printf("Nome: %s\nCognome: %s\nLuogo di nascita: %s\nData di nascita: %s\nIndirizzo: %s\nNumero tessera: %d\nAnno iscrizione: %d\nUltimo anno pagamento: %d\nQuota versata: %d\nCodice allenatore: %d\n", insiemeSoci[i].nome, insiemeSoci[i].cognome, insiemeSoci[i].luogoNascita, insiemeSoci[i].dataNascita, insiemeSoci[i].indirizzo, insiemeSoci[i].numeroTessera, insiemeSoci[i].annoIscrizione, insiemeSoci[i].ultimoAnnoPagamento, insiemeSoci[i].quotaVersata, insiemeSoci[i].codiceAllenatore);
        printf("*************************************************\n");
    }
}

// Cesare de Cal: Funzione main
void mostraMenuSoci(struct Socio insiemeSoci[]) {
    printf("-------------------------------------------------------------------------\n");
    printf("1. Inserire nuovo socio\n");
    printf("2. Modificare i dati di un socio gia' presente inseriti nome e cognome\n");
    printf("3. Eliminare un socio inseriti nome e cognome\n");
    printf("4. Visualizzare dati di tutti i soci\n");
    printf("-------------------------------------------------------------------------\n");
    printf("Seleziona opzione menu: ");
    int scelta = acquisisciNumeroCompresoTraValori(1, 4);
    switch (scelta) {
        case 1:
            inserireNuovoSocio(insiemeSoci);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            visualizzaDatiSoci(insiemeSoci);
            break;
        default:
            break;
    }
}

// Cesare de Cal: Inizializzazione insieme soci
void inizializzaInsiemeSoci(struct Socio insiemeSoci[]) {
    int i;
    for (i = 0; i < numeroMassimoSoci; i++) {
        insiemeSoci[i].codiceAllenatore = 0;
    }
}

void inizializzaInsiemeAllenatori(struct Allenatore insiemeAllenatori[]) {
    int i;
    for (i = 0; i < numeroMassimoAllenatori; i++) {
        insiemeAllenatori[i].codiceAllenatore = 0;
    }
}

// Cesare de Cal: Funzione main
void mostraMenuPrincipale(struct Socio insiemeSoci[], struct Allenatore insiemeAllenatori[]) {
    printf("----------------------------\n");
	printf("1. Gestire i soci\n");
	printf("2. Gestire gli allenatori\n");
	printf("3. Mostrare le statistiche\n");
    printf("----------------------------\n");
	printf("Seleziona un'opzione del menu: ");
    int scelta = acquisisciNumeroCompresoTraValori(1, 3);
    switch (scelta) {
		case 1:
		    mostraMenuSoci(insiemeSoci);
			break;
		case 2:
            mostraMenuAllenatori(insiemeAllenatori);
			break;
		case 3:
			break;
		default:
			break;
	}
}

// Cesare de Cal: Funzione main
int main() {
    struct Socio insiemeSoci[numeroMassimoSoci];
    struct Allenatore insiemeAllenatori[numeroMassimoAllenatori];
    inizializzaInsiemeSoci(insiemeSoci);
    inizializzaInsiemeAllenatori(insiemeAllenatori);
    
	while (1) {
		mostraMenuPrincipale(insiemeSoci, insiemeAllenatori);
	}
}
