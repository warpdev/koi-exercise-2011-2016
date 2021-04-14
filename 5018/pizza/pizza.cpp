#include <stdio.h>
#define N 1000

FILE *fp1,*fp2;

int n,m,k,sm;
int a[2*N+2],b[2*N+2];
int ck[2000001];
int ck1[2000001];

void input(void)
{
    int i;

    fscanf(fp1,"%d",&k);
    fscanf(fp1,"%d %d",&n,&m);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%d",&a[i]);
        a[i+n]=a[i];
    }
    for(i=1; i<=m; i++)
    {
        fscanf(fp1,"%d",&b[i]);
        b[i+m]=b[i];
    }
    for(i=1; i<=2*n; i++)
    {
        a[i]+=a[i-1];
    }
    for(i=1; i<=m*2; i++)
    {
        b[i]+=b[i-1];
    }
}

void process(void)
{
    int i,t;

    for(t=1; t<n; t++)
    {
        for(i=t; i<=n+t-1; i++)
        {
            ck[a[i]-a[i-t]]++;
        }
    }
    ck[a[n]]++;
    ck[0]=1;
    for(t=1; t<m; t++)
    {
        for(i=t; i<=m+t-1; i++)
        {
            ck1[b[i]-b[i-t]]++;
        }
    }
    ck1[b[m]]++;
    ck1[0]=1;
    for(i=0; i<=k; i++)
    {
        sm+=ck[i]*ck1[k-i];
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
