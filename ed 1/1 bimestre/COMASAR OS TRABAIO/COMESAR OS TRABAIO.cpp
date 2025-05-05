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

/*void limparTela() { chat gepeteco
    // Limpar a tela usando caracteres de nova linha
    std::cout << "\033[2J\033[1;1H";
}*/

int validar() {
    FILE *ptr = fopen("cidades.dat","rb");

    if (ptr == NULL) {
        return 1;     // Nao tem
        //fclose(ptr);  // Fechar o arquivo antes de retornar, pois se nao o fclose nunca vai acontecer
    } else {
        return 0;     // tem
        //fclose(ptr);  // Fechar o arquivo antes de retornar, pois se nao o fclose nunca vai acontecer
    }
}
void cadastrar(FILE *ptr) {
    int key;
    TpCidade cit;
    FILE *ptrTemp = fopen("cidadestemp.dat","ab");

    key = validar();
	
	printf("%d",key);
    if (key == 1) {
        printf("\nArquivo nao existente");
        printf("\nGostaria de cadastrar um novo? S/N");
        if (toupper(getch()) == 'S') {
            printf("\ninforme o nome da cidade: ");
            fflush(stdin);//nao escquecer pelo amor de Deus
            gets(cit.Nome);
            printf("\ninforme a populacao da cidade: ");
            scanf("%d",&cit.Populacao);
			fwrite(&cit,sizeof(TpCidade),1,ptrTemp);    
        } 
		else {
            printf("\nFIM");
        }
    }
	else {
        printf("\nInforme o nome da cidade");
        gets(cit.Nome);
    }
    
    fclose(ptr);
    fclose(ptrTemp);
    remove("cidades.dat");
    rename("cidadestemp.dat","cidades.dat");//o nome do arquivos a - > b(a)
    getch();
}



char menu(void)
{
	printf("# # #  M E N U  F O R N E C E D O R  # # #\n");
	printf("\n[A] Cadastrar ");;
	printf("\n[B] Consultar");
	printf("\n[C] Ordenar ");
	printf("\n[D] Exibir");
	printf("\n[E] Relatorio de dados");
	printf("\n[ESC] Finalizar\n");
	return toupper(getch());
}

int main()
{
	FILE *ptr;
	char op;
	menu();
	do
	{
		//limparTela();
		op = toupper(getch());
		switch(op)
		{
			case 'A':
				cadastrar(ptr);
			break;	
		}
	}while(op!=27);
	return 0;
}
