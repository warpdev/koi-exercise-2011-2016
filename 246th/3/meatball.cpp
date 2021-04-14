#include <stdio.h>
#define N 30

FILE *fp1,*fp2;

int n;
int a[N+1];
int cnta,cntb;

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
	int i,j,t=0;
	
	for(i=1; i<=n; i++)
	{
		cnta=0;
		cntb=0;
		for(j=1; j<=i; j++)
		{
			cnta+=a[j];
		}
		for(j=i+1; j<=n; j++)
		{
			cntb+=a[j];
		}
		if(cnta==cntb)
		{
			fprintf(fp2,"%d %d\n",i,i+1);
			t=1;
			break;
		}
	}
	if(t==0)
	{
		fprintf(fp2,"-1\n");
	}
}

int main(void)
{
	fp1=fopen("input.txt","r");
	fp2=fopen("output.txt","w");
	input();
	process();
	input();
	process();
	return 0;
}