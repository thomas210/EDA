#include <stdio.h>
#include <stdlib.h>

void quicksort (int *vetor, int inicio, int fim);

int quickfind (int *vetor, int inicio, int fim, int kEsimo){
	int pivo = vetor[kEsimo-1];
	int pos = kEsimo-1;
	int i, j;
	if (inicio >= fim) return 0;
	i = inicio;
	j = fim;
	while (i != j){
		while (vetor[j] > pivo){
			j--;
			if (i == j) break;
			
		}
		if (i == j) break;
		vetor[pos] = vetor[j];
		pos = j;
		while (vetor[i] <= pivo){
			i++;
			if (i == j) break;
		}
		if (i == j) break;
		vetor[pos] = vetor[i];
		pos = i;
	}
	vetor[pos] = pivo;
	printf("%d %d\n", pivo, pos);
	if (pos == kEsimo-1) return pivo;
	else if (pos > kEsimo-1) return quickfind(vetor, inicio, pos-1, kEsimo);
	else return quickfind(vetor, pos+1, fim, kEsimo);
}

void main (){
	int S[] = {7,1,3,10,17,2,21,9};
	int i;
	printf("%d ", quickfind(S,0,7,5));
}

void quicksort (int *vetor, int inicio, int fim){
	int pivo = vetor[inicio];
	int pos = inicio;
	int i, j;
	if (inicio >= fim) return;
	i = inicio;
	j = fim;
	while (i != j){
		while (vetor[j] > pivo){
			j--;
			if (i == j) break;
			
		}
		if (i == j) break;
		vetor[pos] = vetor[j];
		pos = j;
		while (vetor[i] <= pivo){
			i++;
			if (i == j) break;
		}
		if (i == j) break;
		vetor[pos] = vetor[i];
		pos = i;
	}
	vetor[pos] = pivo;
	quicksort(vetor, inicio, pos-1);
	quicksort(vetor, pos+1, fim);
}