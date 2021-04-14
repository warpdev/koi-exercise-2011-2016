#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 300000

typedef pair<int,int> pp;

FILE *fp1,*fp2;

int n;
int s;
pp a[N+1];
int dy[N+1];

void input(void)
{
    int i;

    fscanf(fp1,"%d %d",&n,&s);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%d %d",&a[i].first,&a[i].second);
    }
    sort(a+1,a+n+1);
}

void process(void)
{
    int i,j;
    int id=0;

    for(i=1; i<=n; i++)
    {
        for(j=id; j<=i; j++)
        {
            if(a[i].first-a[j].first<s)
            {
                id=j-1;
                if(dy[id]+a[i].second>dy[i-1])
                {
                    dy[i]=dy[id]+a[i].second;
                }
                else
                {
                    dy[i]=dy[i-1];
                }
                break;
            }
        }
    }
    fprintf(fp2,"%d",dy[n]);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    return 0;
}
