#include <stdio.h>
#define N 1000000
#include <algorithm>
using namespace std;
typedef pair<long long,long long> pp;

FILE *fp1,*fp2;

int n;
long long b;
long long cnt;
pp a[N+1];

void input(void)
{
    int i;

    fscanf(fp1,"%d %lld",&n,&b);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%lld %lld",&a[i].first,&a[i].second);
    }
    sort(a+1,a+n+1);
}

void process(void)
{
    int i;

    for(i=1; i<=n; i++)
    {
        if(a[i].first*a[i].second<=b)
        {
            b-=a[i].first*a[i].second;
            cnt+=a[i].second;
        }
        else if(a[i].first<=b)
        {
            while(a[i].first<=b)
            {
                b-=a[i].first;
                cnt++;
            }
            fprintf(fp2,"%lld",cnt);
            break;
        }
        else
        {
            fprintf(fp2,"%lld",cnt);
            break;
        }
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
