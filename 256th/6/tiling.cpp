#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
#define N 30
typedef pair<int,int> pp;

FILE *fp1,*fp2;

int n;
pp a[N+1];

void input(void)
{
    fscanf(fp1,"%d",&n);
    if(n%2!=0)
    {
        fprintf(fp2,"0");
        exit(0);
    }
    a[2].second=3;
}

void process(void)
{
    int i,j;
    int t;
    int x;

    x=n;

    n=2;
    while(x!=n)
    {
        n+=2;
        for(i=2; i<=n; i+=2)
        {
            a[n].first+=a[i].second*a[n-i].first;
            a[n].first+=a[i].second*a[n-i].second;
        }
        a[n].second=2;
    }
    fprintf(fp2,"%d",a[n].first+a[n].second);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    if(n==0)
    {
        fprintf(fp2,"1");
        exit(0);
    }
    process();
    return 0;
}
