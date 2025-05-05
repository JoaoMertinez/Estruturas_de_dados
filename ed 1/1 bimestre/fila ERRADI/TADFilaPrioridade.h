#include <stdio.h>

#define MAXFILA 10

// Struct que vai ter a prioridade e elemento da fila
struct TpElemento {
    char id;
    int prior;
};

// Struct que vai ter o fim da fila e a fila
struct TpFilaP {
    int fim;
    TpElemento fila[MAXFILA];
};

// Função que inicializa a fila
void inicializarP(TpFilaP &fp) {
    fp.fim = -1;
}

// Função que diz se a pilha ta vazia ou não
char filaVaziaP(int fim) {
    return fim == -1;
}

// Função que diz se a fila ta cheia ou não
char filaCheiaP(int fim) {
    return fim == MAXFILA - 1;
}

// Função que insere os elementos dentro da fila
void inserirP(TpFilaP &fp, TpElemento elemento) {
    int cont = fp.fim;//quantos elementos tem ANTES de jogar o novo
    
    fp.fila[++fp.fim] = elemento;//joga o elemento para frente, indifente da prioridade
    
    while (cont > 0 && fp.fila[cont].prior < fp.fila[cont - 1].prior) {
        TpElemento temp = fp.fila[cont];
        fp.fila[cont] = fp.fila[cont - 1];
        fp.fila[cont - 1] = temp;
        cont--;
    }
}

// Função que retira um elemento da fila
TpElemento retirarP(TpFilaP &fp) {
    TpElemento elem = fp.fila[0];
    for (int i = 0; i < fp.fim; i++)
        fp.fila[i] = fp.fila[i + 1];
    fp.fim--;
    return elem;
}

// Função que exibe todo o conteúdo de dentro da fila
void exibirFilaP(TpFilaP fp) {
    while (!filaVaziaP(fp.fim)) {
        TpElemento elem = retirarP(fp);
        printf("(%c, %d) ", elem.id, elem.prior);
    }
    printf("\n");
}

int main() {
    TpFilaP filaPrioridade;
    inicializarP(filaPrioridade);
    
    // Inserindo elementos na fila de prioridade
    TpElemento elem1 = {'A', 3};
    TpElemento elem2 = {'B', 1};
    TpElemento elem3 = {'C', 2};
    
    inserirP(filaPrioridade, elem1);
    inserirP(filaPrioridade, elem2);
    inserirP(filaPrioridade, elem3);
    
    // Exibindo a fila de prioridade
    printf("Fila de prioridade: ");
    exibirFilaP(filaPrioridade);
    
    return 0;
}

