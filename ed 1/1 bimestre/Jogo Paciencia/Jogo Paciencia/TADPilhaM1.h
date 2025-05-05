/* Listas Concorrentes 
 
 	*Aplicação em PILHAS MÚLTIPLAS
 	**CASO 1 -> para 2 PILHAS 
 	
 	_______________________________
 	|  |  |  |  |  |  |  |  |  |  | MAXPILHA[10]
 | 0   1  2  3  4  5  6  7  8  9  	  |
 |--->							  <---|
  TOPO 1	                      TOPO 2*/
  
//TADPILHAM1.H

#define MAXPILHAM1 48
#include<stdio.h>


struct TpPilhaM1
{
	int TOPO1, TOPO2;
	TpBaralho PILHA[MAXPILHA];
};

//operações associadas
//TA COM UNS NOME DIFERENTE NAO SEI SE TA CERTO
void InicializarM1(TpPilhaM1 &PM);
void PUSHM1(TpPilhaM1 &PM, TpBaralho carta, int NP);
TpBaralho POPM1(TpPilhaM1 &PM, int NP);
TpBaralho ElementoTOPOM1(TpPilhaM1 PM, int NP);
int PM1Vazia(int topo, int NP);
int PM1Cheia(int topo1, int topo2);
void ExibirPM1(TpPilhaM1 PM, int NP);

void InicializarM1(TpPilhaM1 &PM)
{
	PM.TOPO1 = -1;
	PM.TOPO2 = MAXPILHAM1;
}

//void PUSH(TpPilhaM1 &PM, int Elem, int NP)
//{
//	if (NP == 1)
//		PM.PILHA[++PM.TOPO1] = Elem;
//	else
//		PM.PILHA[--PM.TOPO2] = Elem;	
//}

void PUSHM1(TpPilhaM1 &PM, TpBaralho carta, int NP) {
	if (NP == 1)
		PM.PILHA[++PM.TOPO1] = carta;
	else
		PM.PILHA[--PM.TOPO2] = carta;
}

//int POP(TpPilhaM1 &PM, int NP)
//{
//	if (NP == 1)
//		return PM.PILHA[PM.TOPO1--];
//	else
//		return PM.PILHA[PM.TOPO2++];
//}

TpBaralho POPM1(TpPilhaM1 &PM, int NP)
{
	if (NP == 1)
		return PM.PILHA[PM.TOPO1--];
	else
		return PM.PILHA[PM.TOPO2++];
}

TpBaralho ElementoTOPOM1(TpPilhaM1 PM, int NP)
{
	if (NP == 1)
		return PM.PILHA[PM.TOPO1];
	else
		return PM.PILHA[PM.TOPO2];
}

int PM1Vazia(int TOPO1, int NP)
{
	if(NP == 1) return TOPO1 == -1;
	else return TOPO1 == MAXPILHA;
}

int PM1Cheia(int TOPO1, int TOPO2)
{
	return TOPO1 + 1 ==  TOPO2;
}

void ExibirPM1(TpPilhaM1 PM, int NP) {
	TpBaralho baralho;
    if (NP == 1)
	{
        printf("\n\nElementos da Pilha 1:\n");
        for (int i = PM.TOPO1; i >= 0; i--)
		{
            printf("Status: %d, Cor: %c, Naipe: %d, Cartas: %d", 
            PM.PILHA[i].status, PM.PILHA[i].cor, PM.PILHA[i].naipe, PM.PILHA[i].cartas);
            
            if(PM.PILHA[i].naipe == 'O')
	        	printf(" %c ",4);
	        else
	        if(PM.PILHA[i].naipe == 'E')
	        	printf(" %c ",6);
	        else
	        if(PM.PILHA[i].naipe == 'C')
	        	printf(" %c ",3);
	        else
	        if(PM.PILHA[i].naipe == 'P')
	        	printf(" %c ",5);
	        	
	        printf("\n");
        }
        
    }
	else
	{
        printf("Elementos da Pilha 2:\n");
        for (int i = PM.TOPO2; i < MAXPILHAM1; i++)
		{
            printf("Status: %d, Cor: %c, Naipe: %d, Cartas: %d\n", 
            PM.PILHA[i].status, PM.PILHA[i].cor, PM.PILHA[i].naipe, PM.PILHA[i].cartas);
        }
        if(PM.PILHA[PM.TOPO2].naipe == 'O')
        	printf("%c",4);
        else
        if(PM.PILHA[PM.TOPO2].naipe == 'E')
        	printf("%c",6);
        else
        if(PM.PILHA[PM.TOPO2].naipe == 'C')
        	printf("%c",3);
        else
        if(PM.PILHA[PM.TOPO2].naipe == 'P')
        	printf("%c",5);
    }
}



//void ExibirPM(TpPilhaM1 PM, int NP)
//{
//	if (NP == 1)
//		while(!PMVazia(PM.TOPO1,NP))
//			  printf("%d",POP(PM,NP));
//	else
//		while(!PMVazia(PM.TOPO2,NP))
//			  printf("%d",POP(PM,NP));
//}

/*void ExibirPM(TpPilhaM1 PM, int NP) {
    if (NP == 1) {
        while (!PMVazia(PM.TOPO1, NP)) {
            TpBaralho carta = POP(PM, NP);
            printf("Valor: %d, Naipe: %c, Cor: %c, Status: %c\n", carta.valor, carta.naipe, carta.cor, carta.status);
        }
    } else {
        while (!PMVazia(PM.TOPO2, NP)) {
            TpBaralho carta = POP(PM, NP);
            printf("Valor: %d, Naipe: %c, Cor: %c, Status: %c\n", carta.valor, carta.naipe, carta.cor, carta.status);
        }
    }
}
*/
