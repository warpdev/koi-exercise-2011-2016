#include <stdio.h>
#define N 300

FILE *fp1,*fp2;

int n,m;
int a[N+1];
int path[N+1][N+1];
int path2[N+1];
int t[N+1][N+1];

void input(void)
{
	int i;

	fscanf(fp1,"%d %d",&n,&m);
	for(i=1; i<=n; i++)
	{
		fscanf(fp1,"%d",&a[i]);
	}
}

int mmx(int x,int y)
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

int slv(int x,int y)
{
	int i;
	int mx=9999999;
	int k=0;

	for(i=x-1; i<=y-1; i++)
	{
		if(mx>mmx(t[1][y]-t[1][i],t[x-1][i]))
		{
			mx=mmx(t[1][y]-t[1][i],t[x-1][i]);
			k=i;
		}
	}
	path[x][y]=y-k;
	return mx;
}

void process(void)
{
	int i,j;

	for(i=1; i<=n; i++)
	{
		t[1][i]=t[1][i-1]+a[i];
		path[1][i]=i;
	}	
	for(i=2; i<=m; i++)
	{
		for(j=i; j<=n; j++)
		{
			t[i][j]=slv(i,j);
		}
	}
}

void output(void)
{
	int i;

	fprintf(fp2,"%d\n",t[m][n]);
	for(i=1; i<=m; i++)
	{
		path2[i]=path[m-i+1][n];
		n-=path[m-i+1][n];
	}
	for(i=m; i>=1; i--)
	{
		fprintf(fp2,"%d ",path2[i]);
	}
	//fprintf(fp2,"%d ",path[1][n]);
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