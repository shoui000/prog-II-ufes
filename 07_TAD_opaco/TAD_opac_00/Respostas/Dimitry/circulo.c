#include <stdlib.h>
#include "circulo.h"
#include "ponto.h"

struct circulo {
    tPonto centro;
    float raio;
};

tCirculo Circulo_Cria(float x, float y, float r) {
    tCirculo c = malloc(sizeof(struct circulo));

    c->centro = Pto_Cria(x, y);
    c->raio = r;

    return c;
}

void Circulo_Apaga(tCirculo c) {
    free(c->centro);
    free(c);
}

tPonto Circulo_Acessa_Centro(tCirculo c) {
    return c->centro;
}

float Circulo_Acessa_Raio(tCirculo c) {
    return c->raio;
}

void Circulo_Atribui_Centro(tCirculo c, tPonto p) {
    c->centro = p;
}

void Circulo_Atribui_Raio(tCirculo c, float r) {
    c->raio = r;
}

int Circulo_Interior(tCirculo c, tPonto p) {
    return Pto_Distancia(c->centro, p) <= c->raio;
}