#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 100
typedef pair<int,int> pp;

FILE *fp1,*fp2;

int n,k;
pp a[N+1];
int s[N+1][N+1];
int cnt;

void input(void)
{
    int i;

    fscanf(fp1,"%d %d",&n,&k);

    for(i=1; i<=k; i++)
    {
        fscanf(fp1,"%d %d",&a[i].first,&a[i].second);
    }
}

void process(void)
{
    int i,j;

    for(i=1; i<=k; i++)
    {
        for(j=1; j<=n; j++)
        {
            s[a[i].first][j]++;
            s[j][a[i].second]++;
        }
        s[a[i].first][a[i].second]--;
        for(j=1; j<=n; j++)
        {
            if(a[i].first+j<=n && a[i].second+j<=n)
            {
                s[a[i].first+j][a[i].second+j]++;
            }
            if(a[i].first-j>=1 && a[i].second-j>=1)
            {
                s[a[i].first-j][a[i].second-j]++;
            }
            if(a[i].first+j<=n && a[i].second-j>=1)
            {
                s[a[i].first+j][a[i].second-j]++;
            }
            if(a[i].first-j>=1 && a[i].second+j>=1)
            {
                s[a[i].first-j][a[i].second+j]++;
            }
        }
    }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(s[i][j]==k)
            {
                cnt++;
            }
        }
    }
    fprintf(fp2,"%d",cnt);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    return 0;
}
