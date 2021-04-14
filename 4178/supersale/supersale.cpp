#include <stdio.h>
#define N 1000
#include <algorithm>
using namespace std;
typedef pair<int,int> pp;

FILE *fp1,*fp2;

int n,g;
pp a[N+1];
int dy[32];
int b[32];
int sm;

void input(void)
{
    int i;

    fscanf(fp1,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%d %d",&a[i].first,&a[i].second);
    }
    fscanf(fp1,"%d",&g);
    for(i=1; i<=g; i++)
    {
        fscanf(fp1,"%d",&b[i]);
    }
}

void process(void)
{
    int i,j;

    for(i=1; i<=n; i++)
    {
        for(j=30 ;j>=a[i].second; j--)
        {
            if(dy[j-a[i].second]+a[i].first>dy[j])
            {
                dy[j]=dy[j-a[i].second]+a[i].first;
            }
        }
    }
    for(i=1; i<=g; i++)
    {
        sm+=dy[b[i]];
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
