#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARTAS 52 // Número total de cartas no baralho

// Estrutura da pilha (já implementada anteriormente)
typedef struct {
    int top;
    int items[NUM_CARTAS];
} Stack;

// Funções da pilha (já implementadas anteriormente)
void initialize(Stack *stack) { /* implementação */ }
int isEmpty(Stack *stack) { /* implementação */ }
int isFull(Stack *stack) { /* implementação */ }
void push(Stack *stack, int value) { /* implementação */ }
int pop(Stack *stack) { /* implementação */ }
int peek(Stack *stack) { /* implementação */ }

// Função para criar e embaralhar o baralho
void criarBaralho(int baralho[]) {
    int i, j;
    int indice = 0;
    
    for (i = 1; i <= 13; i++) {
        for (j = 0; j < 4; j++) {
            baralho[indice++] = i; // Coloca a carta no baralho
        }
    }
}

// Função para embaralhar o baralho
void embaralhar(int baralho[]) {
    srand(time(NULL));
    int i, j, temp;
    
    for (i = NUM_CARTAS - 1; i > 0; i--) {
        j = rand() % (i + 1); // Gera um índice aleatório entre 0 e i
        // Troca as cartas nas posições i e j
        temp = baralho[i];
        baralho[i] = baralho[j];
        baralho[j] = temp;
    }
}

int main() {
    Stack stack;
    initialize(&stack); // Inicializa a pilha
    
    int baralho[NUM_CARTAS]; // Array para armazenar as cartas do baralho
    
    criarBaralho(baralho); // Cria o baralho
    embaralhar(baralho);   // Embaralha o baralho
    
    // Armazena as cartas na pilha
    for (int i = 0; i < NUM_CARTAS; i++) {
        push(&stack, baralho[i]);
    }
    
    // Testando se as cartas foram armazenadas corretamente
    printf("Cartas na pilha:\n");
    while (!isEmpty(&stack)) {
        printf("%d ", pop(&stack));
    }
    printf("\n");
    
    return 0;
}

