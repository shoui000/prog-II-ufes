#include <stdio.h>
#include "tabuleiro.h"
#include "jogador.h"
#include "jogada.h"

/**
 * Cria um jogador com o id passado como parâmetro e retorna o jogador criado.
 * 
 * @param idJogador o id do jogador (1 ou 2).
 * 
 * @return tJogador o jogador criado.
 */
tJogador CriaJogador(int idJogador) {
	tJogador j;
	j.id = idJogador;
	return j;
}


/**
 * Recebe um jogador e um tabuleiro e retorna o tabuleiro com a jogada do jogador.
 * 
 * @param jogador o jogador que fará a jogada.
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return o tabuleiro atualizado com a jogada do jogador.
 */
tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro) {
	tJogada jogada = {-1, -1, -1};
	int x = 0, y = 0, valida = 0, livre = 0;

	while (1) {
		printf("Jogador %d\n", jogador.id);

		jogada = LeJogada();

		x = ObtemJogadaX(jogada);
		y = ObtemJogadaY(jogada);
		valida = EhPosicaoValidaTabuleiro(x, y);
		if (valida) {
			livre = EstaLivrePosicaoTabuleiro(tabuleiro, x, y);

			if (livre) {
				printf("Jogada [%d,%d]!\n", x, y);

				tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, jogador.id, x, y);
				break;
			} else {
				printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", x, y);
			}
		} else {
			printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", x, y);
		}
	}

	return tabuleiro;
}


/**
 * Recebe um jogador e um tabuleiro e retorna 1 se o jogador venceu e 0 caso contrário.
 * 
 * @param jogador o jogador a ser verificado.
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return 1 se o jogador venceu, 0 caso contrário.
 */
int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro) {
	int ganhou = 1;
	char peca = (jogador.id == ID_JOGADOR_1) ? 'X' : '0';

	for (int i = 0; i < TAM_TABULEIRO; i++) {
		ganhou = 1;

		for (int j = 0; j < TAM_TABULEIRO; j++) {
			ganhou = ganhou && tabuleiro.posicoes[j][i] == peca;
		}

		if (ganhou) return 1;
	}

	return (tabuleiro.posicoes[0][0] == peca && tabuleiro.posicoes[1][1] == peca && tabuleiro.posicoes[2][2] == peca) ||
					(tabuleiro.posicoes[0][2] == peca && tabuleiro.posicoes[1][1] == peca && tabuleiro.posicoes[2][0] == peca);
}


