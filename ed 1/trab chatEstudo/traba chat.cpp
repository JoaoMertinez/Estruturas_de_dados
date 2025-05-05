#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EDITORAS 100
#define NOME_TAMANHO 100
#define TF 100

typedef struct TpAutores {
    char sobrenome[TF];
    char nome[TF];
    struct TpAutores *prox;
} TpAutores;

typedef struct TpLista_autor {
    TpAutores *autor;
    struct TpLista_autor *prox;
} TpLista_autor;

typedef struct TpLivro {
    char titulo[TF];
    int ano;
    int paginas;
    TpLista_autor *pAutor;
    struct TpLivro *prox;
    struct TpLivro *ant;
} TpLivro;

typedef struct TpEditoras {
    char editora[TF];
    TpLivro *pLivros;
    struct TpEditoras *prox;
} TpEditoras;

typedef struct TpBiblioteca {
    char autores[TF];
    char titulo_livro[TF];
    char editora[TF];
    int ano;
    int paginas;
} TpBiblioteca;

typedef struct TpDescritor {
    TpEditoras *inicio;
} TpDescritor;

void inicializarDescritor(TpDescritor *desc) {
    desc->inicio = NULL;
}

TpEditoras *novaCaixaEditoras(char *nomeEditora) {
    TpEditoras *novaEditora = (TpEditoras *)malloc(sizeof(TpEditoras));
    strcpy(novaEditora->editora, nomeEditora);
    novaEditora->pLivros = NULL;
    novaEditora->prox = NULL;
    return novaEditora;
}

TpAutores *novaCaixaAutores(char *sobrenome, char *nome) {
    TpAutores *novoAutor = (TpAutores *)malloc(sizeof(TpAutores));
    strcpy(novoAutor->sobrenome, sobrenome);
    strcpy(novoAutor->nome, nome);
    novoAutor->prox = NULL;
    return novoAutor;
}

TpLivro *novaCaixaLivro(char *titulo, int ano, int paginas) {
    TpLivro *novoLivro = (TpLivro *)malloc(sizeof(TpLivro));
    strcpy(novoLivro->titulo, titulo);
    novoLivro->ano = ano;
    novoLivro->paginas = paginas;
    novoLivro->pAutor = NULL;
    novoLivro->prox = NULL;
    novoLivro->ant = NULL;
    return novoLivro;
}

void inserirLivro(TpEditoras *editora, TpLivro *livro) {
    if (editora->pLivros == NULL) {
        editora->pLivros = livro;
        livro->prox = NULL;
        livro->ant = NULL;
    } else {
        livro->prox = editora->pLivros;
        livro->ant = NULL;
        if (editora->pLivros != NULL) {
            editora->pLivros->ant = livro;
        }
        editora->pLivros = livro;
    }
}

TpAutores *inserirAutor(TpAutores *listaA) {
    TpBiblioteca biblioteca;
    int num = 1, i = 0, j = 0;
    char nome[TF], sobrenome[TF];

    FILE *ptr = fopen("livros.dat", "rb");
    if (ptr == NULL) {
        printf("Erro ao abrir o arquivo binário!\n");
        return listaA;
    }

    fread(&biblioteca, sizeof(TpBiblioteca), 1, ptr);
    while (!feof(ptr)) {
        num = 1;
        i = 0;
        while (biblioteca.autores[i] != '\0') {
            if (biblioteca.autores[i] == ';')
                num++;
            i++;
        }
        i = 0;
        while (num > 0) {
            int cont = 0;
            while (biblioteca.autores[i] != ',' && biblioteca.autores[i] != '\0') {
                sobrenome[cont] = biblioteca.autores[i];
                i++;
                cont++;
            }
            sobrenome[cont] = '\0';
            i++;
            cont = 0;

            while (biblioteca.autores[i] != ';' && biblioteca.autores[i] != '\0') {
                nome[cont] = biblioteca.autores[i];
                i++;
                cont++;
            }
            nome[cont] = '\0';

            TpAutores *autor = novaCaixaAutores(sobrenome, nome);
            if (listaA == NULL) {
                listaA = autor;
            } else {
                autor->prox = listaA;
                listaA = autor;
            }
            if (biblioteca.autores[i] == ';') {
                i++;
            }
            num--;
        }
        fread(&biblioteca, sizeof(TpBiblioteca), 1, ptr);
    }
    fclose(ptr);
    return listaA;
}

void inserirAlocDinamica(TpBiblioteca biblioteca, TpDescritor *desc, TpAutores *listaA) {
    FILE *ptr = fopen("livros.dat", "rb");
    if (ptr == NULL) {
        printf("Erro ao abrir o arquivo binário!\n");
        return;
    }

    fread(&biblioteca, sizeof(TpBiblioteca), 1, ptr);

    while (!feof(ptr)) {
        TpLivro *ncL = novaCaixaLivro(biblioteca.titulo_livro, biblioteca.ano, biblioteca.paginas);
        TpLista_autor *ncLA;
        int num = 1, i = 0, j = 0;

        while (biblioteca.autores[i] != '\0') {
            if (biblioteca.autores[i] == ';')
                num++;
            i++;
        }
        i = 0;
        while (num > 0) {
            char sobrenome[TF], nome[TF];
            int cont = 0;
            while (biblioteca.autores[i] != ',' && biblioteca.autores[i] != '\0') {
                sobrenome[cont] = biblioteca.autores[i];
                i++;
                cont++;
            }
            sobrenome[cont] = '\0';
            i++;
            cont = 0;

            while (biblioteca.autores[i] != ';' && biblioteca.autores[i] != '\0') {
                nome[cont] = biblioteca.autores[i];
                i++;
                cont++;
            }
            nome[cont] = '\0';

            TpAutores *auxA = listaA;
            while (auxA != NULL && (strcmp(auxA->sobrenome, sobrenome) != 0 || strcmp(auxA->nome, nome) != 0)) {
                auxA = auxA->prox;
            }

            ncLA = (TpLista_autor *)malloc(sizeof(TpLista_autor));
            ncLA->autor = auxA;
            ncLA->prox = ncL->pAutor;
            ncL->pAutor = ncLA;

            if (biblioteca.autores[i] == ';') {
                i++;
            }
            num--;
        }

        TpEditoras *auxEditora = desc->inicio;

        while (auxEditora != NULL && strcmp(auxEditora->editora, biblioteca.editora) != 0) {
            auxEditora = auxEditora->prox;
        }

        if (auxEditora == NULL) {
            auxEditora = novaCaixaEditoras(biblioteca.editora);
            auxEditora->prox = desc->inicio;
            desc->inicio = auxEditora;
        }

        inserirLivro(auxEditora, ncL);

        fread(&biblioteca, sizeof(TpBiblioteca), 1, ptr);
    }

    fclose(ptr);
}

// Função para importar livros do arquivo de texto para binário
void importarLivros() {
    FILE *texto = fopen("livros.txt", "r");
    FILE *binario = fopen("livros.dat", "wb");
    if (texto == NULL || binario == NULL) {
        printf("Erro ao abrir os arquivos!\n");
        return;
    }

    TpBiblioteca biblioteca;

    while (fscanf(texto, "%[^|]|%[^|]|%[^|]|%d|%d\n", biblioteca.autores, biblioteca.titulo_livro, biblioteca.editora, &biblioteca.ano, &biblioteca.paginas) != EOF) {
        fwrite(&biblioteca, sizeof(TpBiblioteca), 1, binario);
    }

    fclose(binario); // Fecha o arquivo binário depois de escrever

    // Reabre o arquivo binário para leitura
    binario = fopen("livros.dat", "rb");
    if (binario == NULL) {
        printf("Erro ao reabrir o arquivo binario!\n");
        fclose(texto);
        return;
    }

    printf("Arquivo importado com sucesso\n");
    fclose(binario);
    fclose(texto);
}

// Função para listar editoras e seus livros
void listarEditoras(TpDescritor *desc) {
    TpEditoras *aux = desc->inicio;
    while (aux != NULL) {
        printf("Editora: %s\n", aux->editora);
        TpLivro *livro = aux->pLivros;
        while (livro != NULL) {
            printf("  Livro: %s\n", livro->titulo);
            livro = livro->prox;
        }
        aux = aux->prox;
    }
}

// Função para listar todos os livros com autores
void listarLivros(TpDescritor *desc) {
    TpEditoras *editora = desc->inicio;
    while (editora != NULL) {
        printf("\nEditora: %s\n", editora->editora);
        TpLivro *livro = editora->pLivros;
        while (livro != NULL) {
            printf("  Livro: %s, Ano: %d, Páginas: %d\n", livro->titulo, livro->ano, livro->paginas);
            TpLista_autor *autores = livro->pAutor;
            while (autores != NULL) {
                printf("    Autor: %s, %s\n", autores->autor->sobrenome, autores->autor->nome);
                autores = autores->prox;
            }
            livro = livro->prox;
        }
        editora = editora->prox;
    }
}

void excluirLivroPorNome(TpDescritor *desc, char *nomeLivro) {
  TpEditoras *editoraAtual = desc->inicio;
  TpLivro *livroAnterior = NULL;
  TpLivro *livroAux = NULL;

  // Percorre a lista de editoras
  while (editoraAtual != NULL) {
    livroAnterior = NULL;
    livroAux = editoraAtual->pLivros;

    // Percorre a lista de livros da editora atual
    while (livroAux != NULL) {
      if (strcmp(livroAux->titulo, nomeLivro) == 0) {
        // Livro encontrado!

        // Remove o livro da lista de livros da editora
        if (livroAnterior == NULL) {
          // Livro é o primeiro da lista
          editoraAtual->pLivros = livroAux->prox;
        } else {
          // Livro está no meio ou no final da lista
          livroAnterior->prox = livroAux->prox;
        }
        free(livroAux); // Libera a memória alocada para o livro
        printf("Livro excluido com sucesso da editora %s!\n", editoraAtual->editora);

        // Verifica se a editora ainda possui livros
        if (editoraAtual->pLivros == NULL) {
          // A editora não possui mais livros:
          // Remove a editora da lista de editoras
          TpEditoras *editoraAnterior = NULL;
          TpEditoras *editoraAux = desc->inicio;
          while (editoraAux != NULL) {
            if (editoraAux == editoraAtual) {
              // Encontramos a editora na lista
              if (editoraAnterior == NULL) {
                // Editora é a primeira da lista
                desc->inicio = editoraAux->prox;
              } else {
                // Editora está no meio ou no final da lista
                editoraAnterior->prox = editoraAux->prox;
              }
              free(editoraAux); // Libera a memória alocada para a editora
              printf("Editora %s excluida por nao possuir mais livros!\n", editoraAtual->editora);
              break;
            }
            editoraAnterior = editoraAux;
            editoraAux = editoraAux->prox;
          }
        }

        return; // Livro excluído, retorna da função
      }

      livroAnterior = livroAux;
      livroAux = livroAux->prox;
    }

    editoraAtual = editoraAtual->prox;
  }

  // Livro não encontrado
  printf("Livro %s nao encontrado!\n", nomeLivro);
}

// Menu para teste do arquivo
void menu() {
    printf("\n");
    printf("##Escolha uma opcao##\n");
    printf("1. Importar livros do arquivo de texto para binario\n");
    printf("2. Alocar na memoria\n");
    printf("3. Mostrar todos os livros\n");
    printf("4. Listar editoras\n");
    printf("5. Excluir livro\n");
    printf("0. Encerrar programa\n");
}

int main() {
    int opcao;
    char nome[NOME_TAMANHO];
    TpDescritor desc;
    inicializarDescritor(&desc);

    TpBiblioteca biblioteca;
    TpAutores *listaA = NULL;

    do {
        menu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();  // Consumir o '\n' deixado pelo scanf
        switch (opcao) {
            case 1:
                printf("Opcao 1 selecionada\n");
                importarLivros();  // importou
                break;

            case 2:
                printf("Opcao 2 selecionada: Alocar dinamicamente\n");
                listaA = inserirAutor(listaA);
                inserirAlocDinamica(biblioteca, &desc, listaA); // alocou
                break;

            case 3:
                printf("Opcao 3 selecionada\n");
                listarLivros(&desc); // mostrou
                break;

            case 4:
                printf("Opcao 4 selecionada\n");
                listarEditoras(&desc); // mostrou
                break;
                
            case 5:
            	printf("Opcao 5 selecionada\n");
            	printf("\nDigite o nome do livro para exclusao");
            	fflush(stdin);
            	gets(nome);
            	excluirLivroPorNome(&desc,nome);
            	
            case 0:
                printf("Encerrando programa...\n");
                break;

            default:
                printf("Opcao invalida\n");
        }
    } while (opcao != 0);

    return 0;
}

