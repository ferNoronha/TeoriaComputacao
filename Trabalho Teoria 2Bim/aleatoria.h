void execA(FILE *arq, int cod,int *menor, int *maior, int *media)
{
	int pos, i = 0, t = 0,n = 1000000;
	Reg r;

	fseek(arq,0,2);
	srand(time(NULL));
	pos = rand() % (ftell(arq)/sizeof(Reg));
	fseek(arq,pos*sizeof(Reg),0);
	fread(&r,sizeof(Reg),1,arq);
	while(i < n && r.valor != cod)
	{
		fseek(arq,pos*sizeof(Reg),0);
		fread(&r,sizeof(Reg),1,arq);
		fseek(arq,0,2);
		pos = rand() % (ftell(arq)/sizeof(Reg));
		t++;
		i++;
	}
	(*media) += t;
	if (t > (*maior))
        *maior = t;
    else if (t < (*menor))
            *menor = t;

	printf("pos: %d\n",pos);
	if(r.valor == cod)
		printf("achou: %d\n",cod);
}

void aleatoria(FILE *arq)
{
	int i = 0, val, inicio, fim, tm = 0, menor = 999999, maior = 0, media = 0;
	Reg reg;

	fseek(arq,0,2);
	srand(time(NULL));
	val = rand() % (ftell(arq)/sizeof(Reg));
	printf("val: %d\n\n",val);
	
	inicio = GetTickCount();
	while(i < 100)
	{
		execA(arq, val, &menor, &maior, &media);
		i++;
		fseek(arq,0,2);
		val = rand() % (ftell(arq)/sizeof(Reg));
	}
	fim = GetTickCount();
	tm = fim - inicio;
	

	fclose(arq);
	printf("\nTempo : %d ms",tm);
	printf("\nLeitura maxima: %d",maior);
	printf("\nLeitura minima: %d",menor);
	printf("\nLeitura media: %d",media/100);
	getch();
}
