#include <stdio.h>
#include "data.h"

int diasDoMes[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

tData CriaData(int dia, int mes, int ano) {
  tData d;
  d.dia = dia;
  d.mes = mes;
  d.ano = ano;

  return d;
}

int VerificaDataValida(tData data) {
  return (
    data.dia > 0 && data.mes > 0 && data.ano > 0 &&
    data.mes < 13 && data.dia <= NumeroDiasMes(data)
  );
}

void ImprimeMesExtenso(tData data) {
  switch (data.mes) {
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

void ImprimeDataExtenso(tData data) {
  printf("%02d de ", data.dia);
  ImprimeMesExtenso(data);
  printf(" de %04d\n", data.ano);
}

int VerificaBissexto(tData data) {
  if (data.ano % 4 != 0) {
    return 0;
  }

  if (data.ano % 100 != 0) {
    return 1;
  }

  if (data.ano % 400 == 0) {
    return 1;
  }

  return 0;
}

int NumeroDiasMes(tData data) {
  if (data.mes == 2) {
    return VerificaBissexto(data) ? 29 : 28;
  }

  return diasDoMes[data.mes];
}

int ComparaData(tData data1, tData data2) {
  if (data1.ano != data2.ano) {
    return (data1.ano > data2.ano) ? 1 : -1;
  }
  
  if (data1.mes != data2.mes) {
    return (data1.mes > data2.mes) ? 1 : -1;
  }

  if (data1.dia != data2.dia) {
    return (data1.dia > data2.dia) ? 1 : -1;
  }

  return 0;
}

int CalculaDiasAteMes(tData data) {
  int dias = 0;
  for (int i = 1; i < data.mes; i++) {
    dias += NumeroDiasMes(CriaData(1, i, data.ano));
  }

  return dias;
}

int CalculaDiferencaDias(tData data1, tData data2) {
  int compare = ComparaData(data1, data2);
  if (compare == 0) return 0;

  int menorAno = (compare == -1) ? data1.ano : data2.ano;
  int maiorAno = (compare == -1) ? data2.ano : data1.ano;


  int dias = 0;

  for (int atualAno = menorAno; atualAno < maiorAno; atualAno++) {
    dias += VerificaBissexto(CriaData(1, 1, atualAno)) ? 366 : 365;
  }

  dias -= compare == -1 ? CalculaDiasAteMes(data1) + data1.dia : CalculaDiasAteMes(data2) + data2.dia;
  dias += compare == 1 ? CalculaDiasAteMes(data1) + data1.dia : CalculaDiasAteMes(data2) + data2.dia;

  return dias;

}