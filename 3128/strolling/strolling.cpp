#include <stdio.h>
#define N 1000

FILE *fp1,*fp2;

int n;
int a[N+1][N+1];
int dist[N+1];
int mmx;

void input(void)
{
    int i;
    int x,y,w;

    fscanf(fp1,"%d",&n);
    for(i=1; i<n; i++)
    {
        fscanf(fp1,"%d %d %d",&x,&y,&w);
        a[x][y]=1;
        a[x][w]=1;
    }
}

void process(void)
{
    int i,j;
    int mx,id;
    int ck[N+1]={0};

    dist[1]=1;
    for(j=1; j<=n; j++)
    {
        mx=0;
        for(i=1; i<=n; i++)
        {
            if(mx<dist[i] && !ck[i])
            {
                mx=dist[i];
                id=i;
            }
        }
        ck[id]=1;
        if(mmx<mx)
        {
            mmx=mx;
        }
        for(i=1; i<=n; i++)
        {
            if(!ck[i] && a[id][i])
            {
                dist[i]=dist[id]+1;
            }
        }
    }
    fprintf(fp2,"%d",mmx);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    return 0;
}
