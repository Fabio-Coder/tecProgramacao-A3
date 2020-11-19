#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char nome[30], ender[50];
	int dia,mes;
	int ano;
	
}PESSOA;

typedef struct
{
	PESSOA *pPessoas;
	int qtdPessoas;
	
}LISTAPESSOAS;



void criarListaVazia(LISTAPESSOAS *listaP)
{
	listaP->pPessoas = (PESSOA *) malloc(10*sizeof(PESSOA));
	listaP->qtdPessoas=0;
}

int buscarRegistro(char *nome,LISTAPESSOAS listaP,PESSOA *pessoa)
{
	int i=0;
	if(listaP.qtdPessoas==0)
	{
		return -1;			//indicativo de lista vazia
	}
	for(i=0;i<listaP.qtdPessoas;i++)
	{
		if(!strcmp(nome,(listaP.pPessoas+i)->nome))
		{
			pessoa = (listaP.pPessoas+i);
			return i;
		}
	}
	return -2;				//indicativo de registro nao encontrado
}

int inserirRegistro (PESSOA pessoa,LISTAPESSOAS *listaP, int pos)
{
	int i;
	if(listaP->qtdPessoas==10)
	{
		return -1;			//indicativo lista cheia
	}
	if(pos > listaP->qtdPessoas)
	{
		return -2;			//indicativo posicao extrapola limite do vetor
	}
	for(i=listaP->qtdPessoas;i>=pos;i--)
	{
		memcpy((listaP->pPessoas+i),(listaP->pPessoas+i-1),sizeof(PESSOA));
	}
	memcpy((listaP->pPessoas+pos),&pessoa,sizeof(PESSOA));
	(listaP->qtdPessoas)++;
}



int main()
{
	int *vetor;
	char *str;
	int numCelulas = 5, tamanhoStr = 10;
	
	//alocando espaco para vetor e para a string
	vetor = (int * ) malloc(numCelulas * sizeof(int));
	str = (char *) calloc(tamanhoStr, sizeof(char));
	
	//realocando espaco para o vetor - aumentando o vetor em 5 posicoes
	vetor = realloc(vetor,(numCelulas+5)*sizeof(int));
	
	//liberando o espacos previamente alocados
	free(vetor);
	free(str);
	return 0;
	
	
}
