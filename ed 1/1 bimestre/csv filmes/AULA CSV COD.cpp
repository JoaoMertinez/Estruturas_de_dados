#include<stdio.h>
#include<conio2.h>
#include<string.h>


/*void relatorio()
{
	FILE *arq = fopen("filmes.txt","r");
	fscanf(arq,"%[^;];%d;%[^;];%f;%f;%d;%f\n",&reg.nome, &reg.ano, &reg.classif, &reg.gasto, &reg.renda, &reg.duracao, &reg.espec);
	while(!feof(arq))
	{
		
		
		fscanf(arq,"%[^;];%d;%[^;];%f;%f;%d;%f\n",&reg.nome, &reg.ano, &reg.classif, &reg.gasto, &reg.renda, &reg.duracao, &reg.espec);
	}	
}*/
struct filme{
    char nome[60], classif[6];
    int ano, duracao;
    float gasto,renda,espec;
};

void Anofilmes()
{
	int maior=0,ano[50],i=0,j,contagemAnos[50] = {0};
	filme reg;
	
	//FILE * ptr = fopen("anofilmes.dat","rb");
	FILE * arq = fopen("filmes.txt","r");//arquivo para pegar as informacoes
	
	fscanf(arq,"%[^;];%d;%[^;];%f;%f;%d;%f\n",&reg.nome, &reg.ano, &reg.classif, &reg.gasto, &reg.renda, &reg.duracao, &reg.espec);//jogando pro reg
	while(!feof(arq))//andando todo o arquivo
	{
		ano[i]=reg.ano;//jogando os anos no vetor
		i++;
		fscanf(arq,"%[^;];%d;%[^;];%f;%f;%d;%f\n",&reg.nome, &reg.ano, &reg.classif, &reg.gasto, &reg.renda, &reg.duracao, &reg.espec);//jogando pro reg
	}
	fclose(arq);
	
	for (int j = 0; j < i; j++) {
    	contagemAnos[ano[j] - 1]++;
    }

    for (int j = 1; j < 50; j++) {
        if (contagemAnos[j] > contagemAnos[maior]) {
            maior = j;
        }
    }

    int anoMaisFrequente = maior + 1; // +1 porque os anos começam em 1 no seu caso

    printf("\nO ano mais frequente é: %d\n", anoMaisFrequente);
} 
 
int main()
{
	int maior=0,maioresp=0,cont=0;
	char filmemaior[50],filmesp[50];
	float media=0;
	
    filme reg;
    
    FILE *arq = fopen("filmes.txt","r");
     
    fscanf(arq,"%[^;];%d;%[^;];%f;%f;%d;%f\n",&reg.nome, &reg.ano, &reg.classif, &reg.gasto, &reg.renda, &reg.duracao, &reg.espec);
    while(!feof(arq))
    {
      if(reg.renda>maior)
      {
    	maior = reg.renda;
    	strcpy(filmemaior,reg.nome);
      }
      
      if(reg.espec>maioresp);
      {
      	maioresp = reg.espec;
      	strcpy(filmesp,reg.nome);
      }
      
      media = media + reg.duracao;
      cont++;
      	
      printf("%s %d %s %.2f %.2f %d %.2f \n",reg.nome, reg.ano, reg.classif, reg.gasto, reg.renda, reg.duracao, reg.espec);
 
      fscanf(arq,"%[^;];%d;%[^;];%f;%f;%d;%f\n",&reg.nome, &reg.ano, &reg.classif, &reg.gasto, &reg.renda, &reg.duracao, &reg.espec);
     
    }
    
    printf("%s %d %s %.2f %.2f %d %.2f \n",reg.nome, reg.ano, reg.classif, reg.gasto, reg.renda, reg.duracao, reg.espec);
    printf("\nO maior lucro foi de: %d e o nome do filme e:  %s", maior, filmemaior);
    printf("\nA maior taxa de espectadores foi de: %d e o nome do filme e:  %s",maioresp, filmesp);//arrumar
	printf("\nA duracao media dos filmes e de: %.2f",(media/cont));
	Anofilmes();
	printf("\nRelatorio por classificacao");
	
	
	
	

    fclose(arq);
    getch();
}




