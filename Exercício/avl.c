#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct No {
	char nome[100];
    char telefone[16];
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

struct No *busca (struct No **raiz, char *elemento){
	if ((*raiz) == NULL) return NULL;
	else if (strcmp((*raiz)->nome, elemento) == 0) return (*raiz);
	else if (strcmp((*raiz)->nome, elemento) < 0) return busca(&(*raiz)->dir, elemento);
	else return busca(&(*raiz)->esq, elemento);
}

void inserir (struct No **raiz, char *nome, char *contato){
	if ((*raiz) == NULL){
		(*raiz) = (struct No *) malloc (sizeof(struct No));
		strcpy((*raiz)->nome, nome);
		strcpy((*raiz)->telefone, contato);
		(*raiz)->esq = NULL;
		(*raiz)->dir = NULL;
		(*raiz)->balance = 0;
		return;
	}else{
		if (strcmp((*raiz)->nome, nome) > 0)
			inserir(&(*raiz)->esq, nome, contato);
		else
			inserir(&(*raiz)->dir, nome, contato);
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
	inserir(&raiz, "thomas", "999-843-797");
	//imprimir(raiz);
	printf("----\n");
	inserir(&raiz, "filipe", "546-648-654");
	//imprimir(raiz);
	printf("----\n");
	inserir(&raiz, "geovanne", "123-456-789");
	imprimir(raiz);
	printf("----\n");
	set = busca(&raiz, "denini");
	//imprimir(set);
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
		imprimir(raiz->esq);
		printf("%s ", raiz->nome);
		printf("%s\n ", raiz->telefone);
		imprimir(raiz->dir);
		if (raiz->esq == NULL) {}//printf ("X ");
		else {
			printf ("%s ", raiz->esq->nome);
			printf ("%s\n ", raiz->esq->telefone);
		}
		if (raiz->dir == NULL) {}//printf ("X\n");
		else {
			printf("%s ", raiz->dir->nome);
			printf("%s\n", raiz->dir->telefone);
		}
		
		
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