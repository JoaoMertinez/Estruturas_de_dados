#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<conio2.h>
#include <iostream>
#include <cstdlib> // Para a função system	


struct TpCidade
{
	char Nome[50];
	int Populacao;
};

int validar ()
{
	FILE * ptr = fopen("cidades.dat","rb");
	
	if(ptr == NULL)
		printf("\nArquivo nao encontrado");
	else
		printf("Arquivo foi aberto");
	
	
	return 0;
	fclose(ptr);
}

void limparTela() { //chat gepeteco
    // Limpar a tela usando caracteres de nova linha
    std::cout << "\033[2J\033[1;1H";
}


void cadastrar()
{
	FILE *ptr = fopen("cidades.dat","ab");
	TpCidade cit;
	
	printf("\ninforme o nome da cidade: ");
    fgets(cit.Nome);
    printf("\ninforme a populacao da cidade: ");
    scanf("%d",&cit.Populacao);
	fwrite(&cit,sizeof(TpCidade),1,ptr);
	
	limparTela();
	fclose(ptr);
	getch();
}

void consultar()
{
	TpCidade cit;
	char ex[30];
	int pos;
	
	FILE *ptr = fopen("cidades.dat","rb");
	printf("Informe a cidade para consulta" );
	fgets(ex);
	
	pos = buscaCidade(ex,)
	
}

char menu(void)
{
	printf("# # #  M E N U  F O R N E C E D O R  # # #\n");
	printf("\n[A] Validar arquivo");;
	printf("\n[B] Cadastrar cidade");;
	printf("\n[C] Consultar populacao");
	printf("\n[D] Ordenar ");
	printf("\n[E] Exibir");
	printf("\n[F] Relatorio de dados");
	printf("\n[ESC] Finalizar\n");
	return toupper(getch());
}

int main()
{
	char op;
	do
	{
		op = menu();
		switch(op)
		{
			case 'A':
				validar();
			break;
			
			case 'B':
				 cadastrar();
			break;
			
			case 'C':
				consultar();
			break;
		}
	}while(op!=27);
	return 0;
}
