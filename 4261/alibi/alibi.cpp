#include <stdio.h>
#define N 500
#define INF 35000001

FILE *fp1,*fp2;

int f,p,c,m;
int a[N+1][N+1];
int dist[N+1];
int s[101];
int ck[N+1];

void input(void)
{
    int i,j;
    int x,y,w;

    fscanf(fp1,"%d %d %d %d",&f,&p,&c,&m);
    for(i=1; i<=f; i++)
    {
        for(j=1; j<=f; j++)
        {
            a[i][j]=INF;
        }
        dist[i]=INF;
    }
    dist[1]=0;
    for(i=1; i<=p; i++)
    {
        fscanf(fp1,"%d %d %d",&x,&y,&w);
        if(a[x][y]>w)
        {
            a[x][y]=w;
            a[y][x]=w;
        }
    }
    for(i=1; i<=c; i++)
    {
        fscanf(fp1,"%d",&s[i]);
    }
}

void process(void)
{
    int i,j,k;
    int cnt=0;
    int id,mx=INF;

    for(j=1; j<=f; j++)
    {
        mx=INF;
        for(i=1; i<=f; i++)
        {
            if(mx>dist[i] && !ck[i])
            {
                mx=dist[i];
                id=i;
            }
        }
        ck[id]=1;
        for(i=1; i<=f; i++)
        {
            if(!ck[i] && dist[i]>dist[id]+a[id][i])
            {
                dist[i]=dist[id]+a[id][i];
            }
        }
    }
    for(i=1; i<=c; i++)
    {
        if(dist[s[i]]<=m)
        {
            cnt++;
        }
    }
    fprintf(fp2,"%d\n",cnt);
    for(i=1; i<=c; i++)
    {
        if(dist[s[i]]<=m)
        {
            fprintf(fp2,"%d\n",i);
        }
    }
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    return 0;
}
