#include <stdio.h>
#define N 100

FILE *fp1,*fp2;

int n;
int a[N+1][N+1];
int mx;
int id;
int sm;

void input(void)
{
	int i,j;

	fscanf(fp1,"%d",&n);
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
		{
			fscanf(fp1,"%d",&a[i][j]);
		}
	}
}

void process(void)
{
	int i,j;

	for(i=1; i<=n; i++)
	{
		sm=0;
		for(j=1; j<=n; j++)
		{
			if(a[i][j]==3)
			{
				sm++;
			}
		}
		if(sm>mx)
		{
			mx=sm;
			id=i;
		}
	}
}

void output(void)
{
	fprintf(fp2,"%d",id);
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