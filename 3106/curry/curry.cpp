#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
#define N 10
typedef pair<int,int> pp;

FILE *fp1,*fp2;

int n;
pp a[N+1];
int mn=1000000001;

void input(void)
{
    int i;

    fscanf(fp1,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%d %d",&a[i].first,&a[i].second);
    }
}

void process(int lev,int sm,int s)
{
    int i;

    if(mn>abs(sm-s) && s)
    {
        mn=abs(sm-s);
    }
    for(i=lev; i<=n; i++)
    {
        process(i+1,sm*a[i].first,s+a[i].second);
    }
}

void output(void)
{
    int i;

    fprintf(fp2,"%d",mn);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process(1,1,0);
    output();
    return 0;
}
