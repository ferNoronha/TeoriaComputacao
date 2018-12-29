void execS(FILE *Arq, int valor, int &qnt)
{
	FILE *Arq2 = fopen("arqaux.dat","wb+");
	Reg sent;
	fread(&sent,sizeof(Reg),1,Arq);
	while(!feof(Arq))
	{
		fwrite(&sent,sizeof(Reg),1,Arq2);
		fread(&sent,sizeof(Reg),1,Arq);
	}
	rewind(Arq);
	sent.valor = valor;
	int tam = ftell(Arq2);
	fwrite(&sent,sizeof(Reg),1,Arq2);
	rewind(Arq2);
	fread(&sent,sizeof(Reg),1,Arq2);
	while(sent.valor!=valor)
	{
		fread(&sent,sizeof(Reg),1,Arq2);
		qnt++;
	}
	if(ftell(Arq2)-sizeof(Reg)!=tam)
		printf("\nAchou %d",valor);
	else printf("\nNao Achou %d",valor);
	fclose(Arq2);
	remove("arqaux.dat");
}

