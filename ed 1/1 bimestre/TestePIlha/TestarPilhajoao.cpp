#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <ctype.h>
#include <string.h>
#include "TADPilha.h"

char Menu(void)
{
	clrscr();
	printf("\n## Operacoes com Pilha ##\n");
	printf("[A] Inicializar\n");
	printf("[B] Empilhar (PUSH)\n");
	printf("[C] Desempilhar (POP)\n");
	printf("[D] Elemento do TOPO\n");
	printf("[E] Exibir a Pilha\n");
	printf("[F] Exerc.01 - Concatenacao de Pilhas\n");
	printf("[G] Exerc.02 - Exclusao de Elementos\n");
	printf("[H] Exerc.05 - Vetor de Elementos inverso\n");
	printf("[I] Exerc.06 - Arquivo texto via parametro\n");
	printf("[ESC] Sair\n");
	printf("\nOpcao: ");
	return toupper(getche());
}
char LeElemento(void)
{
	printf("\nDigite o caracter: ");
	return getche();
}

void InserirElementos(TpPilha &P)//porque por parametro
{
	char Elem;
	Inicializar(P);//inicializa aqui dentro
	printf("\nDigite os elementos...[ESC para sair]\n");
	Elem = getche();
	while (Elem!=27 && !PilhaCheia(P.TOPO))
	{
		PUSH(P,Elem);//colocs o que eu digitei no P
		Elem = getche();
	}
	printf("\nElementos inseridos na PILHA!\n");
	getch();
}

void Concatenacao(TpPilha &P1, TpPilha P2)
{
	TpPilha P3;
	Inicializar(P3);
	while (!PilhaVazia(P2.TOPO))
		PUSH(P3,POP(P2));
	
	while (!PilhaVazia(P3.TOPO) && !PilhaCheia(P1.TOPO))
			PUSH(P1,POP(P3));
}

void ExcluirElemen(TpPilha &P,char Ele)
{
	TpPilha Paux;
	if(!PilhaVazia(P.TOPO))
	{
		Inicializar(Paux);
		while(ElementoTopo(P)!=Ele)//vendo se o aux nao está cheio 
			PUSH(Paux,POP(P));
			
		POP(P);//desempilha a pilha 1
		
		while(!PilhaCheia(P.TOPO) && !PilhaVazia(Paux.TOPO))
			PUSH(P,POP(Paux));
			
		printf("\nElemento excluido");
	}	
	else printf("\nPilha Vazia!\n");
}

void VetorExercicio(int vet[MAXPILHA], int tl)
{
	int i;
	TpPilha P3;
	Inicializar(P3);
	
	printf("\nPreencha o vetor");
    for (int i = 0; i < tl && vet[i] != 0; i++) {
        printf("\nPos_%d: ", i + 1);
        scanf("%d", &vet[i]);
    }
	
	i=0;
	while(i<=tl && !PilhaCheia(P3.TOPO))
	{
		PUSH(P3,vet[i]);
		i++;
	}
	printf("\nElementos inseridos na PILHA!\n");
	
	i=0;
	POP(P3);//pra nao pegar o topo vazio
	while(i<=tl)
	{
		vet[i]=POP(P3);
		i++;
	}
	
	for (int i = 0; i < tl; i++) {
        printf("%d ", vet[i]);
    }
	
}

void TextoParapilha() {
    FILE *PtrTxt = fopen("texto.txt", "a");
    FILE *PtrAux = fopen("invertido.txt", "w+");
    char linha[MAXPILHA], caracter;
    TpPilha P4;
    Inicializar(P4);

    if (PtrTxt == NULL || PtrAux == NULL)
	{
        printf("\nErro ao abrir os arquivos\n");
        return;
    }
	 else 
	 {
        printf("\nDigite o texto:");
        fflush(stdin);
        fgets(linha, MAXPILHA, stdin);

        while (strcmp(linha, "\n") != 0) {
            fputs(linha, PtrTxt);
            fputs("\n", PtrTxt);

            fflush(stdin);
            fgets(linha, MAXPILHA, stdin);
        }

        printf("\nElementos inseridos no Arquivo texto!\n");
        fclose(PtrTxt); // fechando o primeiro arquivo

        PtrTxt = fopen("texto.txt", "r");
        // rewind(PtrTxt);
        while (!PilhaCheia(P4.TOPO)) {
            caracter = fgetc(PtrTxt);
            PUSH(P4,caracter);
        }
        
        printf("\nElemento topo: %c\n", ElementoTopo(P4));
        rewind(PtrTxt);
        while(!PilhaVazia(P4.TOPO)) 
		{
			caracter = POP(P4);
			fputc(caracter, PtrAux);
		}
        printf("\nElementos invertidos com sucesso!\n");
	}
	
    fclose(PtrTxt);
    fclose(PtrAux);
}

int main(void)
{
	TpPilha Pilha, Pilha2;
	char op,texto[30];
	
	
	int vet[MAXPILHA],tl=7;
	do
	{
		op = Menu();
		switch (op)
		{
			case '1':	InserirElementos(Pilha);
						break;
						
			case 'A':	Inicializar(Pilha);
						printf("\nPilha Inicializada!\n");
						break;
						
			case 'B':	printf("\nInserir elemento...\n");
						if (!PilhaCheia(Pilha.TOPO))
						{
							PUSH(Pilha,LeElemento());
							printf("\nElemento Empilhado!\n");
						}
						else printf("\nPilha Cheia!\n");
						break;
						
			case 'C':	printf("\nRetirar elemento...\n");
						if(!PilhaVazia(Pilha.TOPO))
							printf("\nElemento Desempilhado: %c\n",POP(Pilha));
						else printf("\nPilha Vazia!\n");
						break;
						
			case 'D':	if(!PilhaVazia(Pilha.TOPO))
							printf("\nElemento do TOPO: %c\n",ElementoTopo(Pilha));
						else printf("\nPilha Vazia!\n");
						break;
						
			case 'E':	printf("\nConteudo da Pilha:\n");
						if(!PilhaVazia(Pilha.TOPO))
							ExibirPilha(Pilha);
						else printf("\nPilha Vazia!\n");
						break;
						
			case 'F':  printf("\nConcatenar PIlhas\n");
					   printf("\nPILHA 1:\n");
					   InserirElementos(Pilha);
					   printf("\nPILHA 2:\n");
					   InserirElementos(Pilha2);
					   Concatenacao(Pilha,Pilha2);
					   printf("\nResultado da Concatenacao\n");
					   ExibirPilha(Pilha);
					   getch();
					   break;
					   
			case 'G': printf("\n##Excluir elemento da Pilha##\n");
					  clrscr();
					  gotoxy(3,3);
					  ExibirPilha(Pilha);
					  printf("\nDigite um elemento para excluir: ");
				      op = getche();
					  ExcluirElemen(Pilha,op);
					  break;
					  
			case 'H': printf("\n##Vetor de Elementos inverso##\n");
					  if(!PilhaVazia(Pilha.TOPO))
					  	VetorExercicio(vet,tl);
					  else printf("\nPilha Vazia!\n");
					  break;
					  
			case 'I': printf("\n##Arquivo texto via parametro##\n");
					  TextoParapilha();
					  break;
			
		}
		getch();
	}while (op!=27);
	return 0;
}
