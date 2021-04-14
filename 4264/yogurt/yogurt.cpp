#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 10000
typedef pair<int,int> pp;

FILE *fp1,*fp2;

pp a[N+1];
int n,s;
__int64 sm;
int k[N+1];

void input(void)
{
    int i;

    fscanf(fp1,"%d %d",&n,&s);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%d %d",&a[i].first,&a[i].second);
    }
}

void process(void)
{
    int i,j;

    for(i=1; i<=n; i++)
    {
        for(j=i+1; j<=n; j++)
        {
            if((a[j].first-a[i].first)>s*(j-i) && !k[j])
            {
                k[j]=1;
                sm+=a[i].first*a[j].second;
                sm+=s*a[j].second*(j-i);
            }
        }
        if(!k[i])
        {
            sm+=a[i].first*a[i].second;
        }
    }
    fprintf(fp2,"%I64d",sm);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    return 0;
}
