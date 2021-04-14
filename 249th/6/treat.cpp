#include <stdio.h>
#define N 2000

FILE *fp1,*fp2;

int n;
int a[N+1];
int dy[N+N][N+N];

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
	int i,j;

	for(i=1; i<=n; i++)
	{
		dy[i][i]=a[i]*n;
	}
	for(j=1; j<=n; j++)
	{
		for(i=1; i<=n; i++)
		{
			if(j==1)
			{
				if(dy[i][i]>dy[i+j][i+j])
				{
					dy[i][i+j]=dy[i][i]+a[i+j]*(n-1);
				}
				else
				{
					dy[i][i+j]=dy[i+j][i+j]+a[i]*(n-1);
				}
			}
			else
			{
				if((a[i]*(n-j)+dy[i+1][i+j])>(a[i+j]*(n-j)+dy[i][i+j-1]))
				{
					dy[i][i+j]=a[i]*(n-j)+dy[i+1][i+j];
				}
				else
				{
					dy[i][i+j]=a[i+j]*(n-j)+dy[i][i+j-1];
				}
			}
		}
	}
}

void output(void)
{
	fprintf(fp2,"%d",dy[1][n]);
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