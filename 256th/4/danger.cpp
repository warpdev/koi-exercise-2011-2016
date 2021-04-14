#include <stdio.h>
#define N 100

FILE *fp1,*fp2;

int n;
int m;
int a[N+1][N+1];
int b[10000+1];
int sm;

void input(void)
{
    int i,j;

    fscanf(fp1,"%d %d",&n,&m);
    for(i=1; i<=m; i++)
    {
        fscanf(fp1,"%d",&b[i]);
    }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            fscanf(fp1,"%d",&a[i][j]);
        }
    }
}

void process(void)
{
    int i,j,k;

    k=m-1;
    for(i=1; i<=k; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(a[b[i]][b[i+1]]>a[b[i]][j]+a[j][b[i+1]])
            {
                a[b[i]][b[i+1]]=a[b[i]][j]+a[j][b[i+1]];
            }
        }
        sm+=a[b[i]][b[i+1]];
    }
    fprintf(fp2,"%d",sm);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    return 0;
}
