#include <stdio.h>
#include <string.h>
#include "lesao.h"

// #define MAX_CARTAO_LES 19
// #define MAX_ID_LES 11
// #define MAX_DIAG_LES 101
// #define MAX_REG_LES 101
//
// typedef struct {
//     char cartaoSus[MAX_CARTAO_LES];
//     char id[MAX_ID_LES];
//     char diagnostico[MAX_DIAG_LES];
//     char regiao[MAX_REG_LES];
//     int malignidade;
// } Lesao;

Lesao criaLesao(char *cartaoSus, char *id, char *diagnostico, char *regiao, int malignidade) {
	Lesao l;
	strcpy(l.cartaoSus, cartaoSus);
	strcpy(l.id, id);
	strcpy(l.diagnostico, diagnostico);
	strcpy(l.regiao, regiao);
	l.malignidade = malignidade;

	return l;
}

Lesao lerLesao() {
	char cartaoSus[MAX_CARTAO_LES];
	char id[MAX_ID_LES];
	char diagnostico[MAX_DIAG_LES];
	char regiao[MAX_REG_LES];
	int malignidade;

	scanf(" %[^\n]\n", cartaoSus);
	scanf(" %[^\n]\n", id);
	scanf(" %[^\n]\n", diagnostico);
	scanf(" %[^\n]\n", regiao);
	scanf(" %d\n", &malignidade);

	return criaLesao(cartaoSus, id, diagnostico, regiao, malignidade);
}

void getCartaoSusLesao(Lesao l, char *cartaoSus) {
	strcpy(cartaoSus, l.cartaoSus);
}

int verificaCirurgicaLesao(Lesao l) {
	return l.malignidade > 50;
}

void imprimeIdLesao(Lesao l) {
	printf("%s", l.id);
}

