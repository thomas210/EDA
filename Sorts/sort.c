#include <stdio.h>
#include <stdlib.h>

void selection (int *vetor, int tam);

void bubble (int *vetor, int tam){
	int i, j, aux;
	for (i = tam-1; i > 0; i--){
		for (j = 0; j < i; i++){
			if (vetor[i] > vetor[i+1]){
				aux = vetor[i];
				vetor[i] = vetor[i+1];
				vetor[i+1] = aux;
			}
		}
	}
}


void main() {
	int vetor[5] = {4,7,8,5,9};
	int i;
	for (i = 0; i < 5; i++){
		printf("%d ", vetor[i]);
	}
	printf("\n");
	bubble(vetor, 5);
	for (i = 0; i < 5; i++){
		printf("%d ", vetor[i]);
	}
	printf("\n");
}

void selection (int *vetor, int tam){
	int i,j, pos, aux;
	for (i = 0; i < tam; i++){
		pos = i;
		aux = vetor[i];
		for (j = i+1; j < tam; j++){
			if (vetor[j] < aux){
				pos = j;
				aux = vetor[j];
			}
		}
		vetor[pos] = vetor[i];
		vetor[i] = aux;
	}
}