#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CAIXAS 4

typedef struct {
    int fila[NUM_CAIXAS][100]; // Filas de cada caixa
    int tempo_atendimento[NUM_CAIXAS]; // Tempos de atendimento para cada caixa
    int clientes_atendidos;
} Supermercado;

void inicializar(Supermercado *supermercado) {
    // Inicializa as filas vazias
    for (int i = 0; i < NUM_CAIXAS; i++) {
        for (int j = 0; j < 100; j++) {
            supermercado->fila[i][j] = 0;
        }
    }
    // Define os tempos de atendimento para cada caixa
    supermercado->tempo_atendimento[0] = 5;
    supermercado->tempo_atendimento[1] = 2;
    supermercado->tempo_atendimento[2] = 4;
    supermercado->tempo_atendimento[3] = 7;
    supermercado->clientes_atendidos = 0;
}

void chegada_cliente(Supermercado *supermercado, int tempo_simulacao) {
    int chegada = rand() % 3 + 1; // A cada 3 unidades de tempo uma pessoa chega
    for (int i = 0; i < chegada; i++) {
        int caixa_escolhido = rand() % NUM_CAIXAS;
        for (int j = 0; j < 100; j++) {
            if (supermercado->fila[caixa_escolhido][j] == 0) {
                supermercado->fila[caixa_escolhido][j] = tempo_simulacao;
                break;
            }
        }
    }
}

void atendimento_caixas(Supermercado *supermercado, int tempo_simulacao) {
    for (int i = 0; i < NUM_CAIXAS; i++) {
        if (supermercado->fila[i][0] != 0 && (tempo_simulacao - supermercado->fila[i][0]) % supermercado->tempo_atendimento[i] == 0) {
            for (int j = 0; j < 100; j++) {
                if (supermercado->fila[i][j] != 0) {
                    supermercado->fila[i][j] = 0;
                    supermercado->clientes_atendidos++;
                    break;
                }
            }
        }
    }
}

float simular(Supermercado *supermercado, int tempo_total) {
    int tempo_simulacao = 0;
    while (tempo_simulacao < tempo_total) {
        chegada_cliente(supermercado, tempo_simulacao);
        atendimento_caixas(supermercado, tempo_simulacao);
        tempo_simulacao++;
    }
    return (float)tempo_total / supermercado->clientes_atendidos;
}

int main() {
    srand(time(NULL));
    Supermercado supermercado;
    inicializar(&supermercado);
    int tempo_total_simulacao = 10000; // Tempo total da simulação
    float tempo_medio = simular(&supermercado, tempo_total_simulacao);
    printf("Tempo medio de atendimento por cliente: %.2f\n", tempo_medio);
    return 0;
}

