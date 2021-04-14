#include <stdio.h>
#define N 100

FILE *fp1,*fp2;

int n,m;
int g;
int a[N+2][N+2];
int b[N+2][N+2];
int mx;

void input(void)
{
    int i,j;
    char t;

    fscanf(fp1,"%d %d %d ",&n,&m,&g);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            fscanf(fp1,"%c ",&t);
            if(t=='*')
            {
                a[i][j]=1;
            }
            else
            {
                a[i][j]=0;
            }
        }
    }
}

void  sl(int x,int y)
{
    int i,j;
    int sm=0;

    for(i=x-1; i<=x+1; i++)
    {
        for(j=y-1; j<=y+1; j++)
        {
            sm+=a[i][j];
        }
    }
    sm-=a[x][y];
    if(sm==3)
    {
        b[x][y]=1;
    }
    else if(sm==2)
    {
        b[x][y]=a[x][y];
    }
    else
    {
        b[x][y]=0;
    }
}

void process(void)
{
    int i,j,k;

    for(i=1; i<g; i++)
    {
        for(j=1; j<=n; j++)
        {
            for(k=1; k<=m; k++)
            {
                sl(j,k);
            }
        }
        for(j=1; j<=n; j++)
        {
            for(k=1; k<=m; k++)
            {
                a[j][k]=b[j][k];
            }
        }
    }

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            mx+=a[i][j];
        }
    }
    fprintf(fp2,"%d",mx);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    return 0;
}
