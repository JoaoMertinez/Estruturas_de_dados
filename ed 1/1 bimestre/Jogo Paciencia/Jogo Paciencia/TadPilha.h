#include <stdio.h>
#define maxpilha 52
#define np 13

// Estrutura da Pilha


struct TpBaralho
{
	int status;
	char cor;
    int naipe, cartas;
};


struct TpPilha {
    int topo;
    
    TpBaralho pilha[maxpilha];
};

// Função para inicializar a pilha
void inicializar(TpPilha &p) {
    p.topo = -1;
}

// Função para verificar se a pilha está vazia
int vazia(int topo) {
    return topo == -1;
}

// Função para verificar se a pilha está cheia
int cheia(int topo) {
    return topo == (maxpilha-1);
}

// Função para empilhar um elemento na pilha

// Função para desempilhar um elemento da pilha

// Função para obter o elemento do topo da pilha
TpBaralho elementoTopo(TpPilha p) {
    return p.pilha[p.topo];
        
}

// Função para desempilhar um elemento da pilha
TpBaralho pop(TpPilha &p)
{
	return p.pilha[p.topo--];
}

void mostrarCarta(struct TpBaralho carta)
{
    int valorCarta = carta.cartas;
    char naipe;

    printf("Carta: ");

    // Exibindo o valor da carta
    if (valorCarta >= 2 && valorCarta <= 10)
    {
        printf("%d - ", valorCarta);
    }
    else
    {
        switch (valorCarta)
        {
            case 1:
                printf("A - ");
                break;
            case 11:
                printf("J - ");
                break;
            case 12:
                printf("Q - ");
                break;
            case 13:
                printf("K - ");
                break;
        }
    }

    // Atribuindo o caractere do naipe
    switch (carta.naipe)
    {
        case 1:
            naipe = 'O';
            break;
        case 2:
            naipe = 'E';
            break;
        case 3:
            naipe = 'C';
            break;
        case 4:
            naipe = 'P';
            break;
    }

    printf("%c - ", naipe);

    printf("Cor: %c - ", carta.cor);

    printf("Status: %d\n", carta.status);
}

void exibirPilha(TpPilha p)
{
	TpBaralho baralho;
	while(!vazia(p.topo))
	{
		baralho = pop(p);
		mostrarCarta(baralho);
	}
}

// Função para empilhar um elemento na pilha
void push(TpPilha &p, TpBaralho valor) {
	p.pilha[++p.topo] = valor;
}




