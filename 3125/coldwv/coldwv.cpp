#include <stdio.h>
#define N 2500
#define INF 2500001

FILE *fp1,*fp2;

int n,m;
int k;
int dist[N+1];
int ck[N+1];
int a[N+1][N+1];

void input(void)
{
    int i;
    int x,y,w;


    fscanf(fp1,"%d %d %d %d",&n,&m,&x,&k);
    for(i=1; i<=n; i++)
    {
        dist[i]=INF;
    }
    dist[x]=0;
    for(i=1; i<=m; i++)
    {
        fscanf(fp1,"%d %d %d",&x,&y,&w);
        a[x][y]=w;
        a[y][x]=w;
    }
}

void process(void)
{
    int i,j;
    int mx,id;

    for(j=1; j<=n; j++)
    {
        mx=INF;
        for(i=1; i<=n; i++)
        {
            if(mx>dist[i] && !ck[i])
            {
                mx=dist[i];
                id=i;
            }
        }
        ck[id]=1;
        for(i=1; i<=n; i++)
        {
            if(a[id][i] && dist[i]>a[id][i]+mx && !ck[i])
            {
                dist[i]=a[id][i]+mx;
            }
        }
    }
    fprintf(fp2,"%d",dist[k]);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    return 0;
}
