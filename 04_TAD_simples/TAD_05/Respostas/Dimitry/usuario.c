#include <stdio.h>
#include <string.h>
#include "usuario.h"

tUsuario CriaUsuario(char nome[20], char cpf[15]) {
    tUsuario u;
    strcpy(u.nome, nome);
    strcpy(u.cpf, cpf);
    return u;
}

void ImprimeUsuario(tUsuario user) {
    printf("Nome: %s\n", user.nome);
    printf("CPF: %s\n", user.cpf);
}
