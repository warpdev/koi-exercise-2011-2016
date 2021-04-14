#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 25
typedef pair<int,int> pp;
typedef pair<double,pp> ppp;

FILE *fp1,*fp2;

int m,n;
ppp a[N+1];
double sm;

void input(void)
{
    int i;

    fscanf(fp1,"%d %d",&m,&n);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%d %d",&a[i].second.first,&a[i].second.second);
        a[i].first=(double)a[i].second.second/(double)a[i].second.first;
    }
    sort(a+1,a+n+1);
}

void process(void)
{
    int i;
    double x,y;

    for(i=n; i>=1; i--)
    {
        if(a[i].second.first<=m)
        {
            m-=a[i].second.first;
            sm+=(double)a[i].second.second;
        }
        else if(m>0)
        {
            x=(double)a[i].second.second;
            y=(double)a[i].second.first;
            x*=(double)m;
            x/=y;
            sm+=x;
            break;
        }
    }
    fprintf(fp2,"%.1f",sm);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    return 0;
}
