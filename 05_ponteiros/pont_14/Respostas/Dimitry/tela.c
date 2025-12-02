#include "tela.h"
#include "botao.h"
#include <stdio.h>

Tela CriarTela(int altura, int largura){
    Tela t;

    t.altura = altura;
    t.largura = largura;

    t.qntBotoes = 0;
    
    return t;
}

void RegistraBotaoTela(Tela *t, Botao b) {
    if (t->qntBotoes == MAX_BOTOES) {
        return;
    }

    t->botoes[t->qntBotoes] = b;
    t->qntBotoes++;
}

void DesenhaTela(Tela t) {
    printf("##################\n");

    for (int i = 0; i < t.qntBotoes; i++) {
        DesenhaBotao(t.botoes[i], i);
        putchar('\n');
    }

    printf("##################\n");
}

void OuvidorEventosTela(Tela t) {
    int op = 0;
    printf("- Escolha sua acao: ");
    scanf("%d", &op);

    if (op > t.qntBotoes || op < 0) {
        exit(1);
    }

    ExecutaBotao(t.botoes[op]);
}