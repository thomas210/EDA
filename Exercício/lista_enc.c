#include <stdio.h>
#include <stdlib.h>


struct Lista {
	int numero;
	int caminho;
	struct Lista *prox;
	struct Lista *ant;
};



void inserir (struct Lista **cabeca, int elemento, struct Lista **anterior){
	if ((*cabeca) == NULL){
		(*cabeca) = (struct Lista*) malloc(sizeof(struct Lista));
		(*cabeca)->numero = elemento;
		(*cabeca)->prox = NULL;
		if (anterior == NULL){
			(*cabeca)->ant = NULL;
			(*cabeca)->caminho = 0;
		}
		else{
			(*cabeca)->ant = (*anterior);
			(*cabeca)->caminho = (*anterior)->caminho + 1;
		}
		
	}
	else inserir(&(*cabeca)->prox, elemento, anterior);
}

void imprimir (struct Lista *cabeca){
	if (cabeca == NULL)
		printf("\n");
	else{
		printf ("%d ", cabeca->numero);
		imprimir (cabeca->prox);
	}
}

void imprimir_caminho (struct Lista *cabeca){
	if (cabeca == NULL)
		printf("\n");
	else{
		printf ("%d ", cabeca->numero);
		imprimir (cabeca->ant);
	}
}

void main (){
	struct Lista *cabeca = NULL;
	struct Lista *set = NULL;
	inserir(&cabeca, 4, NULL);
	inserir(&cabeca, 3, &cabeca);
	inserir(&cabeca, 6, &cabeca->prox);
}