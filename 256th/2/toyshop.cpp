#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 25000
typedef pair<double,double> pp;
typedef pair<pp,pp> ppp;

FILE *fp1,*fp2;

int n;
ppp a[N+1];
double s;

void input(void)
{
    int i;

    fscanf(fp1,"%d",&n);
    for(i=1; i<=n ; i++)
    {
        fscanf(fp1,"%d %d",&a[i].second.first,&a[i].first.second);
        a[i].first.first=a[i].second.first/a[i].first.second;
        a[i].second.second=i;
    }
    sort(a+1,a+n+1);
}

void process(void)
{
    int i;

    for(i=n; i>=n-2; i--)
    {
        s+=a[i].first.second;
    }
    fprintf(fp2,"%d\n",s);
    for(i=n; i>=n-2; i--)
    {
        fprintf(fp2,"%.0f\n",a[i].second.second);
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
