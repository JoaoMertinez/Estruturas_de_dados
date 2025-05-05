#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>

#define TF 100

struct TpJogador{
	char NomeJ[TF];
	int Rg,idade,numero,gols;
	char EquipeAnt[50];
	int ano;
	TpJogador *prox;
};

struct TpEquipe{
	char nome[TF],nomeTreinador[TF];
	TpJogador *time;
	TpEquipe *ant,*prox;
};

TpEquipe *novaCaixaEquipe(TpEquipe equipe)
{
	TpEquipe *caixa;
	caixa = new TpEquipe;
	strcpy(caixa->nome, equipe.nome);
	strcpy(caixa->nomeTreinador, equipe.nomeTreinador);
	caixa->ant = NULL;
	caixa->prox = NULL;
	caixa->time = NULL; // Initialize the time pointer
	return caixa;
}

TpJogador* novaCaixaJogador(TpJogador jogador) 
{
    TpJogador *caixa = new TpJogador;
    
    strcpy(caixa->NomeJ, jogador.NomeJ);
    caixa->Rg = jogador.Rg;
    caixa->idade = jogador.idade;
    caixa->numero = jogador.numero;
    caixa->gols = jogador.gols;
    strcpy(caixa->EquipeAnt, jogador.EquipeAnt);
    caixa->ano = jogador.ano;
    caixa->prox = NULL;    
    return caixa;
}

/*
TpJogador *DefineTime(TpJogador *listaJ)
{
	TpJogador jogador, *nc, *fim;
	int cont = 1, resp;
	
	do
	{
		printf("Digite o nome do jogador: ");
		fflush(stdin);
		gets(jogador.NomeJ);
		/*
		printf("Digite o RG do jogador: ");
		scanf("%d", &jogador.Rg);
		printf("Digite a idade do jogador: ");
		scanf("%d", &jogador.idade);
		printf("Digite o numero do jogador: ");
		scanf("%d", &jogador.numero);
		printf("Digite a quantidade de gols do jogador: ");
		scanf("%d", &jogador.gols);
		printf("Digite o ano de entrada do jogador no time: ");
		scanf("%d", &jogador.ano);
		* /
		nc = novaCaixaJogador(jogador);
		if(listaJ == NULL)
		{
			listaJ = nc;
			fim = nc;
		}
		else
		{
			fim->prox = nc;
			fim = nc;
		}
		cont++;
		
		if(cont >= 2) //numero minimo de jogadores
		{
			printf("Deseja inserir mais jogadores?(0 para nao): ");
			scanf("%d", &resp);
			if(resp == 0)
				cont = 0;
		}
		
	}while(cont != 0);
	
	return listaJ;
}
*/

void exibirEquipe(TpEquipe *lista)
{
	TpJogador *time;
	
	printf("Relatorio da equipe e seus jogadores\n");
	
	while(lista != NULL)
	{
		printf("Nome da equipe: %s\n", lista->nome);
		printf("Nome do treinador: %s\n", lista->nomeTreinador);
		
		time = lista->time;
		while(time != NULL)
		{
			printf("Nome do jogador: %s\n", time->NomeJ);
			time = time->prox;
		}
		
		lista = lista->prox;
	}
}

/*TpEquipe *DefinirEquipe(TpEquipe *listaE) 
{
	
	TpEquipe equipe, *ncE;
	TpJogador *listaJ;
	
	do
	{
		printf("Digite o nome da equipe: ");
		fflush(stdin);
		gets(equipe.nome);
		if(strlen(equipe.nome) == 0) break;//kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk
		
		printf("Digite o nome do treinador: ");
		fflush(stdin);
		gets(equipe.nomeTreinador);
		
		ncE = novaCaixaEquipe(equipe);
		
		if(listaE == NULL)
		{
			listaE = ncE;
		}
		else
		{
			if(strcmp(ncE->nome, listaE->nome) <= 0)
			{
				ncE->prox = listaE;
				listaE->ant = ncE;
				listaE = ncE;
			}
			else
			{
				TpEquipe *atual = listaE;
				
				while(atual->prox != NULL && strcmp(ncE->nome, atual->nome) > 0)
					atual = atual->prox;
				
				if(strcmp(ncE->nome, atual->nome) < 0)
				{
					ncE->ant = atual->ant;
					ncE->prox = atual;
					atual->ant->prox = ncE;
					atual->ant = ncE;
				}
				else
				{
					atual->prox = ncE;
					ncE->ant = atual;
				}
			}
		}
		
		listaJ = NULL;
		listaJ = DefineTime(listaJ);
		ncE->time = listaJ;
		
		exibirEquipe(listaE);
		
	}while(1);

	return listaE;   
}
*/

//pedi pro chat pra adiantar meu lado porem as de inserir que fiz ja estao funcionando e eu ja testei
TpEquipe* inserirAutomatico(TpEquipe *listaE) {
    TpEquipe equipe, *ncE;
    TpJogador jogador, *listaJ = NULL, *ncJ, *fim;

    // Inserir uma equipe
    strcpy(equipe.nome, "Equipe1");
    strcpy(equipe.nomeTreinador, "Treinador1");
    ncE = novaCaixaEquipe(equipe);

    if (listaE == NULL) {
        listaE = ncE;
    } else {
        if (strcmp(ncE->nome, listaE->nome) <= 0) {
            ncE->prox = listaE;
            listaE->ant = ncE;
            listaE = ncE;
        } else {
            TpEquipe *atual = listaE;
            while (atual->prox != NULL && strcmp(ncE->nome, atual->nome) > 0) {
                atual = atual->prox;
            }
            if (strcmp(ncE->nome, atual->nome) < 0) {
                ncE->ant = atual->ant;
                ncE->prox = atual;
                atual->ant->prox = ncE;
                atual->ant = ncE;
            } else {
                atual->prox = ncE;
                ncE->ant = atual;
            }
        }
    }

    // Inserir jogadores na equipe
    for (int i = 1; i <= 3; i++) { // Insere 3 jogadores para exemplo
        sprintf(jogador.NomeJ, "Jogador%d", i);
        jogador.Rg = 1111110 + i;
        jogador.idade = 20 + i;
        jogador.numero = i;
        jogador.gols = 10 * i;
        strcpy(jogador.EquipeAnt, "EquipeAnt1");
        jogador.ano = 2020 + i;

        ncJ = novaCaixaJogador(jogador);
        if (listaJ == NULL) {
            listaJ = ncJ;
            fim = ncJ;
        } else {
            fim->prox = ncJ;
            fim = ncJ;
        }
    }

    ncE->time = listaJ;
    return listaE;
}

void excluirEquipe(TpEquipe *&listaE) 
{
    char nome[50];
    int cont;
    TpJogador *time = NULL;
    int encontrou = 0;
    
    
    printf("\nDigite o nome da equipe para a EXCLUSAO (0 pra nao excluir): ");
    fflush(stdin);
    gets(nome);
    
    TpEquipe *atual = listaE;
    TpEquipe *anterior = NULL;
    
    while(atual != NULL && !encontrou) 
	{
        if(strcmp(atual->nome, nome) == 0) 
		{
            encontrou = 1;
            cont = 0;

            printf("Nome da equipe: %s\n", atual->nome);
            printf("Nome do treinador: %s\n", atual->nomeTreinador);

            time = atual->time;
            while(time != NULL) 
			{
                printf("Nome do jogador: %s\n", time->NomeJ);
                time = time->prox;
                cont++;
            }

            printf("O numero de jogadores dessa equipe e de: %d\n", cont);
            printf("Deseja excluir essa equipe? (1 para sim, 0 para nao): ");
            scanf("%d", &cont);

            if(cont == 1) 
			{
                // Exclui os jogadores da equipe
                time = atual->time;
                while(time != NULL) 
				{
                    TpJogador *auxJog = time;
                    time = time->prox;
                    delete auxJog;
                }
                
                // Exclui a equipe da lista
                if(anterior == NULL) //primeiro
				{
                    listaE = atual->prox;
                    if(listaE != NULL) 
                        listaE->ant = NULL;
                } 
				else //meio ou fim
				{
                    anterior->prox = atual->prox;
                    if(atual->prox != NULL) 
                        atual->prox->ant = anterior;
                }
                
                delete atual;
                printf("Equipe excluida com sucesso\n");
            } 
			else 
                printf("Exclusao nao autorizada\n");
        } 
		else 
		{
            anterior = atual;
            atual = atual->prox;
        }
    }
    
    if(!encontrou)
        printf("Equipe nao encontrada ou exclusao nao autorizada\n");
}

void RelatorioArtilheiros(TpEquipe *listaE)
{
	int maior;
	TpJogador *time;
	TpEquipe *atual;
	printf("\nRelatorio artilheiros de cada equipe\n");
	
	while(listaE!=NULL)
	{
		printf("Nome da equipe: %s\n", listaE->nome);
		maior = 0;
		time = listaE->time;
		while(time!=NULL)//pegando o artilheiro
		{
			if(time->gols>=maior)
				maior = time->gols;
			time = time->prox;
		}
		
		time = listaE->time;
		while(time!=NULL)
		{
			if(time->gols == maior)
				printf("Nome do jogador: %s Numero de goals: %d\n", time->NomeJ, maior);
			time = time->prox;
		}
		
		listaE = listaE -> prox;
	}
	
}

int main() 
{
    TpEquipe *listaE = NULL;
    
    listaE = inserirAutomatico(listaE); // Inserir dados automaticamente
    exibirEquipe(listaE);
    excluirEquipe(listaE);
    RelatorioArtilheiros(listaE);
    
    return 0;
}

