#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Para mostra o código, utilizei a mesma rede social da questão 2.

struct Lista {
	char nome[30];
	struct Lista *prox;
};

int indice(char dicionario[13][30], char *nome);
void add_amizade(char dicionario[13][30], int grafo[13][13], char *nome, char *ligacao);
void remover_amizade(char dicionario[13][30], int grafo[13][13], char *nome, char *ligacao);
void snapshot (int grafo[13][13], char dicionario[13][30], char **msg);
void imprimir (struct Lista *cabeca);
void inserir_fila_pilha (struct Lista **cabeca, char nome[30]);
void retirar_fila (struct Lista **cabeca, char nome[30]);
void busca_largura (char dicionario[13][30], int grafo[13][13], char *inicio, struct Lista **cabeca, char **msg);
void busca_profundidade (char dicionario[13][30], int grafo[13][13], char *inicio, struct Lista **cabeca, char **msg);
void retirar_pilha (struct Lista **cabeca, char nome[30]);

//Inicialização das vairáveis
void main (){
	char dicionario[13][30];
	int i;
	char *msg = NULL;
	struct Lista *cabeca = NULL;
	int grafo[13][13] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	for (i = 0; i < 13; i++){
		strcpy(dicionario[i], "vazio");
	}
	add_amizade(dicionario, grafo, "V", NULL);
	add_amizade(dicionario, grafo, "thomas", NULL);
	add_amizade(dicionario, grafo, "filipe", NULL);
	add_amizade(dicionario, grafo, "denini", NULL);
	add_amizade(dicionario, grafo, "brenno", NULL);
	add_amizade(dicionario, grafo, "breno", NULL);
	add_amizade(dicionario, grafo, "rhuan", NULL);
	add_amizade(dicionario, grafo, "geovanne", NULL);
	add_amizade(dicionario, grafo, "jorge", NULL);
	add_amizade(dicionario, grafo, "pedro", NULL);
	add_amizade(dicionario, grafo, "mylena", NULL);
	add_amizade(dicionario, grafo, "luis", NULL);
	add_amizade(dicionario, grafo, "cleber", NULL);
	add_amizade(dicionario, grafo, "V", "filipe");
	add_amizade(dicionario, grafo, "V", "denini");
	add_amizade(dicionario, grafo, "V", "thomas");
	add_amizade(dicionario, grafo, "filipe", "denini");
	add_amizade(dicionario, grafo, "denini", "brenno");
	add_amizade(dicionario, grafo, "denini", "breno");
	add_amizade(dicionario, grafo, "brenno", "breno");
	add_amizade(dicionario, grafo, "breno", "rhuan");
	add_amizade(dicionario, grafo, "rhuan", "geovanne");
	add_amizade(dicionario, grafo, "rhuan", "jorge");
	add_amizade(dicionario, grafo, "geovanne", "thomas");
	add_amizade(dicionario, grafo, "geovanne", "jorge");
	add_amizade(dicionario, grafo, "jorge", "pedro");
	add_amizade(dicionario, grafo, "jorge", "mylena");
	add_amizade(dicionario, grafo, "pedro", "luis");
	add_amizade(dicionario, grafo, "luis", "cleber");
	add_amizade(dicionario, grafo, "cleber", "mylena");
	add_amizade(dicionario, grafo, "pedro", "mylena");
	busca_largura(dicionario, grafo, "V", &cabeca, &msg);
	printf("%s", msg);
}

//função que retorna qual posição do dicionario o nome está relacionado, e consequentemente qual sua posição de linha/coluna na matriz de adjacência
int indice(char dicionario[13][30], char *nome){
	int i;
	for (i = 0; i < 13; i++)
		if (strcmp(dicionario[i],nome) == 0)
			return i;
	return -1;

}

//A função insere o valor no dicionario e, se ela vier também com alguma ligação para fazer, pega o indice da ligação e coloca o "1" na matriz na posição das duas
void add_amizade(char dicionario[13][30], int grafo[13][13], char *nome, char *ligacao){
	int i, pos_nome, pos_lig;
	for (i = 0; i < 13; i++){
		if (strcmp(dicionario[i],"vazio") == 0 || strcmp(dicionario[i],nome) == 0){
			strcpy(dicionario[i], nome);	//inserindo no dicionário
			break;
		}
	}
	if (ligacao == NULL) return;	//checando se a função veio com alguma ligação
	pos_nome = i;
	pos_lig = indice(dicionario, ligacao);
	if (pos_lig == -1) return;
	grafo[pos_nome][pos_lig] = 1;	//marcando na matriz
	grafo[pos_lig][pos_nome] = 1;	//marcando na matriz
}

//A função coloca dentro da variável msg, todas as informções de amizade seguindo o seguinte modelo:
//Nome_pessoa é amigo de: nome_amigo | nome_amigo | etc ...
void snapshot (int grafo[13][13], char dicionario[13][30], char **msg){
	int i, j;
	(*msg) = (char *)malloc(sizeof(char)*1000);
	strcpy((*msg), "");
	for (i = 0; i < 13; i++){
		if (strcmp(dicionario[i], "vazio") == 0) break;	//quando ele encontra uma posição vazia do dicionário, ele para pois os nomes estão adcionados em sequencia
		strcat((*msg), dicionario[i]);	//inserindo nome da pessoa
		strcat((*msg), " e amigo de: ");
		for (j = 0; j < 13; j++){
			if (grafo[i][j] == 1){ 	//se ele encontra uma confirmação na matriz, adiciona em "msg" o nome correspondente
				strcat((*msg), dicionario[j]);
				strcat((*msg), "|");
			}
		}
		strcat((*msg), "\n");
	}
}

//Função que remove a ligação entre os nomes, pega o índice dos dois nomes e coloca 0 nas posições da mtraiz correspondentes
void remover_amizade(char dicionario[13][30], int grafo[13][13], char *nome, char *ligacao){
	int pos_nome, pos_lig;
	pos_nome = indice(dicionario, nome);
	pos_lig = indice(dicionario, ligacao);
	if (pos_nome == -1 || pos_lig == -1) return;
	grafo[pos_nome][pos_lig] = 0;
	grafo[pos_lig][pos_nome] = 0;
}

void inserir_fila_pilha (struct Lista **cabeca, char elemento[30]){
	if ((*cabeca) == NULL){
		(*cabeca) = (struct Lista*) malloc(sizeof(struct Lista));
		strcpy((*cabeca)->nome, elemento);
		(*cabeca)->prox = NULL;
	}
	else
		inserir_fila_pilha(&(*cabeca)->prox, elemento);
}

void imprimir (struct Lista *cabeca){
	if (cabeca == NULL)
		printf("\n");
	else{
		printf ("%s ", cabeca->nome);
		imprimir (cabeca->prox);
	}
}

void retirar_fila (struct Lista **cabeca, char nome[30]){
	strcpy(nome, (*cabeca)->nome);
	(*cabeca) = (*cabeca)->prox;
}

void retirar_pilha (struct Lista **cabeca, char nome[30]){
	struct Lista *temp = NULL;
	struct Lista *aux = NULL;
	if ((*cabeca) == NULL) return;
	temp = (struct Lista *)malloc(sizeof(struct Lista));
	aux = (struct Lista *)malloc(sizeof(struct Lista));
	temp = (*cabeca);
	aux = (*cabeca)->prox;
	if (aux == NULL){
		strcpy(nome, (*cabeca)->nome);
		free(temp);
		free(aux);
		return;
	}
	while (aux->prox != NULL){
		temp = aux;
		aux = aux->prox;
	}
	temp->prox = NULL;
	strcpy(nome, aux->nome);
	free(aux);
}

//Função que realiza a busca em largura, adiciona na fila as ligações e retira a primeira e chama a função recursivamente. Retorna um vetor indicando a ordem em que foram visitados os nomes
void busca_largura (char dicionario[13][30], int grafo[13][13], char *inicio, struct Lista **cabeca, char **msg){
	int pos, i;
	static int visitados[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
	char proximo[30];
	pos = indice(dicionario, inicio);
	visitados[pos] = 1;
	if (pos == -1) return;
	if ((*msg) == NULL) {	//inicio o vetor da mensagem e coloco o primeiro nome da lista, no caso "V"
		(*msg) = (char *)malloc(sizeof(char)*1000);
		strcpy((*msg), inicio);
		strcat((*msg), "\n");
	}
	for (i = 0; i < 13; i++){
		if (grafo[pos][i] == 1){
			if (visitados[i] == 1) continue;
			else{
				visitados[i] = 1;
				strcat((*msg), dicionario[i]);
				strcat((*msg), "\n");
				inserir_fila_pilha(cabeca, dicionario[i]);	//insiro na fila o elemento
			}
		}
	}
	if ((*cabeca) != NULL){
		retirar_fila(cabeca, proximo);
		busca_largura (dicionario, grafo, proximo, cabeca, msg);
	}
	
}

//Função que realiza a busca em profudidade, adiciona na pilha as ligaões e retira a ultima e chama a função recursivamente. Retorna um vetor indicando a ordem em que foram visitados os nomes
void busca_profundidade (char dicionario[13][30], int grafo[13][13], char *inicio, struct Lista **cabeca, char **msg){
	int pos, i;
	static int visitados[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
	char proximo[30];
	pos = indice(dicionario, inicio);
	if (pos == -1) return;
	if ((*msg) == NULL) {	//inicio o vetor da mensagem e coloco o primeiro nome da lista, no caso "V"
		(*msg) = (char *)malloc(sizeof(char)*1000);
		strcpy((*msg), inicio);
		strcat((*msg), "\n");
	}
	visitados[pos] = 1;
	inserir_fila_pilha(cabeca, dicionario[pos]);	//insiro na pilha o elemento
	for (i = 0; i < 13; i++){
		if (grafo[pos][i] == 1){	//comçea a busca pelas ligações
			if (visitados[i] == 1) continue;	//checo se ja visitei esse elemento
			else{
				visitados[i] = 1;
				strcat((*msg), dicionario[i]);
				strcat((*msg), "\n");
				busca_profundidade (dicionario, grafo, dicionario[i], cabeca, msg); //chamo a função novamente, dessa vez com o elemento da ligação
			}
		}
	}
	if ((*cabeca)->prox != NULL){	//retiro os dois últimos elementos da pilha, o primeiro é o que estava usando, e o segundo é o que vou usar
		retirar_pilha(cabeca, proximo);
		retirar_pilha(cabeca, proximo);
		busca_profundidade (dicionario, grafo, proximo, cabeca, msg);
	}
}