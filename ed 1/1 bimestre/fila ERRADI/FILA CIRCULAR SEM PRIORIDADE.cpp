#include <stdio.h>

#define MAXFILA 10

// Struct que vai conter os elementos da fila
struct TpElemento {
    char id;
};

// Struct que vai ter o in�cio e o fim da fila
struct TpFila {
    int inicio;
    int fim;
    TpElemento fila[MAXFILA];
};

// Fun��o que inicializa a fila
void inicializar(TpFila &fila) {
    fila.inicio = 0;
    fila.fim = -1;
}

// Fun��o que verifica se a fila est� vazia
char filaVazia(TpFila fila) {
    return fila.inicio == 0;
}

// Fun��o que verifica se a fila est� cheia
char filaCheia(TpFila fila) {
    return (fila.fim + 1) % MAXFILA == fila.inicio;
}

// Fun��o que insere um elemento na fila
void inserir(TpFila &fila, TpElemento elemento) {
    if (!filaCheia(fila)) {
        if (filaVazia(fila)) {
            fila.inicio = 0;
            fila.fim = 0;
        } else {
            fila.fim = (fila.fim + 1) % MAXFILA;
        }
        fila.fila[fila.fim] = elemento;
    } else {
        printf("Fila cheia. N�o � poss�vel inserir.\n");
    }
}

// Fun��o que remove um elemento da fila
TpElemento remover(TpFila &fila) {
    TpElemento elem;
    if (!filaVazia(fila)) {
        elem = fila.fila[fila.inicio];
        if (fila.inicio == fila.fim) {
            fila.inicio = -1;
            fila.fim = -1;
        } else {
            fila.inicio = (fila.inicio + 1) % MAXFILA;
        }
        return elem;
    } else {
        printf("Fila vazia. N�o � poss�vel remover.\n");
        return {'\0'};
    }
}

// Fun��o que exibe todo o conte�do da fila
void exibirFila(TpFila fila) {
    if (!filaVazia(fila)) {
        int i = fila.inicio;
        while (i != fila.fim) {
            printf("%c ", fila.fila[i].id);
            i = (i + 1) % MAXFILA;
        }
        printf("%c\n", fila.fila[fila.fim].id);
    } else {
        printf("Fila vazia.\n");
    }
}

int main() {
    TpFila fila;
    inicializar(fila);

    TpElemento elem1 = {'A'};
    TpElemento elem2 = {'B'};
    TpElemento elem3 = {'C'};

    inserir(fila, elem1);
    inserir(fila, elem2);
    inserir(fila, elem3);

    printf("Conte�do da fila: ");
    exibirFila(fila);

    TpElemento removido = remover(fila);
    printf("Elemento removido: %c\n", removido.id);

    printf("Conte�do da fila ap�s remover: ");
    exibirFila(fila);

    return 0;
}

