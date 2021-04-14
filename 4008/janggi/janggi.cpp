#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define N 100
typedef pair<int,int> pp;
typedef pair<int,pp> ppp;

FILE *fp1,*fp2;

int n;
pp a[N+1];
int dx[8]={2,3,3,2,-2,-3,-3,-2};
int dy[8]={3,2,-2,-3,-3,-2,2,3};
int sm;
int k;
priority_queue<ppp,vector<ppp>,greater<ppp> > Q;

void process(void)
{
    int i;
    int ck[8][8]={0};
    int x,y,w;

    while(!Q.empty())
    {
        w=Q.top().first;
        x=Q.top().second.first;
        y=Q.top().second.second;
        Q.pop();
        if(x==a[k].first && y==a[k].second)
        {
            sm+=w;
            break;
        }
        if(x>=1 && y>=1 && x<=7 && y<=7 && !ck[x][y])
        {
            ck[x][y]=1;
            for(i=0; i<=7; i++)
            {
                Q.push(make_pair(w+1,make_pair(x+dy[i],y+dx[i])));
            }
        }
    }
    while(!Q.empty())
    {
        Q.pop();
    }
}

void input(void)
{
    int i;

    fscanf(fp1,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%d %d",&a[i].first,&a[i].second);
    }
    for(i=1; i<n; i++)
    {
        Q.push(make_pair(0,make_pair(a[i].first,a[i].second)));
        k=i+1;
        process();
    }
    fprintf(fp2,"%d",sm);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    return 0;
}
