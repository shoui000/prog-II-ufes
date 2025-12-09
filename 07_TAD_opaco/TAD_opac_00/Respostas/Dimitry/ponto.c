#include "ponto.h"
#include <math.h>
#include <stdlib.h>

struct ponto {
    float x, y;
};

tPonto Pto_Cria(float x, float y) {
    tPonto p = malloc(sizeof(struct ponto));
    p->x = x;
    p->y = y;

    return p;
}

void Pto_Apaga(tPonto p) {
    free(p);
}

float Pto_Acessa_x(tPonto p) {
    return p->x;
}

float Pto_Acessa_y(tPonto p) {
    return p->y;
}

void Pto_Atribui_x(tPonto p, float x) {
    p->x = x;
}

void Pto_Atribui_y(tPonto p, float y) {
    p->y = y;
}

float Pto_Distancia(tPonto p1, tPonto p2) {
    return sqrt((p1->x - p2->x) * (p1->x - p2->x) + (p1->y - p2->y) * (p1->y - p2->y));
}