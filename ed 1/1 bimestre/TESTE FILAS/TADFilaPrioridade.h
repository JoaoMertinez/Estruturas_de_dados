#define MAXFILA 10

//Struct que vai ter a prioridade e elemento da fila
struct TpElemento
{
	char id;
	int prior;
};

//push NAO TEM FOR

//Struct que vai ter o fim da fila e a fila
struct TpFilaP
{
	int fim;
	
	TpElemento fila[MAXFILA];
};

//Funções para manipulação da fila:
/*
void inicializarP(TpFilaP &fp);
char filaVaziaP(int fim);
char filaCheiaP(int fim);
void inserirP(TpFilaP &fp, TpElemento elemento);
TpElemento retirarP(TpFilaP &fp);
TpElemento elementoInicioP(TpFilaP fp);
TpElemento elementoFimP(TpFilaP fp);
void exibirFilaP(TpFila fp);
*/

//Função que inicializa a fila
void inicializarP(TpFilaP &fp)
{
	fp.fim = -1;
}

//Função que diz se a pilha ta vazia ou não
char filaVaziaP(int fim)
{
	return fim == -1;
}

//Função que diz se a fila ta cheia ou não
char filaCheiaP(int fim)
{
	return fim == MAXFILA - 1;
}

//Função que insere os elementos dentro da fila		***FALTA FAZE!!!***
void inserirP(TpFilaP &fp, TpElemento elemento)
{
	fp.fila[++fp.fim] = elemento;//Joga pra ultima posicao +1 idenpetende da prioridade
	TpElemento aux;
	int cont=fp.fim;//recebe a pos do ultimo elemento
	
	while(cont>0 && fp.fila[cont].prior < fp.fila[cont-1].prior)//ve se o anterior tem a prioridade menor para remanejar 
	{
		aux = fp.fila[cont];
		fp.fila[cont] = fp.fila[cont-1];
		fp.fila[cont-1] = aux;
		cont--;
	}
	
}

/*
INSERIR COM PRIORIDADE DO LUCAS PARA ANALISAR!!!
void INSERIR(TpFilaP &FP, TpElemento elem)
{
	FP.FILA[++FP.FIM] = elem;
	TpElemento AUX;
	int pos=FP.FIM;
	
	while(pos>0 && FP.FILA[pos].PRIORIDADE < FP.FILA[pos-1].PRIORIDADE)
	{
		AUX = FP.FILA[pos];
		FP.FILA[pos] = FP.FILA[pos-1];
		FP.FILA[pos-1] = AUX;
		pos--;
	}
}
*/

//Função que retira um elemento da fila
TpElemento retirarP(TpFilaP &fp)
{
	TpElemento elem;
	int i;
	
	elem = fp.fila[0];
	for(i=0; i<fp.fim; i++)
		fp.fila[i] = fp.fila[i+1];
	fp.fim--;
	
	return elem;
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
	while(!filaVaziaP(fp.fim))
		printf("\n%c",retirarP(fp));
}

