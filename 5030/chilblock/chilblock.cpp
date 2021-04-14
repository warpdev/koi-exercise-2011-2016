#include <stdio.h>
#define N 100

FILE *fp1,*fp2;

int n;
int a[N+1];
int b[N+1];
int ck[N+1];
int ck1[N+1];

void input(void)
{
    int i;

    fscanf(fp1,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%d",&a[i]);
    }
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%d",&b[i]);
    }
}

int mx(int x,int y)
{
    if(x>y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

int mn(int x,int y)
{
    if(x<y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

void process(void)
{
    int i,j;
    int sm=0;

    for(i=1; i<=n; i++)
    {
        ck[a[i]]++;
    }
    for(i=1; i<=n; i++)
    {
        ck1[b[i]]++;
    }
    for(i=1; i<=n; i++)
    {
        sm+=mx(ck1[i],ck[i])*i;
    }
    fprintf(fp2,"%d ",sm);
    sm=0;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            sm+=mn(a[i],b[j]);
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
