#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 10000

FILE *fp1,*fp2;

int n;
int a[N+1];
int m;
int mx,cst;
int lef,rig,mid;

void input(void)
{
    int i;

    fscanf(fp1,"%d",&n);

    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%d",&a[i]);
    }
    fscanf(fp1,"%d",&m);
    sort(a+1,a+n+1);
}

int ok(int x)
{
    int j;
    int sm;

    sm=0;
    for(j=1; j<=n; j++)
    {
        if(a[j]>x)
        {
            sm+=x;
        }
        else
        {
            sm+=a[j];
        }
    }
    if(sm<=m && sm>mx)
    {
        mx=sm;
        cst=x;
        return 1;
    }
    else if(sm>m)
    {
        return 0;
    }
}

void process(void)
{
    int i,j;
    int t=a[1];
    int sm;

    lef=1;
    rig=a[n];
    mid=(lef+rig)/2;
    while(lef<=rig)
    {
        if(ok(mid))
        {
            lef=mid+1;
        }
        else
        {
            rig=mid-1;
        }
        mid=(lef+rig)/2;
    }
    fprintf(fp2,"%d",cst);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    return 0;
}
