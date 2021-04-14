#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 160
typedef pair<int,int> pp;
typedef pair<double,pp> ppp;

FILE *fp1,*fp2;

int n;
ppp s[N*N+N];
int cnt;

void input(void)
{
    int i,j;

    fscanf(fp1,"%d",&n);
    for(i=2; i<=n; i++)
    {
        for(j=1; j<i; j++)
        {
            if(j==1 || i%j!=0)
            {
                cnt++;
                s[cnt].first=(double)i/(double)j;
                s[cnt].second.first=i;
                s[cnt].second.second=j;
            }
        }
    }
    sort(s+1,s+cnt+1);
}

void process(void)
{
    int i;

    fprintf(fp2,"0/1\n");
    for(i=cnt; i>=1; i--)
    {
        fprintf(fp2,"%d/%d\n",s[i].second.second,s[i].second.first);
    }
    fprintf(fp2,"1/1\n");
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    return 0;
}
