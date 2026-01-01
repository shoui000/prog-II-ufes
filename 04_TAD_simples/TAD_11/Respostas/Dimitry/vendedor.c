#include <string.h>
#include <stdio.h>
#include "vendedor.h"

// typedef struct Vendedor {
//     char nome[50]; /**< Nome do vendedor */
//     float valor_vendido; /**< Valor total vendido pelo vendedor */
//     float salario; /**< Salário base do vendedor */
//     float prct_comissao; /**< Porcentagem de comissão do vendedor */
// } tVendedor;

tVendedor RegistraVendedor(char nome[50], float salario, float prct_comissao) {
	tVendedor v;
	strcpy(v.nome, nome);
	v.salario = salario;
	v.prct_comissao = prct_comissao;
	v.valor_vendido = 0;

	return v;
}

int VerificaNomeVendedor(tVendedor vendedor, char nome[50]) {
	return strcmp(vendedor.nome, nome) == 0;
}

tVendedor ContabilizaVenda(tVendedor vendedor, float valor) {
	vendedor.valor_vendido += valor;
	return vendedor;
}

float GetSalario(tVendedor vendedor) {
	return vendedor.salario;
}

float GetComissao(tVendedor vendedor) {
	return (vendedor.prct_comissao * vendedor.valor_vendido);
}

float GetTotalVendido(tVendedor vendedor) {
	return vendedor.valor_vendido;
}

float GetTotalRecebido(tVendedor vendedor) {
	return (GetComissao(vendedor)) + vendedor.salario;
}

void ImprimeRelatorioVendedor(tVendedor vendedor) {
	printf("\t%s > Total vendido: R$%.02f\n", vendedor.nome, vendedor.valor_vendido);
	printf("\t\tTotal recebido: R$%.02f\n", GetTotalRecebido(vendedor));
}
