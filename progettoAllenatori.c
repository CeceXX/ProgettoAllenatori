/*
    Gruppo 1
    Progetto Allenatori
    Risorse: - Paolo Valeri
             - Gianluca Tesi
             - Elis Belletta
             - Cesare de Cal
    Consegnare entro:
            - 3 aprile
 */

#include <stdio.h>

struct Socio {
	int numeroTessera;
	int annoIscrizione;
	int ultimoAnnoPagamento;
	int quotaVersata;
	int codiceAllenatore;
	char nome[80];
	char cognome[80];
	char luogoNascita[80];
	char dataNascita[80];
	char indirizzo[80];
};

struct Allenatore {
	int codiceAllenatore;
	int pagaOraria;
	int oreEffettuate;
	char cognome[80];
	char nome[80];
};

void inserireNuovoSocio(struct Socio f[]) {
    //int numeroTessera, annoIscrizione, ultimoAnnoPagamento, quotaVersata, codiceAllenatore;
    //char nome[80], cognome[80], luogoNascita[80], dataNascita[80], indirizzo[80];

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
    printf("Inserisci nome ");
    scanf("%s", &f[0].nome);
    printf("Inserisci cognome ");
    scanf("%s", &f[0].cognome);
    printf("Inserisci luogo di nascita ");
    scanf("%s", &f[0].luogoNascita);
    printf("Inserisci data di nascita ");
    scanf("%s", &f[0].dataNascita);
    printf("Inserisci indirizzo ");
    scanf("%s", &f[0].indirizzo);


//    struct Socio membroPalestra = {numeroTessera, annoIscrizione, ultimoAnnoPagamento, quotaVersata, codiceAllenatore, nome, cognome, luogoNascita, dataNascita, indirizzo};
}

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

void mostraMenu() {
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

int main() {
    struct Socio S[100];
	while (1) {
		mostraMenu();
	}
}
