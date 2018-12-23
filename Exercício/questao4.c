#include <stdio.h>
#include <stdlib.h>

int quickfind (int *vetor, int inicio, int fim, int kEsimo);

void main (){
	int S[] = {7,1,3,10,17,2,21,9};
	int i;
	printf("%d ", quickfind(S,0,7,5));
}

//Função que retorna o k-ésimo elemento do vetor, ele define a posição como pivo e utilizando a lógico do quicksort, ele checa se o pivo esta na posição correta pedida, se tiver retorna o pivo, caso contrário realiza a função novamente de acordo com o posição do pivo
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
	if (pos == kEsimo-1) return pivo;	//caso esteja certo, ele retorna o pivo
	else if (pos > kEsimo-1) return quickfind(vetor, inicio, pos-1, kEsimo);	//caso o pivo esteja numa posição acima do k-ésimo, então ele realiza novamente o quickfind, mas dessa vez com o subvetor da esquerda.
	else return quickfind(vetor, pos+1, fim, kEsimo);	//caso o pivo esteja numa posição abaixo do k-ésimo, então ele realiza novamente o quickfind, mas dessa vez com o subvetor da direita.
}