#include <stdio.h>
#define N 100

FILE *fp1,*fp2;

int a[3+1];
int n=3;
int ck[N+1];
int ta,tb;
int sm;
int mx;

void input(void)
{
	int i,j;

	for(i=1; i<=n; i++)
	{
		fscanf(fp1,"%d",&a[i]);
	}
	for(i=1; i<=n; i++)
	{
		fscanf(fp1,"%d %d",&ta,&tb);
		if(tb>mx)
		{
			mx=tb;
		}
		for(j=ta; j<=tb-1; j++)
		{
			ck[j]++;
		}
	}
}

void process(void)
{
	int i;

	for(i=1; i<=mx; i++)
	{
		sm+=a[ck[i]]*ck[i];
	}
	fprintf(fp2,"%d",sm);
}

int main(void)
{
	fp1=fopen("input.txt","r");
	fp2=fopen("output.txt","w");
	input();
	process();
	return 0;
}