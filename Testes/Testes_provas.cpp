#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

void JogaPrabaxo(ListaGen **L, char *atomo) {
    ListaGen *novo = CriaT(atomo);
    ListaGen *atual = *L;

    while (Tail(atual) != NULL) {
    	//printf("oi2");
        atual = Tail(atual);
    }

    atual->no.lista.cauda = Cons(novo, NULL);
}

void prabaxo(ListaGen *L) {
    Pilha *p = init();
    push(&p, L);

    while (!isEmpty(p)) {
        ListaGen *top = pop(&p);
        while (top != NULL) {
            if (!Atomo(top)) {
                ListaGen *sublista = Head(top);
                while (sublista != NULL) {
                    push(&p, sublista);
                    sublista = Tail(sublista);
                }
            } else if (Atomo(top)) {
                JogaPrabaxo(&L, top->no.info);
            }
            top = Tail(top);
        }
    }
}

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

//ListaGen *Exercicio2(char *str)
//{
//	ListaGen * Lista = NULL;
//	char aux;
//	
//	for(i=0;str[i]!="/0";i++)
//	{
//		
//		
//		
//		
//	}
//	return Lista;	
//}

void deph(ListaGen *L,int Nivel, int *Maior)
{
	if(!Nula(L))
	{
		if(!Atomo(L))
		{
			if(Nivel>*Maior)
				*Maior=Nivel;
				
			deph(Head(L),Nivel+1,&*Maior);
			deph(Tail(L),Nivel,&*Maior);
		}
	}
}

// Exemplo de uso
int main() {
	ListaGen *L;
	int maior=0;
    L = Cons(CriaT("aaa"), Cons(Cons(CriaT("bbbb"), Cons(CriaT("ccc"), NULL)), NULL));
    Exibe(L);
    //prabaxo(L);
    //printf("\n");
//    Exibe(L);
    deph(L,1,&maior);
    printf("\nnivel: %d",maior);

    return 0;
}

