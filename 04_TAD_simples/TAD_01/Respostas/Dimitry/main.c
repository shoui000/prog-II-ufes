#include <stdbool.h>
#include <stdlib.h>

#include "jogo.h"

int main() {
	tJogo j = CriaJogo();

	do {
		ComecaJogo(j);
	} while (ContinuaJogo());

	exit(EXIT_SUCCESS);
}
