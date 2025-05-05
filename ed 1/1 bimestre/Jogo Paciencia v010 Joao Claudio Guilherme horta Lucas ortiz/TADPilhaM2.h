#define MAXPILHA 600
#include <conio2.h>
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

void exibirPilhaM2(TpPilhaM PM, int npc)
{
	int l=5, c=100, i, nump=6, j;
	
	for(i=7; i>0; i--)
	{
		gotoxy(c,l);
		printf("%d",i);
		c=c-6;
	}
	l=l+3;
    for(i = 0; i <= 6; i++) // Itera de 6 até 0
    {
        c=100;
        while (!PMVazia(PM, nump))
        {
            /*
            65 corresponde ao caractere "A" maiúsculo.
            74 corresponde ao caractere "J" maiúsculo.
            75 corresponde ao caractere "K" maiúsculo.
            81 corresponde ao caractere "Q" maiúsculo.
            */

            TpBaralho baralho = POPM(PM, nump);
			if(baralho.status == 1)
			{
				if (baralho.cor == 'V')
	                textcolor(RED);
	            else
	                textcolor(BLACK);
	              
				//EXIBINDO O NAIPE DAS CARTAS
		        if(baralho.naipe == 'O')
		        {
					gotoxy(c,l);
		        	printf("%c ",4);
		        }
		        else
		        if(baralho.naipe == 'E')
		        {
					gotoxy(c,l);
		        	printf("%c ",6);
		        }	
		        else
		        if(baralho.naipe == 'C')
		        {
					gotoxy(c,l);
					printf("%c ",3);
		        }	
		        else
		        if(baralho.naipe == 'P')
		        {
					gotoxy(c,l);
		        	printf("%c ",5);
		        }
		        
		    	c=c-2;
		    	
		        //EXIBINDO OS VALORES DAS CARTAS
		        if (baralho.cartas == 65)
	            {
	            	gotoxy(c,l);
	            	printf("A ", baralho.cartas);
	            }
	            else
				if (baralho.cartas == 74)
				{
					gotoxy(c,l);
					printf("J ", baralho.cartas);
				}
	            else
				if (baralho.cartas == 75)
				{
					gotoxy(c,l);
					printf("K ", baralho.cartas);
				}
	            else
				if (baralho.cartas == 81)
				{
					gotoxy(c,l);
					printf("Q ", baralho.cartas);
				}
	                
	            else
	            {
					gotoxy(c,l);
	            	printf("%d ", baralho.cartas);
	            }
			}
			else
			{
	            textcolor(WHITE);
	                
	        	//EXIBINDO O NAIPE DAS CARTAS COM O STATUS 0
		        if(baralho.naipe == 'O')
		        {
					gotoxy(c,l);
		        	printf("#");
		        }
		        else
		        if(baralho.naipe == 'E')
		        {
					gotoxy(c,l);
		        	printf("#");
		        }	
		        else
		        if(baralho.naipe == 'C')
		        {
					gotoxy(c,l);
					printf("#");
		        }	
		        else
		        if(baralho.naipe == 'P')
		        {
					gotoxy(c,l);
		        	printf("#");
		        }
		        
		        c=c-2;
		        
		        //EXIBINDO O VALORES DAS CARTAS COM O STATUS 0
		        if (baralho.cartas == 65)
	            {
	            	gotoxy(c,l);
	            	printf("*");
	            }
	            else
				if (baralho.cartas == 74)
				{
					gotoxy(c,l);
					printf("*");
				}
	            else
				if (baralho.cartas == 75)
				{
					gotoxy(c,l);
					printf("*");
				}
	            else
				if (baralho.cartas == 81)
				{
					gotoxy(c,l);
					printf("*");
				}
	            else
	            {
					gotoxy(c,l);
	            	printf("*");
	            }
			}
            c=c-4;
	        /*	
			c=c-4;
            if(baralho.status == 0)
            {
				gotoxy(c,l);
				printf("0"); // Exibe 0 se o status for 0
            }
            else
            {
				gotoxy(c,l);
				printf("1");
            }
            */
            
        }
        l = l+3;
        nump--;
    }
    
    l=5;
	c=124;
	for(i=11; i>7; i--)
	{
		textcolor(WHITE);
		gotoxy(c,5);
		printf("%d",i);
		c=c-4;
	}
	
	for(j=3; j!=6; j++)
	{
		if(j==3 || j==4)
		{
			textcolor(RED);
			
			//ouro
			gotoxy(124,8);
			printf("*");
			printf("%c ",4);
			
			//copas
			gotoxy(120,8);
			printf("*");
			printf("%c ",3); 
		}
		else
		if(j==5 || j==6)
		{
			textcolor(BLACK);
			
			//espada
			gotoxy(115,8);
			printf("*");
			printf("%c ",6); 
			
			//paus
			gotoxy(111,8);
			printf("*");
			printf("%c ",5); 
		}
	}
	

    /*
    for(i = 7; i <= 10; i++)
    {
    	
        65 corresponde ao caractere "A" maiúsculo.
        74 corresponde ao caractere "J" maiúsculo.
        75 corresponde ao caractere "K" maiúsculo.
        81 corresponde ao caractere "Q" maiúsculo.
        

        TpBaralho baralho = POPM(PM, nump);
        
        if (baralho.cor == 'V')
	        textcolor(RED);
	    else
	        textcolor(BLACK);
	              
		//EXIBINDO O NAIPE DAS CARTAS
		if(!PMVazia(PM, nump))
		{
			if(baralho.naipe == 'O')
			{
				gotoxy(c,l);
				printf("*    ");
			    printf("%c ",4);
			}
			else
			if(baralho.naipe == 'E')
			{
				gotoxy(c,l);
				printf("*    ");
			    printf("%c ",6);
			}
			else
			if(baralho.naipe == 'C')
			{
				gotoxy(c,l);
				printf("*    ");
				printf("%c ",3);
			}	
			else
			if(baralho.naipe == 'P')
			{
				gotoxy(c,l);
				printf("*    ");
			    printf("%c ",5);
			}
		}
		else
		{
			if(baralho.naipe == 'O')
			{
				gotoxy(c,l);
				printf("*    ");
			    printf("%c ",4);
			}
			else
			if(baralho.naipe == 'E')
			{
				gotoxy(c,l);
				printf("*    ");
			    printf("%c ",6);
			}
			else
			if(baralho.naipe == 'C')
			{
				gotoxy(c,l);
				printf("*    ");
				printf("%c ",3);
			}	
			else
			if(baralho.naipe == 'P')
			{
				gotoxy(c,l);
				printf("*    ");
			    printf("%c ",5);
			}
		}
    }
	*/
}

