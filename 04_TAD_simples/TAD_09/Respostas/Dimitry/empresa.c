#include <stdio.h>
#include "empresa.h"
#include "funcionario.h"

// typedef struct empresa {
//     int id;
//     tFuncionario funcionarios[20];
//     int qtdFuncionarios;
// } tEmpresa;

tEmpresa criaEmpresa(int id) {
  tEmpresa e;
  e.id = id;
  e.qtdFuncionarios = 0;

  return e;
}

tEmpresa leEmpresa() {
  int qtdf;
  tEmpresa e;
  e.qtdFuncionarios = 0;
  scanf("%d %d\n", &e.id, &qtdf);

  for (int i = 0; i < qtdf; i++) {
    e = contrataFuncionarioEmpresa(e, leFuncionario());
  }

  return e;
}

tEmpresa contrataFuncionarioEmpresa(tEmpresa empresa, tFuncionario funcionario) {
  int contratado = 0;
  for (int i = 0; i < empresa.qtdFuncionarios; i++) {
    if (empresa.funcionarios[i].id == funcionario.id) {
      printf("A empresa %d ja possui um funcionario com o id %d\n", empresa.id, funcionario.id);
      contratado = 1;
      break;
    }
  }

  if (!contratado) {
    empresa.funcionarios[empresa.qtdFuncionarios++] = funcionario;
  }

  return empresa;
}

void imprimeEmpresa(tEmpresa empresa) {
  printf("Empresa %d:\n", empresa.id);

  for (int i = 0; i < empresa.qtdFuncionarios; i++) {
    imprimeFuncionario(empresa.funcionarios[i]);
  }
}