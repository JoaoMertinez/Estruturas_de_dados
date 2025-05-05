#include <stdio.h>
#include <ctype.h>
#include <conio2.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "TadPilha.h"

struct TpBaralho
{
    int naipe, cartas;
};

//falta atribuir o valor da tabela ascii dos elementos
void mostrarBaralho(struct TpBaralho baralho[], int tamanho)
{
    printf("Baralho:\n");
    for (int i = 0; i < maxpilha; i++)
    {
        int valorCarta = baralho[i].cartas;
        char naipe;
        
        if (valorCarta >= 2 && valorCarta <= 10)
        {
            printf("%d - ", valorCarta);
        }
        else
        {
            switch (valorCarta)
            {
            case 'A':
                printf("A - ");
                break;
            case 'J':
                printf("J - ");
                break;
            case 'Q':
                printf("Q - ");
                break;
            case 'K':
                printf("K - ");
                break;
            }
        }

        // Atribuindo o caractere do naipe
        switch (baralho[i].naipe)
        {
        case 'O':
            naipe = 'O';
            break;
        case 'E':
            naipe = 'E';
            break;
        case 'C':
            naipe = 'C';
            break;
        case 'P':
            naipe = 'P';
            break;
        }

        printf("%c\n\n", naipe); // Imprimindo o naipe
    }
}

void Embaralhar(struct TpBaralho baralho[], int tamanho)
{
    srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios
    int i;

    for (i = tamanho - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        struct TpBaralho temp = baralho[i];
        baralho[i] = baralho[j];
        baralho[j] = temp;
    }
    
    mostrarBaralho(baralho, maxpilha);
}

void gerarBaralho(struct TpBaralho baralho[], int tamanho)
{
    int i, j, k = 0;

    char vetNaipe[4] = {'O', 'E', 'C', 'P'};
    int vetValor[13] = {'A', 2, 3, 4, 5, 6, 7, 8, 9, 10, 'J', 'Q', 'K'};

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 13; j++)
        {
            baralho[k].naipe = vetNaipe[i];
            baralho[k].cartas = vetValor[j];
            k++;
        }
    }
}

/*void EmpilharBaralho(TpBaralho baralho[], int tamanho, TpPilha &P)
{
	int i=0;
	while(!vazia(P.topo))
	{
		push(P,baralho[i].cartas);
		push(P,baralho[i].naipe);
		i++;
		//???	
	}
}*/

int main(void)
{
    TpPilha pilha;
    inicializar(pilha);

    // Declarando o vetor de struct que vai conter o valor das cartas e naipe do nosso baralho
    struct TpBaralho baralho[maxpilha];

    // Função que gera o baralho, sendo 4 cartas iguais de cada e cada uma com seu naipe diferente
    gerarBaralho(baralho, maxpilha);
    // Função que faz o embaralhamento das cartas assim o jogo fica com uma senquência aleatoria de cartas
    Embaralhar(baralho, maxpilha);
    //empilhando o baralho, começar
    //EmpilharBaralho(baralho,maxpilha,pilha);
    

    return 0;
}

