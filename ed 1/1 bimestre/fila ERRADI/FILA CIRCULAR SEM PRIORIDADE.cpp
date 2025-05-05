#include <stdio.h>

#define MAXFILA 10

// Struct que vai conter os elementos da fila
struct TpElemento {
    char id;
};

// Struct que vai ter o início e o fim da fila
struct TpFila {
    int inicio;
    int fim;
    TpElemento fila[MAXFILA];
};

// Função que inicializa a fila
void inicializar(TpFila &fila) {
    fila.inicio = 0;
    fila.fim = -1;
}

// Função que verifica se a fila está vazia
char filaVazia(TpFila fila) {
    return fila.inicio == 0;
}

// Função que verifica se a fila está cheia
char filaCheia(TpFila fila) {
    return (fila.fim + 1) % MAXFILA == fila.inicio;
}

// Função que insere um elemento na fila
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
        printf("Fila cheia. Não é possível inserir.\n");
    }
}

// Função que remove um elemento da fila
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
        printf("Fila vazia. Não é possível remover.\n");
        return {'\0'};
    }
}

// Função que exibe todo o conteúdo da fila
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

    printf("Conteúdo da fila: ");
    exibirFila(fila);

    TpElemento removido = remover(fila);
    printf("Elemento removido: %c\n", removido.id);

    printf("Conteúdo da fila após remover: ");
    exibirFila(fila);

    return 0;
}

