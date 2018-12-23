/**************************************************************
*	UPE - Caruaru
*	Dupla: Filipe Tabosa e Thomás Tabosa
*	Data: 20/09/2017
*	DESCRIÇÃO: Algoritmo de Lista Encadeada da Cadeira de Estruturas de Dados UPE - Campus Caruaru
*	Requisitos: Seperar uma lista encadeada de acordo com o valor
***************************************************************/

#include <stdio.h>
#include <stdlib.h>

//struct com os dados da Lista encadeada
struct Lista {
	int numero;
	struct Lista *prox;
};

void imprimir (struct Lista *cabeca);
void inserir (struct Lista **cabeca, int elemento);
struct Lista* separa (struct Lista **l, int n);


void main (){
	struct Lista *cabeca = NULL;
	struct Lista *set = NULL;
	inserir(&cabeca, 4);
	inserir(&cabeca, 3);
	inserir(&cabeca, 6);
	inserir(&cabeca, 8);
	inserir(&cabeca, 9);
	imprimir(cabeca);
	set = (struct Lista*) malloc(sizeof(struct Lista));
	set = separa (&cabeca, 1);
	imprimir(cabeca);
	imprimir(set);
}

/*função que separa, ele primeiro checa se a lista está vazia, se estiver retorna vazio 
, caso contrário ele checa se o elemento da lista é o número pedido, caso seja ele armaena 
próximo elemento em um temp, aponta o atual para NULL e retorna o temp, que será a cabeça 
da nova lista, caso não seja o elemento ele chama a função novamente, dessa vez passando o 
prox elemento da lista, e realizada tudo de novo recursivamente*/
struct Lista* separa (struct Lista **l, int n){
	if ((*l) == NULL)
		return NULL;
	else if ((*l)->numero == n){
		struct Lista *temp = NULL;
		temp = (struct Lista*) malloc(sizeof(struct Lista));
		temp = (*l)->prox;
		(*l)->prox = NULL;
		return temp;
	}
	else
		return separa (&(*l)->prox, n);
}


//função inserir da lista encadeada
void inserir (struct Lista **cabeca, int elemento){
	if ((*cabeca) == NULL){
		(*cabeca) = (struct Lista*) malloc(sizeof(struct Lista));
		(*cabeca)->numero = elemento;
		(*cabeca)->prox = NULL;
	}
	else
		inserir(&(*cabeca)->prox, elemento);
}

//função imprimir da lista encadeada
void imprimir (struct Lista *cabeca){
	if (cabeca == NULL)
		printf("\n");
	else{
		printf ("%d ", cabeca->numero);
		imprimir (cabeca->prox);
	}
}