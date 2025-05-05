#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definições de structs
struct reg_lista {
    struct listagen *cabeca;
    struct listagen *cauda;
};

union info_lista {
    char info[8];
    struct reg_lista lista;
};

struct listagen {
    char terminal; // 1 se for atomo, 0 se for lista
    union info_lista no;
};

typedef struct listagen ListaGen;

// Funções auxiliares
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

ListaGen *Cons(ListaGen *H, ListaGen *T) {
    if (Atomo(T)) {
        printf("Cons: Segundo arqumento nao pode ser Atomo!");
        return NULL;
    }
    
    ListaGen *L = (ListaGen*) malloc(sizeof(ListaGen));
    L->terminal = 0;
    L->no.lista.cabeca = H;
    L->no.lista.cauda = T;
    return L;
}

ListaGen *Head(ListaGen *L) {
    if (Nula(L) || Atomo(L)) {
        printf("Head: argumento deve ser lista não vazia!\n");
        return NULL;
    }
    return L->no.lista.cabeca;
}

ListaGen *Tail(ListaGen *L) {
    if (Nula(L) || Atomo(L)) {
        printf("Tail: argumento deve ser lista não vazia!\n");
        return NULL;
    }
    return L->no.lista.cauda;
}

void Exibe(ListaGen *L) {
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

// Função para construir a lista a partir de uma string
ListaGen *CriaListaDeString(char *str) {
    ListaGen *L = NULL; // Lista final a ser retornada
    ListaGen *temp = NULL; // Lista temporária para construção
    char buffer[8]; // Buffer para átomos
    int i = 0, j = 0;
    
    while (str[i] != '\0') {
        if (str[i] == '[') {
            // Inicia uma nova lista
            temp = Cons(NULL, L); // Cria uma nova lista aninhada
            L = temp;
            i++;
        } else if (str[i] == ']') {
            // Fecha uma lista
            L = Tail(L); // Retorna à lista anterior
            i++;
        } else if (str[i] == ',') {
            // Separador de átomos ou listas
            i++;
        } else {
            // Coletando o próximo átomo
            j = 0;
            while (str[i] != ',' && str[i] != ']' && str[i] != '\0') {
                buffer[j++] = str[i++];
            }
            buffer[j] = '\0';
            // Cria o átomo e o adiciona à lista
            L = Cons(CriaT(buffer), L);
        }
    }
    return L;
}

int main() {
    char str[] = "[aaa,[bbb,ccc]]";
    
    // Cria a lista a partir da string
    ListaGen *L = CriaListaDeString(str);
    
    // Exibe a lista gerada
    Exibe(L);
    
    return 0;
}

