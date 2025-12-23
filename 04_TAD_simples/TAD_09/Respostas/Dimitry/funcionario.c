#include <stdio.h>
#include "funcionario.h"

tFuncionario criaFuncionario(int id, float salario) {
  tFuncionario f;
  f.id = id;
  f.salario = salario;

  return f;
}

tFuncionario leFuncionario() {
  int id;
  float salario;
  scanf("%d %f\n", &id, &salario);

  return criaFuncionario(id, salario);
}

int getIdFuncionario(tFuncionario funcionario) {
  return funcionario.id;
}

void imprimeFuncionario(tFuncionario funcionario) {
  printf("- Funcionario %d: R$ %.2f\n", funcionario.id, funcionario.salario);
}