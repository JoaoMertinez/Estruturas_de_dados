#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct TpProduto{
	int idProd;
	float valor;
	TpProduto *prox;
};

struct TpCliente{
	int cpf;
	TpCliente *prox;
	TpProduto *compras;
};

struct TpCaixa{
	char nomeA[50];
	TpCliente *atendidos;
	float total;
	TpCaixa *prox;	
	TpCaixa *ant;
};

TpCaixa *novoCaixa(char nome[50])
{
	TpCaixa * caixa = new TpCaixa;
	strcpy(caixa->nomeA, nome);
    caixa->prox = NULL;
    caixa->ant = NULL;
    caixa->atendidos = NULL;
    return caixa;
}

TpCliente *novaCaixaC(int cpf)
{
	TpCliente * caixa = new TpCliente;	
	caixa->prox = NULL;
	caixa->cpf = cpf;
	caixa->compras = NULL;
	
	return caixa;
}

TpProduto *novaCaixaProduto(int id, float valor)
{
    TpProduto *produto = new TpProduto;
    produto->idProd = id;
    produto->valor = valor;
    produto->prox = NULL;
    return produto;
}

float calcularTotalProdutos(TpProduto *listaProdutos)
{
    float total = 0.0;

    // Percorre a lista de produtos
    TpProduto *atual = listaProdutos;
    while (atual != NULL)
    {
        total += atual->valor;
        atual = atual->prox;
    }

    return total;
}

TpCliente *relatorioRecursivo(TpCliente *lista)
{
    if (lista != NULL)
    {
        printf("CPF do cliente: %d\n", lista->cpf);
        
        // Calcular o total dos produtos comprados por este cliente
        float totalGasto = calcularTotalProdutos(lista->compras);
        printf("Total gasto: %.2f\n", totalGasto);

        // Chamada recursiva para o próximo cliente na lista
        relatorioRecursivo(lista->prox);
    }

    return lista;
}

TpProduto *cadastroProdutos()
{
    TpProduto *listaP = NULL;
    int id;
    float valor;

    printf("Digite o ID do produto (ou 0 para terminar o cadastro): ");
    scanf("%d", &id);

    while (id != 0)
    {
        if (id < 0)
        {
            printf("ID do produto deve ser positivo. Digite novamente: ");
            scanf("%d", &id);
            continue;
        }

        printf("Digite o valor do produto: ");
        scanf("%f", &valor);

        if (valor < 0)
        {
            printf("Valor do produto deve ser positivo. Digite novamente: ");
            scanf("%f", &valor);
            continue;
        }

        TpProduto *novoProduto = novaCaixaProduto(id, valor);

        if (listaP == NULL)
        {
            listaP = novoProduto;
        }
        else
        {
            TpProduto *ultimo = listaP;
            while (ultimo->prox != NULL)
            {
                ultimo = ultimo->prox;
            }
            ultimo->prox = novoProduto;
        }

        printf("Digite o ID do proximo produto (ou 0 para terminar o cadastro): ");
        scanf("%d", &id);
    }

    return listaP;
}

TpCliente *cadastrarCompra(TpCliente *lista)
{
	TpCliente *fim=NULL,*nc;
	//TpProduto *listaP;	
	int cpf;
	printf("\nDigite o cpf: ");
	scanf("%d",&cpf);
	
	while(cpf!=0)
	{
		nc = novaCaixaC(cpf);	
		if(lista==NULL)
		{
			lista=nc;
			fim=nc;
		}
		else
		{
			fim->prox = nc;
			fim=nc;
		}
		
		//listaP = NULL;
		nc->compras = cadastroProdutos();
		
		printf("\nDigite o cpf: ");
		scanf("%d",&cpf);
	}
	
	//relatorioRecursivo(lista);
	return lista;
}

TpCaixa *AbrirCaixa(TpCaixa *listaC)
{
    char nome[50];
    TpCaixa *nc;
    TpCliente *cli;
    float *total;
    
    do
    {
        printf("\nDigite o nome do atendente (ou 'fim' para terminar): ");
        fflush(stdin);
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = '\0'; // Remover o '\n' adicionado pelo fgets

        if (strcmp(nome, "fim") == 0)
            break;

        nc = novoCaixa(nome);

        if (listaC == NULL) // Lista vazia
        {
            listaC = nc;
        }
        else
        {
            TpCaixa *atual = listaC;

            // Encontrar a posição correta na lista ordenada por nome
            while (atual->prox != NULL && strcmp(nc->nomeA, atual->nomeA) > 0)
                atual = atual->prox;

            if (strcmp(nc->nomeA, atual->nomeA) < 0)
            {
                nc->prox = atual;
                nc->ant = atual->ant;
                if (atual->ant != NULL)
                    atual->ant->prox = nc;
                atual->ant = nc;

                if (atual == listaC)
                    listaC = nc;
            }
            else
            {
                nc->ant = atual;
                atual->prox = nc;
            }
        }

        cli = NULL;
        nc->atendidos = cadastrarCompra(cli); // Chamar a função para cadastrar compras
        total = relatorioRecursivo(cli);
        nc->total = total;

    } while (strcmp(nome, "fim") != 0);

    return listaC;
}

int main()
{
    TpCaixa *listaCaixas = NULL;

    listaCaixas = AbrirCaixa(listaCaixas);

    //imprimirRelatorio(listaCaixas);

    return 0;
}
