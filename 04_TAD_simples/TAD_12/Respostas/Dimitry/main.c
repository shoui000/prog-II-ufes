#include <stdio.h>
#include <string.h>
#include "lesao.h"
#include "paciente.h"
#include "data.h"

int main() {
	Paciente pacientes[100];
	int qtdPct = 0;

	char op;

	do {
		scanf("%c\n", &op);

		if (op == 'P' && qtdPct < 100) {
			pacientes[qtdPct++] = lerPaciente();
		} else if (op == 'L') {
			Lesao l = lerLesao();

			char cartaoSusLesao[MAX_CARTAO_SUS], cartaoSusPct[MAX_CARTAO_SUS];
			getCartaoSusLesao(l, cartaoSusLesao);

			for (int i = 0; i < qtdPct; i++) {
				getCartaoSusPaciente(pacientes[i], cartaoSusPct);

				if (strcmp(cartaoSusLesao, cartaoSusPct) == 0) {
					pacientes[i] = vinculaLesaoPaciente(pacientes[i], l);
					break;
				}
			}
		}

	} while (op != 'F');

	Data hoje = criaData(12, 9, 2023);

	int somaIdades = 0, qtdLesoes = 0, qtdCir = 0;
	
	for (int i = 0; i < qtdPct; i++) {
		somaIdades += calculaIdadePaciente(pacientes[i], hoje);
		qtdLesoes += getNumLesoesPaciente(pacientes[i]);
		qtdCir += qtdLesoesCirurgicasPaciente(pacientes[i]);
	}

	printf("TOTAL PACIENTES: %d\n", qtdPct);

	if (qtdPct > 0) {
		printf("MEDIA IDADE (ANOS): %d\n", somaIdades / qtdPct);
	} else {
		printf("MEDIA IDADE (ANOS): -\n");
	}

	printf("TOTAL LESOES: %d\n", qtdLesoes);
	printf("TOTAL CIRURGIAS: %d\n", qtdCir);
	printf("LISTA DE PACIENTES:\n");

	for (int i = 0; i < qtdPct; i++) {
		imprimePaciente(pacientes[i]);
	}

	return 0;
}
