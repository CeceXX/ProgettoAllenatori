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

// MARK: Strutture e costanti

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

// MARK: Gestione statistiche

// Cesare de Cal
int ottieniAnnoCorrente() {
    printf("Inserisci l'anno (corrente o un altro): ");
    return acquisisciNumeroCompresoTraValori(0, 1000);
}

// Cesare de Cal
void determinaIncassoTotaleSoci(struct Socio insiemeSoci[]) {
    int i, incassoTotale = 0;
    for (i = 0; i < numeroMassimoSoci; i++) {
        if (insiemeSoci[i].codiceAllenatore != -1) {
            incassoTotale += insiemeSoci[i].quotaVersata;
        }
    }
    
    printf("L'incasso totale e' %d.\n", incassoTotale);
}

// Cesare de Cal: soci paganti anno corrente e incasso
void visualizzaSociPagantiAnnoCorrente(struct Socio insiemeSoci[]) {
    int annoCorrente = ottieniAnnoCorrente(), i, almenoUnSocioTrovato = 0;
    for (i = 0; i < numeroMassimoSoci; i++) {
        if (insiemeSoci[i].codiceAllenatore != -1) {
            if (insiemeSoci[i].ultimoAnnoPagamento == annoCorrente) {
                printf("Il socio con nome %s e cognome %s ha pagato quest'anno.\n", insiemeSoci[i].nome, insiemeSoci[i].cognome);
                almenoUnSocioTrovato = 1;
            }
        }
    }
    
    if (!almenoUnSocioTrovato) {
        printf("Non ho trovato alcun socio.\n");
    }
}

// Cesare de Cal
void determinaSociInscrittiDeterminatoAnno(struct Socio insiemeSoci[]) {
    int annoInserito = ottieniAnnoCorrente(), i;
    for (i = 0; i < numeroMassimoSoci; i++) {
        if (insiemeSoci[i].codiceAllenatore != -1) {
            if (insiemeSoci[i].annoIscrizione == annoInserito) {
                printf("Socio con nome %s %s si e' iscritto nell'anno %d.\n", insiemeSoci[i].nome, insiemeSoci[i].cognome, annoInserito);
            }
        }
    }
    
}

// Cesare de Cal
void determinaSocioConQuotaMinore(struct Socio insiemeSoci[]) {
    int codiceSocioConQuotaMinore = -1, i, quotaMinore = 0;
    for (i = 0; i < numeroMassimoSoci; i++) {
        if (insiemeSoci[i].codiceAllenatore != -1) {
            if (insiemeSoci[i].quotaVersata >= quotaMinore) {
                codiceSocioConQuotaMinore = insiemeSoci[i].codiceAllenatore;
                quotaMinore = insiemeSoci[i].quotaVersata;
            }
        }
    }
    if (codiceSocioConQuotaMinore != -1) {
        printf("Il socio con quota minore si chiama %s %s e ha codice %d\n", insiemeSoci[codiceSocioConQuotaMinore].nome, insiemeSoci[codiceSocioConQuotaMinore].cognome, insiemeSoci[codiceSocioConQuotaMinore].codiceAllenatore);
    } else {
        printf("Non ho trovato soci nel database.\n");
    }
}

// Cesare de Cal
void determinaSociSeguitiDaAllenatore(struct Socio insiemeSoci[], struct Allenatore insiemeAllenatori[]) {
    int i, p;
    char nomeAllenatore[100], cognomeAllenatore[100];
    printf("Inserisci nome allenatore: ");
    scanf("%s", nomeAllenatore);
    printf("Inserisci cognome allenatore: ");
    scanf("%s", cognomeAllenatore);
    
    for (i = 0; i < numeroMassimoAllenatori; i++) {
        if (insiemeAllenatori[i].codiceAllenatore != -1) {
            if (strcpy(insiemeAllenatori[i].nome, nomeAllenatore) == 0 && strcpy(insiemeAllenatori[i].cognome, cognomeAllenatore)) {
                for (p = 0; p < numeroMassimoSoci; p++) {
                    if (insiemeSoci[p].codiceAllenatore != -1) {
                        if (insiemeAllenatori[i].codiceAllenatore == insiemeSoci[p].codiceAllenatore) {
                            printf("Allenatore %s %s segue socio %s %s.\n", insiemeAllenatori[i].nome, insiemeAllenatori[i].cognome, insiemeSoci[p].nome, insiemeSoci[p].cognome);
                        }
                    }
                }
            }
        }
    }
}

void bubbleSort(int vettore[], int lunghezzaArray) {
    int tmp;
    for (int i = 0; i < lunghezzaArray-1; i++) {
        if (vettore[i] > vettore[i+1]) {
            tmp = vettore[i];
            vettore[i] = vettore[i+1];
            vettore[i+1] = tmp;
        }
    }
}

void stampaOrdineDecrescentePagaOrariaAllenatori(struct Allenatore insiemeAllenatori[]) {
    int pagaOraria[numeroMassimoAllenatori];
    int i, z = 0;
    for (i = 0; i < numeroMassimoAllenatori; i++) {
        if (insiemeAllenatori[i].codiceAllenatore != -1) {
            pagaOraria[z] = insiemeAllenatori[i].pagaOraria;
            z++;
        }
    }
    bubbleSort(pagaOraria, numeroMassimoAllenatori);
    for (i = numeroMassimoAllenatori; i < 0; i--) {
        printf("La paga oraria e' %d\n.", pagaOraria[i]);
    }
}

// Cesare de Cal: funzione main
void mostraMenuStatistiche(struct Socio insiemeSoci[], struct Allenatore insiemeAllenatori[]) {
    printf("--------------------------------------------------------------------------------------\n");
    printf("1. Stampare quanti sono i soci che hanno pagato nell'anno corrente e l'incasso totale\n");
    printf("2. Stampare il socio che ha pagato la quota minore\n");
    printf("3. Stampare tutti i soci che hanno pagato nell'anno corrente\n");
    printf("4. Stampare tutti i soci che si sono iscritti in un dato anno inserito dall'utente\n");
    printf("5. Inseriti nome e cognome di un allenatore visualizzare tutti i soci che segue\n");
    printf("6. Stampare il nome e il cognome dell'allenatore che segue più soci\n");
    printf("7. Stampare in ordine decrescente di retribuzione gli allenatori\n");
    printf("--------------------------------------------------------------------------------------\n");
    printf("Seleziona opzione menu: ");
    int scelta = acquisisciNumeroCompresoTraValori(1, 7);
    switch (scelta) {
        case 1:
            visualizzaSociPagantiAnnoCorrente(insiemeSoci);
            determinaIncassoTotaleSoci(insiemeSoci);
            break;
        case 2:
            determinaSocioConQuotaMinore(insiemeSoci);
            break;
        case 3:
            visualizzaSociPagantiAnnoCorrente(insiemeSoci);
            break;
        case 4:
            determinaSociInscrittiDeterminatoAnno(insiemeSoci);
            break;
        case 5:
            determinaSociSeguitiDaAllenatore(insiemeSoci, insiemeAllenatori);
            break;
        case 6:
            break;
        case 7:
            break;
        default:
            break;
    }
}

// MARK: Gestione allenatori

// Elis Belletta: gestione file
void importaDatiSociInMemoria(FILE *fileTesto, struct Socio insiemeSoci[]) {
	char datiSoci[1000];
	//fscanf(fileTesto, "%s", datiSoci);
	//fprintf(fileTesto, "%s", datiSoci);
	
	fclose(fileTesto);
}

// Elis Belletta: gestione file
void importaDatiAllenatoriInMemoria(FILE *fileTesto, struct Allenatore insiemeAllenatori[]) {
    char datiAllenatore[1000];
    //fscanf(fileTesto, "%s", datiAllenatore);
}

void visualizzaAllenatori(struct Allenatore insiemeAllenatori[]) {
    int i, almenoUnAllenatoreTrovato = 0;
    for (i = 0; i < numeroMassimoAllenatori; i++) {
        if (insiemeAllenatori[i].codiceAllenatore != -1) {
            printf("Nome: %s\nCognome: %s\nPaga oraria: %d\nOre effettuate: %d\nCodice allenatore: %d\n", insiemeAllenatori[i].nome, insiemeAllenatori[i].cognome, insiemeAllenatori[i].pagaOraria, insiemeAllenatori[i].oreEffettuate, insiemeAllenatori[i].codiceAllenatore);
            almenoUnAllenatoreTrovato = 1;
        }
    }
    if (!almenoUnAllenatoreTrovato) {
        printf("Non ci sono allenatori nel database.\n");
    }
}

// Elis Belletta: Funzione supplementare per modificare e eliminare un allenatore
int trovaPosizioneArrayAllenatoreConNomeCognome(struct Allenatore insiemeAllenatori[]) {
    char nome[100], cognome[100];
    printf("Inserisci nome: ");
    scanf("%s", nome);
    printf("Inserisci cognome: ");
    scanf("%s", cognome);
    
    int i;
    for (i = 0; i < numeroMassimoAllenatori; i++) {
        if ((strcmp(nome, insiemeAllenatori[i].nome) && strcmp(cognome, insiemeAllenatori[i].cognome)) == 0) {
            return i;
        }
    }
    return -1;
}

void eliminaAllenatore(struct Allenatore insiemeAllenatori[]) {
    int i = trovaPosizioneArrayAllenatoreConNomeCognome(insiemeAllenatori);
    if (i != -1) {
        insiemeAllenatori[i].codiceAllenatore = -1;
    }
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

void modificaAllenatore(struct Allenatore insiemeAllenatori[]) {
    int i = trovaPosizioneArraySenzaAllenatore(insiemeAllenatori);
    if (i != -1) {
        int scelta;
        do {
            printf("---------------------------------------------------------------------------\n");
            printf("1. Nome\n");
            printf("2. Cognome\n");
            printf("3. Paga oraria\n");
            printf("4. Ore effettuate\n");
            printf("---------------------------------------------------------------------------\n");
            printf("Inserisci il numero dell'opzione vuoi modificare oppure termina digitando 5: ");
            scelta = acquisisciNumeroCompresoTraValori(1, 5);
            switch (scelta) {
                case 1:
                    printf("Il nome attuale e' %s. Inserisci il nuovo nome: ", insiemeAllenatori[i].nome);
                    scanf("%s", insiemeAllenatori[i].nome);
                    break;
                case 2:
                    printf("Il cognome attuale e' %s. Inserisci il nuovo cognome: ", insiemeAllenatori[i].cognome);
                    scanf("%s", insiemeAllenatori[i].cognome);
                    break;
                case 3:
                    printf("Inserisci la paga oraria: ");
                    scanf("%d", &insiemeAllenatori[i].pagaOraria);
                    break;
                case 4:
                    printf("Inserisci le ore effettuate: ");
                    scanf("%d", &insiemeAllenatori[i].oreEffettuate);
                    printf("Inserisci indirizzo: ");
                    break;
                default:
                    break;
            }
        } while (scelta != 5);
    } else {
        printf("Non ho trovato l'allenatore con il nome e cognome che hai inserito.\n");
    }
}

// Cesare de Cal: inserimento allenatore
void inserisciAllenatore(struct Allenatore insiemeAllenatori[]) {
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
        printf("Non c'e' sufficiente spazio per poter inserire un nuovo allenatore. Considera eliminarne uno.\n");
    }
}

// Cesare de Cal: Funzione main
void mostraMenuAllenatori(struct Allenatore insiemeAllenatori[]) {
    printf("---------------------------------------------------------------------------\n");
    printf("1. Inserire un nuovo allenatore\n");
    printf("2. Modificare i dati di un allenatore già presente inseriti nome e cognome\n");
    printf("3. Eliminare un allenatore inseriti nome e cognome\n");
    printf("4. Visualizzare i dati di tutti gli allenatori\n");
    printf("5. Torna indietro\n");
    printf("---------------------------------------------------------------------------\n");
    printf("Seleziona un'opzione del menu: ");
    int scelta = acquisisciNumeroCompresoTraValori(1, 4);
    switch (scelta) {
        case 1:
            inserisciAllenatore(insiemeAllenatori);
            break;
        case 2:
            modificaAllenatore(insiemeAllenatori);
            break;
        case 3:
            eliminaAllenatore(insiemeAllenatori);
            break;
        case 4:
            visualizzaAllenatori(insiemeAllenatori);
        default:
            break;
    }
}

// MARK: Gestione soci

// Elis Belletta: gestione file
void salvaDatiSociSuFile(struct Socio insiemeSoci[], FILE *fileTesto) {
    fprintf(fileTesto, "");
    fclose(fileTesto);
}

// Paolo Valeri: inserimento socio
int trovaPosizioneArraySenzaSocio(struct Socio insiemeSoci[]) {
    int i;
    for (i = 0; i < numeroMassimoSoci; i++) {
        if (insiemeSoci[i].codiceAllenatore == -1) {
            return i;
        }
    }
    return -1;
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

// Elis Belletta: visualizzazione socio
void visualizzaSoci(struct Socio insiemeSoci[]) {
    int i, almenoUnSocioTrovato = 0;
    for (i = 0; i < numeroMassimoSoci; i++) {
        if (insiemeSoci[i].codiceAllenatore != -1) {
            printf("Nome: %s\nCognome: %s\nLuogo di nascita: %s\nData di nascita: %s\nIndirizzo: %s\nNumero tessera: %d\nAnno iscrizione: %d\nUltimo anno pagamento: %d\nQuota versata: %d\nCodice allenatore: %d\n", insiemeSoci[i].nome, insiemeSoci[i].cognome, insiemeSoci[i].luogoNascita, insiemeSoci[i].dataNascita, insiemeSoci[i].indirizzo, insiemeSoci[i].numeroTessera, insiemeSoci[i].annoIscrizione, insiemeSoci[i].ultimoAnnoPagamento, insiemeSoci[i].quotaVersata, insiemeSoci[i].codiceAllenatore);
            almenoUnSocioTrovato = 1;
        }
    }
    if (!almenoUnSocioTrovato) {
        printf("Non ci sono soci nel database.\n");
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

// Gianluca Tesi: eliminazione socio
void eliminaSocio(struct Socio insiemeSoci[]) {
    int i = trovaPosizioneArraySocioConNomeCognome(insiemeSoci);
    if (i != -1) {
        insiemeSoci[i].codiceAllenatore = -1;
    } else {
        printf("Non ho trovato soci con il nome e cognome che hai inserito.\n");
    }
}

// Paolo Valeri: modifica socio
void modificaSocio(struct Socio insiemeSoci[]) {
    int i = trovaPosizioneArraySocioConNomeCognome(insiemeSoci);
    if (i != -1) {
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
        printf("Non ho trovato soci con il nome e cognome che hai inserito.\n");
    }
}

// Elis Belletta: inserimento socio
void inserisciSocio(struct Socio insiemeSoci[]) {
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
    printf("6. Torna indietro\n");
    printf("-------------------------------------------------------------------------\n");
    printf("Seleziona opzione menu: ");
    int scelta = acquisisciNumeroCompresoTraValori(1, 6);
    switch (scelta) {
        case 1:
            inserisciSocio(insiemeSoci);
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

// MARK: Inizializzazione programma

// Cesare de Cal: Menu principale
void mostraMenuPrincipale(struct Socio insiemeSoci[], struct Allenatore insiemeAllenatori[], FILE *fileTestoSoci, FILE *fileTestoAllenatori) {
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
            salvaDatiSociSuFile(insiemeSoci, fileTestoSoci);
            break;
        default:
            break;
    }
}

// Elis Belletta: gestione file
int inizializzaFileAllenatori(FILE *fileTestoAllenatori) {
    fileTestoAllenatori = fopen("datiAllenatori.txt", "ab+");
    if (fileTestoAllenatori != NULL) {
        return 0;
    } else {
        perror("Impossibiile aprire il file allenatori.\n");
        return 1;
    }
}

// Elis Belletta: gestione file
int inizializzaFileSoci(FILE *fileTestoSoci) {
    fileTestoSoci = fopen("datiSoci.txt", "ab");
    if (fileTestoSoci != NULL) {
        return 0;
    } else {
        perror("Impossibiile aprire il file soci.\n");
        return 1;
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
    
    FILE *fileTestoSoci;
    FILE *fileTestoAllenatori;
    if (inizializzaFileSoci(fileTestoSoci) == 0) {
        importaDatiSociInMemoria(fileTestoSoci, insiemeSoci);
    } else {
        printf("Errore a inizializzare file!\n");
    }
    
    if (inizializzaFileAllenatori(fileTestoAllenatori) == 0) {
        importaDatiAllenatoriInMemoria(fileTestoAllenatori, insiemeAllenatori);
    }
    
    while (1) {
        mostraMenuPrincipale(insiemeSoci, insiemeAllenatori, fileTestoSoci, fileTestoAllenatori);
    }
}
