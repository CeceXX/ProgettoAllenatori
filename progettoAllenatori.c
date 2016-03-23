/*
 Gruppo 1:
 - Progetto Allenatori e Soci: structs
 Risorse:
 - Paolo Valeri
 - Gianluca Tesi
 - Elis Belletta
 - Cesare de Cal
 Studio fattibilita:
 - http://bit.do/studiofattibilita2
 Consegnare entro:
 - Domenica 3 Aprile 2016
 */

#include <stdio.h>
#include <string.h>
#define numeroMassimoSoci 100
#define numeroMassimoAllenatori 100

// Gianluca Tesi: creazione struct Soci
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

// Paolo Valeri: creazione struct Allenatori
struct Allenatore {
    char cognome[80];
    char nome[80];
    int codiceAllenatore;
    int pagaOraria;
    int oreEffettuate;
};

// Cesare de Cal: funzione extra che facilita l'acquisizione di interi
int acquisisciNumeroCompresoTraValori(int inserimentoMinimoConsentito, int inserimentoMassimoConsentito) {
    int inserimento;
    scanf("%d", &inserimento);
    while ((inserimento < inserimentoMinimoConsentito) || (inserimento > inserimentoMassimoConsentito)) {
        printf("'%d' non e' un inserimento valido. Inserisci un valore compreso tra %d e %d: ", inserimento, inserimentoMinimoConsentito, inserimentoMassimoConsentito);
        scanf("%d", &inserimento);
    }
    return inserimento;
}

// Paolo Valeri: inserimento Allenatore
int trovaPosizioneArraySenzaAllenatore(struct Allenatore insiemeAllenatori[]) {
    int i;
    for (i = 0; i < numeroMassimoAllenatori; i++) {
        if (insiemeAllenatori[i].codiceAllenatore == -1) {
            return i;
        }
    }
    return -1;
}

// Paolo Valeri: Inserimento allenatore
void inserisciNuovoAllenatore(struct Allenatore insiemeAllenatori[]) {
    int i = trovaPosizioneArraySenzaAllenatore(insiemeAllenatori);
    if (i != -1) {
        printf("Inserisci nome: ");
        scanf("%s", insiemeAllenatori[i].nome);
        printf("Inserisci cognome: ");
        scanf("%s", insiemeAllenatori[i].cognome);
        printf("Inserisci codice dell'allenatore: ");
        scanf("%d", &insiemeAllenatori[i].codiceAllenatore);
        printf("Inserisci paga oraria: ");
        scanf("%d", &insiemeAllenatori[i].pagaOraria);
        printf("Inserisci ore effettuate: ");
        scanf("%d", &insiemeAllenatori[i].oreEffettuate);
        insiemeAllenatori[i].codiceAllenatore = i;
    } else {
        printf("Non c'e' sufficiente spazio per poter inserire un nuovo Allenatore. Considera eliminare un Allenatore.\n");
    }
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

void visualizzaSoci(struct Socio insiemeSoci[]) {
    int i;
    for (i = 0; i < numeroMassimoSoci; i++) {
        if (insiemeSoci[i].codiceAllenatore != -1) {
            printf("Nome: %s\nCognome: %s\nLuogo di nascita: %s\nData di nascita: %s\nIndirizzo: %s\nNumero tessera: %d\nAnno iscrizione: %d\nUltimo anno pagamento: %d\nQuota versata: %d\nCodice allenatore: %d\n", insiemeSoci[i].nome, insiemeSoci[i].cognome, insiemeSoci[i].luogoNascita, insiemeSoci[i].dataNascita, insiemeSoci[i].indirizzo, insiemeSoci[i].numeroTessera, insiemeSoci[i].annoIscrizione, insiemeSoci[i].ultimoAnnoPagamento, insiemeSoci[i].quotaVersata, insiemeSoci[i].codiceAllenatore);
        }
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
            inserisciNuovoAllenatore(insiemeAllenatori);
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            break;
    }
}

// Elis Belletta: Anno soci
void visualizzaSociDatoAnnoInscrizione(struct Socio insiemeSoci[]) {
    printf("Inserisci l'anno d'iscrizione per cercare i soci: ");
    int annoInserito = acquisisciNumeroCompresoTraValori(0, 10000);
    int i, trovatoAlmenoUnSocio = 0;
    for(i = 0; i < numeroMassimoSoci; i++) {
        if (insiemeSoci[i].annoIscrizione == annoInserito) {
            printf("Ho trovato un socio con nome %s e cognome %s che si e' iscritto nell'anno %d.\n", insiemeSoci[i].nome, insiemeSoci[i].cognome, insiemeSoci[i].annoIscrizione);
            trovatoAlmenoUnSocio = 1;
        }
    }
    if (!trovatoAlmenoUnSocio) {
        printf("Non ho trovato soci iscritti nell'anno %d.\n", annoInserito);
    }
}

// Cesare De Cal: Funzione supplementare per modificare e eliminare un socio
int trovaPosizioneArraySocioConNomeCognome(struct Socio insiemeSoci[]) {
    char nome[100], cognome[100];
    printf("Inserisci nome: ");
    scanf("%s", nome);
    printf("Inserisci cognome: ");
    scanf("%s", cognome);
    
    int i;
    for (i = 0; i < numeroMassimoSoci; i++) {
        if ((strcmp(nome, insiemeSoci[i].nome) && strcmp(cognome, insiemeSoci[i].cognome)) == 0) {
            return i;
        }
    }
    return -1;
}

// Gianluca Tesi: Eliminazione socio
void eliminaSocio(struct Socio insiemeSoci[]) {
    int i = trovaPosizioneArraySocioConNomeCognome(insiemeSoci);
    if (i != -1) {
        insiemeSoci[i].codiceAllenatore = -1;
    } else {
        printf("Non ho trovato soci da eliminare.\n");
    }
}

// Paolo Valeri: Modifica Dati Soci
void modificaSocio(struct Socio insiemeSoci[]) {
    int i = trovaPosizioneArraySocioConNomeCognome(insiemeSoci);
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
            printf("---------------------------------------------------------------------------\n");
            printf("Inserisci il numero dell'opzione vuoi modificare oppure termina digitando 10: ");
            scelta = acquisisciNumeroCompresoTraValori(1, 10);
            switch (scelta) {
                case 1:
                    printf("Il nome attuale e' %s. Inserisci il nuovo nome: ", insiemeSoci[i].nome);
                    scanf("%s", insiemeSoci[i].nome);
                    break;
                case 2:
                    printf("Il cognome attuale e' %s. Inserisci il nuovo cognome: ", insiemeSoci[i].cognome);
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
        } while (scelta != 10);
    } else {
        //printf("Non ho trovato il socio con nome %s e cognome %s.\n", nome, cognome);
    }
}

// Elis Belletta: Inserimento socio
void inserisciNuovoSocio(struct Socio insiemeSoci[]) {
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

// Cesare de Cal: Gestione soci
void mostraMenuSoci(struct Socio insiemeSoci[]) {
    printf("-------------------------------------------------------------------------\n");
    printf("1. Inserire nuovo socio\n");
    printf("2. Modificare i dati di un socio gia' presente inseriti nome e cognome\n");
    printf("3. Eliminare un socio inseriti nome e cognome\n");
    printf("4. Visualizzare dati di tutti i soci\n");
    printf("5. Individuare soci con un preciso anno di iscrizione\n");
    printf("-------------------------------------------------------------------------\n");
    printf("Seleziona opzione menu: ");
    int scelta = acquisisciNumeroCompresoTraValori(1, 5);
    switch (scelta) {
        case 1:
            inserisciNuovoSocio(insiemeSoci);
            break;
        case 2:
            modificaSocio(insiemeSoci);
            break;
        case 3:
            eliminaSocio(insiemeSoci);
            break;
        case 4:
            visualizzaSoci(insiemeSoci);
            break;
        case 5:
            visualizzaSociDatoAnnoInscrizione(insiemeSoci);
            break;
        default:
            break;
    }
}

// Elis Belletta: gestione file
void salvaModificheSuFile(struct Socio insiemeSoci[], FILE *fileTesto) {
    fclose(fileTesto);
    fprintf(fileTesto, "");
}

// Elis Belletta: gestione file
void inizializzaFile(FILE *fileTesto) {
    fileTesto = fopen("datiSoci.txt", "w+");
    if (fileTesto == NULL) {
        perror("Impossibiile aprire il file.\n");
    }
    
    // Leggi dal file e importa i dati presenti nel file con fscanf
}

// Cesare de Cal: Menu principale
void mostraMenuPrincipale(struct Socio insiemeSoci[], struct Allenatore insiemeAllenatori[], FILE *fileTesto) {
    printf("----------------------------\n");
    printf("1. Gestire i soci\n");
    printf("2. Gestire gli allenatori\n");
    printf("3. Mostrare le statistiche\n");
    printf("4. Salva modifiche su file\n");
    printf("----------------------------\n");
    printf("Seleziona un'opzione del menu: ");
    int scelta = acquisisciNumeroCompresoTraValori(1, 4);
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
        case 4:
            salvaModificheSuFile(insiemeSoci, fileTesto);
            break;
        default:
            break;
    }
}

// Cesare de Cal: Inizializzazione insieme allenatori
void inizializzaInsiemeAllenatori(struct Allenatore insiemeAllenatori[]) {
    int i;
    for (i = 0; i < numeroMassimoAllenatori; i++) {
        insiemeAllenatori[i].codiceAllenatore = -1;
    }
}

// Cesare de Cal: Inizializzazione insieme soci
void inizializzaInsiemeSoci(struct Socio insiemeSoci[]) {
    int i;
    for (i = 0; i < numeroMassimoSoci; i++) {
        insiemeSoci[i].codiceAllenatore = -1;
    }
}

// Cesare de Cal: Funzione main
int main() {
    struct Socio insiemeSoci[numeroMassimoSoci];
    struct Allenatore insiemeAllenatori[numeroMassimoAllenatori];
    inizializzaInsiemeSoci(insiemeSoci);
    inizializzaInsiemeAllenatori(insiemeAllenatori);
    
    FILE *fileTesto;
    inizializzaFile(fileTesto);
    
    while (1) {
        mostraMenuPrincipale(insiemeSoci, insiemeAllenatori, fileTesto);
    }
}
