#include <stdio.h>
#include <stdlib.h>
#define nl 5
#define nc 6

//para inserir em uma matriz tem 3 casos se ta vazio se e maior ou menor que o primeiro senao insere onde precisa

struct matrizEsp
{
	int lin,col,valor;
	struct matrizEsp *pc, *pl;
//	struct algumacoisa info
}; typedef struct matrizEsp Matesp;

void verificaOcupado(Matesp *vetlin[], int lin, int col, Matesp **aux){

	Matesp *p;
	p = vetlin[lin];

	while(p!=NULL && col != p->col){
		p = p->pl;
	}

	if(p!=NULL && p->col == col){
		*aux = p;
	}
	else{
		*aux = NULL;
	}

}

void insere(Matesp *vetlin[], Matesp *vetcol[], int lin, int col, int valor)
{
	Matesp *ant, *aux, *nova;

	if(lin >= 0 && lin < nl && col >= 0 && col < nc) // verifica se cabe no vetor
	{
		verificaOcupado(vetlin, lin, col, &aux);
		if(aux != NULL)
			aux->valor = valor;
		else
		{
			nova = (Matesp *) malloc(sizeof(Matesp));
			nova->lin = lin;
			nova->col = col;
			nova->valor = valor;

			// liga��o horizontal
			if(vetlin[lin] == NULL) // primeiro caso
			{
				vetlin[lin] = nova;
				nova->pl = NULL;
			}
			else
			{
				if(col < vetlin[lin]->col) // ordenando pela coluna
				{
					nova->pl = vetlin[lin];
					vetlin[lin] = nova;
				}
				else // precisa procurar
				{
					ant = vetlin[lin];
					aux = ant->pl;
					while(aux != NULL && col > aux->col)
					{
						ant = aux;
						aux = aux->pl;
					}
					ant->pl = nova;
					nova->pl = aux;
				}
			}

			// liga��o vertical
			if(vetcol[col] == NULL) // primeiro caso
			{
				vetcol[col] = nova;
				nova->pc = NULL;
			}
			else
			{
				if(lin < vetcol[col]->lin) // ordenando pela linha
				{
					nova->pc = vetcol[col];
					vetcol[col] = nova;
				}
				else // precisa procurar
				{
					ant = vetcol[col];
					aux = ant->pc;
					while(aux != NULL && lin > aux->lin)
					{
						ant = aux;
						aux = aux->pc;
					}
					ant->pc = nova;
					nova->pc = aux;
				}
			}
		}
	}
	else
	{
		printf("nao!!");
	}
}

void inializaVet(matrizEsp *vetlin[], matrizEsp *vetcol[])
{
	//coloca dois for aqui e boa

}

int main()
{
	matrizEsp *vetlin[nl],*vetcol[nc];
	inicializaVet(vetlin,vetcol);

	insere(vetlin,vetcol,1,1,15);
	insere(vetlin,vetcol,1,2,15);
	insere(vetlin,vetcol,1,3,15);
}



