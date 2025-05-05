#include <stdio.h>


int mdc(int n1, int n2)
{
	if(n2==0)
		return n1;
	else
		return mdc(n2,n1%n2);
}


int main() {
    int questao,n1,n2;

    do {
        printf("Selecione uma questao (1 a 6, ou 0 para sair): ");
        scanf("%d", &questao);

        switch(questao) {
            case 1: printf("Digite o primeiro inteiro positivo: ");
				    scanf("%d", &n1);
				    printf("Digite o segundo inteiro positivo: ");
				    scanf("%d", &n2);
				    if (n1 <= 0 || n2 <= 0) {
				        printf("Invalido\n");
					}
					else
				    	printf("O MDC de %d e %d e: %d\n", n1, n2, mdc(n1, n2));
					break;
					
            /*case 2:
                questao2();
                break;
            case 3:
                questao3();
                break;
            case 4:
                questao4();
                break;
            case 5:
                questao5();
                break;
            case 6:
                questao6();
                break;*/
        }

    } while (questao != 0);

    return 0;
}

