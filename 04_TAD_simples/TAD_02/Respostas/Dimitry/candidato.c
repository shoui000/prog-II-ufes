#include <string.h>
#include <stdio.h>
#include "candidato.h"

tCandidato CriaCandidato(char *nome, char *partido, char cargo, int id) {
	tCandidato c;
	strcpy(c.nome, nome);
	strcpy(c.partido, partido);
	c.cargo = cargo;
	c.id = id;
	c.votos = 0;

	return c;
}

tCandidato LeCandidato() {
	char nome[50], partido[50], cargo;
	int id;

	scanf(" %[^,], %[^,], %c, %d", nome, partido, &cargo, &id);

	return CriaCandidato(nome, partido, cargo, id);
}

int VerificaIdCandidato(tCandidato candidato, int id) {
	return candidato.id == id;
}

int EhMesmoCandidato(tCandidato candidato1, tCandidato candidato2) {
	return strcmp(candidato1.nome, candidato2.nome) == 0 &&
		strcmp(candidato1.partido, candidato2.partido) == 0 &&
		candidato1.cargo == candidato2.cargo &&
		candidato1.id == candidato2.id &&
		candidato1.votos == candidato2.votos;
}

char ObtemCargo(tCandidato candidato) {
	return candidato.cargo;
}

tCandidato IncrementaVotoCandidato(tCandidato candidato) {
	candidato.votos++;
	return candidato;
}

int ObtemVotos(tCandidato candidato) {
	return candidato.votos;
}

float CalculaPercentualVotos(tCandidato candidato, int totalVotos) {
	return 100 * (float)candidato.votos / (float)totalVotos;
}

void ImprimeCandidato(tCandidato candidato, float percentualVotos) {
	printf("%s (%s), %d voto(s), %.2f%%\n", candidato.nome, candidato.partido, candidato.votos, percentualVotos);
}
