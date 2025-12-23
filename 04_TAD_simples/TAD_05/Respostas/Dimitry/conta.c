#include <stdio.h>
#include "conta.h"
#include "usuario.h"

tConta CriaConta(int numero, tUsuario user) {
    tConta c;
    c.numero = numero;
    c.user = user;
    c.saldo = 0;

    return c;
}

void ImprimeConta(tConta conta) {
    printf("Conta: %d\n", conta.numero);
    printf("Saldo: R$ %.2f\n", conta.saldo);
    ImprimeUsuario(conta.user);
}

int VerificaConta(tConta conta, int numero) {
    return conta.numero == numero;
}

tConta SaqueConta(tConta conta, float valor) {
    conta.saldo -= valor;
    return conta;
}

tConta DepositoConta(tConta conta, float valor) {
    conta.saldo += valor;
    return conta;
}
