#include <stdio.h>
#include <stdlib.h>

struct No {
	int num;
	struct No *esq;
	struct No *dir;
	int balance;
};

void imprimir (struct No *raiz);
int fbl (struct No *raiz);
void rotacaoEsquerda (struct No **raiz);
void rotacaoDireita (struct No **raiz);
void rotacaoED (struct No **raiz);
void rotacaoDE (struct No **raiz);

struct No *busca (struct No **raiz, int elemento){
	if ((*raiz) == NULL) return NULL;
	else if ((*raiz)->num == elemento) return (*raiz);
	else if (elemento > (*raiz)->num) return busca(&(*raiz)->dir, elemento);
	else return busca(&(*raiz)->esq, elemento);
}

void inserir (struct No **raiz, int elemento){
	if ((*raiz) == NULL){
		(*raiz) = (struct No *) malloc (sizeof(struct No));
		(*raiz)->num = elemento;
		(*raiz)->esq = NULL;
		(*raiz)->dir = NULL;
		(*raiz)->balance = 0;
		return;
	}else{
		if ((*raiz)->num > elemento)
			inserir(&(*raiz)->esq, elemento);
		else
			inserir(&(*raiz)->dir, elemento);
	}
	(*raiz)->balance = fbl((*raiz));
	if ((*raiz)->balance == 2) {
		if ((*raiz)->dir->balance == -1) rotacaoED(raiz);
		else rotacaoEsquerda(raiz);
	}
	if ((*raiz)->balance == -2){
		if ((*raiz)->esq->balance == 1) rotacaoDE(raiz);
		else rotacaoDireita;
	}
}

void main (){
	struct No *raiz = NULL;
	struct No *set = NULL;
	set = (struct No *) malloc (sizeof(struct No));
	inserir(&raiz, 30);
	imprimir(raiz);
	printf("----\n");
	inserir(&raiz, 10);
	imprimir(raiz);
	printf("----\n");
	inserir(&raiz, 15);
	imprimir(raiz);
	printf("----\n");
	set = busca(&raiz, 36);
	imprimir(set);
	printf("----\n");
}

int fbl (struct No *raiz){
	int esq, dir;
	if (raiz->dir == NULL) dir = 0;
	else {
		if (raiz->dir->balance >= 0) dir = raiz->dir->balance + 1;
		else dir = (raiz->dir->balance * -1) + 1;
	}
	if (raiz->esq == NULL) esq = 0;
	else {
		if (raiz->esq->balance <= 0) esq = raiz->esq->balance - 1;
		else esq = (raiz->esq->balance * -1) - 1;
	}
	return esq + dir;
} 

void imprimir (struct No *raiz){
	if (raiz != NULL){
		printf("%d ", raiz->num);
		if (raiz->esq == NULL) printf ("X ");
		else printf ("%d ", raiz->esq->num);
		if (raiz->dir == NULL) printf ("X\n");
		else printf("%d\n", raiz->dir->num);
		imprimir(raiz->esq);
		imprimir(raiz->dir);
	}
}

void rotacaoEsquerda (struct No **raiz){
	struct No *temp = NULL;
	struct No *aux = NULL;
	temp = (struct No *) malloc (sizeof(struct No));
	aux = (struct No *) malloc (sizeof(struct No));
	aux = (*raiz)->dir;
	temp = aux->esq;
	aux->esq = (*raiz);
	(*raiz)->dir = temp;
	(*raiz) = aux;
}

void rotacaoDireita (struct No **raiz){
	struct No *temp = NULL;
	struct No *aux = NULL;
	temp = (struct No *) malloc (sizeof(struct No));
	aux = (struct No *) malloc (sizeof(struct No));
	aux = (*raiz)->esq;
	temp = aux->dir;
	aux->dir = (*raiz);
	(*raiz)->esq = temp;
	(*raiz) = aux;
}

void rotacaoED (struct No **raiz){
	rotacaoDireita(&(*raiz)->dir);
	rotacaoEsquerda(raiz);
}

void rotacaoDE (struct No **raiz){
	rotacaoEsquerda(&(*raiz)->esq);
	rotacaoDireita(raiz);
}