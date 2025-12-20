#include <stdio.h>
#include "eleicao.h"
#include "candidato.h"
#include "eleitor.h"

tEleicao InicializaEleicao() {
	tEleicao e;
	e.totalEleitores = 0;
	e.totalGovernadores = 0;
	e.totalPresidentes = 0;
	e.votosBrancosGovernador = 0;
	e.votosBrancosPresidente = 0;
	e.votosNulosGovernador = 0;
	e.votosNulosPresidente = 0;

	int candidatos = 0;

	scanf("%d\n", &candidatos);

	tCandidato c;
	for (int i = 0; i < candidatos; i++) {
		c = LeCandidato();

		if (ObtemCargo(c) == 'P') {
			e.presidentes[e.totalPresidentes] = c;
			e.totalPresidentes++;
		} else if (ObtemCargo(c) == 'G') {
			e.governadores[e.totalGovernadores] = c;
			e.totalGovernadores++;
		}
	}

	return e;
}

tEleicao RealizaEleicao(tEleicao eleicao) {
	scanf("%d\n", &eleicao.totalEleitores);

	tEleitor el;
	for (int i = 0; i < eleicao.totalEleitores; i++) {
		el = LeEleitor();
		eleicao.eleitores[i] = el;

		int votou = 0;

		if (ObtemVotoPresidente(el) == 0) {
			eleicao.votosBrancosPresidente++;
		} else {
			votou = 0;

			for (int j = 0; j < eleicao.totalPresidentes; j++) {
				if (VerificaIdCandidato(eleicao.presidentes[j], ObtemVotoPresidente(el))) {
					eleicao.presidentes[j] = IncrementaVotoCandidato(eleicao.presidentes[j]);
					votou = 1;
				}
			}

			if (!votou) eleicao.votosNulosPresidente++;
		}

		if (ObtemVotoGovernador(el) == 0) {
			eleicao.votosBrancosGovernador++;
		} else {
			votou = 0;

			for (int j = 0; j < eleicao.totalGovernadores; j++) {
				if (VerificaIdCandidato(eleicao.governadores[j], ObtemVotoGovernador(el))) {
					eleicao.governadores[j] = IncrementaVotoCandidato(eleicao.governadores[j]);
					votou = 1;
				}
			}

			if (!votou) eleicao.votosNulosGovernador++;
		}
	}

	return eleicao;
}

void ImprimeResultadoEleicao(tEleicao eleicao) {
	if (eleicao.totalEleitores > 10 || eleicao.totalPresidentes > 3 || eleicao.totalGovernadores > 3) 
		goto anulaEleicao;

	for (int i = 0; i < eleicao.totalEleitores; i++) {
		for (int j = i+1; j < eleicao.totalEleitores; j++) {
			if (EhMesmoEleitor(eleicao.eleitores[i], eleicao.eleitores[j]))
				goto anulaEleicao;
		} 
	}

	int posGanhador = 0;
	int votosGanhador = ObtemVotos(eleicao.presidentes[0]);
	int votos = 0;

	for (int i = 1; i < eleicao.totalPresidentes; i++) {
		votos = ObtemVotos(eleicao.presidentes[i]);

		if (votos > votosGanhador) {
			posGanhador = i;
			votosGanhador = votos;
		} else if (votos == votosGanhador) {
			posGanhador = -1;
		}
	}

	printf("- PRESIDENTE ELEITO: ");

	if (posGanhador == -1) {
		printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
	} else if (votosGanhador < eleicao.votosNulosPresidente + eleicao.votosBrancosPresidente) {
		printf("SEM DECISAO\n");
	} else {
		ImprimeCandidato(eleicao.presidentes[posGanhador], CalculaPercentualVotos(eleicao.presidentes[posGanhador], eleicao.totalEleitores));
	}

	posGanhador = 0;
	votosGanhador = ObtemVotos(eleicao.governadores[0]);
	votos = 0;

	for (int i = 1; i < eleicao.totalGovernadores; i++) {
		votos = ObtemVotos(eleicao.governadores[i]);

		if (votos > votosGanhador) {
			posGanhador = i;
			votosGanhador = votos;
		} else if (votos == votosGanhador) {
			posGanhador = -1;
		}
	}

	printf("- GOVERNADOR ELEITO: ");

	if (posGanhador == -1) {
		printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
	} else if (votosGanhador < eleicao.votosNulosGovernador + eleicao.votosBrancosGovernador) {
		printf("SEM DECISAO\n");
	} else {
		ImprimeCandidato(eleicao.governadores[posGanhador], CalculaPercentualVotos(eleicao.governadores[posGanhador], eleicao.totalEleitores));
	}

	printf("- NULOS E BRANCOS: %d, %d",
			eleicao.votosNulosGovernador + eleicao.votosNulosPresidente,
			eleicao.votosBrancosGovernador + eleicao.votosBrancosPresidente
			);

	return;

anulaEleicao:
	printf("ELEICAO ANULADA");
}
