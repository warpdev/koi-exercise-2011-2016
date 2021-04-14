#include <stdio.h>
#define N 100

FILE *fp1,*fp2;

int n;
int c[N+1][N+1],r[N+1][N+1],f[N+1][N+1];
int dist[N+1];
int ck[N+1]={0};

void input(void)
{
    int i,k;
    char x,y;

    fscanf(fp1,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%c %c %d ",&x,&y,&k);
        if(x<97)
        {
            x-=64;
        }
        else
        {
            x-=69;
        }
        if(y<97)
        {
            y-=64;
        }
        else
        {
            y-=69;
        }
        c[x][y]=k;
        r[x][y]=k;
        dist[1]=9999999;
    }
}

void dis(void)
{
    int i,id;
    int mx=0;

    for(i=1; i<=n; i++)
    {
        if(!ck[i] && mx<dist[i])
        {
            id=i;
            mx=dist[i];
        }
    }

}

void process(void)
{
    int i;

    while(dis())
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    printf("%d",'a'-96+27);
    return 0;
}
