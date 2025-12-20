#include <stdio.h>
#include "eleitor.h"

tEleitor CriaEleitor(int id, int votoP, int votoG) {
	tEleitor e;
	e.id = id;
	e.votoG = votoG;
	e.votoP = votoP;

	return e;
}

tEleitor LeEleitor() {
	int id, votoG, votoP;
	scanf(" %d %d %d", &id, &votoP, &votoG);

	return CriaEleitor(id, votoP, votoG);
}

int ObtemVotoPresidente(tEleitor eleitor) {
	return eleitor.votoP;
}

int ObtemVotoGovernador(tEleitor eleitor) {
	return eleitor.votoG;
}

int EhMesmoEleitor(tEleitor eleitor1, tEleitor eleitor2) {
	return eleitor1.id == eleitor2.id &&
		eleitor1.votoP == eleitor2.votoP &&
		eleitor1.votoG == eleitor2.votoG;
}
