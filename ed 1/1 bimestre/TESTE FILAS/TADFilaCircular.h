#define MAXFILA 10

//struct que est� guardando os dados da fila
//na fila circular � so ++

struct TpFilaCirc
{
    int inicio, fim, cont;
    char fila[MAXFILA];
};

//fun��o que inicializa a fila
void inicializarFC(TpFilaCirc &F)
{
    F.inicio = 0;
    F.fim = -1;
    F.cont = 0;
}

//fun��o que insere os elementos na fila e tornando ela circular
void inserirFC(TpFilaCirc &F, char Elem)
{
    if(F.fim == MAXFILA -1)   // se o fim for a ultima posi��o do vetor, ele recebe -1 para assim ser inserido na posi��o 0 (o inicio)
        F.fim = -1;

    F.fila[++F.fim] = Elem;

    F.cont ++;
}

//fun��o que retira os elementos da fila e torna ela tambem circular
char retirarFC(TpFilaCirc &F)
{
    int aux;

    aux = F.fila[F.inicio++];      // a vari�vel aux recebe o elemento do in�cio da fila, o que vai ser retirado

    if(F.inicio == MAXFILA)     // se o inicio for == MAXFILA ele recebe 0, ele "reseta", volta pro in�cio
        F.inicio = 0;

    F.cont --;  //decrementa o contador, ja que foi retirado um elemento

    return aux; //retornando para exibir qual elemento foi retirado
}

//fun��o que exibe o elemento do inicio da fila circular
char elementoInicioFC(TpFilaCirc F)
{
    return F.fila[F.inicio];
}

//fun��o que exibe o elemento do fim da fila circular
int elementoFimFC(TpFilaCirc F )
{
    return F.fila[F.fim];
}

//fun��o que retorna se a fila � vazia ou n�o
int vaziaFC( int cont )
{
    return cont == 0;
}

//fun��o que retorna se a fila est� cheia ou n�o
char cheiaFC(int cont)
{
    return cont == MAXFILA;
}

//fun��o que exibe todos os elementos presentes dentro da fila circular
void exibirFC(TpFilaCirc F)
{
    while(!vaziaFC(F.cont))
        printf("\t%c", retirarFC(F));
}

