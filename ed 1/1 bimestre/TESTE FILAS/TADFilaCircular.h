#define MAXFILA 10

//struct que está guardando os dados da fila
//na fila circular é so ++

struct TpFilaCirc
{
    int inicio, fim, cont;
    char fila[MAXFILA];
};

//função que inicializa a fila
void inicializarFC(TpFilaCirc &F)
{
    F.inicio = 0;
    F.fim = -1;
    F.cont = 0;
}

//função que insere os elementos na fila e tornando ela circular
void inserirFC(TpFilaCirc &F, char Elem)
{
    if(F.fim == MAXFILA -1)   // se o fim for a ultima posição do vetor, ele recebe -1 para assim ser inserido na posição 0 (o inicio)
        F.fim = -1;

    F.fila[++F.fim] = Elem;

    F.cont ++;
}

//função que retira os elementos da fila e torna ela tambem circular
char retirarFC(TpFilaCirc &F)
{
    int aux;

    aux = F.fila[F.inicio++];      // a variável aux recebe o elemento do início da fila, o que vai ser retirado

    if(F.inicio == MAXFILA)     // se o inicio for == MAXFILA ele recebe 0, ele "reseta", volta pro início
        F.inicio = 0;

    F.cont --;  //decrementa o contador, ja que foi retirado um elemento

    return aux; //retornando para exibir qual elemento foi retirado
}

//função que exibe o elemento do inicio da fila circular
char elementoInicioFC(TpFilaCirc F)
{
    return F.fila[F.inicio];
}

//função que exibe o elemento do fim da fila circular
int elementoFimFC(TpFilaCirc F )
{
    return F.fila[F.fim];
}

//função que retorna se a fila é vazia ou não
int vaziaFC( int cont )
{
    return cont == 0;
}

//função que retorna se a fila está cheia ou não
char cheiaFC(int cont)
{
    return cont == MAXFILA;
}

//função que exibe todos os elementos presentes dentro da fila circular
void exibirFC(TpFilaCirc F)
{
    while(!vaziaFC(F.cont))
        printf("\t%c", retirarFC(F));
}

