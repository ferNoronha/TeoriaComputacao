#include<conio2.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>


struct TpLer
{
	char leitura;
	int estadoProx;
};


struct TpMaquina
{
	int estado,TLL;
	bool ler;
	TpLer leitura[50];
};

void Entrada(TpMaquina M, TpLer L)
{
	
}



int buscaEstado(TpMaquina M[],int TL,int estado)
{
	int i;
	for(i=0;i<TL && M[i].estado != estado;i++);
	if(i == TL)
		return -1;
	else
		return i;
}


void LeArq(TpMaquina M[], int &TL)
{
	FILE *arq=fopen("Entrada.txt","r+");
	char leitura,temp[10];
	int cont=0,pos,barra=0;
	leitura = getc(arq);
	while(!feof(arq))
	{
		if(leitura == '\')
		{
			temp[cont]='\0';
			pos = buscaEstado(M,TL,atoi(temp));
			cont=0;
			if(pos ==-1)
			{
				//O estado não existe ainda, vou em M na posição TL e vou colocar o estado atual que é temp
				leitura = getc(arq);
				strcpy(M[TL].estao,temp);
				pos = buscaEstado(M,TL,atoi(temp));
				M[TL].ler = true;
			}
		}
		
		if(leitura == '/')
			barra=1;
		
		if(leitura == '=')
		{
			leitura = getc(arq);
			M[TL].ler = false;
		}
		
		if(leitura == 10)
		{
			temp[cont] = '\0';
			if(barra == 1)
			{
				strcpy(M[TL].leitura[M[TL].TLL].estadoProx,temp);
				M[TL].TLL++;
			}
			else
				M[TL].ler = true;
			
			
			getc(arq);
			TL++;
		}
		temp[cont]=leitura;
		cont++;
	}
	
}

int main()
{
	TpMaquina estados[50];
	
}
