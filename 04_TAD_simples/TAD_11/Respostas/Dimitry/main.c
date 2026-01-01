#include <stdio.h>
#include "loja.h"
#include "vendedor.h"

int main() {
	int maxLojas, op, nLojas = 0;
	scanf("%d\n", &maxLojas);

	tLoja lojas[maxLojas];

	do {
		scanf("%d\n", &op);

		if (op == 1) {
			int id;
			float aluguel;
			scanf("%d %f\n", &id, &aluguel);

			lojas[nLojas++] = AbreLoja(id, aluguel);
		} else if (op == 2) {
			int loja;
			char buffer[50];
			float salario, prctg;
			scanf("%s %f %f\n", buffer, &salario, &prctg);
			scanf("%d\n", &loja);
			for (int i = 0; i < nLojas; i++) {
				if (VerificaIdLoja(lojas[i], loja)) {
					loja = i;
					break;
				}
			}
			lojas[loja] = ContrataVendedor(lojas[loja], RegistraVendedor(buffer, salario, prctg));
		} else if (op == 3) {
			int loja;
			float valor;
			char buffer[50];
			scanf("%d %s %f", &loja, buffer, &valor);
			for (int i = 0; i < nLojas; i++) {
				if (VerificaIdLoja(lojas[i], loja)) {
					loja = i;
					break;
				}
			}
			lojas[loja] = RegistraVenda(lojas[loja], buffer,  valor);
		} else if (op == 4) {
			for (int i = 0; i < nLojas; i++) {
				lojas[i] = CalculaLucro(lojas[i]);
				ImprimeRelatorioLoja(lojas[i]);
			}
		}

	} while (op != 0);

	return 0;
}
