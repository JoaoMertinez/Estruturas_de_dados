#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <windows.h>
#include <ctype.h>
#include <time.h>

#include "TadPaciencia.h"

void Executa(void)
{
	int i, j, index;
	TpPilha baralho, vetor[13], PilhaAux;	//Vetor de Pilhas(Todos vazios por enquanto) e outra estrutura TpPilha separada para inicializar cada carta 
	
	for(int inicializar = 0; inicializar < 13; inicializar++)	//Inicializa todas a pilhas
		InicializaPilha(vetor[inicializa]);
		
	InicializaPilha(baralho);	//Inicializa a pilha do Baralho
	
	InicializaPilha(PilhaAux);
	
	IniciaCartas(baralho);
	
	Embaralha(baralho);	//Embaralha a pilha do Baralho
	
	index = 0;
	
	for(i = 0; i < 8; i++)	// Laço para espalhar as cartas do baralho para cada monte(pilha)
	{
		if(i == 0)
		{
			PUSH(vetor[i].Pilha[vetor[i].TOPO],baralho.Pilha[index]);
			index++;
		}
		if(i == 1)
		{
			for(j = 0; j < 2; j++)
			{
				PUSH(vetor[i].Pilha[vetor[i].TOPO],baralho.Pilha[index]);
				index++;
			}
		}
		if(i == 2)
		{
			for(j = 0; j < 3; j++)
			{
				PUSH(vetor[i].Pilha[vetor[i].TOPO],baralho.Pilha[index]);
				index++;
			}
		}
		if(i == 3)
		{
			for(j = 0; j < 4; j++)
			{
				PUSH(vetor[i].Pilha[vetor[i].TOPO],baralho.Pilha[index]);
				index++;
			}
		}
		if(i == 4)
		{
			for(j = 0; j < 5; j++)
			{
				PUSH(vetor[i].Pilha[vetor[i].TOPO],baralho.Pilha[index]);
				index++;
			}
		}
		if(i == 5)
		{
			for(j = 0; j < 6; j++)
			{
				PUSH(vetor[i].Pilha[vetor[i].TOPO],baralho.Pilha[index]);
				index++;
			}
		}
		if(i == 6)
		{
			for(j = 0; j < 7; j++)
			{
				PUSH(vetor[i].Pilha[vetor[i].TOPO],baralho.Pilha[index]);
				index++;
			}
		}
		if(i == 7)
		{
			while(index < Tam_Baralho)
			{
				PUSH(vetor[i].Pilha[vetor[i].TOPO],baralho.Pilha[index]);
				index++;
			}
		}
	}
	
	for(int a = 0; a < 8; a++))
		Exibir(vetor[a]);
	getch();
}

int main(void)
{
	Executa();
	
	return 0;
}
