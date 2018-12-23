#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//O grafo da rede social funciona da seguinte maneira: o grafo é a matriz de adjacência, e também possui um dicionario identificando qual posição correspondente ao nome

int indice(char dicionario[10][30], char *nome);
void add_amizade(char dicionario[10][30], int grafo[10][10], char *nome, char *ligacao);
void remover_amizade(char dicionario[10][30], int grafo[10][10], char *nome, char *ligacao);
void snapshot (int grafo[10][10], char dicionario[10][30], char **msg);


//Inicialização das vairáveis
void main (){
	char dicionario[10][30];
	int i;
	char *msg = NULL;
	int grafo[10][10] = 	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	for (i = 0; i < 10; i++){
		strcpy(dicionario[i], "vazio");
	}
	add_amizade(dicionario, grafo, "thomas", NULL);
	add_amizade(dicionario, grafo, "clovis", "thomas");
	add_amizade(dicionario, grafo, "geovanne", "thomas");
	add_amizade(dicionario, grafo, "matheus", "clovis");
	add_amizade(dicionario, grafo, "matheus", "thomas");
	add_amizade(dicionario, grafo, "juninho", "clovis");
	add_amizade(dicionario, grafo, "juninho", "thomas");
	add_amizade(dicionario, grafo, "juninho", "matheus");
	add_amizade(dicionario, grafo, "denini", "thomas");
	add_amizade(dicionario, grafo, "denini", "geovanne");
	snapshot(grafo, dicionario, &msg);
	printf("%s", msg);
	remover_amizade(dicionario, grafo, "denini", "geovanne");
	printf("\n");
	snapshot(grafo, dicionario, &msg);
	printf("%s", msg);
}

//função que retorna qual posição do dicionario o nome está relacionado, e consequentemente qual sua posição de linha/coluna na matriz de adjacência
int indice(char dicionario[10][30], char *nome){
	int i;
	for (i = 0; i < 10; i++)
		if (strcmp(dicionario[i],nome) == 0)
			return i;
	return -1;

}

//A função insere o valor no dicionario e, se ela vier também com alguma ligação para fazer, pega o indice da ligação e coloca o "1" na matriz na posição das duas
void add_amizade(char dicionario[10][30], int grafo[10][10], char *nome, char *ligacao){
	int i, pos_nome, pos_lig;
	for (i = 0; i < 10; i++){
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
void snapshot (int grafo[10][10], char dicionario[10][30], char **msg){
	int i, j;
	(*msg) = (char *)malloc(sizeof(char)*300);
	strcpy((*msg), "");
	for (i = 0; i < 10; i++){
		if (strcmp(dicionario[i], "vazio") == 0) break;	//quando ele encontra uma posição vazia do dicionário, ele para pois os nomes estão adcionados em sequencia
		strcat((*msg), dicionario[i]);	//inserindo nome da pessoa
		strcat((*msg), " e amigo de: ");
		for (j = 0; j < 10; j++){
			if (grafo[i][j] == 1){ 	//se ele encontra uma confirmação na matriz, adiciona em "msg" o nome correspondente
				strcat((*msg), dicionario[j]);
				strcat((*msg), "|");
			}
		}
		strcat((*msg), "\n");
	}
}

//Função que remove a ligação entre os nomes, pega o índice dos dois nomes e coloca 0 nas posições da mtraiz correspondentes
void remover_amizade(char dicionario[10][30], int grafo[10][10], char *nome, char *ligacao){
	int pos_nome, pos_lig;
	pos_nome = indice(dicionario, nome);
	pos_lig = indice(dicionario, ligacao);
	if (pos_nome == -1 || pos_lig == -1) return;
	grafo[pos_nome][pos_lig] = 0;
	grafo[pos_lig][pos_nome] = 0;
}