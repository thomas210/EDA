#include <stdio.h>
#include <stdlib.h>


int indice(int dicionario[5], int valor);
void adicionar(int dicionario[5], int grafo[5][5], int valor, int ligacao);
void remover(int dicionario[5], int grafo[5][5], int valor, int ligacao);
void imprimir (int grafo[5][5], int dicionario[5]);

int minimo (int dicionario[5], int grafo[5][5], int inicio, int fim, int *visitados){
	int pos_inicio, pos_fim, i, aux, caminho = 0;
	if (visitados == NULL) {
		visitados = (int *)malloc(sizeof(int) * 5);
		for (i = 0; i < 5; i++)
			visitados[i] = 0;
	}
	pos_inicio = indice(dicionario, inicio);
	pos_fim = indice(dicionario, fim);
	if (pos_fim == -1 || pos_inicio == -1) return 0;
	if (grafo[pos_inicio][pos_fim] == 1) return 1;
	for (i = 0; i < 5; i++){
		if (grafo[pos_inicio][i] == 1){
			if (visitados[i] == 1) continue;
			else {
				visitados[i] = 1;
				aux = minimo(dicionario, grafo, dicionario[i], fim, visitados) + 1;
				if (aux < caminho || caminho == 0) caminho = aux;
			}
		}
	}
	return caminho;
}

void main (){
	int dicionario[5] = {-1,-1,-1,-1,-1};
	int grafo[5][5] = 	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int *visitados = NULL;
	adicionar(dicionario, grafo, 5, -1);
	adicionar(dicionario, grafo, 4, -1);
	adicionar(dicionario, grafo, 3, 5);
	adicionar(dicionario, grafo, 3, 4);
	adicionar(dicionario, grafo, 2, 4);
	adicionar(dicionario, grafo, 2, 3);
	adicionar(dicionario, grafo, 7, 4);
	adicionar(dicionario, grafo, 5, 4);
	imprimir(grafo, dicionario);
	printf("%d\n", minimo(dicionario, grafo, 7, 5, NULL));
	remover(dicionario, grafo, 5,4);
	imprimir(grafo, dicionario);
	printf("%d", minimo(dicionario, grafo, 7, 5, NULL));
}

void adicionar(int dicionario[5], int grafo[5][5], int valor, int ligacao){
	int i, pos_valor, pos_lig;
	for (i = 0; i < 5; i++){
		if (dicionario[i] == -1 || dicionario[i] == valor){
			dicionario[i] = valor;
			break;
		}
	}
	if (ligacao == -1) return;
	pos_valor = i;
	pos_lig = indice(dicionario, ligacao);
	if (pos_lig == -1) return;
	grafo[pos_valor][pos_lig] = 1;
	grafo[pos_lig][pos_valor] = 1;
}

void imprimir (int grafo[5][5], int dicionario[5]){
	int i, j;
	for (i = 0; i < 5; i++){
		if (dicionario[i] == -1) break;
		printf("%d se liga com: ", dicionario[i]);
		for (j = 0; j < 5; j++){
			if (grafo[i][j] == 1) printf("%d ", dicionario[j]);
		}
		printf("\n");
	}
}

int indice(int dicionario[5], int valor){
	int i;
	for (i = 0; i < 5; i++)
		if (dicionario[i] == valor)
			return i;
	return -1;
}

void remover(int dicionario[5], int grafo[5][5], int valor, int ligacao){
	int pos_valor, pos_lig;
	pos_valor = indice(dicionario, valor);
	pos_lig = indice(dicionario, ligacao);
	if (pos_valor == -1 || pos_lig == -1) return;
	grafo[pos_valor][pos_lig] = 0;
	grafo[pos_lig][pos_valor] = 0;
}