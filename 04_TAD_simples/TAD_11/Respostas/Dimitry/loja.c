#include "loja.h"
#include "vendedor.h"
#include <stdio.h>

// #define MAX_VENDEDORES 10 /**< Número máximo de vendedores que uma loja pode ter */

// typedef struct Loja {
//     int id; /**< ID da loja */
//     int totalVendedores; /**< Número total de vendedores da loja */
//     float aluguel; /**< Valor do aluguel da loja */
//     float lucro; /**< Lucro da loja */
//     tVendedor vendedores[MAX_VENDEDORES]; /**< Vetor de vendedores da loja */
// } tLoja;

tLoja AbreLoja(int id, float aluguel) {
	tLoja l;
	l.id = id;
	l.aluguel = aluguel;
	l.totalVendedores = 0;
	l.lucro = 0;

	return l;
}

int VerificaIdLoja(tLoja loja, int id) {
	return loja.id == id;
}

tLoja ContrataVendedor(tLoja loja, tVendedor vendedor) {
	if (loja.totalVendedores < MAX_VENDEDORES) {
		loja.vendedores[loja.totalVendedores++] = vendedor;
	}

	return loja;
}

tLoja RegistraVenda(tLoja loja, char nome[50], float valor) {
	for (int i = 0; i < loja.totalVendedores; i++) {
		if (VerificaNomeVendedor(loja.vendedores[i], nome)) {
			loja.vendedores[i] = ContabilizaVenda(loja.vendedores[i], valor);
		}
	}

	return loja;
}

tLoja CalculaLucro(tLoja loja) {
	for (int i = 0; i < loja.totalVendedores; i++) {
		loja.lucro += GetTotalVendido(loja.vendedores[i]);
		loja.lucro -= GetTotalRecebido(loja.vendedores[i]);
	}

	loja.lucro -= loja.aluguel;

	return loja;
}

/**
 * @brief Imprime o relatório da loja.
 * 
 * @param loja Estrutura do tipo tLoja contendo os dados da loja.
 */
void ImprimeRelatorioLoja(tLoja loja) {
	printf("Loja %d: Lucro total: R$ %.02f\n", loja.id, loja.lucro);
	for (int i = 0; i < loja.totalVendedores; i++) {
		ImprimeRelatorioVendedor(loja.vendedores[i]);
	}
}

