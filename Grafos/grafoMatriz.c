#include <stdio.h>
#include <stdlib.h>

int inserir_vetor (int vetor_num[5], int elemento);
void inserir_grafo (int vetor_num[5], int matriz_grafo[5][5], int elemento);
void imprimir (int vetor_num[5], int matriz_grafo[5][5]);

void main (){
	int vetor_num[5];
	int i,j;
	int matriz_grafo[5][5];
	for (i = 0; i < 5; i++){
		vetor_num[i] = 0;
	}
	inserir_grafo(vetor_num, matriz_grafo, 2);
	inserir_grafo(vetor_num, matriz_grafo, 1);
	inserir_grafo(vetor_num, matriz_grafo, 10);
	inserir_grafo(vetor_num, matriz_grafo, 3);
	inserir_grafo(vetor_num, matriz_grafo, 5);
	imprimir(vetor_num, matriz_grafo);
}

int inserir_vetor (int vetor_num[5], int elemento){
	int i;
	for (i = 0; i < 5; i++){
		if (vetor_num[i] == 0){
			vetor_num[i] = elemento;
			return i;
		}
	}
}

void inserir_grafo (int vetor_num[5], int matriz_grafo[5][5], int elemento){
	int i, pos;
	pos = inserir_vetor(vetor_num, elemento);
	for (i = 0; i <= pos; i++){
		if ((vetor_num[i]%elemento) == 0)
			matriz_grafo[i][pos] = 1;
		else
			matriz_grafo[i][pos] = 0;
		if ((vetor_num[pos]%vetor_num[i]) == 0)
			matriz_grafo[pos][i] = 1;
		else
			matriz_grafo[pos][i] = 0;
	}
}

void imprimir (int vetor_num[5], int matriz_grafo[5][5]){
	int i,j;
	printf("Linhas\n");
	for (i = 0; i < 5; i++){
		printf("linha %d: %d\n", i+1, vetor_num[i]);
	}
	printf("\n");
	printf("    ");
	for (i = 0; i < 5; i++){
		printf("%d ", i+1);
	}
	printf("\n");
	printf("    ");
	for (i = 0; i < 5; i++){
		printf("| ", i+1);
	}
	printf("\n");
	for (i = 0; i < 5; i++){
		printf("%d - ", i+1);
		for (j = 0; j < 5; j++){
			printf("%d ", matriz_grafo[i][j]);
		}
	printf("\n");
	}
}


