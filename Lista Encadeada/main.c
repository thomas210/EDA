#include "lista_encadeada.h"

void exec (const char *arquivo);

void main (int argc, char *argv[]){
	exec(argv[1]);
}

void exec (const char *arquivo){
	FILE *arq = NULL;
	FILE *res = NULL;
	struct Lista *cabeca = NULL;
	char escolha;
	res = fopen("saida.txt", "w");
	arq = fopen(arquivo, "r");
	if (arq == NULL){
		fprintf(res, "Erro 404 Not Found!\n");
		return;
	}
	fclose(res);
	while (!feof(arq)){
		struct Lista *set = NULL;
		set = (struct Lista *) malloc (sizeof (struct Lista));
		fscanf(arq, "%c ", &escolha);
		if (escolha == 'f'){
			fscanf(arq, "%d\n", &set->numero);
			set->prox = NULL;
			inserir_f (&cabeca, &set);
		}
		else if (escolha == 'b'){
			fscanf(arq, "%d\n", &set->numero);
			set->prox = NULL;
			inserir_b (&cabeca, &set);
		}
		else if (escolha == 'i'){
			imprimir(cabeca);
		}
	}
	//free(set);
	free(cabeca);
	fclose(arq);
}