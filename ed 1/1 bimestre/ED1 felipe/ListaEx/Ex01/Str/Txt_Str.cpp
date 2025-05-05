#include<stdio.h>
#include<conio2.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

//strupr (String); Pega a string toda e joga para mauiscula;

//EX01. Ao receber um arquivo de texto, via parâmetro, retorne um novo arquivo com
//todas as letras em maiúsculo. 

//fputs
void GravarTxtStr(char NomeArq[50])
{
	FILE *PtrTxt = fopen (NomeArq,"a");
	char linha [100];
	
	printf("Digite o texto:\n");
	fflush(stdin);
	gets(linha);
	
	while(strcmp(linha,"\0")!= 0)
	{
		fputs(linha,PtrTxt);//string,buffer
		fputs("\n",PtrTxt);
		
		fflush(stdin);
		gets(linha);
	}
	fclose(PtrTxt);
}
void ExibeTxtStr (char NomeArq[50],char NomeArqCaps[50])
{
	FILE * PtrTxt = fopen(NomeArq,"r");
	FILE * PtrTxtCap = fopen(NomeArqCaps, "a");
	char linha[100],linha2[100];
	
	if(PtrTxt == NULL)
		printf("\nArquivo com erro!\n");
	else
	{
		fgets(linha, 100, PtrTxt);  // lê a linha do arquivo
		strupr(linha);  // converte para maiúsculas
		while (fgets(linha, 100, PtrTxt) != NULL)//quando fgets chega no final retorna NULL
		{
			printf("%s", linha);  // exibe no console
			fgets(linha, 100, PtrTxt);  // lê a linha do arquivo
			
		}
		    
		    
		strcpy(linha2,linha);
	    fputs(linha2, PtrTxtCap);  // escreve no novo arquivo
	    fputs("\n", PtrTxtCap);  // adiciona uma quebra de linha no novo arquivo
	}
	getch();
	fclose(PtrTxt);
	fclose(PtrTxtCap);
}
//fputs


int main (void)
{
	char Arquivo[50],Arquivo2[50];
	
	printf("Nome do Arquivo:");
	fflush(stdin);
	gets(Arquivo);
	
	GravarTxtStr(Arquivo);
	ExibeTxtStr(Arquivo,Arquivo2);
	
	
	return 0;
}
