#include <stdio.h>
#define N 100000

FILE *fp1,*fp2;

int n;
int a[N+1];
int dy[N+1];
int d[N+1];

void input(void)
{
	int i;

	fscanf(fp1,"%d",&n);
	for(i=1; i<=n; i++)
	{
		fscanf(fp1,"%d",&a[i]);
	}
}

void process(void)
{
	int i;

	for(i=1; i<=n; i++)
	{
		if(a[i]>=a[i-1])
		{
			dy[i]=dy[i-1]+1;
		}
		else
		{
			dy[i]=1;
		}
		if(a[i]<=a[i-1])
		{
			d[i]=d[i-1]+1;
		}
		else
		{
			d[i]=1;
		}
	}
}

void output(void)
{
	int i,mx=0;

	for(i=1; i<=n; i++)
	{
		if(mx<dy[i])
		{
			mx=dy[i];
		}
	}
	for(i=1; i<=n; i++)
	{
		if(mx<d[i])
		{
			mx=d[i];
		}
	}
	fprintf(fp2,"%d",mx);
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