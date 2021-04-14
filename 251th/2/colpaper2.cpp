#include <stdio.h>
#define N 100

FILE *fp1,*fp2;

int n;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int a[N+1][N+1];
int sm;

void input(void)
{
	int i,j,k;
	int x,y;

	fscanf(fp1,"%d",&n);
	for(i=1; i<=n; i++)
	{
		fscanf(fp1,"%d %d",&x,&y);
		for(j=y; j<=y+9; j++)
		{
			for(k=x; k<=x+9; k++)
			{
				a[j][k]=1;
			}
		}
	}
}

int ckc(int x,int y)
{
	int i;
	int tm=0;

	for(i=0; i<=3; i++)
	{
		if(a[x+dy[i]][y+dx[i]]==0)
		{
			tm++;
		}
	}
	return tm;
}

void process(void)
{
	int i,j;

	for(i=1; i<=100; i++)
	{
		for(j=1; j<=100; j++)
		{
			if(a[i][j]==1)
			{
				sm+=ckc(i,j);
			}
		}
	}
}

void output(void)
{
	fprintf(fp2,"%d",sm);
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