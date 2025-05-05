#define MAXPILHA 10
/*
PIlha caso 1 a gente não especifica de onde até onde a pilha vai usar
No caso 2 a gente já avisa onde elas vão se encontrar, é um caso que pode ter "n" pilhas
No caso 1 temos os TAD destintos Ex: TOPO1 e TOPO2

Na base vamos armazenar as posições que começa cada pilha
*/
struct TpPilhaM2
{
	int TOPO[MAXPILHA], BASE[MAXPILHA];
	char PILHA[MAXPILHA];
};

void inicializa(TpPilhaM2 &PM, int qtde) //qtde é a quantidade de pilhas que precisamos, esse valor vem de fora
{
	int qtdeElem, i;
	
	qtdeElem = MAXPILHA/qtde;
	
	for(i=0; i<=qtde; i++)
	{
		PM.BASE[i] = i * qtdeElem;
		PM.TOPO[i] = PM.BASE[i] - 1;
	}
}

void PUSH(TpPilhaM2 &PM, char elem, int NP)
{
	PM.PILHA[++PM.TOPO[NP]] = elem; 
}

void POP(TpPilhaM2 &PM, char elem, int NP)
{
	return PM.PILHA[PM.TOPO[NP]--];
}

char elementoTopo(TpPilhaM2 &PM, int NP)
{
	return PM.PILHA[PM.TOPO[NP]];
}

char PMVazia(TpPilhaM2 &PM, int NP)
{
	return PM.TOPO[NP] < PM.BASE[NP];
}

char PMCheia(TpPilhaM2 &PM, int NP)
{
	return PM.TOPO[NP]+1 == PM.BASE[NP+1];
}

char exibirPilha(TpPilhaM2 &PM, int NP)
{
	while(!PMVazia(PM,NP))
	{
		printf("\n%c",POP(PM,NP));
	}
}
