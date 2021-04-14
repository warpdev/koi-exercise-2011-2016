#include <stdio.h>
#define N 20

FILE *fp1,*fp2;

int n,t,m;
int a[N+1];
int dy[N+1][N+1][N+1];
int mx[N+1][N+1];
int cnt;

void input(void)
{
    int i;

    fscanf(fp1,"%d %d %d",&n,&t,&m);

    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%d",&a[i]);
    }
}

void process(void)
{
    int i,j,k,l;
    int tmx=0;

    for(i=1; i<=m; i++)
    {
        for(j=1; j<=n; j++)
        {
            tmx=0;
            for(k=a[j]; k<=t; k++)
            {
                for(l=0; l<=j-1; l++)
                {
                    if(dy[i][l][k-a[j]]+1>dy[i][j][k])
                    {
                        dy[i][j][k]=dy[i][l][k-a[j]]+1;
                    }
                    if(mx[i-1][l]+1>dy[i][j][k])
                    {
                        dy[i][j][k]=mx[i-1][l]+1;
                    }
                }
                if(tmx<dy[i][j][k])
                {
                    tmx=dy[i][j][k];
                }
            }
            mx[i][j]=tmx;
        }
    }
}

void output(void)
{
    fprintf(fp2,"%d",dy[m][n][t]);
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
