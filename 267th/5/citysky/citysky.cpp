#include <stdio.h>
#define N 50000
#include <algorithm>
using namespace std;
typedef pair<int,int> pp;

FILE *fp1,*fp2;

int n,w;
pp a[N+1];
int ck[N+1];
int cnt;

void input(void)
{
    int i;

    fscanf(fp1,"%d %d",&n,&w);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%d %d",&a[i].first,&a[i].second);
    }
}

void process(void)
{
    int i,j,tx,ty;

    for(i=1; i<=n; i++)
    {
        if(a[i].second)
        {
            ty=a[i].second;
            for(j=i; j<=n; j++)
            {
                if(ty>a[j].second)
                {
                    break;
                }
                else if(ty==a[j].second)
                {
                    a[j].second=0;
                }
            }
            a[i].second=0;
            cnt++;
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
