#include <stdio.h>
#include <stdlib.h>


struct Lista {
	int numero;
	struct Lista *prox;
};

struct Fila {
	struct Lista *elemento;
	int caminho;
};

void inserir_b (struct Lista **cabeca, int elemento){
	if ((*cabeca) == NULL){
		(*cabeca) = (struct Lista *) malloc (sizeof (struct Lista));
		(*cabeca)->numero = elemento;
		(*cabeca)->prox = NULL;
	}
	else
		inserir_b(&(*cabeca)->prox, elemento);
}

int inserir_vetor (struct Lista *vetor_num[10], int elemento){
	int i;
	for (i = 0; i < 10; i++){
		if (vetor_num[i]->numero == 0){
			vetor_num[i]->numero = elemento;
			return i;
		}
	}
}

void inserir_grafo (struct Lista *grafo[10], int elemento){
	int i, pos;
	pos = inserir_vetor (grafo, elemento);
	for (i = 0; i <= pos; i++){
		if ((grafo[i]->numero%elemento) == 0)
			inserir_b (&grafo[i], elemento);
		if ((grafo[pos]->numero%grafo[i]->numero) == 0){
			if(pos == i)
				break;
			inserir_b (&grafo[pos], grafo[i]->numero);
		}
	}
}

void imprimir (struct Lista *cabeca[10]){
	struct Lista *temp = NULL;
	int i;
	temp = (struct Lista *) malloc (sizeof (struct Lista));
	for (i = 0; i < 5; i++){
		if (cabeca[i]->numero < 10)
			printf("Numero :%d  -> ", cabeca[i]->numero);
		else
			printf("Numero :%d -> ", cabeca[i]->numero);
		temp = cabeca[i];
		while(temp->prox != NULL){
			temp = temp->prox;
			printf("%d ", temp->numero);
		}
		printf("\n");
	}
	free(temp);
	
}

void busca (struct Lista **cabeca, int elemento){
	
}

int busca_largura (struct Lista *grafo[10], int origem, int final){
	struct Fila *fila;
	struct Lista *aux;
	int passados[10];
	int i, temp;
	int cont = 0;
	fila = (struct Fila *) malloc (sizeof (struct Fila));
	fila->elemento = NULL;
	aux = (struct Lista *) malloc (sizeof (struct Lista));
	temp = origem;
	while (grafo[i]->numero != final){
		for (i = 0; i < 10; i++)
			if (grafo[i]->numero == temp)
				break;
		aux = grafo[i];
		fila->caminho++;
		while (aux != NULL){
			int j;
			if (aux->numero == final)
				return fila->caminho;
			for (j = 0; j < 10; j++){
				if (passados[j] == aux->numero)
					break;
			}
			if (j == 10){
				inserir_b(&(fila->elemento), aux->numero);
				passados[cont++] = aux->numero;
			}
			aux = aux->prox;
		}
		fila->caminho++;
		
	}
}


void main (){
	struct Lista *grafo[10];
	int i;
	for (i = 0; i < 10; i++){
		grafo[i] = (struct Lista *) malloc (sizeof (struct Lista));
		grafo[i]->numero = 0;
		grafo[i]->prox = NULL;
	}
	inserir_grafo(grafo, 2);
	inserir_grafo(grafo, 1);
	inserir_grafo(grafo, 10);
	inserir_grafo(grafo, 3);
	inserir_grafo(grafo, 5);
	imprimir(grafo);
}
