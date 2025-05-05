void chatgpt()
{
	/*
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	
	#define MAX_LINE_SIZE 100
	
	struct Veiculo {
	    char id[50];
	    char cor[50];
	    char fabricante[50];
	    char prioridade[50];
	};
	
	int main() {
	    struct Veiculo veiculo;
	    FILE *arquivo = fopen("DadosVeiculos.csv", "r");
	
	    if (arquivo == NULL) {
	        printf("Erro ao abrir o arquivo.\n");
	        return 1;
	    }
	
	    char linha[MAX_LINE_SIZE];
	    while (fgets(linha, MAX_LINE_SIZE, arquivo) != NULL) {
	        // Dividindo a linha em campos separados por vírgula
	        char *id = strtok(linha, ",");
	        char *cor = strtok(NULL, ",");
	        char *fabricante = strtok(NULL, ",");
	        char *prioridade = strtok(NULL, ",");
	
	        // Removendo caracteres de nova linha dos campos (se houver)
	        if (prioridade != NULL && prioridade[strlen(prioridade) - 1] == '\n') {
	            prioridade[strlen(prioridade) - 1] = '\0';
	        }
	
	        // Copiando os valores para a estrutura Veiculo
	        strcpy(veiculo.id, id);
	        strcpy(veiculo.cor, cor);
	        strcpy(veiculo.fabricante, fabricante);
	        strcpy(veiculo.prioridade, prioridade);
	
	        // Exibindo os valores lidos
	        printf("\nID: %s\n", veiculo.id);
	        printf("Cor: %s\n", veiculo.cor);
	        printf("Fabricante: %s\n", veiculo.fabricante);
	        printf("Prioridade: %s\n", veiculo.prioridade);
	    }
	
	    fclose(arquivo);
	    return 0;
}
*/
	
}

#include<stdio.h>
#include<string.h>

#include "TADVEICULOSFP.h"
	
int main() {
	
    carro veiculo;
    TpFila fila[MAXFILA];
    
    FILE *arquivo = fopen("DadosVeiculos.csv", "r");
    
    if (arquivo == NULL)
        printf("\nERRO");
    else {
        fscanf(arquivo, "%*[^,],%*[^,],%*[^,],%*[^\n]\n"); // Lendo e descartando o cabeçalho
        
        while (fscanf(arquivo, "%[^,],%[^,],%[^,],%c\n", veiculo.id, veiculo.cor, veiculo.fab, &veiculo.prior) == 4) {
			printf("ID: %s, Cor: %s, Fabricante: %s, Prioridade: %c\n", veiculo.id, veiculo.cor, veiculo.fab, veiculo.prior);
			if(veiculo.prior=='A')
				printf("MAIOR\n");
			else
				if(veiculo.prior=='B');
					printf("MEIO\n");
				else
					printf("ULTIMO\n");
						        	
			//push(fila,veiculo);

        }
    }
    
    fclose(arquivo);
    return 0;
}
