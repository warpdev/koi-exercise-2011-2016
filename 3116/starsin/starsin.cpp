#include <stdio.h>
#define N 100
#include <algorithm>
using namespace std;
typedef pair<int,int> pp;

FILE *fp1,*fp2;

int n;
pp a[N+1];
int tm;
int mx;

void input(void)
{
    int i;

    fscanf(fp1,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%d %d",&a[i].first,&a[i].second);
    }
    sort(a+1,a+n+1);
}

void process(int lev,int cnt)
{
    int i;

    if(lev>n)
    {
        if(cnt>mx)
        {
            mx=cnt;
        }
    }
    else
    {
        for(i=lev; i<n+lev-mx; i++)
        {
            if(i<=n && a[lev-1].second<=a[i].first)
            {
                process(i+1,cnt+1);
            }
        }
        if(cnt>mx)
        {
            mx=cnt;
        }
    }
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process(1,0);
    fprintf(fp2,"%d",mx);
    return 0;
}
