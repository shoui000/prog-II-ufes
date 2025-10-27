#include <stdio.h>
#include "data.h"

int verificaDataValida(int dia, int mes, int ano) {
  return ano > 0 && mes > 0 && mes <= 12 && dia > 0 && dia <= numeroDiasMes(mes, ano);
}

void imprimeDataExtenso(int dia, int mes, int ano) {
  printf("%02d de ", dia);
  imprimeMesExtenso(mes);
  printf(" de %04d\n", ano);
}

void imprimeMesExtenso(int mes) {
  switch (mes) {
    case 1:
      printf("Janeiro");
      break;
    case 2:
      printf("Fevereiro");
      break;
    case 3:
      printf("Marco");
      break;
    case 4:
      printf("Abril");
      break;
    case 5:
      printf("Maio");
      break;
    case 6:
      printf("Junho");
      break;
    case 7:
      printf("Julho");
      break;
    case 8:
      printf("Agosto");
      break;
    case 9:
      printf("Setembro");
      break;
    case 10:
      printf("Outubro");
      break;
    case 11:
      printf("Novembro");
      break;
    case 12:
      printf("Dezembro");
      break;
  }
}

int verificaBissexto(int ano) {
  if (ano % 4 != 0) {
    return 0;
  }

  if (ano % 100 != 0) {
    return 1;
  }

  if (ano % 400 == 0) {
    return 1;
  }

  return 0;
}

int numeroDiasMes(int mes, int ano) {
  if (mes == 2) {
    return verificaBissexto(ano) ? 29 : 28;
  }

  // jan, fev, mar, abril, maio, jun, jul, ago, set, out, nov, dez
  // 31   28   31   30     31    30   31   31   30   31   30   31
  // 1    2    3    4      5     6    7    8    9    10   11   12

  if (mes > 7) {
    return (mes % 2 == 0) ? 31 : 30;
  } else {
    return (mes % 2 != 0) ? 31 : 30;
  }
}

int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
  if (ano1 != ano2) {
    return (ano1 > ano2) ? 1 : -1;
  }

  if (mes1 != mes2) {
    return (mes1 > mes2) ? 1 : -1;
  }

  if (dia1 == dia2) {
    return 0;
  }

  return (dia1 > dia2) ? 1 : -1;
}

int calculaDiasAteMes(int mes, int ano) {
  int dias = 0;
  for (int i = 1; i < mes; i++) {
    dias += numeroDiasMes(i, ano);
  }

  return dias;
}

int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2) {
  int compare = comparaData(dia1, mes1, ano1, dia2, mes2, ano2);
  if (compare == 0) return 0;

  int menorAno = (compare == -1) ? ano1 : ano2;
  int maiorAno = (compare == -1) ? ano2 : ano1;


  int dias = 0;

  for (int atualAno = menorAno; atualAno < maiorAno; atualAno++) {
    dias += verificaBissexto(atualAno) ? 366 : 365;
  }

  dias -= compare == -1 ? calculaDiasAteMes(mes1, ano1) + dia1 : calculaDiasAteMes(mes2, ano2) + dia2;
  dias += compare == 1 ? calculaDiasAteMes(mes1, ano1) + dia1 : calculaDiasAteMes(mes2, ano2) + dia2;

  return dias;
}

