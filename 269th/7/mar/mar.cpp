#include <stdio.h>
#include <stdlib.h>
#define N 10000

FILE *fp1,*fp2;

bool a[N+2][N+2];
int n;
int sm;

void input(void)
{
    int i,j,k,x,y,w,z;

    fscanf(fp1,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%d %d %d %d",&x,&y,&w,&z);
        if(x<=N && y<=N && w<=N && z<=N)
        {
            for(j=x; j<w; j++)
            {
                for(k=y; k<z; k++)
                {
                    a[j][k]=1;
                }
            }
        }
        else
        {
            if(x<=N || y<=N || w<=N || z<=N)
            {
                fprintf(fp2,"%d",(w-x)*(z-y));
                exit(0);
            }
            else
            {
                sm+=(w-x)*(z-y);
            }
        }
    }
}

void process(void)
{
    int i,j;

    for(i=0; i<=N; i++)
    {
        for(j=0; j<=N; j++)
        {
            sm+=a[i][j];
        }
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

