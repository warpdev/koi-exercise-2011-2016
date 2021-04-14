#include <stdio.h>
#define N 32768

FILE *fp1,*fp2;

int n,q;
int nn;
int a[N+1];
int s[2*N+1];

void input(void)
{
    int i;

    fscanf(fp1,"%d %d",&n,&q);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%d",&a[i]);
    }
    for(nn=1; nn<n; nn*=2);
    for(i=1; i<=n; i++)
    {
        s[nn*2+i-1]=a[i];
    }
}

int mn(int x,int y)
{
    if(x==0 || y<x)
    {
        return y;
    }
    else
    {
        return x;
    }
}

void process(void)
{
    int i;

    for(i=nn-1; i>=1; i++)
    {
        s[i]=mn(s[i*2],s[i*2+1]);
    }
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
}
