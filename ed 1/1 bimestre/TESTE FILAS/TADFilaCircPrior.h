#define MAXFILA 10

struct TpElemento
{
	char elemento;
	int prior;
};

struct TpFilaCircPrior
{
	int inicio, fim, cont;
	
	TpElemento fila[MAXFILA];
};

void inicializarFCP(TpFilaCircPrior &fcp)
{
	fcp.inicio = 0;
	fcp.fim = -1;
	fcp.cont = 0;
}

void inserirFCP(TpFilaCircPrior &fcp, TpElemento elem)
{
	TpElemento aux;
	int i;
	
	if(fcp.fim == MAXFILA - 1)
		fcp.fim = -1;
		
	fcp.fila[++fcp.fim] = elem;
	i = fcp.fim;
	while(i>fcp.inicio && fcp.fila[i].prior < fcp.fila[i-1].prior)
	{
		aux = fcp.fila[i];
		fcp.fila[i] = fcp.fila[i-1];
		fcp.fila[i-1] = aux;
		i--;
	}
	fcp.cont++;
}

TpElemento retirarFCP(TpFilaCircPrior &fcp)
{
	TpElemento aux;
	
	aux = fcp.fila[fcp.inicio++];
	if(fcp.inicio == MAXFILA)
		fcp.inicio = 0;
		
	fcp.cont--;
	return aux;
}

TpElemento elementoInicioFCP(TpFilaCircPrior fcp)
{
	return fcp.fila[fcp.inicio];
}

TpElemento elementoFimFCP(TpFilaCircPrior fcp)
{
	return fcp.fila[fcp.fim];
}

char vaziaFCP(int cont)
{
	return cont == 0;
}

char cheiaFCP(int cont)
{
	return cont == MAXFILA;
}

void exibirFCP(TpFilaCircPrior fcp)
{
	TpElemento aux;
	while(!vaziaFCP(fcp.cont))
	{
		aux = retirarFCP(fcp);
		printf("\nElemento - %c | Prioridade - %d",aux.elemento, aux.prior);
	}
}
