#define MAXPILHA 50

struct TpPilha
{
	int topo;
	char pilha[MAXPILHA];
};

/*passar a struct por referencia(&) para que copie ela dentro das funções
//OPERAÇÕES ASSOCIADAS:
void inicializar(TpPilha &P);
void push(TpPilha &P, char elemento); //Empilhar na pilha
char POP(TpPilha &P); //Desempilhar da pilha
char elementoTopo(TpPilha P);
char pilhaCheia(int topo);
char pilhaVazia(int topo); 
void exibePilha(TpPilha P);
*/

void inicializar(TpPilha &P)
{
	P.topo = -1;
}

/*
Nessa caso a ordem do ++ ou do -- faz todo diferença que se vc colocar o ++ antes ele vai incrementar antes de inserir
o valor na pilha, se caso fosse depois ele iria inserir primeiro para depois incrementar
*/

void push(TpPilha &P, char elemento) //Empilhar na pilha 
{
	P.pilha[++P.topo] = elemento;
}
char POP(TpPilha &P) //Desempilhar da pilha
{
	return P.pilha[P.topo--];
}
char elementoTopo(TpPilha P)
{
	return P.pilha[P.topo];
}

char pilhaCheia(int topo)
{
	return topo == MAXPILHA-1;
	
	/*
	if(topo == maxpilha-1)
		return -1;
	else
		return 0;
		*/
}

char pilhaVazia(int topo)
{
	return topo == -1;
	
	/*
	if(topo == -1)
		return -1;
	else
		return 0;
		*/
}

void exibirPilha(TpPilha P)
{
	while(!pilhaVazia(P.topo))
		printf("\n%c",POP(P));
}
