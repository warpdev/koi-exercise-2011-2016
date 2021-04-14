#include <stdio.h>
#include <stdlib.h>
#define N 100

FILE *fp1,*fp2;

int a[N+1];
int nm;

void input(void)
{
	fscanf(fp1,"%d",&nm);
}

void output(void)
{
	int i;

	for(i=1; i<=N; i++)
	{
		if(a[i])
		{
			fprintf(fp2,"%d ",i);
		}
	}
	fprintf(fp2,"\n");
}

void process(void)
{
	while(1)
	{
		input();
		if(nm==0)
		{
			exit(0);
		}
		else
		{
			if(!a[nm])
			{
				a[nm]=1;
			}
			else
			{
				a[nm]=0;
			}
			output();
		}
	}
}

int main(void)
{
	fp1=fopen("input.txt","r");
	fp2=fopen("output.txt","w");
	process();
	return 0;
}
