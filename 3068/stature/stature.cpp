#include <stdio.h>
#define N 50000
#include <algorithm>
using namespace std;

FILE *fp1,*fp2;

int n;
int k;
double a[N+1];

void input(void)
{
    int i;

    fscanf(fp1,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%lf",&a[i]);
    }
    fscanf(fp1,"%d",&k);
    sort(a+1,a+n+1);
}

void output(void)
{
    fprintf(fp2,"%.2f",a[n-k+1]);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    output();
    return 0;
}
