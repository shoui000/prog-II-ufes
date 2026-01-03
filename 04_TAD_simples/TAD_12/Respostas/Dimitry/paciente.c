#include <stdio.h>
#include <string.h>
#include "paciente.h"
#include "data.h"
#include "lesao.h"

// #define MAX_NOME_PAC 101
// #define MAX_CARTAO_SUS 19
// #define MAX_LESOES 10
//
// typedef struct {
//     char nome[MAX_NOME_PAC];    
//     char cartaoSus[MAX_CARTAO_SUS];
//     char genero;
//     Data dataNasc;   
//     Lesao lesoes[MAX_LESOES]; 
//     int numLesoes;
// } Paciente;

Paciente criaPaciente(char *nome, char *cartaoSus, char genero, Data dataNasc) {
	Paciente p;

	strcpy(p.nome, nome);
	strcpy(p.cartaoSus, cartaoSus);
	p.genero = genero;
	p.dataNasc = dataNasc;
	p.numLesoes = 0;

	return p;
}

Paciente lerPaciente() {
	char nome[MAX_NOME_PAC];
	char cartaoSus[MAX_CARTAO_SUS];
	char genero;

	scanf(" %[^\n]\n", nome);
	Data dataNasc = lerData();
	scanf(" %[^\n]\n", cartaoSus);
	scanf(" %c\n", &genero);

	return criaPaciente(nome, cartaoSus, genero, dataNasc);
}

Paciente vinculaLesaoPaciente(Paciente p, Lesao l) {
	if (p.numLesoes < MAX_LESOES) {
		p.lesoes[p.numLesoes++] = l;
	}

	return p;
}

int calculaIdadePaciente(Paciente p, Data dataBase) {
	return diferencaAnoData(p.dataNasc, dataBase);
}

void getCartaoSusPaciente(Paciente p, char *cartaoSus) {
	strcpy(cartaoSus, p.cartaoSus);
}

int getNumLesoesPaciente(Paciente p) {
	return p.numLesoes;
}

int qtdLesoesCirurgicasPaciente(Paciente p) {
	int sum = 0;

	for (int i = 0; i < p.numLesoes; i++) {
		if (verificaCirurgicaLesao(p.lesoes[i]))
			sum++;
	}

	return sum;
}

void imprimePaciente(Paciente p) {
	if (p.numLesoes == 0) {
		return;
	}

	printf("- %s - ", p.nome);

	for (int i = 0; i < p.numLesoes; i++) {
		if (i != 0)
			putchar(' ');

		imprimeIdLesao(p.lesoes[i]);
	}

	putchar('\n');
}
