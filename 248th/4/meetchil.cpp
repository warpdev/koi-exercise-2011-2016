#include <stdio.h>
#define N 30
#define INF 10000000

FILE *fp1,*fp2;

int n=26;
int m;
int a[N+1][N+1];
int b[N+1][N+1];
char x,y;

void input(void)
{
	int i,k;
	char w,r;

	fscanf(fp1,"%d ",&m);
	for(i=1; i<=n; i++)
	{
		for(k=1; k<=n; k++)
		{
			if(i!=k)
			{
				a[i][k]=INF;
				b[i][k]=INF;
			}
		}
	}
	for(i=1; i<=m; i++)
	{
		fscanf(fp1,"%c %c %c %c %d ",&x,&y,&w,&r,&k);
		if(x=='Y' && w!=r)
		{
			if(y=='U')
			{
				a[w-64][r-64]=k;
			}
			else
			{
				a[w-64][r-64]=k;
				a[r-64][w-64]=k;
			}
		}
		else if(w!=r)
		{
			if(y=='U')
			{
				b[w-64][r-64]=k;
			}
			else
			{
				b[w-64][r-64]=k;
				b[r-64][w-64]=k;
			}
		}
	}
	fscanf(fp1,"%c %c",&x,&y);
}

void process(void)
{
	int i,j,k;

	for(k=1; k<=n; k++)
	{
		for(i=1; i<=n; i++)
		{
			for(j=1; j<=n; j++)
			{
				if(a[i][j]>a[i][k]+a[k][j])
				{
					a[i][j]=a[i][k]+a[k][j];
				}
			}
		}
	}
	for(k=1; k<=n; k++)
	{
		for(i=1; i<=n; i++)
		{
			for(j=1; j<=n; j++)
			{
				if(b[i][j]>b[i][k]+b[k][j])
				{
					b[i][j]=b[i][k]+b[k][j];
				}
			}
		}
	}
}

void output(void)
{
	int mx,id,i,j;

	mx=INF;
	id=0;
	for(i=1; i<=n; i++)
	{
		if(mx>a[x-64][i]+b[y-64][i])
		{
			mx=a[x-64][i]+b[y-64][i];
			id=i;
		}
	}
	if(!id)
	{
		fprintf(fp2,"-1");
		return;
	}
	else
	{
		fprintf(fp2,"%d ",mx);
		for(i=1; i<=n; i++)
		{
			if(mx==a[x-64][i]+b[y-64][i])
			{
				fprintf(fp2,"%c ",i+64);
			}
		}
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