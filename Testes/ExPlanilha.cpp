#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio2.h>


union linhaCol{
	int l;
	char c;
};

struct matrizesparsa{
	int lin;
	char col;
	char valor[25];
	matrizesparsa *pl, *pc;
};
typedef struct matrizesparsa matEsp;

struct TpLC{
	union linhaCol elem;
	matEsp *mat;
	TpLC *prox; 
};

struct tpPlanilha{
	TpLC *linha;
	TpLC *coluna;
};
typedef struct tpPlanilha TpPlan;


//"C2G3"
//vou ter que fazer um while e ir dando prox até C chegar em G

void excluirRegiao(TpPlan *plan, char coord[25]){
	char CI=' ', CF=' ';
	char strAux[25]="";
	matEsp *auxL, *ant, *aux;
	
	int LI=0, LF=0, i;
	
	for(i=0; i<strlen(coord);i++){
		if(coord[i]>='A' && coord[i]<='Z'){
			if(CI==' ')
				CI=coord[i];
			else
				CF=coord[i];
		}
		else
			if(coord[i]>='0' && coord[i]<='9' && coord[i+1]>='0' && coord[i+1]<='9'){
				if(LI==0){
					strAux[0]=coord[i];
					strAux[1]=coord[i+1];
					strAux[2]='\0';
					LI=(int)*strAux;
				}
					
				else{
					strAux[0]=coord[i];
					strAux[1]=coord[i+1];
					strAux[2]='\0';
					LF=(int)*strAux;
				}
				i++;
				
			}
			else{
				if(LI==0)
					LI=coord[i];
				else
					LF=coord[i];
			}
	}
	struct TpLC *LinI=plan->linha;
	while(LinI->elem.l!=LI)
		LinI=LinI->prox;
	struct TpLC *LinF=plan->linha;
	while(LinF->elem.l!=LF)
		LinF=LinF->prox;
	struct TpLC *ColI=plan->coluna;
	while(ColI->elem.c!=CI)
		ColI=ColI->prox;
	struct TpLC *ColF=plan->coluna;
	while(ColF->elem.c!=CF)
		ColF=ColF->prox;
	//horizontal;
	while(LinI!=LinF->prox){
		ant=aux=LinI->mat;
		while(aux!=NULL){
			if(aux->col>=CI && aux->col<=CF){
				Push(&P,aux);
				if(ant==aux)
					LinI->mat=aux->pl;
				else
					ant->pl=aux->pl;
			}
			aux=aux->pl;
		}
		LinI=LinI->prox;
	}
	//vertical;
	while(ColI!=ColI->prox){
		ant=aux=ColI->mat;
		while(aux!=NULL){
			if(aux->lin>=LI && aux->lin<=LF){
				Push(&P,aux);
				if(ant=aux)
					ColI=aux->pc;
				else
					ant->pc=aux->pc;
			}
			
			aux=aux->pc;
		}
		
		ColI=ColI->prox;
	}
	
	while(!isEmpity(P)){
		Pop(&P,&aux);
		free(aux);
	}

	//excluir linhas e colunas que não apontam para nada:
	struct TpLC *antLC, *auxLC, *delLC;
	
	if(plan->linha->mat==NULL){
		delLc=plan->linha;
		plan->linha=plan->linha->prox;
		free(delLC);
	}
	else{
		antLC=plan->linha;
		auxLC=antLC->prox;
		while(auxLC!=NULL){
			
			if(auxLC->mat==NULL){
				delLC=auxLC;
				antLC->prox=auxLC->prox;
				auxLC=auxLC->prox;
				free(delLC);
			}
			
			antLC=auxLC;
			auxLC=auxLC->prox;
		}
		
	}
	
	if(plan->coluna->mat==NULL){
		delLC=plan->coluna;
		plan->coluna=plan->coluna->prox;
		free(delLC);
	}
	else{
		antLC=plan->coluna;
		auxLC=antLC->prox;
		while(auxLC!=NULL){
			
			if(auxLC->mat=NULL){
				delLC=auxLC;
				antLC=auxLC->prox;
				auxLC=auxLC->prox;
				free(delLC);
			}
			
			
			antLC=auxLC;
			auxLC=auxLC->prox;
		}
	}
	
}

int main(){
	
}
