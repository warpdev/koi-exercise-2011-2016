#include <stdio.h>
#define N 1000

FILE *fp1,*fp2;

int t,n,m;
int a[N+1];
int b[N+1];
int cnt;
int as[10000+1];
int bs[10000+1];

void input(void)
{
    int i;

    fscanf(fp1,"%d",&t);
    fscanf(fp1,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%d",&a[i]);
    }
    fscanf(fp1,"%d",&m);
    for(i=1; i<=m; i++)
    {
        fscanf(fp1,"%d",&b[i]);
    }
}

void process(void)
{
    int i,j;
    int tsm;

    for(i=1; i<=n; i++)
    {
        tsm=0;
        for(j=i; j<=n; j++)
        {
            tsm+=a[j];
            if(tsm<=t)
            {
                as[tsm]++;
            }
        }
    }
    for(i=1; i<=m; i++)
    {
        tsm=0;
        for(j=i; j<=m; j++)
        {
            tsm+=b[j];
            if(tsm<=t)
            {
                bs[tsm]++;
            }
        }
    }
    for(i=1; i<=t; i++)
    {
        cnt+=as[i]*bs[t-i];
    }
    fprintf(fp2,"%d",cnt);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    return 0;
}
