#include <stdio.h>
#define N 100

FILE *fp1,*fp2;

int n,k;
char a[N+2][N+2];

void input(void)
{
    int i,j;

    fscanf(fp1,"%d %d ",&n,&k);
    k%=360;
    k/=90;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            fscanf(fp1,"%c ",&a[i][j]);
        }
    }
}

void turn(void)
{
    int i,j;
    char t[N+2][N+2];

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            t[i][j]=a[i][j];
        }
    }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            a[j][n-i+1]=t[i][j];
        }
    }
}

void process(void)
{
    int i;

    for(i=1; i<=k; i++)
    {
        turn();
    }
}

void output(void)
{
    int i,j;

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            fprintf(fp2,"%c ",a[i][j]);
        }
        fprintf(fp2,"\n");
    }
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    output();
    return 0;
}
