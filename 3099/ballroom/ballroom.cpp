#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define N 1000

FILE *fp1,*fp2;

int n;
int a[N+1];
int b[N+1];
int sm;

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
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
}

void process(void)
{
    int i;

    for(i=1; i<=n; i++)
    {
        sm+=abs(a[i]-b[i]);
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
