#include <stdio.h>
#include <ctype.h>
#include <conio2.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
	
#include "TadPilha.h"
#include "TADPilhaM2.h"
#include "TADPilhaM1.h"


//falta atribuir o valor da tabela ascii dos elementos
void Embaralhar(struct TpBaralho baralho[], int tamanho)
{
	srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios
	int i;
	
	for (i = tamanho - 1; i > 0; i--)
	{
	    int j = rand() % (i + 1);
	    TpBaralho temp = baralho[i];
	    baralho[i] = baralho[j];
	    baralho[j] = temp;
	}
}

//Função que gera o baralho dentro de uma struct
void gerarBaralho(struct TpBaralho baralho[], int tamanho)
{
    int i, j, k = 0;
    
    char vetNaipe[4] = {'O', 'E', 'C', 'P'};
    int vetValor[13] = {'A', 2, 3, 4, 5, 6, 7, 8, 9, 10, 'J', 'Q', 'K'};
    
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 13; j++)
        {
            baralho[k].naipe = vetNaipe[i];
            baralho[k].cartas = vetValor[j];

            if (vetNaipe[i] == 'E' || vetNaipe[i] == 'P') 
                baralho[k].cor = 'P'; // Preto
			else 
                baralho[k].cor = 'V'; // Vermelho
                
            baralho[k].status = 0;

            k++;
        }
    }
}

void empilharBaralho(TpBaralho baralho[], int tamanho, TpPilha &P){
	//puxa o vetor para a função com a Pilha para comparar enquanto nao seja fim da 
	//pilha e nao for fim do vetor, coloca na pilha p/ usar depois
	TpBaralho carta;
	for(int i=0; i<tamanho && !cheia(P.topo);i++)
	{
		carta.status = baralho[i].status;//ativo - virado pra cima
		carta.naipe = baralho[i].naipe; //pegando os naipes da struct e jogando para outra
		carta.cartas = baralho[i].cartas; //pegando os valores da struct e jogando para outra
		carta.cor = baralho[i].cor;
		push(P,carta); //jogando os valores da struct carta e empilhando
	}
}

/*
char PodeJogarPaciencia(TpBaralho cartaOrigem, TpBaralho carta Destino)
{
	return (cartaOrigem.cor != cartaDestino.cor) && (cartaOrigem.cartas == cartaDestino.cartas - 1);
}
*/

void distribuirCartas(TpPilha &P, TpPilha vetPilhas[], int qtdeP)
{
    /* Inicializa cada pilha do vetor
    for (int i = 0; i < qtdeP; i++)
        inicializar(vetPilhas[i]);
        */

    // Distribui as cartas conforme a quantidade desejada em cada pilha
    for (int i = 0; i < qtdeP; i++)
	{
        for (int j = 0; j < i + 1; j++)
		{
            if(!vazia(P.topo))
			{
                TpBaralho carta = pop(P); // Retira uma carta da pilha original
                push(vetPilhas[i], carta); // Coloca a carta na pilha correspondente
            }
        }
    }
}

//funçao que eu estava fazendo mas deu errado
void PilhasJogo(TpPilhaM &PM2,TpPilha &P)//no momento só as 7
{
	//J=COLUNA    I=LINHA
	
	
	int numCarta=1, i, j, npc = 0;//contador para impalhar - exemplo na primeira pilha ele empilha 1 na segunda 2 e por ai vai
	TpBaralho baralho;
	//mostrarBaralho(baralho,maxpilha);
	for(i=0; i<7; i++)
	{
		baralho = pop(P);
		baralho.status = 1;
		push(P,baralho);
		PUSHM(PM2,pop(P),npc);
		for(j=1; j < numCarta; j++)//aqui temos um problema, pois as pilhas de fundaçao podem ter ate 13 cartas e as pilhas normais ate 7
		{
			PUSHM(PM2,pop(P),npc);
		}
		
		npc++;
		if(numCarta < 7)//sla oque to fazendo
			numCarta++;
	}
	
	
	/*TpBaralho teste;//para mostrar o topo
	teste = elementoTopoM(PM2,1);
	printf("\nValor da Carta: %d",teste.cartas);//ta pegando lixo
	*/
	
	getch();
	/*i=0;
	exibirPilhaM(PM2,i);
	*/
}

//Função que contém todas as regras da gameplay de alto nivel
void validacaoCompra(TpPilhaM1 &pm1, TpPilhaM &pm2, int NP)
{
	TpBaralho carta, aux, auxJogo;
	//carta = POPM1(pm1,np);
	//aux = carta; 
	//carta.cor == aux.cor && carta.cartas == aux.cartas-1
	
	//verificação para mover uma carta da pilha de compara para o monte de ganhar
	carta = ElementoTOPOM1(pm1,2); //monte de compra
	if(NP>=7 && NP<=10)
	{
		aux = elementoTopoM(pm2,NP); //monte de fundação
		if(!PMVazia(pm2,NP))
		{
			if(aux.cartas == 'A')
			{
				if(carta.naipe == aux.naipe && carta.cartas == 2)
				{
					//MOVER A CARTA DO USUARIO E SE QUISER EXIBIR UMA MENSAGEM DIZENDO QUE DEU CERTO
					PUSHM(pm2,POPM1(pm1,2),NP);
				}
				else
				{
					//EXIBIR MENSAGEM QUE NÃO PODE EXECUTAR A MOVIMENTAÇÃO
				}
			}
			else
			if(aux.cartas == 10)
			{
				if(carta.naipe == aux.naipe && carta.cartas == 'J')
				{
					//MOVER A CARTA DO USUARIO E SE QUISER EXIBIR UMA MENSAGEM DIZENDO QUE DEU CERTO
					PUSHM(pm2,POPM1(pm1,2),NP);
				}
				else
				{
					//EXIBIR MENSAGEM QUE NÃO PODE EXECUTAR A MOVIMENTAÇÃO
				}
			}
			else
			if(aux.cartas == 'J')
			{
				if(carta.naipe == aux.naipe && carta.cartas == 'Q')
				{
					//MOVER A CARTA DO USUARIO E SE QUISER EXIBIR UMA MENSAGEM DIZENDO QUE DEU CERTO
					PUSHM(pm2,POPM1(pm1,2),NP);
				}
				else
				{
					//EXIBIR MENSAGEM QUE NÃO PODE EXECUTAR A MOVIMENTAÇÃO
				}
			}
			else
			if(aux.cartas == 'Q')
			{
				if(carta.naipe == aux.naipe && carta.cartas == 'K')
				{
					//MOVER A CARTA DO USUARIO E SE QUISER EXIBIR UMA MENSAGEM DIZENDO QUE DEU CERTO
					PUSHM(pm2,POPM1(pm1,2),NP);
				}
				else
				{
					printf("Nao e possivel de acordo com as regras");
				}
			}
			
			if(carta.naipe == aux.naipe && aux.cartas+1 == carta.cartas)
			{
				//MOVER A CARTA DO USUARIO E SE QUISER EXIBIR UMA MENSAGEM DIZENDO QUE DEU CERTO
				PUSHM(pm2,POPM1(pm1,2),NP);
			}
			else
			{
				printf("Nao e possivel de acordo com as regras");
			}
			
			
		}
		else //se caso o monte for vazio
		{
			if(carta.cartas == 'A')
			{
				//EXIBIR MENSAGEM QUE O 'A' FOI ADICIONADO
				PUSHM(pm2,POPM1(pm1,2),NP);
			}
		}
	}
	else
	if(NP>=0 && NP<=6)//verificação do monte de compra para o monte de jogo
	{
		auxJogo = elementoTopoM(pm2,NP); //monte de jogo
		if(auxJogo.cartas == 2)
		{
			if(carta.naipe == aux.naipe && carta.cartas == 'A')
			{
				//MOVER A CARTA DO USUARIO E SE QUISER EXIBIR UMA MENSAGEM DIZENDO QUE DEU CERTO
				PUSHM(pm2,POPM1(pm1,2),NP);
			}
			else
			{
				printf("Nao é possivel de acordo com as regras");
			}
		}
		else
		if(auxJogo.cartas == 'J')
		{
			if(carta.cor != auxJogo.cor && carta.cartas == 10)
			{
		 		//MOVER A CARTA DO USUARIO E SE QUISER EXIBIR UMA MENSAGEM DIZENDO QUE DEU CERTO
				PUSHM(pm2,POPM1(pm1,2),NP);
		 	}
		 	else
		 	{
		 		printf("Nao é possivel de acordo com as regras");
		 	}
		 	
		}
		else
		if(auxJogo.cartas == 'Q')
		{
		 	if(carta.cor != auxJogo.cor && carta.cartas == 'J')
		 	{
		 		//MOVER A CARTA DO USUARIO E SE QUISER EXIBIR UMA MENSAGEM DIZENDO QUE DEU CERTO
				PUSHM(pm2,POPM1(pm1,2),NP);
		 	}
		 	else
		 	{
		 		printf("Nao é possivel de acordo com as regras");
		 	}
		}
		else
		if(auxJogo.cartas == 'K')
		{
		 	if(carta.cor != auxJogo.cor && carta.cartas == 'Q')
		 	{
		 		//MOVER A CARTA DO USUARIO E SE QUISER EXIBIR UMA MENSAGEM DIZENDO QUE DEU CERTO
				PUSHM(pm2,POPM1(pm1,2),NP);
		 	}
		 	else
		 	{
				printf("Nao é possivel de acordo com as regras");			 	}
		}
		if(carta.cor != auxJogo.cor && auxJogo.cartas-1 == carta.cartas)
		{
			//MOVER A CARTA DO USUARIO E SE QUISER EXIBIR UMA MENSAGEM DIZENDO QUE DEU CERTO
			PUSHM(pm2,POPM1(pm1,2),NP);
		}
		else
		{
			printf("Nao é possivel de acordo com as regras");
		}
	}
}

//Função que vai ter as regras entre as pilhas de jogo
void validaPilhas(TpPilhaM &pm2, int npO, int npD) // O=ORIGEM | D=DESTINO
{
    TpBaralho cartaO, cartaD;

    cartaO = elementoTopoM(pm2, npO);
    cartaD = elementoTopoM(pm2, npD);

    if (npO >= 0 && npO <= 6)
    {
        if (npD >= 7 && npD <= 10) // SE CASO ELE FOR MOVER DA PILHA DE JOGO PARA PILHA DE FUNDAÇÃO
        {
            if (cartaD.cartas == 'A')
            { 
                if (cartaD.naipe == cartaO.naipe && cartaO.cartas == 2)
                {
                    PUSHM(pm2, POPM(pm2, npO), npD);
                    return; // Movimento realizado com sucesso
                }
                else
					printf("Impossivel fazer a alteração\n");
            }
            else if (cartaD.cartas == 10)
            {
                if (cartaD.naipe == cartaO.naipe && cartaO.cartas == 'J')
                {
                    PUSHM(pm2, POPM(pm2, npO), npD);
                    return; // Movimento realizado com sucesso
                }
                else 
					printf("Impossivel fazer a alteração\n");
            }
            else if (cartaD.cartas == 'J')
            {
                if (cartaD.naipe == cartaO.naipe && cartaO.cartas == 'Q')
                {
                    PUSHM(pm2, POPM(pm2, npO), npD);
                    return; // Movimento realizado com sucesso
                }
                else
				printf("Impossivel fazer a alteração\n");
            }
            else if (cartaD.cartas == 'Q')
            {
                if (cartaD.naipe == cartaO.naipe && cartaO.cartas == 'K')
                {
                    PUSHM(pm2, POPM(pm2, npO), npD);
                    return; // Movimento realizado com sucesso
                }
                else
					printf("Impossivel fazer a alteração\n");
            }

            if (cartaD.naipe == cartaO.naipe && cartaO.cartas - 1 == cartaD.cartas)
            {
                PUSHM(pm2, POPM(pm2, npO), npD);
                return; // Movimento realizado com sucesso
            }
            else 
				printf("Impossivel fazer a alteração\n");

            // Exibir mensagem que não é possível executar a movimentação
        }
        else if (npD >= 0 && npD <= 6) // SE CASO ELE FOR MOVER DA PILHA DE JOGO PARA PILHA DE JOGO
        {
            if (cartaD.cartas == 2)
            {
                if (cartaO.cor != cartaD.cor && cartaO.cartas == 'A')
                {
                    PUSHM(pm2, POPM(pm2, npO), npD);
                    return; // Movimento realizado com sucesso
                }
                else 
					printf("Impossivel fazer a alteração\n");
            }
            else if (cartaD.cartas == 'J')
            {
                if (cartaO.cor != cartaD.cor && cartaO.cartas == 10)
                {
                    PUSHM(pm2, POPM(pm2, npO), npD);
                    return; // Movimento realizado com sucesso
                }
                else 
					printf("Impossivel fazer a alteração\n");
            }
            else if (cartaD.cartas == 'Q')
            {
                if (cartaO.cor != cartaD.cor && cartaO.cartas == 'J')
                {
                    PUSHM(pm2, POPM(pm2, npO), npD);
                    return; // Movimento realizado com sucesso
                }
                else 
					printf("Impossivel fazer a alteração\n");
            }
            else if (cartaD.cartas == 'K')
            {
                if (cartaO.cor != cartaD.cor && cartaO.cartas == 'Q')
                {
                    PUSHM(pm2, POPM(pm2, npO), npD);
                    return; // Movimento realizado com sucesso
                }
                else 
					printf("Impossivel fazer a alteração\n");
            }

            if (cartaO.cor != cartaD.cor && cartaO.cartas + 1 == cartaD.cartas)
            {
                PUSHM(pm2, POPM(pm2, npO), npD);
                return; // Movimento realizado com sucesso
            }
            else 
				printf("Impossivel fazer a alteração\n");

				
        }
    }
    else
    	printf("Opcao Invalida\n");
}
 
TpPilhaM1 comprarCartas(TpPilhaM1 &PM1, TpPilhaM &PM2) {
    TpBaralho carta, aux;
    char op;
    int num;
    int numCompras = 0;
    char opc = ' ';
    
    //ExibirPM1(PM1, 1);
    
    while (opc != '0') { // Loop continua até o usuário digitar '0'
        printf("\n\nDeseja comprar uma carta (S/N) ou digite '0' para encerrar\n");
        scanf(" %c", &opc); // Adiciona um espaço antes do %c para consumir qualquer espaço em branco residual
        opc = toupper(opc);
        
        if (opc == 'S') {
            if (!PM1Vazia(PM1.TOPO1, 1)) { 
                carta = POPM1(PM1, 1);
                carta.status = 1;
                PUSHM1(PM1, carta, 2);
                numCompras++;
                if (numCompras > 3) {
                    printf("\nopa");
                    carta = POPM1(PM1, 2);
                    PUSHM1(PM1, carta, 1);
                    numCompras = 0;
                }
                printf("Carta comprada: ");
                mostrarCarta(carta);
                
                printf("Deseja colocar em alguma pilha?\n");
                scanf(" %c", &op);
                op = toupper(op);
                
                if (op == 'S') {
                    printf("Numero da pilha de destino: ");
                    scanf("%d", &num);
                    validacaoCompra(PM1, PM2, num);
                    //ExibirPM2!!!!!!
                }
            } else {
                if (PM1Vazia(PM1.TOPO1, 1)) {
                    while (!PM1Vazia(PM1.TOPO2, 2)) {
                        aux = POPM1(PM1, 2);
                        aux.status = 0;
                        PUSHM1(PM1, aux, 1);
                    }
                }
                printf("A pilha está vazia\n");
            }
        } else {
            printf("Compra Cancelada\n");
        }
    }
    
    return PM1;
}

void cartasRestantes(TpPilha &P, TpPilhaM1 &PM1)//puxa as cartas que sobraram da pilha normal para a m1
{
	TpBaralho carta;
	TpPilha pilhaAux;
	inicializar(pilhaAux);
	while(!vazia(P.topo)){
		carta = pop(P);
		PUSHM1(PM1,carta,1);
	}
}

/*void moverCartaNoBaralho(TpPilhaM &PM) {
    int origem, destino;

    printf("Digite o numero da pilha de origem: ");
    scanf("%d", &origem);

    printf("Digite o numero da pilha de destino: ");
    scanf("%d", &destino);
	
	
    //validaPilhas(PM, origem, destino);
}*/

void moverCartaNoBaralho(TpPilhaM &PM) {
    int origem, destino;

    // Ler a pilha de origem do usuário
    printf("Digite o numero da pilha de origem: ");
    scanf("%d", &origem);

    // Ler a pilha de destino do usuário
    printf("Digite o numero da pilha de destino: ");
    scanf("%d", &destino);

    // Verificar se as pilhas são válidas
    if (origem < 0 || origem >= MAXPILHA || destino < 0 || destino >= MAXPILHA) {
        printf("Pilha inválida. Tente novamente.\n");
        return;
    }

    // Verificar se há cartas na pilha de origem
    if (PM.TOPO[origem] < 0) {
        printf("Pilha de origem vazia. Tente novamente.\n");
        return;
    }

    // Mover a carta da pilha de origem para a pilha de destino
    TpBaralho cartaMovida = POPM(PM, origem);
    PUSHM(PM, cartaMovida, destino);

    printf("Carta movida com sucesso!\n");
}


void moverCartaNaCompra(TpPilhaM1 PM1)
{
	printf("Selecione a carta que deseja mover ");
	ExibirPM1(PM1,2);
}

char PodeJogarPaciencia(TpBaralho cartaOrigem, TpBaralho cartaDestino)
{
    // Verificar se as cartas são da mesma cor
    if (cartaOrigem.cor == cartaDestino.cor) {
        return 0;
    }

    // Verificar se a carta de origem é um número menor que a carta de destino
    if (cartaOrigem.cartas < cartaDestino.cartas) {
        return 1;
    }

    return 0;
}



//Função que chama a moldura do jogo
void GameFrontMoldura(TpPilhaM &PM, TpPilha &P, TpPilhaM1 P1, int npc) {
    TpBaralho aux;
    int i=0, op;
    
    //aux = elementoTopo(P);
    //printf("\nElemento topo do restante: %d", aux.cartas);
    exibirPilhaM2(PM,i);
    cartasRestantes(P,P1);
    
	do
	{
		textcolor(WHITE);
        printf("\n\nEscolha uma opcao:\n");
        printf("1. Comprar carta\n");
        printf("2. Mover carta no baralho\n");
        printf("3. Mover carta da pilha de compra\n");
    	printf("4. Exibir\n");
        printf("Pressione ESC para sair\n");
        op = tolower(getch());
        switch (op) 
		{
            case '1':
            	comprarCartas(P1,PM);
                break;
            case '2':
                moverCartaNoBaralho(PM);
                break;
            case '3':
            	//exibirPilhaM2(PM, i);
            	break;
            case '4':
            	clrscr();
            	exibirPilhaM2(PM,i);
            	break;
            default:
                printf("opcao invalida. Escolha novamente.\n");
        }
        //clrscr();
    }while (op != 27);
}

int main(void)
{
    /*
    //COMANDO PARA DEIXAR O FUNDO DA TELA VERDE E ASSIM MAIS PARECIDO COM O JOGO REAL!!!
    getch();
    clrscr();
	textbackground(GREEN);
    //clrscr();
    */
    int npBaralho = 7, npc=0, npO, npD; // controle da pilha que estamos mechendo - np coemça de 11 pela conta na inicializaçao da pilha
    int game = 1;
    TpBaralho baralho[maxpilha];  // Declarando o vetor de struct que vai conter o valor das cartas e naipe do nosso baralho
    TpPilha pilha;
    TpPilhaM1 pilhaM1;
    
    while(game != 0)
    {
    	clrscr();
        inicializar(pilha);
        InicializarM1(pilhaM1);
        gerarBaralho(baralho, maxpilha); // Função que gera o baralho, sendo 4 cartas iguais de cada e cada uma com seu naipe diferente
        Embaralhar(baralho, maxpilha);   // Função que faz o embaralhamento das cartas assim o jogo fica com uma senquência aleatoria de cartas
        
        // empilhando o baralho, começar
        empilharBaralho(baralho, maxpilha, pilha);
        
        // ##EXIBIÇAO##//
        // mostrarBaralho(baralho,maxpilha);//exibindo a struct para fazer o teste se esta funcioando certin - e está :) 
        // exibirPilha(pilha);//exibindo a pilha - nao está :(
        
        // Função que inicializa as 7 pilhas para a manipulação
        TpPilhaM pilhasM2;
        inicializarM(pilhasM2, npBaralho);
        PilhasJogo(pilhasM2, pilha); // passando os parametros - nao esquecer de zera o Np na funçao
        // exibirPilhaM(pilhaM,npBaralho);
        
        /* isso nao é aqui
        //Função que chama as validações de compra para teste
        validacaoCompra(pilhaM1,pilhasM2,npc);
        */
        
        /*isso nao é aqui
        //Função que chama as validações de jogo
        validaPilhas(pilhasM2,npO,npD);
        */
        
        // começo de jogo
        while (game != 0) { // Loop para continuar o jogo
            GameFrontMoldura(pilhasM2, pilha, pilhaM1, npc);//AQUI vai acontecer o jogo, favor usar
            
            // Perguntar ao jogador se deseja continuar jogando
            printf("\nDeseja jogar novamente? (0 para sair, outro para continuar): ");
            scanf("%d", &game);
            
            if (game != 0) // Reiniciar o jogo
                break;//nao assumo esse Bo
        }
    }
    return 0;
}
