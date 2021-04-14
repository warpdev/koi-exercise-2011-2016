#include <stdio.h>
#define N 1000

FILE *fp1,*fp2;

int a[N+1][N+1];
int sm;

void input(void)
{
    int i,j,k;
    int x,y,w,z;

    for(k=1; k<=4; k++)
    {
        fscanf(fp1,"%d %d %d %d",&x,&y,&w,&z);
        for(i=x; i<w; i++)
        {
            for(j=y; j<z; j++)
            {
                a[i][j]=1;
            }
        }
    }
}

void process(void)
{
    int i,j;

    for(i=1; i<=N; i++)
    {
        for(j=1; j<=N; j++)
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
