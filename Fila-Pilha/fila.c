#include <stdio.h>
#include <stdlib.h>

struct Lista {
	int numero;
	struct Lista *prox;
};

void remover_fila (struct Lista **fila);
void inserir_fila (struct Lista **cabeca, struct Lista **elemento);
void exec (const char *arquivo);
void imprimir (struct Lista *cabeca);


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
		if (escolha == 'a'){
			fscanf(arq, "%d\n", &set->numero);
			set->prox = NULL;
			if (cabeca == NULL){
				cabeca = (struct Lista *) malloc (sizeof(struct Lista));
				cabeca = set;
			}
			else
				inserir_fila (&cabeca, &set);
		}
		else if (escolha == 'i'){
			imprimir(cabeca);
		}
		else if (escolha == 'r'){
			fscanf (arq, "%d\n", &set->numero);
			remover_fila (&cabeca);
		}
	}
}

void inserir_f (struct Lista **cabeca, struct Lista **elemento){
	if ((*cabeca) == NULL){
		cabeca = malloc (sizeof(struct Lista));
		(*cabeca) = (*elemento);
	}
	else{
		(*elemento)->prox = (*cabeca);
		(*cabeca) = (*elemento);
	}
}

void inserir_fila (struct Lista **cabeca, struct Lista **elemento){
	if ((*cabeca) == NULL)
		(*cabeca) = (*elemento);
	else{
		struct Lista *temp = NULL;
		temp = (struct Lista *) malloc(sizeof (struct Lista));
		temp = (*cabeca);
		while (temp->prox != NULL)
			temp = temp->prox;
		temp->prox = (*elemento);
	}
}

void remover_fila (struct Lista **fila){
	if (fila == NULL)
		return;
	(*fila) = (*fila)->prox;
}

void imprimir (struct Lista *cabeca){
	FILE *res = NULL;
	struct Lista *temp = NULL;
	res = fopen("saida.txt", "a");
	if (cabeca == NULL){
		fprintf(res, "Vazio\n");
	}
	temp = (struct Lista *) malloc (sizeof (struct Lista));
	fprintf(res, "%d ", cabeca->numero);
	temp = cabeca;
	while(temp->prox != NULL){
		temp = temp->prox;
		fprintf(res, "%d ", temp->numero);
	}
	fprintf(res, "\n");
	fclose(res);
}