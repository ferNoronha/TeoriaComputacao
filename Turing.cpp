#include<conio2.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>

struct TpMaquina
{
	char estado[4], escrita, leitura, direcao, caminho[4];
};

int BuscaEstado(TpMaquina M[], int TL,char estado[],char leitura)
{
	int i=0;
	bool achou=false;
	while(i<TL && !achou)
	{
		if(stricmp(M[i].estado, estado)==0 &&  M[i].leitura == leitura)
			achou=true;
		else
			i++;
	}

	if(i<TL)
		return i;
	else
		return -1;
}



char Entrada(char palavra[],TpMaquina M[], int &TL)
{
	int posString=0,posVet=0,resultado=3;
	char estadoAtual[4];
	strcpy(estadoAtual,"Q0");
	printf("Entrada: ");
	fflush(stdin);
	gets(palavra);

		while(resultado==3 && M[posVet].escrita != 'X')
		{
			if(posString>=strlen(palavra))
				posVet = BuscaEstado(M,TL,estadoAtual,'|');
			else
				posVet = BuscaEstado(M,TL,estadoAtual,palavra[posString]);
				
			if(posVet != -1)
			{
				if(M[posVet].direcao=='X')
					resultado=1;
				else
				{
					
					char esc = M[posVet].escrita;
					if(M[posVet].escrita != '|')
						palavra[posString] = M[posVet].escrita;
					if(M[posVet].direcao == 'D')
						posString++;
					else
						posString--;

				strcpy(estadoAtual,M[posVet].caminho);
				}
			}
			else
				resultado=0;
			if(BuscaEstado(M,TL,estadoAtual,'X')!=-1)
				resultado=1;
				
		}
		

	return resultado;
}

void LeArq(TpMaquina M[], int &TL)
{
	FILE *arq=fopen("LeituraT.txt","r+");
	fscanf(arq,"%[^;];%c;%c;%c;%[^;];\r\n",&M[0].estado,&M[0].leitura,&M[0].escrita,&M[0].direcao,&M[0].caminho);
	TL++;
	while(!feof(arq))
	{
		fscanf(arq,"%[^;];%c;%c;%c;%[^;];\r\n",&M[TL].estado,&M[TL].leitura,&M[TL].escrita,&M[TL].direcao,&M[TL].caminho);	
		TL++;
	}
	fclose(arq);
}



int main()
{
	TpMaquina M[50];
	int TL=0;
	char palavra[100];
	LeArq(M,TL);
	if(Entrada(palavra,M,TL)==1)
		printf("ACEITO");
	else
		printf("REJEITA");
	getch();
}
