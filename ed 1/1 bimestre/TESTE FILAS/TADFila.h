#define MAXFILA 10

//Struct do tipo fila onde vai guardar os dados 
struct TpFila
{
	int fim;
	char fila[MAXFILA];
};

//Fun��es para manipula��o da fila:
/*
void inicializar(TpFila &f);
void inserir(TpFila &f, char elem);
char retirar(TpFila &f);
char filaVazia(int fim);
char filaCheia(int fim);
char elementoFim(TpFila f);
void exibirFila(TpFila f);
*/

//Fun��o que inicializa a fila para come�ar a manipula��o
void inicializar(TpFila &f)
{
	f.fim = -1;
}

//Fun��o que insere os elementos na fila
void inserir(TpFila &f, char elem)
{
	f.fila[++f.fim] = elem;
}

//Fun��o que retira os elementos de dentro da fila
char retirar(TpFila &f)
{
	char auxElem; //Elemento auxiliar para onde vai ser jogado o primeiro elemento da fila
	int i;
	
	auxElem = f.fila[0]; //jogando o primeiro elemento da fila para dentro da variavel auxiliar
	
	for(i=0; i<f.fim; i++)
		f.fila[i] = f.fila[i+1]; //fazendo remanejamento para retirar o elemento de dentro da fila
	f.fim--;
	
	return auxElem; //retornando o elemento que foi guardado na variavel auxiliar
}

//Fun��o que verifica se a fila ta vazia ou n�o
int filaVazia(int fim)
{
	return fim == -1;
}

//Fun��o que verifica se a fila ta cheia ou n�o
int filaCheia(int fim)
{
	return fim == MAXFILA - 1;
}

//Fun��o que exibe o elemento fim da fila
char elementoFim(TpFila f)
{
	return f.fila[f.fim];
}

//Fun��o que exibe todos os elementos da fila
void exibirFila(TpFila f)
{
	while(!filaVazia(f.fim))
		printf("\n%c",retirar(f));
}
