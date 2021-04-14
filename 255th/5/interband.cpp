#include <stdio.h>
#define N 100
#define INF 99999999

FILE *fp1,*fp2;

int n;
int r[N+1][N+1];
int c[N+1][N+1];
int f[N+1][N+1];
int dist[N+1];
int ck[N+1];
int a,b,d;

void input(void)
{
    int i;
    int x,y,w;

    fscanf(fp1,"%d %d %d %d",&n,&a,&b,&d);
    for(i=1; i<=d; i++)
    {
        fscanf(fp1,"%d %d %d",&x,&y,&w);
        r[x][y]+=w;
        r[y][x]+=w;
        c[x][y]+=w;
        c[y][x]+=w;
    }
    dist[a]=INF;
    for(i=1; i<=n; i++)
    {
        r[b][i]=0;
        c[b][i]=0;
        r[i][a]=0;
        c[i][a]=0;
    }
}

void process(void)
{
    int i,j;
    int mx=0,id;

    while(1)
    {
        mx=0;
        id=0;
        for(i=1; i<=n; i++)
        {
            if(mx<dist[i] && ck[i]!=1 && i!=b)
            {
                mx=dist[i];
                id=i;
            }
        }
           if(id==0)
        {
            break;
        }
        /*if(id==b)
        {
            fprintf(fp2,"%d",mx);
            break;
        }*/
        ck[id]=1;
        if(ck[b]!=1 && c[id][b]>0)
        {
            if(mx>c[id][b])
            {
                dist[b]+=c[id][b];
                dist[id]-=c[id][b];
                f[id][b]-=c[id][b];
                f[b][id]+=c[id][b];
            }
            else
            {
                dist[b]+=dist[id];
                f[id][b]-=dist[id];
                f[b][id]+=dist[id];
                dist[id]=0;
            }
        }
        for(i=1; i<=n; i++)
        {
            if(ck[i]!=1 && c[id][i]>0 && i!=b)
            {
                if(mx>c[id][i])
                {
                    dist[i]+=c[id][i];
                    dist[id]-=c[id][i];
                    f[id][i]-=c[id][i];
                    f[i][id]+=c[id][i];
                }
                else
                {
                    dist[i]+=dist[id];
                    f[id][i]-=dist[id];
                    f[i][id]+=dist[id];
                    dist[id]=0;
                }
            }
        }
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                c[i][j]=r[i][j]+f[i][j];
            }
        }
    }
    fprintf(fp2,"%d",dist[b]);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    return 0;
}
