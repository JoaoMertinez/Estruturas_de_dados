#include <stdio.h>

void moverDisco(int n, char origem, char destino, char auxiliar) {
    if (n == 1) {
        printf("Mova o disco 1 de %c para %c\n", origem, destino);
        return;
    }
    moverDisco(n-1, origem, auxiliar, destino);
    printf("Mova o disco %d de %c para %c\n", n, origem, destino);
    moverDisco(n-1, auxiliar, destino, origem);
}

int main() {
    int n = 3;  // Número de discos
    moverDisco(n, 'A', 'C', 'B');  // A é a haste de origem, C é a haste de destino, B é a haste auxiliar
    return 0;
}
