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

int main() {
}