#include <stdio.h>
#include "aluno.h"

int main() {
    int n;
    scanf("%d\n", &n);

    tAluno alunos[n];
    for (int i = 0; i < n; i++) {
        alunos[i] = LeAluno();
    }

    int swaps;
    do {
        swaps = 0;
        for (int i = 0; i < n-1; i++) {
            if (ComparaMatricula(alunos[i], alunos[i+1]) == 1) {
                tAluno temp = alunos[i];
                alunos[i] = alunos[i+1];
                alunos[i+1] = temp;
                swaps++;
            }
        }
    } while (swaps);

    for (int i = 0; i < n; i++) {
        if (VerificaAprovacao(alunos[i]))
            ImprimeAluno(alunos[i]);
    }

    return 0;
}
