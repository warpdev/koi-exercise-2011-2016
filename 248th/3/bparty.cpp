#include <stdio.h>
#define N 1000
#define INF 100000009

FILE *fp1,*fp2;

int n,m,x;
int a[N+1][N+1];
int dist[N+1];
int ck[N+1];
int fmx;

void input(void)
{
	int i,xx,yy,w;

	fscanf(fp1,"%d %d %d",&n,&m,&x);
	for(i=1; i<=n; i++)
	{
		dist[i]=INF;
	}
	for(i=1; i<=m; i++)
	{
		fscanf(fp1,"%d %d %d",&xx,&yy,&w);
		if(a[xx][yy]>w || a[xx][yy]==0)
		{
			a[xx][yy]=w;
			a[yy][xx]=w;
		}
	}
	dist[x]=0;
}

void process(void)
{
	int i,mx,id;

	while(1)
	{
		mx=INF;
		id=0;
		for(i=1; i<=n; i++)
		{
			if(mx>dist[i] && ck[i]==0)
			{
				mx=dist[i];
				id=i;
			}
		}
		if(!id)
		{
			break;
		}
		ck[id]=1;
		if(fmx<mx)
		{
			fmx=mx;
		}
		for(i=1; i<=n; i++)
		{
			if(a[id][i] && ck[i]==0 && dist[i]>dist[id]+a[id][i])
			{
				dist[i]=dist[id]+a[id][i];
			}
		}
	}
	fprintf(fp2,"%d",fmx*2);
}

int main(void)
{
	fp1=fopen("input.txt","r");
	fp2=fopen("output.txt","w");
	input();
	process();
	return 0;
}