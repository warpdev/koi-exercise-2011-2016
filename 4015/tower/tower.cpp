#include <stdio.h>
#define N 100
#include <algorithm>
using namespace std;
typedef pair<int,int> pp;
typedef pair<pp,pp> ppp;

FILE *fp1,*fp2;

int n;
ppp a[N+1];
pp dy[N+1];
int path[N+1];
int id;
int mx;

void input(void)
{
    int i;

    fscanf(fp1,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%d %d %d",&a[i].first.first,&a[i].second.first,&a[i].first.second);
        a[i].second.second=i;
    }
    sort(a+1,a+n+1);
}

void process(void)
{
    int i,j;
    int p[N+1]={0};
    int k;

    for(i=1; i<=n; i++)
    {
        for(j=0; j<i; j++)
        {
            if(dy[i].first<dy[j].first+a[i].second.first)
            {
                if(a[i].first.second>=a[j].first.second)
                {
                    dy[i].first=dy[j].first+a[i].second.first;
                    dy[i].second=dy[j].second+1;
                    path[i]=j;
                }
            }
        }
        if(mx<dy[i].first)
        {
            mx=dy[i].first;
            k=dy[i].second;
            id=i;
        }
    }
    for(i=1; i<=k; i++)
    {
        p[k-i+1]=id;
        id=path[id];
    }
    fprintf(fp2,"%d\n",k);
    for(i=1; i<=k; i++)
    {
        fprintf(fp2,"%d\n",a[p[i]].second.second);
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
