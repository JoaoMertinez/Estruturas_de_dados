#include <stdio.h>
#include "ArvoresArq.h"

int ProfundidadeReturn (Tree *raiz,int info)
{
    int cont=0, flag =0;
    
    if(raiz==NULL)
      return -1;
    else
    {
      while(raiz!=NULL && flag==0)
      {
        cont++;
        if(raiz->info == info)
          flag=1;
          
        if(info < raiz->info)
          raiz = raiz->esq;
        else
          raiz = raiz->dir;
          
      }
    }
    
    return cont;
  
}

Tree *retornaPai(Tree *raiz,int info)
{
  Tree *ant=NULL;
  int flag=0;
  
  if(raiz!=NULL)
  {
    if(raiz->info==info)
      ant=raiz;
    else{
      while(raiz!=NULL && flag==0){
        ant = raiz;
        
        if(info < raiz->info)
            raiz = raiz->esq;
        else
            raiz = raiz->dir;
           
            
        if(raiz->info==info)
          flag=1;
      }
      
    }
    
  }
  
  return ant;
  
}

void toraArvore(Tree **raiz)
{
  if(*raiz!=NULL)
  {
    toraArvore(&(*raiz)->esq);
    toraArvore(&(*raiz)->dir);
    free(*raiz);
  }
}


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
	//printf("##insere ABB##");
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
	
	//Exercicios
	
	//1
	int cont = ProfundidadeReturn(raiz_ABB,5);
	if(cont<0)
	  printf("\n no nao encontrado");
	else
	  printf("\n numero encontrado no nivel %d",cont);
	
	//2
	Tree *pai = retornaPai(raiz_ABB,6);
	if(pai!=NULL)
	  printf("\n nodo pai do numero informado %d",pai->info);
	else
	  printf("\npai nao encontrado");
	  
	//3
	//exibeIn_ordem(raiz_ABB);
	//exibePre_ordem(raiz_ABB);
	//exibePos_ordem(raiz_ABB);
	//in_ordemI(raiz_ABB);
	//pre_ordemI(raiz_ABB);
	//pos_ordemI(raiz_ABB);
	
	//4
	//toraArvore(raiz_ABB);
	
	
	
	//arvoreAVL
	
	return 0;
}
	
