#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <ctype.h>

#include "TADFilaPrioridade.h"


//FAZER UM MENU PARA EXECUTAR AS FUNÇÕES DO TADPilha
//Função que gera o menu para manipulação da pilha
char menu(void)
{
	clrscr();
	printf("### Operacoes com fila ###\n");
	printf("\n[A] Inicializar\n");
	printf("[B] Inserir\n");
	printf("[C] Retirar\n");
	printf("[D] Elemento inicio\n");
	printf("[E] Elemento fim\n");
	printf("[F] Exibir a pilha\n");
	printf("[ESC] Sair\n");
	printf("\nOpcao: ");
	
	return toupper(getch());
}

//Função que lê os elementos da fila(CARACTER)
TpElemento leElemento(void)
{
	TpElemento valores;
	printf("\nDigite o caracter: ");
	valores.id = getche();
	printf("\nDigite a prioridade: ");
	scanf("%d",&valores.prior);
	
	return valores;
}

//Função do exercicio 1 de inserir os elementos nas pilhas
/*
void inserirElementos(TpPilha &P)
{
	char elem;
	inicializar(P);
	printf("\nDigite os elementos...[ESC] - Sair\n");
	elem = getche();
	while(elem != 27 && !pilhaCheia(P.topo))
	{
		PUSH(P,elem);
		elem = getche();
	}
	printf("\nElementos inseridos na pilha!\n");
	getch();
}
*/

int main(void)
{
	TpElemento valores;
	TpFilaP fila;
	char op, elem, frase;
	int prior;
	
	do
	{
		op = menu();
		switch(op)
		{
			case 'A':
				inicializarP(fila);
				printf("\nFila Inicializada!\n");
				
				break;
				
			case 'B'://inserindo os elementos na fila
				printf("\nInserir elementos na fila\n");
				
				//elem = leElemento();
				valores = leElemento();
				while(valores.id != 48 && !filaCheiaP(fila.fim))
				{
					if(!filaCheiaP(fila.fim))
					{
						inserirP(fila,valores); //chamando uma função que lê um caracter e já adiciona ele na pilha...
						printf("\nElemento inserido!\n");
						
						valores = leElemento(); //sai lido
					}
					else
						printf("\nFila cheia!\n");
				}
			
				break;
				
			case 'C'://retirando os elementos da pilha
				printf("\nRetirar elemento\n"); //A gente não escolhe o elemento a ser retirado pois vai removendo um a um
				
				if(!filaVaziaP(fila.fim))
					printf("\nElemento retirado: %c\n",retirarP(fila));
				else
					printf("\nFila vazia!\n");
				
				break;
				
			case 'D': //mostrando o elemento que está no inicio da fila naquele momento
				if(!filaVaziaP(fila.fim))
					printf("\nElemento do inicio: %c\n",elementoInicioP(fila)); 
				else
					printf("\nA fila esta vazia!!!");
				break;
				
			case 'E': //mostrando o elemento que está no fim da fila naquele momento
				if(!filaVaziaP(fila.fim))
					printf("\nElemento do fim: %c\n",elementoFimP(fila)); 
				else
					printf("\nA fila esta vazia!!!");
				break;
			
			case 'F'://exibindo todo o conteudo da fila como se fosse um relatorio
				if(!filaVaziaP(fila.fim))
				{
					printf("\nConteudo da fila: \n");
					exibirFilaP(fila);
				}
				else
					printf("\nA fila esta vazia!!!");
				
				
				break;
				
			case 27:
				printf("\nPrograma encerrado!\n");
				
				break;
		}
		getch();
	}while(op != 27);
	return 0;
}
