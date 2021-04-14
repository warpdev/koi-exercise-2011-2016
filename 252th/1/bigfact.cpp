#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 5000

FILE *fp1,*fp2;

int a[N+1];
int n;
int mx,md;

void input(void)
{
	int i;

	fscanf(fp1,"%d",&n);
	for(i=1; i<=n; i++)
	{
		fscanf(fp1,"%d",&a[i]);
	}
}

int slv(int x)
{
	int j,i,k,t;
	int cnt=0;

	for(i=1; i<=x; i++)
	{
		cnt=0;
		if(x%i==0)
		{
			k=x/i;
			t=sqrt(k);
			for(j=1; j<=t; j++)
			{
				if(k%j==0)
				{
					cnt++;
				}
			}
			if(cnt==1)
			{
				return k;
			}
		}
	}
	return 1;
}

void process(void)
{
	int i,j;
	int k;

	for(i=1; i<=n; i++)
	{
		k=slv(a[i]);
		if(mx<k)
		{
			mx=k;
			md=i;
		}
	}
}

void output(void)
{
	fprintf(fp2,"%d",a[md]);
}

int main(void)
{
	fp1=fopen("input.txt","r");
	fp2=fopen("output.txt","w");
	input();
	process();
	output();
	return 0;
}
