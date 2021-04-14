#include <stdio.h>
#include <stdlib.h>
#define N 15

FILE *fp1,*fp2;

int n,m;
int t[N+1][N+1];
int a[N+1][N+1];
int s[N+1][N+1];
int c[N+1][N+1];
int k;
int km=99999;

void input(void)
{
    int i,j;

    fscanf(fp1,"%d %d",&n,&m);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            fscanf(fp1,"%d",&t[i][j]);
        }
    }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            a[i][j]=t[i][j];
            s[i][j]=0;
        }
    }
}

void filp(int x,int y)
{
    a[x][y]=1-a[x][y];
    a[x-1][y]=1-a[x-1][y];
    a[x][y-1]=1-a[x][y-1];
    a[x+1][y]=1-a[x+1][y];
    a[x][y+1]=1-a[x][y+1];
}

void process(void)
{
    int i,j;

    for(i=2; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            if(a[i-1][j]==1)
            {
                s[i][j]=1;
                //printf("%d %d\n",i,j);
                filp(i,j);
            }
        }
    }
}

void output(void)
{
    int i,j;

    if(km==99999)
    {
        fprintf(fp2,"IMPOSSIBLE");
    }
    else
    {
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                fprintf(fp2,"%d ",c[i][j]);
            }
            fprintf(fp2,"\n");
        }
    }
}

void clen(void)
{
    int i,j;

    for(i=2; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            if(s[i][j])
            {
                filp(i,j);
            }
        }
    }
}

void start(int x)
{
    int i,j;

    if(x>m)
    {
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                //printf("%d ",a[i][j]);
            }
            //printf("\n");
        }
        for(i=2; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                s[i][j]=0;
            }
        }
        process();
        for(i=1; i<=m; i++)
        {
            if(a[n][i]==1)
            {
                //printf("-------------\n");
                clen();
                return;
            }
        }
        k=0;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                k+=s[i][j];
                //if(s[i][j])
                //printf("-----%d %d-----\n",i,j);
            }
        }
        //printf("k=%d\n",k);
        if(k<km)
        {
            km=k;
            for(i=1; i<=n; i++)
            {
                for(j=1; j<=m; j++)
                {
                    c[i][j]=s[i][j];
                }
            }
        }
        clen();
        return;
    }
    for(i=1; i>=0; i--)
    {
        s[1][x]=1-i;
   // printf("%d %d\n",x,1-i);
        start(x+1);
        filp(1,x);
    }
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    start(1);
    output();
    return 0;
}
