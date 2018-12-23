/**************************************************************
*	UPE - Caruaru
*	Dupla: Filipe Tabosa e Thomás Tabosa
*	Data: 20/09/2017
*	DESCRIÇÃO: Algoritmo de Lista Encadeada da Cadeira de Estruturas de Dados UPE - Campus Caruaru
*	Requisitos: Mostre como uma pilha pode ser implementada utilizndo duas filas
***************************************************************/

#include <stdio.h>
#include <stdlib.h>

//Stuct que contem os dados das posições das filas
struct Info {
	int ini;
	int fim;
	int pos_fim;
};

//struct da pilha em si;
struct Pilha {
	int pilha[10];
	struct Info dados;
};

void inserir (int *fila, struct Info *dados, int num);
void imprimir (int *fila, struct Info *dados);
int remover (int *fila, struct Info *dados);
int pop (struct Pilha *p);
void push (struct Pilha *p, int num);

void main (){
	struct Pilha p;
	p.dados.ini = 0;
	p.dados.fim = 0;
	p.dados.pos_fim = 10;
	push (&p, 4);
	push (&p, 5);
	push (&p, 6);
	imprimir(p.pilha, &(p.dados));
	printf ("Elemento retirado: %d\n", pop(&p));
	imprimir(p.pilha, &(p.dados));
}

//função de inserir da fila
void inserir (int *fila, struct Info *dados, int num){
	if ((dados->fim == dados->pos_fim))
		printf ("CHEIO");
	else
		fila[dados->fim++] = num;
}

//função de imprimir a fila na tela
void imprimir (int *fila, struct Info *dados){
	int i;
	for (i = dados->ini; i < dados->fim; i++){
		printf("%d ", fila[i]);
	}
	printf("\n");
}

//função que remove o elemento da fila
int remover (int *fila, struct Info *dados){
	if (dados->ini == dados->fim)
		printf("VAZIO");
	else{
		return fila[dados->ini++];
	}
}

//push, que é basicamente inserir na fila
void push (struct Pilha *p, int num){
	inserir (p->pilha, &(p->dados), num);
}

/*pop, que o que foi ulitizado é o seguinte: remover todos os elementos até o penúltimo da fila 
principal, chamado de pilha, e insere na fila auxiliar, criada na função, depois disso coloca o último 
elemento fila principal e coloca na em um temp, após isso coloca o insire os elementos da fila 
auxiliar na fila principal, no final retorna o temp, o elemento removido*/
int pop (struct Pilha *p){
	int temp, i;
	int fila[p->dados.pos_fim + 1];
	struct Info dados2;
	dados2.ini = 0;
	dados2.fim = 0;
	while (p->dados.ini != (p->dados.fim - 1)){	//aqui ele remova da fila principal, pilha, e insere na fila secundária, aux
		temp = remover(p->pilha, &(p->dados));
		inserir(fila, &dados2, temp);
	}
	temp = remover(p->pilha, &(p->dados));
	for (i = 0; i < dados2.fim; i++)	//removendo elementos da fila secundária e coloca na fila principal
		p->pilha[i] = remover(fila, &dados2);
	p->dados.ini = 0;
	p->dados.fim = i;
	return temp;
}