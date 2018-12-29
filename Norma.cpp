#include<conio2.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>

struct Natural
{
	int s,n;
	Natural()
	{this->s=0;}
	Natural(int a, int b)
	{
		this->s=a;
		this->n=b;
	}
};

void Adiciona (Natural &a)
{
	if(a.s==0)
		a.n++;
	else
		a.n--;
		
	if(a.n==0)
		a.s--;
}

void Retira (Natural &a)
{
	if(a.n==0)
	{
		a.n++;
		a.s++;
	}
	else
	  if(a.s==0)
	  	a.n--;
	  else
	  	a.n++;
}

char Not (Natural a)
{
	if(a.n==0)
		return '1';
	else
		return '0';
}

char Ou (Natural a, Natural b)
{
	if(a.n==0)
		if(b.n==0)
			return '0';

	return '1';
}

char E (Natural a, Natural b)
{
	if(a.n==0)
		return '0';
	if(b.n==0)
		return '0';
	return '1';	
}

char Igualdade (Natural a, Natural b)
{
	while(a.n && b.n)
	{
		Retira(a);
		Retira(b);
	}
	if(a.n == 0 && b.n == 0 && a.s ==0 && b.s==0)
		return '1';
	else
		return '0';
}
		
char Diferente (Natural a, Natural b)
{
	if(Igualdade(a,b)=='1')
		return '0';
	else
		return '1';
}

char Maior (Natural a, Natural b)
{
	if(Igualdade(a,b)=='1')
		return '0';
	if(a.s==0)
	{
		if(b.s==0)
		{
			while(a.n!=0 && b.n!=0)
			{
				Retira(a);
				Retira(b);
			}
			if(a.n!=0)
				return '1';
			else
				return '0';	
		}
		else
			return '1';
		
	}
	else
		if(b.s==0)
			return '0';
		else
		{
			while(a.n!=0 && b.n!=0)
			{
				Adiciona(a);
				Adiciona(b);
			}
			if(b.n!=0)
				return '1';
			else
				return '0';
		}			
}

char Menor (Natural a, Natural b)
{
	if(Igualdade(a,b)=='1')
		return '0';
	if(a.s==0)
	{
		if(b.s==0)
		{
			while(a.n!=0 && b.n!=0)
			{
				Retira(a);
				Retira(b);
			}
			if(b.n!=0)
				return '1';
			else
				return '0';
		}
		else
			return '0';
	}
	else
		if(b.s==0)
			return '1';
		else
		{
			while(a.n!=0 && b.n!=0)
			{
				Adiciona(a);
				Adiciona(b);
			}
			if(a.n!=0)
				return '1';
			else
				return '0';
		}
}

char MaiorIgual (Natural a, Natural b)
{
	if(Igualdade(a,b)=='1')
		return '1';
	if(a.s==0)
	{
		if(b.s==0)
		{
			while(a.n!=0 && b.n!=0)
			{
				Retira(a);
				Retira(b);
			}
			if(a.n!=0)
				return '1';
			else
				return '0';
		}
		else
			return '1';

	}
	else
		if(b.s==0)
			return '0';
		else
		{
			while(a.n!=0 && b.n!=0)
			{
				Adiciona(a);
				Adiciona(b);
			}
			if(b.n!=0)
				return '1';
			else
				return '0';
		}
}

int main ()
{
	Natural a,b;
	
	a.n=3, b.n=2;
	
	Adiciona(a);
	printf("A++ %d\n",a.n);
	Retira(b);
	printf("B-- %d\n",b.n);
	printf("Not A = %c\n",Not(a));
	printf("A && B = %c\n",E(a,b));
	printf("A || B = %c\n",Ou(a,b));
	printf("A == B = %c\n",Igualdade(a,b));
	printf("A != B = %c\n",Diferente(a,b));
	printf("A > B = %c\n",Maior(a,b));
	printf("A < B = %c\n",Menor(a,b));
	printf("A >= B = %c\n",MaiorIgual(a,b));
		
	getch();
	
	
	return 0;
	
	
}
