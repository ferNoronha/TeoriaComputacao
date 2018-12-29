#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <sys/time.h>
#include "Estrutura.h"
#include "binaria.h"
#include "sentinela.h"
#include "exaustiva.h"
#include "aleatoria.h"

void menu(char nome[])
{
	FILE *Arq = fopen(nome,"rb");
	int opcao;
	printf("\n\n\nSelecione a busca desejada: "
				"\n1 - Aleatoria"
				"\n2 - Binaria"
				"\n3 - Exaustiva"
				"\n4 - Sentinela"
				"\n\nOpcao: ");
	opcao = getche();
	switch(opcao)
	{
		case 49: aleatoria(Arq);
				break;
		case 50: Binaria(Arq);
				break;
		case 51: exaustiva(Arq);
				break;
		case 52: Sentinela(Arq);
				break;
		default: printf("\n\nOpcao incorreta!"); getch();
	}
	fclose(Arq);
}

int main()
{
	char nome[10];
	int op;
	do
	{
		system("cls");
		printf("Selecione o arquivo que deseja utilizar: "
				"\n1 - 1000 posicoes"
				"\n2 - 10000 posicoes"
				"\n3 - 100000 posicoes"
				"\n\nOpcao: ");
		op = getche();
		switch(op)
		{
			case 49: strcpy(nome,"arq1000.dat");
					menu(nome);
					break;
			case 50: strcpy(nome,"arq10000.dat");
					menu(nome);
					break; 
			case 51: strcpy(nome,"arq100000.dat");
					menu(nome);
					break;
			default: printf("\n\nOpcao incorreta!"); getch();
		}
	}while(op!=0);
}
