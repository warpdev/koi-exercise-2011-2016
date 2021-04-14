#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define N 1000
#define INF 99999999
typedef pair<int,int> pp;
typedef pair<int,pp> ppp;

FILE *fp1,*fp2;

int n,m;
int a[N+1][N+1];
int dist[N+1];
int sm;
int ckk[N+1];
int path[N+1];
priority_queue<ppp> Q;

void input(void)
{
	int i,x,y,w;

	fscanf(fp1,"%d %d",&n,&m);
	for(i=1; i<=m; i++)
	{
		fscanf(fp1,"%d %d %d",&x,&y,&w);
		if(a[x][y]<w)
		{
			a[x][y]=w;
			a[y][x]=w;
		}
	}
	dist[1]=INF;
	path[1]=1;
}

void process(void)
{
	int i,id,mx;
	
	while(1)
	{
		mx=0;
		id=0;
		for(i=1; i<=n; i++)
		{
			if(mx<dist[i] && ckk[path[i]]==0)
			{
				mx=dist[i];
				id=i;
			}
		}
		if(!id)
		{
			break;
		}
		if(id==1)
		{
			mx=0;
		}
		ckk[path[id]]=1;
		ckk[id]=1;
		sm+=mx;
		for(i=1; i<=n; i++)
		{
			if(a[id][i] && dist[i]<a[id][i])
			{
				dist[i]=a[id][i];
				path[i]=i;
			}
			else if(a[i][id] && dist[i]<a[i][id] && ckk[i]==0)
			{
				dist[i]=a[i][id];
				path[i]=id;
			}
		}
	}
}

void output(void)
{
	int i;

	for(i=1; i<=n; i++)
	{
		if(ckk[i]==0)
		{
			fprintf(fp2,"-1");
			return;
		}
	}
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