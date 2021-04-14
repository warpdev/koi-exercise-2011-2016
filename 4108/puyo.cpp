#include <stdio.h>
#define N 12

FILE *fp1,*fp2;

int n;
int a[N+1][N+1];
int typ,loc,col1,col2;

void input(void)
{
	int i,j;

	for(i=1; i<=12; i++)
	{
		for(j=1; j<=6; j++)
		{
			fscanf(fp1,"%d",&a[i][j]);
		}
	}
	fscanf(fp1,"%d %d %d %d",&typ,&loc,&col1,&col2);
}

void process(void)
{
	int i;

	for