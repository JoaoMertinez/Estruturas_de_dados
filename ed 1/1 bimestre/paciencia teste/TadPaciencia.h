#include <cstdio>
#include <cstdlib>
#include <ctime>

#define Tam_Baralho 24
#define Tam_Val_Carta 13

struct TpBaralho
{
    int valor;
    int naipe;
    char cor;
    int virada;
};

struct TpPilha
{
    int TOPO;
    TpBaralho Pilha[Tam_Baralho];
};

void InicializaPilha(TpPilha &baralho)
{
    baralho.TOPO = -1;
}

void IniciaCartas(TpPilha &baralho)
{
    int index = 0;
    for (int i = 3; i < 7; ++i)
        for (int j = 0; j < Tam_Val_Carta; ++j)
        {
            baralho.Pilha[index].valor = j + 1;
            baralho.Pilha[index].naipe = i;
            if (i == 3 || i == 4)
                baralho.Pilha[index].cor = 'V';
            else if (i == 5 || i == 6)
                baralho.Pilha[index].cor = 'P';
            baralho.Pilha[index].virada = 0;
            index++;
        }
}

void PUSH(TpPilha &baralho, TpBaralho carta)
{
    baralho.Pilha[++baralho.TOPO] = carta;
}

TpBaralho POP(TpPilha &P)
{
    return P.Pilha[P.TOPO--];
}

void Embaralha(TpPilha &baralho)
{
    TpBaralho aux;
    srand(time(NULL));
    for (int i = 0; i < Tam_Baralho; i++)
    {
        int j = rand() % Tam_Baralho;
        aux = baralho.Pilha[i];
        baralho.Pilha[i] = baralho.Pilha[j];
        baralho.Pilha[j] = aux;
    }
}

bool Vazia(int TOPO)
{
    return TOPO == -1;
}

bool Cheia(int TOPO)
{
    return TOPO == Tam_Baralho - 1;
}

void Exibir(TpPilha P)
{
    for (int i = P.TOPO; i >= 0; --i)
        printf("\n%d%c", P.Pilha[i].valor, P.Pilha[i].naipe);
}

