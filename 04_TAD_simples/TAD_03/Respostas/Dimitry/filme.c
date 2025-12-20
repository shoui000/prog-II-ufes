#include <stdio.h>
#include <string.h>
#include "filme.h"

tFilme criarFilme(char *nome, int codigo, int valor, int quantidade) {
    tFilme t;
    strcpy(t.nome, nome);
    t.codigo = codigo;
    t.valor = valor;
    t.qtdEstoque = quantidade;
    t.qtdAlugada = 0;

    return t;
}

tFilme leFilme(int codigo) {
    tFilme t;

    t.codigo = codigo;

    scanf(" %[^,],%d,%d ", t.nome, &t.valor, &t.qtdEstoque);

    t.qtdAlugada = 0;

    return t;
}

int obterCodigoFilme(tFilme filme) {
    return filme.codigo;
}

void imprimirNomeFilme(tFilme filme) {
    printf("%s", filme.nome);
}

int obterValorFilme(tFilme filme) {
    return filme.valor;
}

int obterQtdEstoqueFilme(tFilme filme) {
    return filme.qtdEstoque;
}

int obterQtdAlugadaFilme(tFilme filme) {
    return filme.qtdAlugada;
}

int ehMesmoCodigoFilme(tFilme filme, int codigo) {
    return filme.codigo == codigo;
}

tFilme alugarFilme(tFilme filme) {
    if (filme.qtdEstoque > 0) {
        filme.qtdAlugada++;
        filme.qtdEstoque--;
    }

    return filme;
}

tFilme devolverFilme(tFilme filme) {
    if (filme.qtdAlugada > 0) {
        filme.qtdAlugada--;
        filme.qtdEstoque++;
    }

    return filme;
}

int compararNomesFilmes(tFilme filme1, tFilme filme2) {
    return strcmp(filme1.nome, filme2.nome);
}
