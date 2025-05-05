#include<stdio.h>
#include<conio2.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

//strupr (String); Pega a string toda e joga para mauiscula;

void GravaTxtStr(char NomeArq[50])
{
	FILE *PtrTxt = fopen (NomeArq,"a");
	char linha [100];
	
	printf("\n Digite o texto:\n");
	fflush(stdin);
	gets(linha);
	
	while(strcmp(linha,"\0")!= 0)
	{
		fputs(linha,PtrTxt);
		fputs("\n",PtrTxt);
		
		fflush(stdin);
		gets(linha);
	}
	
	fclose(PtrTxt);
}

void ExibeTxtStr(char NomeArq[50])
{
	FILE * PtrTxt = fopen(NomeArq,"r");
	char linha[100];
	
	if(PtrTxt == NULL)
		printf("\nErro de Abertura!\n");
	else
	{
		fgets(linha,100,PtrTxt);
		while(!feof(PtrTxt))
		{
			printf("%s",linha);
			fgets(linha,100,PtrTxt);
		}
	}
	getch();
	fclose(PtrTxt);
}

int main (void)
{
	char Arquivo[50];
	
	printf("\nNome do Arquivo:");
	fflush(stdin);
	gets(Arquivo);
	
	GravaTxtStr(Arquivo);
	ExibeTxtStr(Arquivo);
	
	
	return 0;
}
