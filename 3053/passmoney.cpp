#include <stdio.h>
#define N 25
#define INF 999999999

FILE *fp1,*fp2;

int n;
int x,y;
int a[N+1][N+1];
int ck[N+1];
int dist[N+1];
int path[N+1];

void input(void)
{
    int i,j;

    fscanf(fp1,"%d %d %d",&n,&x,&y);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(i!=j)
            {
                fscanf(fp1,"%1d",&a[i][j]);
            }
        }
        dist[i]=INF;
    }
    dist[x]=0;
}

void process(void)
{
    int i,j;
    int t,cnt=0,p[N+1]={0};
    int mn,id;

    for(j=1; j<=n; j++)
    {
        mn=INF;
        for(i=1; i<=n; i++)
        {
            if(mn>dist[i] && !ck[i])
            {
                mn=dist[i];
                id=i;
            }
        }
        if(id==y)
        {
            break;
        }
        ck[id]=1;
        for(i=1; i<=n; i++)
        {
            if(!ck[i] && dist[i]>mn+a[id][i] && a[id][i])
            {
                dist[i]=mn+a[id][i];
                path[i]=id;
            }
        }
    }
    if(dist[y]!=INF)
    {
        fprintf(fp2,"%d\n",dist[y]);
        t=y;
        while(t)
        {
            cnt++;
            p[cnt]=t;
            t=path[t];
        }
        fprintf(fp2,"%d\n",cnt);
        for(i=cnt; i>=1; i--)
        {
            fprintf(fp2,"%d ",p[i]);
        }
    }
    else
    {
        fprintf(fp2,"-1");
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
