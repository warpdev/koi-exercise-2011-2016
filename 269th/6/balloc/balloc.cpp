#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 100000
typedef pair<int,int> pp;
typedef pair<int,pp> ppp;

FILE *fp1,*fp2;

int n,m;
int a[N+1];
int cnt;
ppp s[N+1];

void input(void)
{
    int i;

    fscanf(fp1,"%d %d",&n,&m);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%d",&a[i]);
    }
    for(i=1; i<=m; i++)
    {
        fscanf(fp1,"%d %d",&s[i].second.first,&s[i].second.second);
        s[i].first=s[i].second.second-s[i].second.first;
    }
    sort(s+1,s+m+1);
}

int ok(int x,int y)
{
    int i,j;

    for(i=x; i<=y; i+=1)
    {
        if(!a[i])
        {
            for(j=x; j<=i; a[j]++ && j++);
            return 0;
        }
        a[i]--;
    }
    return 1;
}

void process(void)
{
    int i;

    for(i=1; i<=m; i++)
    {
        cnt+=ok(s[i].second.first,s[i].second.second);
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
