#include <stdio.h>
#define N 1000
#define INF 100001

FILE *fp1,*fp2;

int n;
int a[N+1][N+1];
int dist[N+1];
int ck[N+1];

void input(void)
{
    int i,t,j;
    int x,y,w;

    fscanf(fp1,"%d %d",&t,&n);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            a[i][j]=INF;
        }
    }
    for(i=1; i<=t; i++)
    {
        fscanf(fp1,"%d %d %d",&x,&y,&w);
        if(a[x][y]>w)
        {
            a[x][y]=w;
        }
        if(a[y][x]>w)
        {
            a[y][x]=w;
        }
    }
}

void process(void)
{
    int i,j;
    int mx,id;

    for(i=1; i<n; i++)
    {
        dist[i]=INF;
    }
    for(i=1; i<=n; i++)
    {
        mx=INF;
        for(j=1; j<=n; j++)
        {
            if(mx>dist[j] && !ck[j])
            {
                mx=dist[j];
                id=j;
            }
        }
        ck[id]=1;
        for(j=1; j<=n; j++)
        {
            if(!ck[j] && dist[j]>mx+a[id][j])
            {
                dist[j]=mx+a[id][j];
            }
        }
    }
    fprintf(fp2,"%d",dist[1]);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
}
