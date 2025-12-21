#include <stdio.h>
#include <string.h>
#include "aluno.h"

tAluno CriaAluno(char *nome, int matricula, int n1, int n2, int n3) {
    tAluno a;
    strcpy(a.nome, nome);
    a.matricula = matricula;
    a.n1 = n1;
    a.n2 = n2;
    a.n3 = n3;

    return a;
}

tAluno LeAluno() {
    char nome[50];
    int matricula, n1, n2, n3;

    scanf("%s\n", nome);
    scanf("%3d\n", &matricula);
    scanf("%d %d %d\n", &n1, &n2, &n3);

    return CriaAluno(nome, matricula, n1, n2, n3);
}

int ComparaMatricula(tAluno aluno1, tAluno aluno2) {
    if (aluno1.matricula > aluno2.matricula)
        return 1;
    else if (aluno1.matricula == aluno2.matricula)
        return 0;
    else
        return -1;
}

int CalculaMediaAluno(tAluno aluno) {
    return (aluno.n1 + aluno.n2 + aluno.n3) / 3;
}

int VerificaAprovacao(tAluno aluno) {
    return CalculaMediaAluno(aluno) > 6;
}

void ImprimeAluno(tAluno aluno) {
    printf("%s\n", aluno.nome);
}
