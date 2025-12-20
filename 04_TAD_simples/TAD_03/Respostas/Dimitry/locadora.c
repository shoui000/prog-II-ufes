#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "locadora.h"
#include "filme.h"

tLocadora criarLocadora() {
    tLocadora l;
    l.lucro = 0;
    l.numFilmes = 0;

    return l;
}

int verificarFilmeCadastrado(tLocadora locadora, int codigo) {
    for (int i = 0; i < locadora.numFilmes; i++) {
        if (ehMesmoCodigoFilme(locadora.filme[i], codigo)) {
            return 1;
        }
    }

    return 0;
}

tLocadora cadastrarFilmeLocadora(tLocadora locadora, tFilme filme) {
    if (verificarFilmeCadastrado(locadora, obterCodigoFilme(filme))) {
        printf("Filme ja cadastrado no estoque\n");
    } else  {
        printf("Filme cadastrado %d - ", obterCodigoFilme(filme));
        imprimirNomeFilme(filme);
        putchar('\n');
        locadora.filme[locadora.numFilmes++] = filme;
    }

    return locadora;
}

tLocadora lerCadastroLocadora(tLocadora locadora) {
    int codigo;

    while (scanf(" %d,", &codigo) == 1) {
        tFilme f = leFilme(codigo);
        locadora = cadastrarFilmeLocadora(locadora, f);
    }

    scanf(" %*c ");

    return locadora;
}

tLocadora alugarFilmesLocadora(tLocadora locadora, int *codigos, int quantidadeCodigos) {
    tFilme f;
    int alugado, qtdAlugado = 0, valor = 0;

    for (int i = 0; i < quantidadeCodigos; i++) {
        alugado = 0;

        for (int j = 0; j < locadora.numFilmes; j++) {
            f = locadora.filme[j];

            if (ehMesmoCodigoFilme(f, codigos[i])) {
                if (obterQtdEstoqueFilme(f) < 1) {
                    printf("Filme %d - ", obterCodigoFilme(f));
                    imprimirNomeFilme(f);
                    printf(" nao disponivel no estoque. Volte mais tarde.\n");
                } else {
                    locadora.filme[j] = alugarFilme(f);
                    qtdAlugado++;
                    valor += obterValorFilme(f);
                }

                alugado = 1;
                break;
            }
        }

        if (!alugado) {
            printf("Filme %d nao cadastrado.\n", codigos[i]);
        }
    }

    if (qtdAlugado > 0) {
        printf("Total de filmes alugados: %d com custo de R$%d\n", qtdAlugado, valor);
    }

    return locadora;
}

tLocadora lerAluguelLocadora(tLocadora locadora) {
    int codigos[MAX_FILMES];
    int codigo, qtdCodigos = 0;

    while (scanf(" %d ", &codigo) == 1) {
        codigos[qtdCodigos++] = codigo;
    }

    scanf(" %*c ");

    locadora = alugarFilmesLocadora(locadora, codigos, qtdCodigos);

    return locadora;
}

tLocadora devolverFilmesLocadora(tLocadora locadora, int *codigos, int quantidadeCodigos) {
    tFilme f;
    int alugado;
    for (int i = 0; i < quantidadeCodigos; i++) {
        alugado = 0;

        for (int j = 0; j < locadora.numFilmes; j++) {
            f = locadora.filme[j];

            if (ehMesmoCodigoFilme(f, codigos[i])) {
                if (obterQtdAlugadaFilme(f) < 1) {
                    printf("Nao e possivel devolver o filme %d - ", obterCodigoFilme(f));
                    imprimirNomeFilme(f);
                    printf(".\n");
                } else {
                    locadora.filme[j] = devolverFilme(f);
                    printf("Filme %d - ", codigos[i]);
                    imprimirNomeFilme(f);
                    printf(" Devolvido!\n");
                    locadora.lucro += obterValorFilme(f);
                }

                alugado = 1;
                break;
            }
        }

        if (!alugado) {
            printf("Filme %d nao cadastrado.\n", codigos[i]);
        }
    }

    return locadora;
}

tLocadora lerDevolucaoLocadora(tLocadora locadora) {
    int codigo, codigos[512], qtdCodigos = 0;

    while (scanf(" %d ", &codigo) == 1) {
        codigos[qtdCodigos++] = codigo;
    }

    scanf(" %*c ");

    locadora = devolverFilmesLocadora(locadora, codigos, qtdCodigos);

    return locadora;
}

tLocadora ordenarFilmesLocadora(tLocadora locadora) {
    int swaps = 0;

    do {
        swaps = 0;
        for (int i = 0; i < locadora.numFilmes-1; i++) {
            if (compararNomesFilmes(locadora.filme[i], locadora.filme[i+1]) > 0) {
                tFilme temp = locadora.filme[i];
                locadora.filme[i] = locadora.filme[i+1];
                locadora.filme[i+1] = temp;
                swaps++;
            }
        }
    } while (swaps > 0);

    return locadora;
}

void consultarEstoqueLocadora(tLocadora locadora) {
    printf("~ESTOQUE~\n");

    for (int i = 0; i < locadora.numFilmes; i++) {
        printf("%d - ", obterCodigoFilme(locadora.filme[i]));
        imprimirNomeFilme(locadora.filme[i]);
        printf(" Fitas em estoque: %d\n", obterQtdEstoqueFilme(locadora.filme[i]));
    }
}

void consultarLucroLocadora(tLocadora locadora) {
    if (locadora.lucro > 0) {
        putchar('\n');
        printf("Lucro total R$%d\n", locadora.lucro);
    }
}
