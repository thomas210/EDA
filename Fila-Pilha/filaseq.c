#include <stdio.h>
#include <stdlib.h>

enum Bool {
	TRUE,
	FALSE,
};

struct Info {
	int ini;
	int fim;
	int pos_fim;
	int num;
};

/*enum Bool inserir (int num, int *fila, int *ini, int *fim, int pos_fim){
	if (pos_fim == (*fim))
		return FALSE;
	fila[(*fim)++] = num;
	return TRUE;
}*/

void inserir (int *fila, struct Info *dados){
	if (dados->pos_fim == dados->fim)
		return;
	fila[dados->fim++] = dados->num;
	return;
}

/*enum Bool remover (int *fila, int *ini, int *fim){
	if (ini == fim)
		return FALSE;
	fila[(*ini)++];
}*/

void remover (int * fila, struct Info *dados){
	if (dados->ini == dados->fim)
		return;
	fila[dados->ini++];
}

/*void imprimir (int *fila, int *ini, int *fim){
	int i;
	for (i = (*ini); i < (*fim);i++){
		printf("%d ", fila[i]);
	}
	printf("\n");
}*/

void imprimir (int *fila, struct Info *dados){
	int i;
	for (i = dados->ini;i < dados->fim;i++){
		printf("%d ", fila[i]);
	}
	printf("\n");
}

void exec (const char *arquivo){
	FILE *arq = NULL;
	int *fila = NULL;
	struct Info dados;
	char escolha;
	arq = fopen(arquivo, "r");
	fscanf(arq, "%d %d %d\n", &dados.ini, &dados.fim, &dados.pos_fim);
	fila = (int *) malloc (sizeof(int) * (dados.pos_fim + 1));
	while(!feof(arq)){
		fscanf(arq, "%c ", &escolha);
		if (escolha == 'a'){
			fscanf(arq, "%d\n", &dados.num);
			inserir(fila, &dados);
		}
		else if (escolha == 'r')
			remover(fila, &dados);
		else if (escolha == 'i')
			imprimir(fila, &dados);
	}
}


void main(int argc, char *argv[]){
	exec (argv[1]);
}

