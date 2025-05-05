#include<stdio.h>
#include<conio2.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

//Struct que vai guardar os dados temporariamente
struct TpCidade
{
	char nome[50];
	int populacao;
};

//Função do menu para execução do codigo
char menu(void)
{
	clrscr();
	printf("[A] Validar arquivo\n");
	printf("[B] Cadastrar cidades\n");
	printf("[C] Consultar populacao\n");
	printf("[D] Ordenar pelo nome da cidade\n");
	printf("[E] Exibir conteudo do arquivo\n");
	printf("[F] Ordenar arquivo de forma desc.\n");
	printf("[ESC] Finalizar\n");
	
	return toupper(getch());
}

//Função que faz busca exaustiva da cidade
int buscaCid(FILE *ptr, char nomeBusca[50])
{
	TpCidade cid;
	rewind(ptr);
	fread(&cid,sizeof(TpCidade),1,ptr);
	
	while(!feof(ptr) && strcmp(nomeBusca,cid.nome) != 0)
		fread(&cid,sizeof(TpCidade),1,ptr);
		
	if(!feof(ptr))
		return ftell(ptr) - sizeof(TpCidade);
	else
		return -1;
}

//função que valida se o arquivo já é existente ou não [A]
void validar(void)
{
	FILE *ptr = fopen("cidades.dat","rb");
	
	clrscr();
	printf("VALIDACAO DO ARQUIVO:\n");
	
	if(ptr == NULL)
		printf("Arquivo inexistente!\n\n\n");
	else
	{
		printf("Arquivo existente!\n\n\n");
		fclose(ptr);
	}
		
		
	getch();
}

//Função que faz o cadastro de cidades [B]
void cadCidade(void)
{
	char nomeBusca[50];
	int pos=0;
	
	clrscr();
	
	printf("*** MENU DE CADASTRO DE CIDADE ***\n");

	TpCidade cid;
	FILE *ptr = fopen("cidades.dat","ab+");
	
	if(ptr == NULL)
		printf("Erro na abertura do arquivo!\n");
	else
	{
		do
		{
			printf("\nDigite o nome da cidade: ");
			fflush(stdin);
			gets(cid.nome);
			
			if(strlen(cid.nome) > 1)
			{
				pos = buscaCid(ptr,cid.nome);
			
				if(pos == -1)
				{
					printf("\nDigite a populacao: ");
					scanf("%d",&cid.populacao);
					
					fwrite(&cid,sizeof(TpCidade),1,ptr);
					
					printf("\nCidade cadastrada com sucesso!\n");
				}
				else
					printf("\nCidade ja cadastrada!\n");
			}
		}while(strlen(cid.nome) > 1);
		
		fclose(ptr);
	}
}

//Função que faz consulta da cidade [C]
void consultar(void)
{
	TpCidade cid;
	int pos=0;
	
	clrscr();
	printf("\n*** CONSULTA DE CIDADE ***\n");
	
	FILE *ptr = fopen("cidades.dat","rb");
	
	if(ptr == NULL)
		printf("\nErro na abertura do arquivo!\n");
	else
	{
		printf("\nDigite o nome da cidade para consulta: ");
		fflush(stdin);
		gets(cid.nome);
		
		pos = buscaCid(ptr,cid.nome);
		
		if(pos == -1)
			printf("\nCidade nao encontrada!\n");
		else
		{
			fseek(ptr,pos,0);
			fread(&cid,sizeof(TpCidade),1,ptr);
			
			printf("\n\n*** DADOS DA CIDADE ***\n");
			
			printf("\nNome da cidade: %s",cid.nome);
			printf("\nPopulacao da cidade: %d",cid.populacao);
			
			printf("\n\nConsulta finalizada!\n");
		}
		getch();
		fclose(ptr);
	}
}

//Função que exibe conteudo do arquivo [E]
void exibir(void)
{
	TpCidade cid;
	
	clrscr();
	printf("*** RELATORIO DAS CIDADES ***\n\n");
	
	FILE *ptr = fopen("cidades.dat","rb");
	if(ptr == NULL)
		printf("Erro na abertura do arquivo!\n");
	else
	{
		printf("DADOS DAS CIDADES\n");
		
		fread(&cid,sizeof(TpCidade),1,ptr);
		while(!feof(ptr))
		{
			printf("\nNome da cidade: %s",cid.nome);
			printf("\nPopulacao da cidade: %d\n",cid.populacao);
			
			fread(&cid,sizeof(TpCidade),1,ptr);
		}
		getch();
		fclose(ptr);
	}
}

//Função que ordena o arquivo por nome de cidade [D]
void ordenaCid()
{

	clrscr();
	TpCidade cid1, cid2;
	
	FILE *ptr = fopen("cidades.dat","rb+");
	fseek(ptr,0,2);//jogando pro final pro pos ser verdadeiro
	int i, pos=ftell(ptr)/sizeof(TpCidade);
	
	printf("ORDENACAO DE ARQUIVO PELO NOME DA CIDADE:\n");
	
	if(ptr == NULL)
		printf("Não foi possivel abrir o arquivo para ordenacao!\n");
	else
	{
		while(pos>0)
		{
			for(i=0; i<pos-1; i++)
			{
				fseek(ptr,i*sizeof(TpCidade),0);
				fread(&cid1,sizeof(TpCidade),1,ptr);
				
				fseek(ptr,(i+1)*sizeof(TpCidade),0);
				fread(&cid2,sizeof(TpCidade),1,ptr);
				
				if(strcmp(cid1.nome,cid2.nome) > 0)
				{
					fseek(ptr,i*sizeof(TpCidade),0);
					fwrite(&cid2,sizeof(TpCidade),1,ptr);
					
					fseek(ptr,(i+1)*sizeof(TpCidade),0);
					fwrite(&cid1,sizeof(TpCidade),1,ptr);
				}	
			}
			pos--;
		}
		fseek(ptr,0,2);//continuar de onde parou
		fclose(ptr);
		printf("Ordenacao feita com sucesso!\n");
	}
	getch();
}

//Função que ordena o arquivo em forma descrescente [F]
void ordenaDesc()
{
	
}

int main(void)
{
	char op;
	
	do
	{
		op = menu();
		switch(op)
		{
			case 'A':
				validar();
				
				break;
				
			case 'B':
				cadCidade();
				
				break;
				
			case 'C':
				consultar();
				
				break;
				
			case 'D':
				ordenaCid();
				
				break;
				
			case 'E':
				exibir();
				
				break;
				
			case 'F':
				ordenaDesc();
				
				break;
				
			case 27:
				printf("\nPrograma encerrado!\n");
				getch();
				
				break;
		}
		
	}while(op!=27);
}
