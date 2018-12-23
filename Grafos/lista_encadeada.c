#include "lista_encadeada.h"

void inserir_f (struct Lista **cabeca, struct Lista **elemento){
	if ((*cabeca) == NULL){
		(*cabeca) = (struct Lista *) malloc (sizeof (struct Lista));
		(*cabeca) = (*elemento);
	}
	else{
		(*elemento)->prox = (*cabeca);
		(*cabeca) = (*elemento);
	}
}

void inserir_b (struct Lista **cabeca, struct Lista **elemento){
	if ((*cabeca) == NULL){
		(*cabeca) = (struct Lista *) malloc (sizeof (struct Lista));
		(*cabeca) = (*elemento);
	}
	else
		inserir_b(&(*cabeca)->prox, elemento);
}

void imprimir (struct Lista *cabeca){
	FILE *res = NULL;
	struct Lista *temp = NULL;
	res = fopen("saida.txt", "a");
	if (cabeca == NULL){
		fprintf(res, "Vazio\n");
	}
	temp = (struct Lista *) malloc (sizeof (struct Lista));
	fprintf(res, "%d ", cabeca->numero);
	temp = cabeca;
	while(temp->prox != NULL){
		temp = temp->prox;
		fprintf(res, "%d ", temp->numero);
	}
	fprintf(res, "\n");
	fclose(res);
	free(temp);
}