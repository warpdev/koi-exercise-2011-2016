#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 100000

FILE *fp1,*fp2;

int n;
int a[N+1];

void input(void)
{
    int i;
    int k;
    int t;

    fscanf(fp1,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%d",&a[i]);
    }
    fscanf(fp1,"%s",&t);
    sort(a+1,a+n+1);
    fscanf(fp1,"%d",&k);
    for(i=1; i<=k; i++)
    {
        fscanf(fp1,"%d",&t);
        fprintf(fp2,"%d\n",a[t]);
    }
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    return 0;
}
