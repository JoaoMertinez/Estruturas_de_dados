#include <stdio.h>
#include <stdlib.h>
#include "QuestoesArvore.h"

struct tree{//struct padrao para todas as arvores
	int info;
	struct tree *dir,*esq;
};
typedef struct tree Tree;

void initAB(Tree **raiz)
{*raiz = NULL;}

void Erro(void)
{
	printf("\nParametros nao encontrados!!");
	//exit(1);
}

Tree *CriaNoAB(int info)
{
	Tree * newT = (Tree*) malloc(sizeof(Tree));
	newT->info = info;
	newT->dir = newT->esq = NULL;
	
	return newT;
}

//void localizaF(Tree *raiz, int varP, Tree **pai)
//{
//	Tree * aux = raiz;
//	while(aux!=NULL)
//	{
//		if(aux->info == varP)
//			*pai=aux;
//			
//		aux = aux ->esq;
//	}
//	
//	if(pai==NULL)
//	{
//		aux = raiz;
//		while(aux!=NULL)
//		{
//			if(aux->info = varP)
//				*pai=aux;
//				
//			aux = aux ->dir;
//		}	
//	}
//	

void localizaFchat(Tree *raiz, int varP, Tree **pai) {
	if (raiz == NULL) {
       return;
   }
    
    if (raiz->info == varP) {
        *pai = raiz;
        return;
    }

    localizaFchat(raiz->esq, varP, pai);

    if (*pai == NULL) {
        localizaFchat(raiz->dir, varP, pai);
    }
}

void localizaF(Tree *raiz,int varP,Tree **pai)
{
	if(raiz!=NULL)
	{
		if (raiz->info == varP) {
        	*pai = raiz;
    	}
	    localizaF(raiz->esq, varP, pai);
	    if (*pai == NULL) {
	        localizaF(raiz->dir, varP, pai);	
		}
	}	
}

void exibeABrecursivo(Tree *raiz)
{
	if(raiz==NULL)
		return;
	
	printf("\n%d",raiz->info);
	exibeABrecursivo(raiz->esq);
	exibeABrecursivo(raiz->dir);
}

void exibePre_ordem(Tree *raiz)
{
	if(raiz!=NULL)
	{
		printf("\n%d",raiz->info);
		exibePre_ordem(raiz->esq);
		exibePre_ordem(raiz->dir);
	}
}

void exibeIn_ordem(Tree *raiz)
{
	if(raiz!=NULL)
	{
		exibeIn_ordem(raiz->esq);
		printf("\n%d",raiz->info);
		exibeIn_ordem(raiz->dir);
	}
}

void exibePos_ordem(Tree *raiz)//bom para exclusao
{
	if(raiz!=NULL)
	{
		exibePre_ordem(raiz->esq);
		exibePos_ordem(raiz->dir);
		printf("\n%d",raiz->info);
	}
}

void insereAB(Tree **raiz,int var,int varP,char lado)
{
	Tree * pai;
	initAB(&pai);
	
	if(*raiz==NULL)
	{
		*raiz = CriaNoAB(var);
		//printf("\nRaiz: %d Inserido com sucesso!!",var);
	}
	else
	{
		localizaF(*raiz,varP,&pai);//aponta para o ponteiro de onde vai ter que apontar
		if(pai==NULL)
			Erro();
		else
			if(lado=='d' && pai->dir==NULL)
			{
				pai->dir = CriaNoAB(var);
				//printf("\n%d Inserido com sucesso!!",var);
			}
			else
				if(lado == 'e' && pai->esq==NULL)
				{
					pai->esq = CriaNoAB(var);
					//printf("\n%d Inserido com sucesso!!",var);
				}
				else
					Erro();
	}
}

void insereABB(Tree **raiz,int var)
{
	Tree *aux,*ant;
	if(*raiz == NULL)
	{
		*raiz = CriaNoAB(var);
		//printf("\nRaiz: %d Inserido com sucesso!!",var);		
	}
	else
	{
		aux = *raiz;
		while(aux!=NULL)
		{
			ant = aux;
			if(var<aux->info)
				aux = aux->esq;
			else 
				aux = aux->dir;
		}
		
		if(var<ant->info)
			ant->esq = CriaNoAB(var);
		else 
			ant->dir = CriaNoAB(var);
	}
}

void insereABBR(Tree **raiz,int info)
{
    if(*raiz==NULL)
        *raiz = CriaNoAB(info);
    else
        if(info < (*raiz)->info)
            insereABBR(&(*raiz)->esq,info);
        else 
            insereABBR(&(*raiz)->dir,info);
}

void buscaABBrefIT(Tree *raiz, int info, Tree **pos)
{
    Tree *aux, *ant;
    
    if(raiz->info==info)
        *pos = raiz;
    else
    {
        aux = raiz;
        while(aux!=NULL)//tenho que lembrar que o aux vai ate chegar no null
        {
            ant = aux;
            if(info < aux->info)
                aux = aux->esq;
            else
                aux = aux->dir;
        }
        
        *pos = ant;
    }
}

Tree *buscaABBretIT(Tree *raiz, int info)
{
    Tree *aux, *ant, *pos;
    
    if(raiz->info==info)
        pos = raiz;
    else
    {
        aux = raiz;
        while(aux!=NULL)//tenho que lembrar que o aux vai ate chegar no null
        {
            ant = aux;
            if(info < aux->info)
                aux = aux->esq;
            else
                aux = aux->dir;
        }
        
        pos = ant;
    }
    return pos;
}

//pre ordem - vai indo para a esquerda até achar o null, exibido tudo, depois voltar e vai para a diretira, depois volta denovo
//in ordem - mostra ordenado, vai indo para e esquerda ate achar o null, ai vai desempilhar e vai voltar na linha de exibir que vai estar a baico

int main(void)
{	
	Tree *raiz;
	Tree *raiz_ABB;
	
	//arvore
	initAB(&raiz);
	insereAB(&raiz, 10, 0, 'd');
	insereAB(&raiz, 20, 10, 'e');
	insereAB(&raiz, 15, 10, 'd');
	insereAB(&raiz, 30, 20, 'd');
	insereAB(&raiz, 25, 20, 'e');
	insereAB(&raiz, 5, 15, 'd');
	insereAB(&raiz, 18, 15, 'e');
	insereAB(&raiz, 35, 30, 'e');
	//exibeABrecursivo(raiz);
	
	//arvore ABB
	printf("##insere ABB##");
	initAB(&raiz_ABB);
	insereABB(&raiz_ABB,10);
	insereABB(&raiz_ABB, 5);
	insereABB(&raiz_ABB, 15);
	insereABB(&raiz_ABB, 3);
	insereABB(&raiz_ABB, 7);
	insereABB(&raiz_ABB, 12);
	insereABB(&raiz_ABB, 18);
	insereABB(&raiz_ABB, 1);
	insereABB(&raiz_ABB, 6);
	insereABB(&raiz_ABB, 8);
	insereABB(&raiz_ABB, 11);
	insereABB(&raiz_ABB, 13);
	insereABB(&raiz_ABB, 17);
	insereABB(&raiz_ABB, 20);
	
	printf("\nin ordem");
	//exibeIn_ordem(raiz_ABB);
	//exibePre_ordem(raiz_ABB);
	//exibePos_ordem(raiz_ABB);
	
	return 0;
}
