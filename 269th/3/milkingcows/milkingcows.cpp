#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 5000
//typedef pair<int,int> pp;

FILE *fp1,*fp2;

int n;
int x[N+1];
int y[N+1];
int mx;
int k;

void input(void)
{
    int i;

    fscanf(fp1,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%d %d",&x[i],&y[i]);
    }
    sort(x+1,x+n+1);
    sort(y+1,y+n+1);
}

void process(void)
{
    int i;
    int t=0;

    for(i=1; i<=n; i++)
    {
        if(y[i-1]<x[i])
        {
            if(mx<x[i]-y[i-1])
            {
                mx=x[i]-y[i-1];
            }
            t=0;
            t=y[i]-x[i];
        }
        else
        {
            t+=(y[i]-y[i-1]);
        }
        if(k<t)
        {
            k=t;
        }
    }
    fprintf(fp2,"%d %d",k,mx);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    return 0;
}
