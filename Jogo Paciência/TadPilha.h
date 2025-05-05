#include <stdio.h>
#define maxpilha 52
#define np 13

//PEGUEI DO CHAT ESSA BOSTA
// Estrutura da Pilha
struct TpPilha {
    int topo;
    char pilha[maxpilha];
};

// Função para inicializar a pilha
void inicializar(TpPilha &p) {
    p.topo = -1;
}

// Função para verificar se a pilha está vazia
int vazia(TpPilha p) {
    return p.topo == -1;
}

// Função para verificar se a pilha está cheia
int cheia(TpPilha p) {
    return p.topo == maxpilha - 1;
}

// Função para empilhar um elemento na pilha
void push(TpPilha &p, char valor) {
    if (!cheia(p)) {
        p.pilha[++p.topo] = valor;
    } else {
        printf("Erro: Pilha cheia\n");
    }
}

// Função para desempilhar um elemento da pilha
char pop(TpPilha &p) {
    if (!vazia(p)) {
        return p.pilha[p.topo--];
    } else {
        printf("Erro: Pilha vazia\n");
        return '\0'; // Retorna um valor nulo se a pilha estiver vazia
    }
}

// Função para obter o elemento do topo da pilha
char elementoTopo(TpPilha p) {
    if (!vazia(p)) {
        return p.pilha[p.topo];
    } else {
        printf("Erro: Pilha vazia\n");
        return '\0'; // Retorna um valor nulo se a pilha estiver vazia
    }
}


