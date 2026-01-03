#include <stdio.h>
#include "data.h"

// typedef struct {
//     int dia;
//     int mes;
//     int ano;
// } Data;

Data criaData(int dia, int mes, int ano) {
	Data d;
	d.dia = dia;
	d.mes = mes;
	d.ano = ano;

	return d;
}

Data lerData() {
	Data d;
	scanf("%2d/%2d/%4d\n", &d.dia, &d.mes, &d.ano);

	return d;
}

int diferencaAnoData(Data inicial, Data atual) {
	int diferenca = atual.ano - inicial.ano;

	if (atual.mes < inicial.mes || (atual.mes == inicial.mes && atual.dia < inicial.dia)) {
		diferenca--;
	}

	return diferenca;
}

void imprimeData(Data d) {
	printf("%02d/%02d/%04d", d.dia, d.mes, d.ano);
}

