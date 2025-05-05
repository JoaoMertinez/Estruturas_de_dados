#include<stdio.h>

int main(void)
{
	int vetNaipe[8];
	int i;
	vetNaipe[0] = 'O';
	vetNaipe[1] = 'E';
	vetNaipe[2] = 'C';
	vetNaipe[3] = 'P';
	vetNaipe[4] = 10;
	vetNaipe[5] = 15;
	vetNaipe[6] = 20;
	vetNaipe[7] = 25;
	
	for(i=0; i<4; i++)
		printf("Teste:%c\n",vetNaipe[i]);
		
	for(i=4; i<8; i++)
		printf("Teste:%d\n",vetNaipe[i]);
    return 0;
}

