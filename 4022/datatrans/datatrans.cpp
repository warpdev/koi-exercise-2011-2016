#include <stdio.h>
#include <stdlib.h>
#define N 26

FILE *fp1,*fp2;

int n;
int a[N+1][N+1];
int path[N+1];
int ck[N+1];
int s;
int cnt=1;

void input(void)
{
    int i,j;
    char t;

    fscanf(fp1,"%d ",&n);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            fscanf(fp1,"%c ",&t);
            if(t=='0')
            {
                a[i][j]=j;
            }
            else
            {
                a[i][j]=t-64;
            }
        }
    }
    fscanf(fp1,"%c ",&t);
    path[1]=t-64;
    ck[path[1]]=1;
    fscanf(fp1,"%c",&t);
    s=t-64;
}

void process(int x,int y)
{
    if(a[x][y]==y)
    {
        cnt++;
        path[cnt]=y;
        if(ck[y])
        {
            fprintf(fp2,"-1");
            exit(0);
        }
        ck[y]=1;
    }
    else
    {
        process(x,a[x][y]);
        process(a[x][y],y);
    }
}

void output(void)
{
    int i;

    for(i=1; i<=cnt; i++)
    {
        fprintf(fp2,"%c",path[i]+64);
    }
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process(path[1],s);
    output();
    return 0;
}
