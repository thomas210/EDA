#include <stdio.h>
#include <stdlib.h>

struct Info {
	int ini;
	int fim;
	int pos_fim;
};

void inserir (int *fila, struct Info *dados, int num){
	if ((dados->fim == dados->pos_fim))
		printf ("CHEIO");
	else
		fila[dados->fim++] = num;
}

void imprimir (int *fila, struct Info *dados){
	int i;
	for (i = dados->ini; i < dados->fim; i++){
		printf("%d ", fila[i]);
	}
	printf("\n");
}

int remover (int *fila, struct Info *dados){
	if (dados->ini == dados->fim)
		printf("VAZIO");
	else{
		return fila[dados->ini++];
	}
}

void inverter (int *fila, int *inv, struct Info *dados){
	int i, ini;
	ini = dados->ini;
	for (i = dados->fim - 1; i >= ini; i--)
		inv[i] = remover(fila, dados);
}

void main (){
	int fila[10];
	int invertido[10];
	struct Info dados;
	int i;
	dados.ini = 0;
	dados.fim = 0;
	dados.pos_fim = 10;
	inserir(fila, &dados, 3);
	inserir(fila, &dados, 7);
	inserir(fila, &dados, 1);
	inserir(fila, &dados, 2);
	inserir(fila, &dados, 0);
	inserir(fila, &dados, 8);
	inserir(fila, &dados, 4);
	inserir(fila, &dados, 7);
	inserir(fila, &dados, 3);
	inserir(fila, &dados, 9);
	imprimir(fila, &dados);
	inverter (fila, invertido, &dados);
	for (i = 0; i < 10; i ++)
		printf ("%d ", invertido[i]);
}