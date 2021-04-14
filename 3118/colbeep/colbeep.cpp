#include <stdio.h>
#include <algorithm>
using namespace std;
#include <math.h>
#define N 10
typedef pair<int,int> pp;

FILE *fp1,*fp2;

int n;
pp a[N+1];
int mn=1000000;
int x,y;
int ck[N+1];

void input(void)
{
    int i;

    fscanf(fp1,"%d %d",&x,&y);
    fscanf(fp1,"%d %d %d",&x,&y,&n);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%d %d",&a[i].first,&a[i].second);
    }
}

void process(int lev,int sm,int odx,int ody)
{
    int i;

    if(lev>n)
    {
        sm+=abs(odx-x)+abs(ody-y);
        if(mn>sm)
        {
            mn=sm;
        }
    }
    else
    {
        for(i=1; i<=n; i++)
        {
            if(!ck[i])
            {
                ck[i]=1;
                process(lev+1,sm+abs(odx-a[i].first)+abs(ody-a[i].second),a[i].first,a[i].second);
                ck[i]=0;
            }
        }
    }
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process(1,0,x,y);
    fprintf(fp2,"%d",mn);
    return 0;
}
