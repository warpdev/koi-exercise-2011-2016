#include <stdio.h>
#define N 1000

FILE *fp1,*fp2;

int n;
int d[N+1][N+1];
int sa;
int sb;

void input(void)
{
	int i;

	fscanf(fp1,"%d",&n);
	for(i=1; i<=n; i++)
	{
		fscanf(fp1,"%d",&d[i][i]);
		sb+=d[i][i];
	}
}

int fidmn(int x,int y)
{
	if(x>y)
	{
		return y;
	}
	else
	{
		return x;
	}
}

int fidmx(int x,int y)
{
	if(x>y)
	{
		return x;
	}
	else
	{
		return y;
	}
}

void process(void)
{
	int i,j,ta,tb;

	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n-i; j++)
		{
			if(i==1)
			{
				d[j][j+i]=fidmx(d[j][j],d[j+i][j+i]);
			}
			else
			{
				if(d[j+1][j+1]<d[j+i][j+i])
				{
					ta=d[j][j]+d[j+1][j+i-1];
				}
				else
				{
					ta=d[j][j]+d[j+2][j+i];
				}
				if(d[j][j]<d[j+i-1][j+i-1])
				{
					tb=d[j+i][j+i]+d[j][j+i-2];
				}
				else
				{
					tb=d[j+i][j+i]+d[j+1][j+i-1];
				}
				d[j][j+i]=fidmx(ta,tb);
			}
		}
	}
	sb-=d[1][n];
}

void output(void)
{
	if(d[1][n]>sb)
	{
		fprintf(fp2,"%d",d[1][n]-sb);
	}
	else
	{
		fprintf(fp2,"%d",sb-d[1][n]);
	}
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
