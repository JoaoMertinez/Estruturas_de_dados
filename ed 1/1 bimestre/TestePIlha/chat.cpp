#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARTAS 52 // N�mero total de cartas no baralho

// Estrutura da pilha (j� implementada anteriormente)
typedef struct {
    int top;
    int items[NUM_CARTAS];
} Stack;

// Fun��es da pilha (j� implementadas anteriormente)
void initialize(Stack *stack) { /* implementa��o */ }
int isEmpty(Stack *stack) { /* implementa��o */ }
int isFull(Stack *stack) { /* implementa��o */ }
void push(Stack *stack, int value) { /* implementa��o */ }
int pop(Stack *stack) { /* implementa��o */ }
int peek(Stack *stack) { /* implementa��o */ }

// Fun��o para criar e embaralhar o baralho
void criarBaralho(int baralho[]) {
    int i, j;
    int indice = 0;
    
    for (i = 1; i <= 13; i++) {
        for (j = 0; j < 4; j++) {
            baralho[indice++] = i; // Coloca a carta no baralho
        }
    }
}

// Fun��o para embaralhar o baralho
void embaralhar(int baralho[]) {
    srand(time(NULL));
    int i, j, temp;
    
    for (i = NUM_CARTAS - 1; i > 0; i--) {
        j = rand() % (i + 1); // Gera um �ndice aleat�rio entre 0 e i
        // Troca as cartas nas posi��es i e j
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

