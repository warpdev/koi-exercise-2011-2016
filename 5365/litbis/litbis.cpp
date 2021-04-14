#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 8

FILE *fp1,*fp2;

int n,k;
int cnt;
int blc,whc;
int bl[N+1];
int wh[N+1];
int dbl[N*N+1];
int dwh[N*N+1];

void input(void)
{
    int i,tcnt=0;

    fscanf(fp1,"%d %d",&n,&k);

    if(n%2==1)
    {
        for(i=1; i<=n; i+=2)
        {
            blc++;
            bl[blc]=i;
        }
        for(i=n-2; i>=1; i-=2)
        {
            blc++;
            bl[blc]=i;
        }
        sort(bl+1,bl+blc+1);
        for(i=2; i<=n-1; i+=2)
        {
            whc++;
            wh[whc]=i;
        }
        for(i=n-1; i>=2; i-=2)
        {
            whc++;
            wh[whc]=i;
        }
        sort(wh+1,wh+whc+1);
    }
    else
    {
        for(i=1; i<=n; i+=2)
        {
            whc++;
            bl[whc]=i;
            wh[whc]=i;
        }
        for(i=n-1; i>=1; i-=2)
        {
            whc++;
            bl[whc]=i;
            wh[whc]=i;
        }
        blc=whc;
        sort(wh+1,wh+whc+1);
        sort(bl+1,bl+whc+1);
    }
}

int bsv(int y,int lev,int x,int hn)
{
    int i,tx=0;

    if(y==0)
    {
        return x;
    }
    else
    {
        for(i=lev; i<=blc; i++)
        {
            tx+=bsv(y-1,i+1,x*(bl[i]+y-hn),hn);
        }
        return tx;
    }
}

int wsv(int y,int lev,int x,int hn)
{
    int i,tx=0;

    if(y==0)
    {
        return x;
    }
    else
    {
        for(i=lev; i<=whc; i++)
        {
            tx+=wsv(y-1,i+1,x*(wh[i]+y-hn),hn);
        }
        return tx;
    }
}

void process(void)
{
    int i;

    for(i=0; i<=k; i++)
    {
        dwh[i]=wsv(i,1,1,i);
        dbl[i]=bsv(k-i,1,1,k-i);
        cnt+=dwh[i]*dbl[i];
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
