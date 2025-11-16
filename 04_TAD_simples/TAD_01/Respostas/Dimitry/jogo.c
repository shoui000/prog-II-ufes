#include <stdio.h>
#include <stdlib.h>
#include "jogador.h"
#include "tabuleiro.h"
#include "jogo.h"

/**
 * Cria um jogo e retorna o jogo criado.
 * 
 * @return o jogo criado.
 */
tJogo CriaJogo() {
	tJogo t;
	t.tabuleiro = CriaTabuleiro();
	t.jogador1 = CriaJogador(ID_JOGADOR_1);
	t.jogador2 = CriaJogador(ID_JOGADOR_2);

	return t;
}


/**
 * Inicia o jogo, definindo o tabuleiro e os jogadores.
 * 
 * @param jogo o jogo a ser iniciado.
 */
void ComecaJogo(tJogo jogo) {
	jogo = CriaJogo();

	while (1) {
		jogo.tabuleiro = JogaJogador(jogo.jogador1, jogo.tabuleiro);
		ImprimeTabuleiro(jogo.tabuleiro);

		if (VenceuJogador(jogo.jogador1, jogo.tabuleiro)) {
			printf("JOGADOR 1 Venceu!\n");
			break;
		} else if (AcabouJogo(jogo)){
			printf("Sem vencedor!\n");
			break;
		}

		jogo.tabuleiro = JogaJogador(jogo.jogador2, jogo.tabuleiro);
		ImprimeTabuleiro(jogo.tabuleiro);

		if (VenceuJogador(jogo.jogador2, jogo.tabuleiro)) {
			printf("JOGADOR 2 Venceu!\n");
			break;
		} else if (AcabouJogo(jogo)){
			printf("Sem vencedor!\n");
			break;
		}
	}
}


/**
 * Verifica se o jogo acabou (se não há mais posições livres no tabuleiro).
 * 
 * @param jogo o jogo atual.
 * 
 * @return 1 se o jogo acabou, 0 caso contrário.
 */
int AcabouJogo(tJogo jogo) {
	return !TemPosicaoLivreTabuleiro(jogo.tabuleiro);
}


/**
 * Verifica se o usuário deseja jogar novamente.
 * 
 * @return 1 se o usuário deseja jogar novamente, 0 caso contrário.
 */
int ContinuaJogo() {
	char letra;
	printf("Jogar novamente? (s,n)\n");
	scanf("%*[^a-z]");
	scanf("%c", &letra);

	return letra == 's';
}
