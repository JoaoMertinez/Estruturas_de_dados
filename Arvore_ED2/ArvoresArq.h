#include <stdio.h>
#include <stdlib.h>

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

//void pre_ordemI(Tree *raiz) { //chegu no no ja exibe
//    Pilha *p;
//    init(&p);
//    push(&p, raiz);
//    while(!isEmpty(p)) {
//        if(raiz != NULL){
//            pop(&p, &raiz);
//            while(raiz != NULL) {
//                printf("%d", raiz->info);
//                push(&p, raiz);
//                raiz = raiz->esq;
//            }
//            pop(&p, &raiz);
//            raiz = raiz->dir;
//            if(raiz != NULL) {
//                push(&p, raiz);
//            }
//        }
//    }
//}

//void in_ordemI(Tree *raiz) {
//    Pilha *p;
//    init(&p);
//    push(&p, raiz);
//    while(!isEmpty(p)) {
//        if(raiz != NULL){
//            pop(&p, &raiz);
//            while(raiz != NULL) {
//                push(&p, raiz);
//                raiz = raiz->esq;
//            }
//            pop(&p, &raiz);
//            printf("%d", raiz->info);
//            raiz = raiz->dir;
//            if(raiz != NULL) {
//                push(&p, raiz);
//            }
//        }
//    }
//}

//void pos_ordemI(Tree *raiz) {
//    Pilha *p, *p2;
//    init(&p);
//    init(&p2);
//    push(&p, raiz);

//    while(!isEmpty(p)) {
//        if(raiz != NULL){
//            pop(&p, &raiz);
//            while(raiz != NULL) {
//                push(&p2, raiz);
//                push(&p, raiz);
//                raiz = raiz->esq;
//            }
//            pop(&p, &raiz);
//            raiz = raiz->dir;
//            if(raiz != NULL) {
//                push(&p, raiz);
//            }
//            while(!isEmpty(p2)) {
//                pop(&p2, &raiz);
//                printf("%d", raiz->info);
//            }
//        }
//    }
//}


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
