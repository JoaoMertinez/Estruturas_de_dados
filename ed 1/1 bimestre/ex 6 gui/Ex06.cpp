#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio2.h>

#include "TADPilha.h"
//Função que faz a manipulação do arquivo texto com pilha
void arqPilha(TpPilha &P)
{
	inicializar(P);
	FILE *ptrTxt = fopen("teste.txt","r");
	FILE *ptrAux = fopen("auxiliar.txt","w");
	char letra;
	
	if(ptrAux == NULL || ptrTxt == NULL)
		printf("Erro na abertura dos arquivos!\n");
	else
	{
		while(!feof(ptrTxt) && !pilhaCheia(P.topo))
		{
			letra = fgetc(ptrTxt); //a letra está recebendo o caracter do arquivo texto
			push(P,letra); //colocando a letra que guardamos na variavel dentro da pilha
		}
		
		while(!pilhaVazia(P.topo)) //verificando se não chegou no fim da pilha
		{
			letra = POP(P);
			fputc(letra,ptrAux);
		}
		
		printf("\nConteudo do arquivo apos manipulacao:\n");
		rewind(ptrAux);
		letra = fgetc(ptrAux);
		while(!feof(ptrAux))
		{
			printf("%c",letra);
			letra = fgetc(ptrAux);
		}
		
		fclose(ptrTxt);
		fclose(ptrAux);
	}
}

int main(void)
{
	TpPilha P;
	char letra;
	FILE *ptrTxt = fopen("teste.txt","a");
	
	if(ptrTxt == NULL)
		printf("Erro na abertura do arquivo!\n");
	else
	{
        printf("Digite [ESC] para encerrar a escrita!\n");
        printf("Digite a frase:\n");
        fflush(stdin);
        letra = getche(); // Ler a primeira letra
        while (letra != 27)
		{ // 27 é o código ASCII para ESC
            if (letra == 13)
			{
                printf("\n");
                fputc('\n', ptrTxt);
            } else
                fputc(letra, ptrTxt);
            
			fflush(stdin);    
            letra = getche(); // Ler a próxima letra
        }
        fclose(ptrTxt);
    }
	arqPilha(P);
}
