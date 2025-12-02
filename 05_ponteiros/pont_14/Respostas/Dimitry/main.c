#include <stdio.h>
#include "tela.h"
#include "botao.h"

void salvar() {
    printf("- Botao de SALVAR dados ativado!\n");
}

void excluir() {
    printf("- Botao de EXCLUIR dados ativado!\n");
}

void opcoes() {
    printf("- Botao de OPCOES ativado!\n");
}

int main() {
    Tela t = CriarTela(200, 400);

    Botao bSalvar = CriarBotao("Salvar", 12, "FFF", 1, &salvar);
    Botao bExcluir = CriarBotao("Excluir", 18, "000", 1, &excluir);
    Botao bOpcoes = CriarBotao("Opcoes", 10, "FF0000", 2, &opcoes);

    RegistraBotaoTela(&t, bSalvar);
    RegistraBotaoTela(&t, bExcluir);
    RegistraBotaoTela(&t, bOpcoes);

    DesenhaTela(t);
    OuvidorEventosTela(t);
}