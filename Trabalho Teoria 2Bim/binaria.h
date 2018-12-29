void execB(FILE *arq, int sorteado, int &contador)
{
	Reg r;
	int inicio=0;
	fseek(arq,0,2);
	int fim = ftell(arq)/sizeof(Reg);
	int meio=(inicio+fim)/2;
	int achou=0;	
	rewind(arq);
	fread(&r,sizeof(Reg),1,arq);
	while(achou!=1 && !feof(arq)){
		if(sorteado>r.valor && !feof(arq))
		{	
			inicio=meio+1;
			meio=(inicio+fim)/2;
			fseek(arq,sizeof(Reg)*inicio,0);
		    fread(&r,sizeof(Reg),1,arq);
		}
		else if(sorteado<r.valor && !feof(arq))
		{
			inicio = fim/2+1;
		    fim=meio-1;
		    meio=(inicio+fim)/2;
		    fseek(arq,sizeof(Reg)*inicio,0);
		    fread(&r,sizeof(Reg),1,arq);
		}
		else
			if(!feof(arq))
				achou=1;
		
		contador++;
	}
	if(achou==1)
		printf(" ACHOU! %d\n",r.valor);
	else
		printf(" NAO ACHOU! %d\n",sorteado);
}

void Binaria(FILE *arq)
{
	int inicio, fim, meio, i=0, achou=0;
	int sorteado;
	int t_inicio, t_fim, t_mili;
	int contador;
	int valor, menor = 999999, maior = 0, total=0,media;
	
	srand(time(NULL));
	
	t_inicio = GetTickCount();
	while(i<100){
		rewind(arq);
		contador=0;
		sorteado = rand() % 100000;
		execB(arq,sorteado,contador);
		total += contador;
		if(contador<menor)
			menor = contador;
		if(contador>maior)
			maior = contador;
		i++;
	}
	media = total /100;
	t_fim = GetTickCount();
	t_mili = t_fim - t_inicio;
	printf("\n\n Tempo de execucao: %d milissegundos.",t_mili);
	printf("\nQuantidade total de leituras: %d",total);
	printf("\n Quantidade de leitura maxima: %d",maior);
	printf("\n Quantidade de leitura minima: %d",menor);
	printf("\n Quantidade de leitura media: %d",media);
	getch();
}
