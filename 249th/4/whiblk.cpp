#include <stdio.h>
#define N 100000

FILE *fp1,*fp2;

int n,k;
int a[N+1];

void input(void)
{
	fscanf(fp1,"%d %d",&n,&k);
}

void process(void)
{
	int i;

	for(i=0; i<=k; i++)
	{
		a[i]=i+1;
	}
	for(i=k+1; i<=n; i++)
	{
		a[i]=(a[i-k-1]+a[i-1])%5000011;
	}
}

void output(void)
{
	fprintf(fp2,"%d",a[n]);
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