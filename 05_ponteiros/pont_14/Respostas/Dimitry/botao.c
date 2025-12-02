#include "botao.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void SetarTexto(Botao *b, char *novoTexto) {
    if (strlen(novoTexto) >= MAX_TAM_TEXTO) {
        exit(1);
    }

    strcpy(b->texto, novoTexto);
}

void SetarTamFonte(Botao *b, int novoTamFonte) {
    if (novoTamFonte < 1) {
        exit(1);
    }

    b->tamFonte = novoTamFonte;
}

void SetarCor(Botao *b, char *novacor) {
    strcpy(b->corHex, novacor);
}

void SetarTipo(Botao *b, int novoTipo) {
    if (novoTipo < 1 || novoTipo > 3) {
        exit(1);
    }

    b->tipo = novoTipo;
}

Botao CriarBotao(char *texto, int tamFonte, char *cor, int tipo, void (*executa)(void)) {
    Botao b;
    if (strlen(texto) >= MAX_TAM_TEXTO || tamFonte < 1 || tipo < 1 || tipo > 3) {
        exit(1);
    }

    b.tamFonte = tamFonte;
    b.tipo = tipo;
    strcpy(b.texto, texto);
    strcpy(b.corHex, cor);
    b.executa = executa;

    return b;
}

void ExecutaBotao(Botao b) {
    switch (b.tipo) {
        case CLICK:
            printf("- Executando o botao com evento de click\n");
            break;
        case LONGO_CLICK:
            printf("- Executando o botao com evento de longo click\n");
            break;
        case HOVER:
            printf("- Executando o botao com evento de hover\n");
            break;
    }
    b.executa();
}

void DesenhaBotao(Botao b, int idx) {
    printf("-------------\n");
    printf("- Botao [%d]:\n", idx);
    printf("(%s | %s | %d | %d)\n", b.texto, b.corHex, b.tamFonte, b.tipo);
    printf("-------------\n");
}