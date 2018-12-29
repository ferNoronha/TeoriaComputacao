#include "busca.h"

void Sentinela(FILE *Arq)
{
	system("cls");
	int i=0, qnt, t_inicio, t_final, t_total=0, min=99999999, max=0, media,total=0;
	int valor = rand() % 10000;
	while(i++<100)
	{
		qnt =0;
		t_inicio = GetTickCount();
		execS(Arq,valor,qnt);
		t_final = GetTickCount();
		t_total += t_final - t_inicio;
		total+=qnt;
		if(qnt<min)
			min = qnt;
		if(qnt>max)
			max = qnt;
		valor = rand() % 10000;
	}
	media = total / 100;
	printf("\n\nTempo total: %d ms",t_total);
	printf("\nTotal de Leituras: %d",total);
	printf("\nLeitura minima: %d",min);
	printf("\nLeitura maxima: %d",max);
	printf("\nLeitura media: %d",media);
	getch();
}
