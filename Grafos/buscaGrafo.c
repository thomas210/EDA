#include <stdio.h>
#include <stdlib.h>

struct Fila {
	int numero;
	int caminho;
};

void inserir (struct Fila *fila[5], int elemento){
	int i;
	for (i = 0; i < 6; i++){
		if (fila[i]->numero == 0)
			fila[i]->numero = elemento;
	}
}

void inicializar (struct Fila *fila[6]){
	int i;
	for (i = 0; i < 6; i++){
		fila[i]->numero = 0;
	}
}

int busca_largura (int grafo[6][6], int vetor_grafo[6], int origem, int fim){
	if (origem == fim)
		return 0;
	int i, j;
	int cond = 0;
	struct Fila elemento[6];
	int historico[6];
	int temp, cont = 0;
	inicializar(&elemento);
	temp = origem;
	while (cond == 0){
		for (i = 0; i < 6; i++){
			if (vetor_grafo[i] == temp)
				break;
		}
		historico[cont++] = temp;
		for (j = 1; j < 6; j++){
			if (grafo[i][j] == 1){
				historico[cont++] = vetor_grafo[j];
			}
				
		}
	}
	
	
}

void main (){
	int grafo [6][6] = {	0,1,0,0,0,1,
							1,0,0,1,0,0,
							0,0,1,0,1,0,
							0,1,1,0,0,0,
							0,0,1,0,0,1,
							1,0,0,0,1,0,
							};
	int vetor_grafo[6] = {5,9,7,4,6,8};
}