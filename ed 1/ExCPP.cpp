/*
Fazer uma exercicio que retira as informações de um aquivo texto, como codigo do produto, nome do fornecedor e o nome do produto
faça um relatorio de maneira recursiva desses dados

retirar informações do arquivo
inserir ordenado na fila
inserir ordenado na pilha
inserir ordenado na alocação dinamica
relatorios:
	relatorio dos dados da pilha
	relatorio dos dados da fila
	relatorio dos dados da alocação dinamica
*/

#include<stdio.h>
#include<string.h>
#include<conio2.h>
#include<ctype.h>
#include<stdlib.h>

#define TF 100

//scruct da alocação dinamica
struct TpPont
{
	char nomeProd[TF], nomeForn[TF];
	int codProd;
	TpPont *prox;
};

//nova caixa na alocação dinamica
TpPont *novaCaixa(int cod, char nomeP[TF], char nomeF[TF])
{
	TpPont *caixa;
	caixa = new TpPont;
	caixa->codProd = cod;
	strcpy(caixa->nomeProd,nomeP);
	strcpy(caixa->nomeForn,nomeF);
	caixa->prox = NULL;
	return caixa;
}


//criando função que retira os dados do arquivo texto e coloca na alocação dinamica e dentro do vetor estatico
TpPont *insereOrdenado(TpPont *lista)
{
	TpPont *ant, *atual, *nc;
	int cod;
	char nomeP[TF], nomeF[TF];
	
	printf("\n### INSERE ORDENADO ###\n");
	
	FILE *ptr = fopen("PRODUTOS.txt","r");
	
	if(ptr == NULL)
		printf("\nErro na abertura do arquivo!\n");
	else
	{
		
		while(fscanf(ptr,"%d;%[^;];%[^;]\n",&cod,&nomeP,&nomeF) != EOF)
		{
			nc = novaCaixa(cod,nomeP,nomeF);
			if(lista == NULL)
				lista = nc;
			else
			{
				if(lista->codProd >= nc->codProd)
				{
					nc->prox = lista;
					lista = nc;
				}
				else
				{
					atual = lista;
					while(atual->prox != NULL && nc->codProd >= atual->codProd)
					{
						ant = atual;
						atual = atual->prox;
					}
					
					if(nc->codProd <= atual->codProd)
					{
						nc->prox = atual;
						ant->prox = nc;
					}
					else
						atual->prox = nc;
				}
			}
		}
		fclose(ptr);
	}
	printf("\n\nO INSERIR DEU CERTO!!!\n");
	return lista;
}

void exibir(TpPont *lista)
{
	printf("\n\n### EXIBIR ###\n");
	if(lista == NULL)
		printf("\nLista vazia!\n");
	else
	{
		while(lista -> prox != NULL)
		{
			printf("\nCODIGO: %D\n\t\tNOME DO PRODUTO: %S\tNOME DO FORNECEDOR:%s\n",lista->codProd,lista->nomeProd,lista->nomeForn);
			lista = lista->prox;
		}
		printf("\nCODIGO: %D\n\t\tNOME DO PRODUTO: %S\tNOME DO FORNECEDOR:%s\n",lista->codProd,lista->nomeProd,lista->nomeForn);
	}
}

//relatorio recursivo
void relatorioRecursivo(TpPont *lista)
{
	printf("\n\n### RELATORIO RECURSIVO ###\n\n");
	if(lista != NULL)
	{
		if(lista->codProd == lista->codProd)
			relatorioRecursivo(lista->prox);
		else
		{
			printf("CODIGO: %D\n\t\tNOME DO PRODUTO: %S\tNOME DO FORNECEDOR:%s\n",lista->codProd,lista->nomeProd,lista->nomeForn);
			//lista = lista->prox;
		}
	}
}


int main(void)
{
	int tl=0;
	TpPont *L = NULL;
	
	L = insereOrdenado(L);
	
	exibir(L);
	
	//relatorioRecursivo(L);
	
	getch();
	
	return 0;
}
