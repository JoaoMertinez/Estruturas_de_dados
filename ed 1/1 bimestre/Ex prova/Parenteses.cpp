#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

#include "TADPilha.h"

void EscreveArquivo(FILE *input) {//aqui ja estou escrevendo direto sem fazer a verificaçao de tamanho maximo de 1000 que ele pede, mudar depois
    fprintf(input, "a+ (b*c) -2-a\n");
    fprintf(input, "(a* (2-0)~2+a)*2\n");
    fprintf(input, "{a*b-(2+c)\n");
    fprintf(input, "2* (3-a) )\n");
    fprintf(input, "23+0* 12-c) (\n");
}

void ExibeArquivo(FILE *input) {
    char linha[MAX];
    while (fgets(linha, MAX, input) != NULL) {
        printf("%s", linha);
    }
}

void EmpilhaArquivo(FILE *input,TpPilha &P,int tamanho)//eu poderia ter empilhado ja na hora de escrever no arquivo
{
	char ele[MAX];
	
	while (fgets(ele, MAX, input) != NULL) {
     	push(P,ele);   
    }
}

int main() {
	
	TpPilha pilha[MAXPILHA];//nao sei qual max usar
	inicializar(pilha);
	
    FILE *input = fopen("Expressoes.txt", "a");
    
    if (input == NULL) {
        printf("\nErro ao abrir o arquivo");
    }
    
    EscreveArquivo(input);
    EmpilhaArquivo(input,pilha,MAXPILHA);
    fclose(input);//sem fechar aqui estava dando erro

    input = fopen("Expressoes.txt", "r");
    if (input == NULL) {
        printf("\nErro ao abrir o arquivo para leitura");
    }

    ExibeArquivo(input);
    fclose(input);

    return 0;
}

