#include<stdio.h>
#include<string.h>

#define MAXFILA 10

struct carro {
    char id[50];
    char cor[20];
    char fab[50];
    char prior;
};

struct TpFila {
    carro FILAC[MAXFILA];
    int fim;
};

void inicializar(TpFila &f) {
    f.fim = -1;
}

void push(TpFila &fc, carro elem) {
    carro aux;
    fc.FILAC[++fc.fim] = elem;
    int cont = fc.fim;

    while (cont > 0 && fc.FILAC[cont].prior < fc.FILAC[cont - 1].prior) {
        aux = fc.FILAC[cont];
        fc.FILAC[cont] = fc.FILAC[cont - 1];
        fc.FILAC[cont - 1] = aux;
        cont--; // Decrease the index
    }
}

carro pop(TpFila &f) {
    carro ele;
    int i;

    ele = f.FILAC[0];

    for (i = 0; i < f.fim; i++)
        f.FILAC[i] = f.FILAC[i + 1];

    f.fim--;

    return ele;
}

int cheia(int fim) {
    return fim == MAXFILA - 1;
}

int vazia(int fim) {
    return fim == -1;
}

void exibir(TpFila f) {
    while (!vazia(f.fim)) {
        carro c = pop(f);
        printf("ID: %d, Cor: %s, Fabricante: %s, Prioridade: %c\n", c.id, c.cor, c.fab, c.prior);
    }
}
