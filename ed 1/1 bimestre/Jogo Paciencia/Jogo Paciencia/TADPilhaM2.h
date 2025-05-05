#define MAXPILHA 600
/*
PIlha caso 1 a gente não especifica de onde até onde a pilha vai usar
No caso 2 a gente já avisa onde elas vão se encontrar, é um caso que pode ter "n" pilhas
No caso 1 temos os TAD destintos Ex: TOPO1 e TOPO2

Na base vamos armazenar as posições que começa cada pilha
*/

//nao precisa disso pois ele ja esta com include no executavel entaos os dois tads conseguem se comunicar - EU ACHO
/*struct TpBaralho
{
	int status;
	char cor;
    int naipe, cartas;
};*/


struct TpPilhaM
{
	int TOPO[MAXPILHA], BASE[MAXPILHA];
	TpBaralho PILHA[MAXPILHA];
};

void inicializarM(TpPilhaM &PM, int qtde) //qtde é a quantidade de pilhas que precisamos, esse valor vem de fora
{
	int qtdeElem, i;
	
	qtdeElem = MAXPILHA/qtde;
	
	for(i=0; i<=qtde; i++)
	{
		PM.BASE[i] = i * qtdeElem;
		PM.TOPO[i] = PM.BASE[i] - 1;
	}
}

void PUSHM(TpPilhaM &PM2, TpBaralho baralho, int NP)//numCarta isso e pra empilhar carta por carta nas pilhas, e nao empilhar a struct baralho inteira
{
    PM2.PILHA[++PM2.TOPO[NP]] = baralho;
}

TpBaralho POPM(TpPilhaM &PM, int NP)
{
	return PM.PILHA[PM.TOPO[NP]--];
}

TpBaralho elementoTopoM(TpPilhaM &PM, int NP)
{
	return PM.PILHA[PM.TOPO[NP]];
}

char PMVazia(TpPilhaM &PM, int NP)
{
	return PM.TOPO[NP] < PM.BASE[NP];
}

char PMCheia(TpPilhaM &PM, int NP)
{
	return PM.TOPO[NP]+1 == PM.BASE[NP+1];
}

/*
void exibirPilhaM(TpPilhaM &PM, int NP)
{
	while(!PMVazia(PM,NP))
	{
		TpBaralho carta = POPM(PM,NP);
		printf("\nNaipe: %c - Carta: %c - Cor: %c - Status: %d",carta.naipe, carta.cartas, carta.cor, carta.status);
	}
}
*/

void exibirPilhaM2(TpPilhaM &PM, int &npc)
{
    for (int i = 6; i >= 0; i--) // Itera de 6 até 0
    {
    	//printf("\nteste");
        printf("\n\n");
        while (!PMVazia(PM, i))
        {
        	//printf("\nteste");
            printf("\t");

            /*
            65 corresponde ao caractere "A" maiúsculo.
            74 corresponde ao caractere "J" maiúsculo.
            75 corresponde ao caractere "K" maiúsculo.
            81 corresponde ao caractere "Q" maiúsculo.
            */

            TpBaralho baralho = POPM(PM, i);

            if (baralho.cor == 'V')
                textcolor(RED);
            else
                textcolor(BLUE);

            if (baralho.cartas == 65)
                printf("A ", baralho.cartas);
            else
			if (baralho.cartas == 74)
                printf("J ", baralho.cartas);
            else
			if (baralho.cartas == 75)
                printf("K ", baralho.cartas);
            else
			if (baralho.cartas == 81)
                printf("Q ", baralho.cartas);
            else
                printf("%d ", baralho.cartas);
                
	        if(baralho.naipe == 'O')
	        	printf("%c ",4);
	        else
	        if(baralho.naipe == 'E')
	        	printf("%c ",6);
	        else
	        if(baralho.naipe == 'C')
	        	printf("%c ",3);
	        else
	        if(baralho.naipe == 'P')
	        	printf("%c ",5);

            if (baralho.status == 0)
                printf("0 "); // Exibe 0 se o status for 0
            else
            	printf("1 ");
        }
    }

}

