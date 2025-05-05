#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct reg_lista {
    struct listagen *cabeca;
    struct listagen *cauda;
};

union info_lista {
    char info[8];
    struct reg_lista lista;
};

struct listagen {
    char terminal;
    union info_lista no;
};

typedef struct listagen ListaGen;

typedef struct Pilha {
    ListaGen *elemento;
    struct Pilha *prox;
} Pilha;

Pilha *init() {
    return NULL;
}

int isEmpty(Pilha *p) {
    return (p == NULL);
}

void push(Pilha **p, ListaGen *n) {
    Pilha *novo = (Pilha *) malloc(sizeof(Pilha));
    novo->elemento = n;
    novo->prox = *p;
    *p = novo;
}

ListaGen *pop(Pilha **p) {
    if (isEmpty(*p)) {
        return NULL;
    }
    Pilha *topo = *p;
    ListaGen *n = topo->elemento;
    *p = topo->prox;
    free(topo);
    return n;
}

ListaGen *CriaT(char *info) {
    ListaGen *l = (ListaGen*) malloc(sizeof(ListaGen));
    l->terminal = 1;
    strcpy(l->no.info, info);
    return l;
}

char Nula(ListaGen *L) {
    return L == NULL;
}

char Atomo(ListaGen *L) {
    return !Nula(L) && L->terminal;
}

// Função para criar uma lista
ListaGen *Cons(ListaGen *H, ListaGen *T) {
    ListaGen *L = (ListaGen*) malloc(sizeof(ListaGen));
    L->terminal = 0;
    L->no.lista.cabeca = H;
    L->no.lista.cauda = T;
    return L;
}

ListaGen *Head(ListaGen *L) {
    if (Nula(L) || Atomo(L)) {
        return NULL;
    } else {
        return L->no.lista.cabeca;
    }
}

ListaGen *Tail(ListaGen *L) {
    if (Nula(L) || Atomo(L)) {
        return NULL;
    } else {
        return L->no.lista.cauda;
    }
}

ListaGen *CriaSublistaProfundidade(ListaGen *atomo, int nivel) {
    ListaGen *sublista = atomo;
    for (int i = 1; i < nivel; i++) {
        sublista = Cons(sublista, NULL);  // Cria sublistas aninhadas até atingir o nível desejado
    }
    return sublista;
}

ListaGen *constroi_lista(char *str) {
    Pilha *P = init();
    ListaGen *lista_atual = NULL;
    ListaGen *atomo = NULL;
    ListaGen *sublista = NULL;
    char buffer[100];
    int i = 0, j = 0, nivel = 1;

    while (str[i] != '\0') {
        if (str[i] == '(') {
            push(&P, lista_atual);  // Empilha a lista atual para começar uma nova sublista
            lista_atual = NULL;
        } else if (str[i] == ')') {
            if (j > 0) {
                buffer[j] = '\0';
                atomo = CriaT(buffer);
                lista_atual = Cons(atomo, lista_atual);
                j = 0;
            }
            sublista = lista_atual;
            lista_atual = pop(&P);  // Desempilha a lista anterior
            lista_atual = Cons(sublista, lista_atual);  // Associa a sublista na lista anterior
        } else if (str[i] == ',') {
            if (j > 0) {
                buffer[j] = '\0';
                atomo = CriaT(buffer);
                if (nivel > 1) {
                    atomo = CriaSublistaProfundidade(atomo, nivel);  // Coloca o átomo na profundidade correta
                }
                lista_atual = Cons(atomo, lista_atual);
                j = 0;
                nivel = 1;  // Reseta o nível
            }
        } else if (str[i] == '#') {
            i++;
            nivel = 0;
            while (isdigit(str[i])) {
                nivel = nivel * 10 + (str[i] - '0');
                i++;
            }
            i--;  // Ajusta o índice para não pular caracteres
        } else {
            buffer[j++] = str[i];  // Adiciona o caractere ao buffer
        }
        i++;
    }

    // Finaliza o último átomo da string
    if (j > 0) {
        buffer[j] = '\0';
        atomo = CriaT(buffer);
        if (nivel > 1) {
            atomo = CriaSublistaProfundidade(atomo, nivel);
        }
        lista_atual = Cons(atomo, lista_atual);
    }

    return lista_atual;
}

// Função para exibir a lista (recursiva)
void Exibe (ListaGen *L) {
    if (Atomo(L)) {
        printf("%s", L->no.info);
    } else {
        printf("[");
        while (!Nula(L)) {
            Exibe(Head(L));
            L = Tail(L);
            if (!Nula(L)) {
                printf(",");
            }
        }
        printf("]");
    }
}

int main() {
    char str[] = "(aula,estudo,#2),(edi,#3,edii,#2),(po,#1)";
    ListaGen *lista = constroi_lista(str);
    Exibe(lista);
    return 0;
}
