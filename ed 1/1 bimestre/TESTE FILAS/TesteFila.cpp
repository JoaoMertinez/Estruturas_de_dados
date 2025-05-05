#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <ctype.h>

#include "TADFila.h"


//FAZER UM MENU PARA EXECUTAR AS FUNÇÕES DO TADPilha
//Função que gera o menu para manipulação da pilha
char menu(void)
{
	clrscr();
	printf("### Operacoes com pilha ###\n");
	printf("\n[A] Inicializar\n");
	printf("[B] Inserir\n");
	printf("[C] Retirar\n");
	printf("[D] Elemento fim\n");
	printf("[E] Exibir a pilha\n");
	printf("[ESC] Sair\n");
	printf("\nOpcao: ");
	
	return toupper(getch());
}

//Função que lê os elementos da pilha(CARACTER)
char leElemento(void)
{
	printf("\nDigite o caracter: ");
	return getche();
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
	TpFila fila;
	char op, elem, frase;
	
	do
	{
		op = menu();
		switch(op)
		{
			case 'A':
				inicializar(fila);
				printf("\nPilha Inicializada!\n");
				
				break;
				
			case 'B'://inserindo os elementos na fila
				printf("\nInserir elementos na fila\n");
				
				elem = leElemento();
				while(elem != 48 && !filaCheia(fila.fim))
				{
					if(!filaCheia(fila.fim))
					{
						inserir(fila,elem); //chamando uma função que lê um caracter e já adiciona ele na fila...
						printf("\nElemento empilhado!\n");
						
						elem = leElemento(); //sai lido
					}
					else
						printf("\fila cheia!\n");
				}
			
				break;
				
			case 'C'://retirando os elementos da pilha
				printf("\nRetirar elemento\n"); //A gente não escolhe o elemento a ser retirado pois vai removendo um a um
				
				if(!filaVazia(fila.fim))
					printf("\nElemento retirado: %c\n",retirar(fila));
				else
					printf("\fila vazia!\n");
				
				break;
				
			case 'D': //mostrando o elemento que está no topo da pilha naquele momento
				if(!filaVazia(fila.fim))
					printf("\nElemento do fim: %c\n",elementoFim(fila)); 
				else
					printf("\nA fila esta vazia!!!");
				break;
			
			case 'E'://exibindo todo o conteudo da pilha como se fosse um relatorio
				if(!filaVazia(fila.fim))
				{
					printf("\nConteudo da fila: \n");
					exibirFila(fila);
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
