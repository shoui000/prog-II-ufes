#include <string.h>
#include "locadora.h"

int main() {
    tLocadora l = criarLocadora();
    char buffer[16];

    while (scanf(" %s ", buffer) == 1) {
        if (!strcmp(buffer, "Cadastrar")) {
            l = lerCadastroLocadora(l);
        } else if (!strcmp(buffer, "Alugar")) {
            l = lerAluguelLocadora(l);
        } else if (!strcmp(buffer, "Devolver")) {
            l =lerDevolucaoLocadora(l);
        } else if (!strcmp(buffer, "Estoque")) {
            l = ordenarFilmesLocadora(l);
            putchar('\n');
            consultarEstoqueLocadora(l);
        }
    }

    consultarLucroLocadora(l);

    return 0;
}