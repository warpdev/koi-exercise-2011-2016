#include <stdio.h>
#define N 100
#include <algorithm>
using namespace std;
typedef pair<int,int> pp;

FILE *fp1,*fp2;

int n;
pp a[N+1];
int dy[N+1];
int mx;

void input(void)
{
    int i,t;

    fscanf(fp1,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%d %d",&a[i].first,&a[i].second);
        if(a[i].first>a[i].second)
        {
            t=a[i].first;
            a[i].first=a[i].second;
            a[i].second=t;
        }
    }
    sort(a+1,a+n+1);
}

void process(void)
{
    int i,j;

    for(i=1; i<=n; i++)
    {
        for(j=0; j<i; j++)
        {
            if(dy[i]<dy[j]+1)
            {
                if(a[i].second>=a[j].second)
                {
                    dy[i]=dy[j]+1;
                }
            }
        }
        if(mx<dy[i])
        {
            mx=dy[i];
        }
    }
    fprintf(fp2,"%d",mx);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    return 0;
}
