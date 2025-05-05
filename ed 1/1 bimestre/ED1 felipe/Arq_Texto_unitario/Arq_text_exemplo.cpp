#include<stdio.h>
#include<conio2.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

void GravarTxtChar (char NomeArq[50])
{
	FILE *Ptrtxt = fopen(NomeArq,"a");
	
	char lido;
	
	printf("\nDigite o texto :\n");
	lido = getche();
	
	while(lido != 27)
	{
		if(lido == 13)
		{
			printf("\n");
			fputc('\n',Ptrtxt);
		}
		else
			fputc(lido,Ptrtxt);
		
		lido = getche();
	}
	fclose(Ptrtxt);
	
	printf("\nArquivo Gerado!\n");
	getch();
}


void ExibeTxtChar(char NomeArq[50])
{
	
	char lido;
	FILE *PtrTxt = fopen(NomeArq,"r");
	
	if(PtrTxt == NULL)
		printf("\nErro de Abertura\n!");
	else
	{
		printf("Conteudo do Arquivo:\n");
		
		lido = fgetc(PtrTxt);
		while(!feof(PtrTxt))
		{
			printf("%c",lido);
			lido = fgetc(PtrTxt);
		}
		fclose(PtrTxt);
	}	
}

int main (void)
{
	char Arquivo[50];
	
	printf("\nNome do Arquivo:");
	fflush(stdin);
	gets(Arquivo);
	
	GravarTxtChar(Arquivo);
	ExibeTxtChar(Arquivo);
	
	
	return 0;
}
