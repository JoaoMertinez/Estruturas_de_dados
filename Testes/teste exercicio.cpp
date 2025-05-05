#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    int size;
    int capacity;
} String;

// 1) Cria uma string vazia
String* cria_string() {
    String *str = (String *)malloc(sizeof(String));
    str->size = 0;
    str->capacity = 10;
    str->data = (char *)malloc(str->capacity * sizeof(char));
    str->data[0] = '\0';
    return str;
}

// 2) Reinicia uma string existente
void reinicia_string(String *str) {
    str->size = 0;
    str->data[0] = '\0';
}

// 3) Exibe uma string dinâmica
void exibe_string(String *str) {
    printf("%s\n", str->data);
}

// 4) Exibe uma string dinâmica invertida
void exibe_string_invertida(String *str) {
    for (int i = str->size - 1; i >= 0; i--) {
        putchar(str->data[i]);
    }
    putchar('\n');
}

// 5) Função que retorna o tamanho de uma string dinâmica
int tamanho_string(String *str) {
    return str->size;
}

// 6) Insere um determinado caractere c na string str1
void insere_char(String *str, char c) {
    if (str->size + 1 >= str->capacity) {
        str->capacity *= 2;
        str->data = (char *)realloc(str->data, str->capacity * sizeof(char));
    }
    str->data[str->size] = c;
    str->size++;
    str->data[str->size] = '\0';
}

// 7) Copia o conteúdo da string str1 para a string str2
void copia_string(String *str1, String *str2) {
    free(str2->data);
    str2->size = str1->size;
    str2->capacity = str1->capacity;
    str2->data = (char *)malloc(str2->capacity * sizeof(char));
    strcpy(str2->data, str1->data);
}

// 8) Concatena a string str1 com a string str2 armazenando o resultado na string str3
void concatena_string(String *str1, String *str2, String *str3) {
    reinicia_string(str3);
    copia_string(str1, str3);
    for (int i = 0; i < str2->size; i++) {
        insere_char(str3, str2->data[i]);
    }
}

// 9) Remove da string str1, a quantidade de caracteres especificado por nro a partir da posição start
void remove_chars(String *str, int start, int nro) {
    if (start >= str->size || start < 0 || nro < 0) return;
    if (start + nro > str->size) nro = str->size - start;
    for (int i = start; i + nro < str->size; i++) {
        str->data[i] = str->data[i + nro];
    }
    str->size -= nro;
    str->data[str->size] = '\0';
}

// 10) Insere na string str1 uma substring subs a partir da posição start
void insere_substring(String *str, const char *subs, int start) {
    int len = strlen(subs);
    if (start > str->size) start = str->size;
    while (str->size + len >= str->capacity) {
        str->capacity *= 2;
        str->data = (char *)realloc(str->data, str->capacity * sizeof(char));
    }
    for (int i = str->size - 1; i >= start; i--) {
        str->data[i + len] = str->data[i];
    }
    for (int i = 0; i < len; i++) {
        str->data[start + i] = subs[i];
    }
    str->size += len;
    str->data[str->size] = '\0';
}

// 11) Função que verifica se uma string str1 é menor que outra str2
int menor_que(String *str1, String *str2) {
    return strcmp(str1->data, str2->data) < 0;
}

// 12) Função que verifica se uma string (str1) é igual a outra (str2)
int igual(String *str1, String *str2) {
    return strcmp(str1->data, str2->data) == 0;
}

// 13) Busca a posição local na string str1 em que a string subs se inicia
int busca_substring(String *str, const char *subs) {
    char *pos = strstr(str->data, subs);
    if (pos == NULL) {
        return -1;
    } else {
        return pos - str->data;
    }
}

// Função para liberar a memória da string dinâmica
void destroi_string(String *str) {
    free(str->data);
    free(str);
}

int main() {
    // Teste das funções
    String *str1 = cria_string();
    String *str2 = cria_string();
    String *str3 = cria_string();

    insere_char(str1, 'H');
    insere_char(str1, 'e');
    insere_char(str1, 'l');
    insere_char(str1, 'l');
    insere_char(str1, 'o');

    exibe_string(str1);

    copia_string(str1, str2);
    exibe_string(str2);

    insere_char(str2, '!');
    exibe_string(str2);

    concatena_string(str1, str2, str3);
    exibe_string(str3);

    remove_chars(str3, 5, 2);
    exibe_string(str3);

    insere_substring(str3, " World", 5);
    exibe_string(str3);

    exibe_string_invertida(str3);

    printf("Tamanho: %d\n", tamanho_string(str3));

    printf("Menor que: %d\n", menor_que(str1, str2));
    printf("Igual: %d\n", igual(str1, str2));

    printf("Posicao da substring: %d\n", busca_substring(str3, "World"));

    // Liberação da memória
    destroi_string(str1);
    destroi_string(str2);
    destroi_string(str3);

    return 0;
}

