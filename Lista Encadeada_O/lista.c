#include <stdio.h>
#include <stdlib.h>

enum Boolean {
	TRUE,
	FALSE,
};

struct Lista {
	int numero;
	struct Lista *prox;
};

void inserir_f (struct Lista **cabeca, struct Lista **elemento);
void inserir_b (struct Lista **cabeca, struct Lista **elemento);
void imprimir (struct Lista *cabeca);
enum Boolean remover (struct Lista **cabeca, int num);
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
			/*if (cabeca == NULL){
				cabeca = (struct Lista *) malloc (sizeof(struct Lista));
				cabeca = set;
			}
			else*/
				inserir_f (&cabeca, &set);
		}
		else if (escolha == 'b'){
			fscanf(arq, "%d\n", &set->numero);
			set->prox = NULL;
			if (cabeca == NULL){
				cabeca = (struct Lista *) malloc (sizeof(struct Lista));
				cabeca = set;
			}
			else
				inserir_b (&cabeca, &set);
		}
		else if (escolha == 'i'){
			imprimir(cabeca);
		}
		else if (escolha == 'r'){
			fscanf (arq, "%d\n", &set->numero);
			remover (&cabeca, set->numero);
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

void inserir_b (struct Lista **cabeca, struct Lista **elemento){
	if ((*cabeca) == NULL)
		(*cabeca) = (*elemento);
	else{
		struct Lista *temp = NULL;
		temp = (struct Lista *) malloc(sizeof (struct Lista));
		temp = (*cabeca);
		while (temp->prox != NULL)
			temp = temp->prox;
		temp->prox = (*elemento);
		//free(temp);
	}
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

enum Boolean remover (struct Lista **cabeca, int num){
	if ((*cabeca)->numero == num)
		(*cabeca) = (*cabeca)->prox;
	else{
		struct Lista *temp;
		struct Lista *aux;
		temp = (struct Lista *) malloc (sizeof (struct Lista));
		aux = (struct Lista *) malloc (sizeof (struct Lista));
		temp = (*cabeca)->prox;
		aux = (*cabeca);
		while(temp->numero != num){
			aux = temp;
			temp = temp->prox;
			if (temp == NULL)
				return FALSE;
		}
		aux->prox = temp->prox;
		return TRUE;
	}
}