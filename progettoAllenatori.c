/*
 Gruppo 1: Progetto Allenatori
 Risorse: - Paolo Valeri
 - Gianluca Tesi
 - Elis Belletta
 - Cesare de Cal
 Consegnare entro: Domenica 3 Aprile 2016
 */

#include <stdio.h>

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
    int codiceAllenatore;
    int pagaOraria;
    int oreEffettuate;
    char cognome[80];
    char nome[80];
};

// Paolo Valeri: Inserimento socio
void inserireNuovoSocio(struct Socio f[]) {
    printf("Inserisci nome ");
    scanf("%s", f[0].nome);
    printf("Inserisci cognome ");
    scanf("%s", f[0].cognome);
    printf("Inserisci luogo di nascita ");
    scanf("%s", f[0].luogoNascita);
    printf("Inserisci data di nascita ");
    scanf("%s", f[0].dataNascita);
    printf("Inserisci indirizzo ");
    scanf("%s", f[0].indirizzo);
    printf("Inserisci numero tessera ");
    scanf("%d", &f[0].numeroTessera);
    printf("Inserisci anno iscrizione");
    scanf("%d", &f[0].annoIscrizione);
    printf("Inserisci ultimo anno pagamento ");
    scanf("%d", &f[0].ultimoAnnoPagamento);
    printf("Inserisci quota versata ");
    scanf("%d", &f[0].quotaVersata);
    printf("Inserisci codice dell' allenatore ");
    scanf("%d", &f[0].codiceAllenatore);
}

// Cesare de Cal: Funzione main
void mostraMenuSoci() {
    printf("-------------------------------------------------------------------------\n");
    printf("1. Inserire nuovo socio\n");
    printf("2. Modificare i dati di un socio gia' presente inseriti nome e cognome\n");
    printf("3. Eliminare un socio inseriti nome e cognome\n");
    printf("4. Visualizzare dati di tutti i soci\n");
    printf("--------------------------------------------------------------------------\n");
    printf("Seleziona opzione menu: ");
    int scelta;
    scanf("%d", &scelta);
    switch (scelta) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            break;
    }
}

// Cesare de Cal: Funzione main
void mostraMenuPrincipale() {
    printf("----------------------------\n");
    printf("1. Gestire i soci\n");
    printf("2. Gestire gli allenatori\n");
    printf("3. Mostrare le statistiche\n");
    printf("----------------------------\n");
    printf("Seleziona opzione menu: ");
    int scelta;
    scanf("%d", &scelta);
    switch (scelta) {
        case 1:
            mostraMenuSoci();
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            break;
    }
}

// Cesare de Cal: Funzione main
int main() {
    struct Socio S[100];
    while (1) {
        mostraMenuPrincipale();
    }
}
