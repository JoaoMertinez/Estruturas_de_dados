#include <stdio.h>
#define maxpilha 52
#define np 13

//PEGUEI DO CHAT ESSA BOSTA
// Estrutura da Pilha
struct TpPilha {
    int topo;
    char pilha[maxpilha];
};

// Fun��o para inicializar a pilha
void inicializar(TpPilha &p) {
    p.topo = -1;
}

// Fun��o para verificar se a pilha est� vazia
int vazia(TpPilha p) {
    return p.topo == -1;
}

// Fun��o para verificar se a pilha est� cheia
int cheia(TpPilha p) {
    return p.topo == maxpilha - 1;
}

// Fun��o para empilhar um elemento na pilha
void push(TpPilha &p, char valor) {
    if (!cheia(p)) {
        p.pilha[++p.topo] = valor;
    } else {
        printf("Erro: Pilha cheia\n");
    }
}

// Fun��o para desempilhar um elemento da pilha
char pop(TpPilha &p) {
    if (!vazia(p)) {
        return p.pilha[p.topo--];
    } else {
        printf("Erro: Pilha vazia\n");
        return '\0'; // Retorna um valor nulo se a pilha estiver vazia
    }
}

// Fun��o para obter o elemento do topo da pilha
char elementoTopo(TpPilha p) {
    if (!vazia(p)) {
        return p.pilha[p.topo];
    } else {
        printf("Erro: Pilha vazia\n");
        return '\0'; // Retorna um valor nulo se a pilha estiver vazia
    }
}


