void execE(FILE *arq, int valor, int *menor, int *maior, int *media)
{
	int contador = 0;
	Reg r;
	
	fread(&r, sizeof(Reg), 1, arq);
	while(r.valor != valor && !feof(arq))
	{
		fread(&r, sizeof(Reg), 1, arq);
		contador++;
	}
	
	(*media) += contador;
	if (contador > (*maior))
        *maior = contador;
    else if (contador < (*menor))
            *menor = contador;
            
    
	if(r.valor == valor)
		printf("achou: %d\n",valor);
	else
		printf("Infelizmente NAO achou!\n");
}

void exaustiva(FILE *arq)
{
	Reg r;
	fseek(arq, 0, 0);
	int i = 0;
	int valor, menor = 999999, maior = 0, media = 0;
	srand(time(NULL));
	int t_inicio, t_fim, t_mili;
	
	t_inicio = GetTickCount();
	while(i < 100)
	{
		fseek(arq,0,2);
		valor = rand() % (ftell((arq))/sizeof(Reg));
		rewind(arq);
		execE(arq,valor,&menor,&maior,&media);
		
		i++;
	}
	t_fim = GetTickCount();
	t_mili = t_fim - t_inicio;
	
	printf("\n\n Tempo de execucao: %d milissegundos.",t_mili);
	printf("\n Quantidade de iteracoes maxima: %d",maior);
	printf("\n Quantidade de iteracoes minima: %d",menor);
	printf("\n Quantidade de iteracoes media: %d",media/100);
	getch();
}
