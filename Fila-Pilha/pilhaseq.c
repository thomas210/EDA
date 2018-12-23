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

void inserir (int *pilha, struct Info *dados){
	if (dados->pos_fim == dados->fim)
		return;
	pilha[dados->fim++] = dados->num;
	return;
}

void remover (int * pilha, struct Info *dados){
	if (dados->ini == dados->fim)
		return;
	pilha[dados->fim--];
}

void imprimir (int *pilha, struct Info *dados){
	int i;
	for (i = dados->ini;i < dados->fim;i++){
		printf("%d ", pilha[i]);
	}
	printf("\n");
}

void exec (const char *arquivo){
	FILE *arq = NULL;
	int *pilha = NULL;
	struct Info dados;
	char escolha;
	arq = fopen(arquivo, "r");
	fscanf(arq, "%d %d %d\n", &dados.ini, &dados.fim, &dados.pos_fim);
	pilha = (int *) malloc (sizeof(int) * (dados.pos_fim + 1));
	while(!feof(arq)){
		fscanf(arq, "%c ", &escolha);
		if (escolha == 'a'){
			fscanf(arq, "%d\n", &dados.num);
			inserir(pilha, &dados);
		}
		else if (escolha == 'r')
			remover(pilha, &dados);
		else if (escolha == 'i')
			imprimir(pilha, &dados);
	}
}


void main(int argc, char *argv[]){
	exec (argv[1]);
}

