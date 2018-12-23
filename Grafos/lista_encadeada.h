#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H
#include <stdlib.h>
#include <stdio.h>

struct Lista {
	int numero;
	struct Lista *prox;
};

void inserir_f (struct Lista **cabeca, struct Lista **elemento);
void inserir_b (struct Lista **cabeca, struct Lista **elemento);
void imprimir (struct Lista *cabeca);

#endif