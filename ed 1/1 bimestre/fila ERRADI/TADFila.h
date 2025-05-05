#define MAXFILA 10

struct TpFila
{
	int fim
	char fila[MAXFILA];
};

void inicializar(TpFila &F)
{
	F.fim = -1;
}

char filaVazia(int fim)
{
	return fim == -1;
}

char filaCheia(int fim)
{
	return fim == MAXFILA -1;
}

void inserir(TpFila &F, char elem)
{
	F.fila[++F.fim] = elem;
	
}

char retirar(TpFila &F)
{
	char elem;
	int i;
	elem = F.fila[0];
	for(i=0; i<F.fim; i++)
		F.fila[i] = F.fila[i+1];
	F.fim--;
	
	return elem;
}

char elementoFim(TpFila F)
{
	return F.fila[F.fim];
}
