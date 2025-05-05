#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ItemCompra {
    char nomeItem[50];
    float preco;
    int id, qtde;
    ItemCompra* prox;
};

struct TpCliente {
    char nomeC[50];
    ItemCompra* compras;
    float valorTotal;
    TpCliente* prox;
};

struct TpCaixa {
    char nome[50];
    TpCaixa* ant;
    TpCaixa* prox;
    TpCliente* atendimentos;
};

// Função para criar um novo nó de atendente
TpCaixa* novoCaixa(char* nome) {
    TpCaixa* caixa = new TpCaixa;
    strcpy(caixa->nome, nome);
    caixa->prox = NULL;
    caixa->ant = NULL;
    caixa->atendimentos = NULL;
    return caixa;
}

// Função para criar um novo nó de cliente
TpCliente* novoCliente(char* nomeC) {
    TpCliente* cliente = new TpCliente;
    strcpy(cliente->nomeC, nomeC);
    cliente->compras = NULL;
    cliente->valorTotal = 0.0;
    cliente->prox = NULL;
    return cliente;
}

// Função para criar um novo nó de item de compra
ItemCompra* novoItemCompra(char* nomeItem, float preco, int id, int qtde) {
    ItemCompra* item = new ItemCompra;
    strcpy(item->nomeItem, nomeItem);
    item->preco = preco;
    item->id = id;
    item->qtde = qtde;
    item->prox = NULL;
    return item;
}

// Função para inserir atendentes na lista de forma ordenada pelo nome
TpCaixa* AbrirCaixa(TpCaixa* Lista) {
    char nome[50];
    TpCaixa *nc, *p;

    printf("\nDigite o nome do atendente (ou 'fim' para terminar): ");
    fflush(stdin);
    fgets(nome, 50, stdin);
    nome[strcspn(nome, "\n")] = 0;

    while (strcmp(nome, "fim") != 0) {
        nc = novoCaixa(nome);
        if (Lista == NULL) {
            Lista = nc;
        } else {
            p = Lista;
            while (p->prox != NULL && strcmp(p->prox->nome, nc->nome) < 0) {
                p = p->prox;
            }
            nc->prox = p->prox;
            if (p->prox != NULL) {
                p->prox->ant = nc;
            }
            p->prox = nc;
            nc->ant = p;
        }

        printf("\nDigite o nome do atendente (ou 'fim' para terminar): ");
        fflush(stdin);
        fgets(nome, 50, stdin);
        nome[strcspn(nome, "\n")] = 0;
    }

    return Lista;
}

// Função para registrar compras dos clientes
void RegistrarCompras(TpCliente* cliente) {
    char nomeItem[50];
    float preco;
    int id, qtde;
    ItemCompra *item, *lastItem = NULL;

    printf("\nDigite o nome do item (ou 'fim' para terminar): ");
    fflush(stdin);
    fgets(nomeItem, 50, stdin);
    nomeItem[strcspn(nomeItem, "\n")] = 0;

    while (strcmp(nomeItem, "fim") != 0) {
        printf("Digite o preço do item: ");
        scanf("%f", &preco);
        printf("Digite o ID do item: ");
        scanf("%d", &id);
        printf("Digite a quantidade do item: ");
        scanf("%d", &qtde);

        item = novoItemCompra(nomeItem, preco, id, qtde);
        cliente->valorTotal += preco * qtde;

        if (cliente->compras == NULL) {
            cliente->compras = item;
        } else {
            lastItem->prox = item;
        }
        lastItem = item;

        printf("\nDigite o nome do item (ou 'fim' para terminar): ");
        fflush(stdin);
        fgets(nomeItem, 50, stdin);
        nomeItem[strcspn(nomeItem, "\n")] = 0;
    }
}

// Função recursiva para finalizar compra e liberar a memória dos itens
void FinalizarCompra(ItemCompra* item) {
    if (item == NULL) return;
    FinalizarCompra(item->prox);
    delete item;
}

// Função para registrar o atendimento de um cliente
void AtenderCliente(TpCaixa* caixa, TpCliente* cliente) {
    RegistrarCompras(cliente);
    cliente->prox = caixa->atendimentos;
    caixa->atendimentos = cliente;

    printf("\nCompra finalizada! Total gasto: R$ %.2f\n", cliente->valorTotal);
    FinalizarCompra(cliente->compras);
    cliente->compras = NULL;
}

// Função para fechar o caixa e emitir a relação dos atendimentos
void FecharCaixa(TpCaixa* caixa) {
    TpCliente* cliente = caixa->atendimentos;
    printf("\nAtendimentos do caixa %s:\n", caixa->nome);
    while (cliente != NULL) {
        printf("Cliente: %s, Total gasto: R$ %.2f\n", cliente->nomeC, cliente->valorTotal);
        cliente = cliente->prox;
    }
    printf("\n");

    // Liberar memória dos atendimentos
    cliente = caixa->atendimentos;
    while (cliente != NULL) {
        TpCliente* temp = cliente;
        cliente = cliente->prox;
        delete temp;
    }
    caixa->atendimentos = NULL;
}

// Função para imprimir a lista de atendentes
void imprimeListaAtendentes(TpCaixa* Lista) {
    TpCaixa* temp = Lista;
    while (temp != NULL) {
        printf("%s\n", temp->nome);
        temp = temp->prox;
    }
    printf("Final\n");
}

// Função principal
int main() {
    TpCaixa* ListaCaixas = NULL;
    ListaCaixas = AbrirCaixa(ListaCaixas);
    imprimeListaAtendentes(ListaCaixas);

    char nomeCliente[50];
    while (true) {
        printf("\nDigite o nome do cliente (ou 'fim' para terminar): ");
        fflush(stdin);
        fgets(nomeCliente, 50, stdin);
        nomeCliente[strcspn(nomeCliente, "\n")] = 0;

        if (strcmp(nomeCliente, "fim") == 0) break;

        TpCliente* cliente = novoCliente(nomeCliente);
        AtenderCliente(ListaCaixas, cliente);
    }

    // Fechar todos os caixas e liberar memória
    TpCaixa* caixa = ListaCaixas;
    while (caixa != NULL) {
        TpCaixa* temp = caixa;
        FecharCaixa(caixa);
        caixa = caixa->prox;
        delete temp;
    }

    return 0;
}

