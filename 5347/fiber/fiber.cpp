#include <stdio.h>
#include <algorithm>
using namespace std;
#include <queue>
#define N 1000

FILE *fp1,*fp2;

int n,p;
int sm;
int mx=1000000;
priority_queue<int> Q[2*N+1];

void input(void)
{
    int i,x,y;

    fscanf(fp1,"%d %d",&n,&p);
    for(i=1; i<=p; i++)
    {
        fscanf(fp1,"%d %d",&x,&y);
        if(x<y)
        {
            Q[x].push(y);
        }
        else
        {
            Q[y].push(x);
        }
    }
}

void process(void)
{
    int i,j,t,x,tx=2*n,y,tmx;

    for(i=1; i<=n; i++)
    {
        sm=0;
        tmx=0;
        t=i+n;
        for(j=i; j<=t; j++)
        {
            if(!Q[j].empty())
            {
                x=j;
                y=Q[j].top();
                if(tmx<y)
                {
                    tmx=y;
                }
                //printf("%d %d %d\n",i,j,y);
            }
        }
        for(j=i; j<=t; j++)
        {
            if(!Q[j].empty())
            {
                x=j;
                y=Q[j].top();
                sm+=tmx-j;
                //printf("%d %d %d\n",i,j,y);
                j=tmx;
            }
        }
        while(!Q[i].empty())
        {
            if(t<=tx)
            {
                y=Q[i].top();
                Q[y].push(t);
                //Q[t].push(y+n);
            }
            Q[i].pop();
        }
        if(sm<mx && sm)
        {
            mx=sm;
        }
    }
    fprintf(fp2,"%d",mx);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
}
