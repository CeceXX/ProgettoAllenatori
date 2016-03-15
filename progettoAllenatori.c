/*
 Gruppo 1: Progetto Allenatori
 Risorse: - Paolo Valeri
 - Gianluca Tesi
 - Elis Belletta
 - Cesare de Cal
 Consegnare entro: Domenica 3 Aprile 2016
 */

#include <stdio.h>
#include <string.h>
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
    //    scanf("%s", insiemeAllenatori[numeroAllenatori].nome);
    //    printf("Inserisci cognome: ");
    //    scanf("%s", insiemeAllenatori[numeroAllenatori].cognome);
    //    printf("Inserisci codice dell'allenatore: ");
    //    scanf("%d", &insiemeAllenatori[numeroAllenatori].codiceAllenatore);
    //    printf("Inserisci paga oraria: ");
    //    scanf("%d", &insiemeAllenatori[numeroAllenatori].pagaOraria);
    //    printf("Inserisci ore effettuate: ");
    //    scanf("%d", &insiemeAllenatori[numeroAllenatori].oreEffettuate);
    //    numeroAllenatori++;
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

// Paolo Valeri: Modifica Dati Soci
int trovaPosizioneArraySocioConNomeCognome(struct Socio insiemeSoci[], char nome[], char cognome[]) {
    int i;
    for (i = 0; i < numeroMassimoSoci; i++) {
        if (strcmp(nome, insiemeSoci[i].nome) && strcmp(cognome, insiemeSoci[i].cognome)) {
            return i;
        }
    }
    return -1;
}

void modificareDatiSocioConNomeCognome(struct Socio insiemeSoci[]) {
    char nome[100], cognome[100];
    printf("Inserisci nome: ");
    scanf("%s", nome);
    printf("Inserisci cognome: ");
    scanf("%s", cognome);
    int i = trovaPosizioneArraySocioConNomeCognome(insiemeSoci, nome, cognome);
    
    if (i != -1) {
        printf("ho trovato un socio con quel nome e cognome alla posizione %d.\n", i);
        int scelta;
        do {
            printf("---------------------------------------------------------------------------\n");
            printf("1. Nome\n");
            printf("2. Cognome\n");
            printf("3. Luogo di nascita\n");
            printf("4. Data di nascita\n");
            printf("5. Indirizzo\n");
            printf("6. Numero di tessera\n");
            printf("7. Anno di iscrizione\n");
            printf("8. Ultimo anno di pagamento\n");
            printf("9. Quota versata\n");
            printf("10. Codice allenatore\n");
            printf("---------------------------------------------------------------------------\n");
            printf("Inserisci il numero dell'opzione vuoi modificare oppure termina digitando 11: ");
            scelta = acquisisciNumeroCompresoTraValori(1, 11);
            switch (scelta) {
                case 1:
                    printf("Inserisci nome: ");
                    scanf("%s", insiemeSoci[i].nome);
                    break;
                case 2:
                    printf("Inserisci cognome: ");
                    scanf("%s", insiemeSoci[i].cognome);
                    break;
                case 3:
                    printf("Inserisci luogo di nascita: ");
                    scanf("%s", insiemeSoci[i].luogoNascita);
                    break;
                case 4:
                    scanf("%s", insiemeSoci[i].dataNascita);
                    printf("Inserisci indirizzo: ");
                case 5:
                    scanf("%s", insiemeSoci[i].indirizzo);
                    printf("Inserisci numero tessera: ");
                case 6:
                    scanf("%d", &insiemeSoci[i].numeroTessera);
                    printf("Inserisci anno iscrizione: ");
                case 7:
                    scanf("%d", &insiemeSoci[i].annoIscrizione);
                    printf("Inserisci ultimo anno pagamento: ");
                case 8:
                    scanf("%d", &insiemeSoci[i].ultimoAnnoPagamento);
                    printf("Inserisci quota versata: ");
                case 9:
                    printf("Inserisci quota versata: ");
                    scanf("%d", &insiemeSoci[i].quotaVersata);
                default:
                    break;
            }
        } while (scelta != 11);
    } else {
        printf("Non ho trovato il socio con nome %s e cognome %s.\n", nome, cognome);
    }
}

// Paolo Valeri: Inserimento socio
int trovaPosizioneArraySenzaSocio(struct Socio insiemeSoci[]) {
    int i;
    for (i = 0; i < numeroMassimoSoci; i++) {
        if (insiemeSoci[i].codiceAllenatore == -1) {
            return i;
        }
    }
    return -1;
}

void inserireNuovoSocio(struct Socio insiemeSoci[]) {
    int i = trovaPosizioneArraySenzaSocio(insiemeSoci);
    if (i != -1) {
        printf("Inserisci nome: ");
        scanf("%s", insiemeSoci[i].nome);
        printf("Inserisci cognome: ");
        scanf("%s", insiemeSoci[i].cognome);
        printf("Inserisci luogo di nascita: ");
        scanf("%s", insiemeSoci[i].luogoNascita);
        printf("Inserisci data di nascita: ");
        scanf("%s", insiemeSoci[i].dataNascita);
        printf("Inserisci indirizzo: ");
        scanf("%s", insiemeSoci[i].indirizzo);
        printf("Inserisci numero tessera: ");
        scanf("%d", &insiemeSoci[i].numeroTessera);
        printf("Inserisci anno iscrizione: ");
        scanf("%d", &insiemeSoci[i].annoIscrizione);
        printf("Inserisci ultimo anno pagamento: ");
        scanf("%d", &insiemeSoci[i].ultimoAnnoPagamento);
        printf("Inserisci quota versata: ");
        scanf("%d", &insiemeSoci[i].quotaVersata);
        insiemeSoci[i].codiceAllenatore = i;
    } else {
        printf("Non c'e' sufficiente spazio per poter inserire un nuovo socio. Considera eliminare un socio.\n");
    }
}

void visualizzaDatiSoci(struct Socio insiemeSoci[]) {
    int i;
    for (i = 0; i < numeroMassimoSoci; i++) {
        if (insiemeSoci[i].codiceAllenatore != -1) {
            printf("Nome: %s\nCognome: %s\nLuogo di nascita: %s\nData di nascita: %s\nIndirizzo: %s\nNumero tessera: %d\nAnno iscrizione: %d\nUltimo anno pagamento: %d\nQuota versata: %d\nCodice allenatore: %d\n", insiemeSoci[i].nome, insiemeSoci[i].cognome, insiemeSoci[i].luogoNascita, insiemeSoci[i].dataNascita, insiemeSoci[i].indirizzo, insiemeSoci[i].numeroTessera, insiemeSoci[i].annoIscrizione, insiemeSoci[i].ultimoAnnoPagamento, insiemeSoci[i].quotaVersata, insiemeSoci[i].codiceAllenatore);
        }
    }
}

// Cesare de Cal: Gestione soci
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
            modificareDatiSocioConNomeCognome(insiemeSoci);
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

// Cesare de Cal: Menu principale
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
            mostraMenuStatistiche(insiemeSoci, insiemeAllenatori);
            break;
        default:
            break;
    }
}

// Cesare de Cal: Inizializzazione insieme soci
void inizializzaInsiemeSoci(struct Socio insiemeSoci[]) {
    int i;
    for (i = 0; i < numeroMassimoSoci; i++) {
        insiemeSoci[i].codiceAllenatore = -1;
    }
}

// Cesare de Cal: Inizializzazione insieme allenatori
void inizializzaInsiemeAllenatori(struct Allenatore insiemeAllenatori[]) {
    int i;
    for (i = 0; i < numeroMassimoAllenatori; i++) {
        insiemeAllenatori[i].codiceAllenatore = -1;
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
