#include <stdio.h>
#define N 100
#include <algorithm>
using namespace std;
typedef pair<int,int> pp;

FILE *fp1,*fp2;

int n;
pp a[N+1];
int sm;

void input(void)
{
    int i;

    fscanf(fp1,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%d",&a[i].first);
        a[i].second=i;
    }
    sort(a+1,a+n+1);
}

void process(void)
{
    int i;

    for(i=1; i<=n; i++)
    {
        sm+=(n-i+1)*a[i].first;
    }
    fprintf(fp2,"%d\n",sm);
    for(i=1; i<=n; i++)
    {
        fprintf(fp2,"%d ",a[i].second);
    }
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    return 0;
}
