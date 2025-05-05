#include <stdio.h>

#define MAXFILA 10

//Struct que vai ter a prioridade e elemento da fila
struct TpElemento
{
	char id;
	int prior;
};

//Struct que vai ter o fim da fila e a fila
struct TpFilaP
{
	int fim;
	TpElemento fila[MAXFILA];
};

//Função que inicializa a fila
void inicializarP(TpFilaP &fp)
{
	fp.fim = -1;
}

//Função que diz se a pilha ta vazia ou não
char filaVaziaP(TpFilaP fp)
{
	return fp.fim == -1;
}

//Função que diz se a fila ta cheia ou não
char filaCheiaP(TpFilaP fp)
{
	return (fp.fim + 1) % MAXFILA == 0;
}

//Função que insere os elementos dentro da fila
void inserirP(TpFilaP &fp, TpElemento elemento)
{
	if (!filaCheiaP(fp)) {
		fp.fim = (fp.fim + 1) % MAXFILA;
		fp.fila[fp.fim] = elemento;
	} else {
		printf("Fila cheia. Não é possível inserir.\n");
	}
}

//Função que retira um elemento da fila
TpElemento retirarP(TpFilaP &fp)
{
	TpElemento elem;
	if (!filaVaziaP(fp)) {
		elem = fp.fila[0];
		for (int i = 0; i < fp.fim; i++)
			fp.fila[i] = fp.fila[i+1];
		fp.fim = (fp.fim - 1 + MAXFILA) % MAXFILA;
		return elem;
	} else {
		printf("Fila vazia. Não é possível retirar.\n");
		return {'\0', -1}; // Retornando um elemento inválido
	}
}

//Função que exibe o elemento do inicio da fila
TpElemento elementoInicioP(TpFilaP fp)
{
	return fp.fila[0];
}

//Função que exibe o elemento fim da fila
TpElemento elementoFimP(TpFilaP fp)
{
	return fp.fila[fp.fim];
}

//Função que exibe todo o conteudo de dentro da fila
void exibirFilaP(TpFilaP fp)
{
	if (!filaVaziaP(fp)) {
		int i = 0;
		int cont = (fp.fim + 1) % MAXFILA;
		while (i != fp.fim) {
			printf("\n%c", fp.fila[cont].id);
			cont = (cont + 1) % MAXFILA;
			i++;
		}
	} else {
		printf("Fila vazia.\n");
	}
}

int main()
{
	TpFilaP fila;
	inicializarP(fila);

	TpElemento elem1 = {'A', 3};
	TpElemento elem2 = {'B', 1};
	TpElemento elem3 = {'C', 2};

	inserirP(fila, elem1);
	inserirP(fila, elem2);
	inserirP(fila, elem3);

	exibirFilaP(fila);

	return 0;
}

