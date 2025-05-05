//3:) (3,0) Faça um algoritmo de forma iterativa que coloque todos os átomos de uma Lista
//Generalizada L no bottom-level. Não é para criar uma nova Lista Generalizada, é para fazer tudo
//na mesma lista! A Pilha não precisa ser implementada, ela contém as funções: Init(P), Top(P),
//Push(P,x), Pop(P,x) e IsEmpty(P) (igual das aulas!)

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
        return NULL;
    } else {
        ListaGen *L = (ListaGen*) malloc(sizeof(ListaGen));
        L->terminal = 0;
        L->no.lista.cabeca = H;
        L->no.lista.cauda = T;
        return L;
    }
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

typedef struct pilha {
    ListaGen *dados[100];
    int topo;
} TpPilha;

void Init(TpPilha *P) {
    P->topo = -1;
}

void Push(TpPilha *P, ListaGen *x) {
    P->dados[++(P->topo)] = x;
}

void Pop(TpPilha *P, ListaGen **x) {
    *x = P->dados[(P->topo)--];
}

ListaGen* Top(TpPilha *P) {
    return P->dados[P->topo];
}

int IsEmpty(TpPilha *P) {
    return P->topo == -1;
}

void JogaPrabaixo(ListaGen *L) {
    TpPilha P;
    ListaGen *atual, *prev = NULL;

    Init(&P);
    Push(&P, L);

    while (!IsEmpty(&P)) {
        atual = Top(&P);
        Pop(&P, &atual);

        if (!Nula(atual) && !Atomo(atual)) {
            if (!Nula(atual->no.lista.cauda)) {
                Push(&P, atual->no.lista.cauda);
            }

            if (!Nula(atual->no.lista.cabeca)) {
                if (!Atomo(atual->no.lista.cabeca)) {
                    ListaGen *sublista_cabeca = atual->no.lista.cabeca->no.lista.cabeca;
                    ListaGen *sublista_cauda = atual->no.lista.cabeca->no.lista.cauda;

                    atual->no.lista.cabeca = sublista_cabeca;
                    atual->no.lista.cauda = Cons(sublista_cauda, atual->no.lista.cauda);
                    
                    Push(&P, sublista_cabeca);
                }
            }
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

void ExibeRecursivo(ListaGen *l)
{
	if(!Nula(l))
	{
		if(Atomo(l))
			printf("%s",l->no.info);
		else
		{
			ExibeRecursivo(Head(l));
			ExibeRecursivo(Tail(l));
		}
	}
}

int main () {
    ListaGen *L;
    L = Cons(CriaT("aaa"), Cons(Cons(CriaT("bbbb"), Cons(CriaT("ccc"), NULL)), NULL));
    Exibe(L);
    JogaPrabaixo(L);
    Exibe(L);
}

