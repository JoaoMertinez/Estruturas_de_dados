#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void inverterPalavras(char *inicio, char *resultado, int tam) {
    char *fimPalavra = inicio;  // Ponteiro para o fim da palavra atual
    int tamanhoPalavra;

    // Procurar o final da primeira palavra ou o fim da string
    while (*fimPalavra != ' ' && *fimPalavra != '\0') {
        fimPalavra++;
    }
    
    // Calcula o tamanho da palavra
    tamanhoPalavra = fimPalavra - inicio;

    // Se n�o � o fim da string, processa o resto
    if (*fimPalavra != '\0') {
        inverterPalavras(fimPalavra + 1, resultado, tam + tamanhoPalavra + 1);
        resultado[tam] = ' ';  // Insere espa�o ap�s a palavra anterior
    }

    // Copia a palavra atual para a posi��o correta
    memcpy(resultado + tam + 1, inicio, tamanhoPalavra);

    // Coloca o caractere nulo no final (mant�m a string sempre terminada corretamente)
    resultado[tam + tamanhoPalavra + 1] = '\0';
}

int main() {
    char frase[] = "Eae chat como vai";
    char *resultado = malloc(strlen(frase) + 1);  // Aloca espa�o para a string invertida

    if (resultado == NULL) {
        printf("Erro de aloca��o de mem�ria.\n");
        return 1;
    }

    printf("Original: %s\n", frase);
    inverterPalavras(frase, resultado, 0);
    printf("Invertida: %s\n", resultado);

    free(resultado);  // Libera a mem�ria alocada
    return 0;
}

