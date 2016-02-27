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

void mostraMenu() {
	printf("1. Gestire i soci\n");
	printf("2. Gestire gli allenatori\n");
	printf("3. Mostrare le statistiche\n");
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

int main() {
	while (1) {
		mostraMenu();
	}
}
