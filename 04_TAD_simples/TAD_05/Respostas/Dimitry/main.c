#include <stdio.h>
#include "conta.h"
#include "usuario.h"

int main() {
    int maxContas, qtdContas = 0, option;

    scanf("%d\n", &maxContas);

    tConta contas[maxContas];

    do {
        scanf("%d\n", &option);

        if (option == 1) {
            int idConta;
            float valor;
            scanf("%d %f\n", &idConta, &valor);

            for (int i = 0; i < qtdContas; i++) {
                if (VerificaConta(contas[i], idConta))
                    contas[i] = SaqueConta(contas[i], valor);
            }
        } else if (option == 2) {
            int idConta;
            float valor;
            scanf("%d %f\n", &idConta, &valor);

            for (int i = 0; i < qtdContas; i++) {
                if (VerificaConta(contas[i], idConta))
                    contas[i] = DepositoConta(contas[i], valor);
            }
        } else if (option == 3) {
            char nome[50], cpf[15];
            int idConta;

            scanf("%s %s %d\n", nome, cpf, &idConta);

            if (qtdContas < maxContas) {
                tUsuario u = CriaUsuario(nome, cpf);
                contas[qtdContas++] = CriaConta(idConta, u);
            }
        } else if (option == 4) {
            printf("===| Imprimindo Relatorio |===\n");
            for (int i = 0; i < qtdContas; i++) {
                ImprimeConta(contas[i]);
                putchar('\n');
            }
        }

    } while (option != 0);

    return 0;
}