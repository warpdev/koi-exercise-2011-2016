#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 2000000
typedef pair<int,int> pp;
typedef pair<pp,int> ppp;

FILE *fp1,*fp2;

int n,m,r;
ppp a[1000+1];
int dy[N+1];
int s;

void input(void)
{
    int i;

    fscanf(fp1,"%d %d %d",&n,&m,&r);
    for(i=1; i<=m; i++)
    {
        fscanf(fp1,"%d %d %d",&a[i].first.first,&a[i].first.second,&a[i].second);
        a[i].first.second=a[i].first.second+r-1;
    }
    sort(a+1,a+m+1);
    n=n+r-1;
}

void process(void)
{
    int i,j;
    int mx;

    for(i=1; i<=m; i++)
    {
        mx=0;
        for(j=a[i].first.first-1; j>=0; j--)
        {
            if(dy[j])
            {
                dy[a[i].first.first-1]=dy[j];
                break;
            }
        }
        dy[a[i].first.second]=a[i].second+dy[j];
        if(s<dy[a[i].first.second])
        {
            s=dy[a[i].first.second];
        }
    }
    fprintf(fp2,"%d",s);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    return 0;
}
