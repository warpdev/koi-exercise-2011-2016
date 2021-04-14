#include <stdio.h>
#include <algorithm>
using namespace std;
#include <queue>
#include <vector>
#define N 100
typedef pair<int,int> pp;
typedef pair<int,pp> ppp;

FILE *fp1,*fp2;

int k,n,r;
priority_queue<ppp,vector<ppp>,greater<ppp> > Q;
vector<pp> a[N+1][N+1];
int dist[N+1];
int mn=99999999,s;

void input(void)
{
    int i;
    int x,y,w,z;

    fscanf(fp1,"%d %d %d",&k,&n,&r);
    for(i=1; i<=r; i++)
    {
        fscanf(fp1,"%d %d %d %d",&x,&y,&w,&z);
        a[x][y].push_back(make_pair(w,z));
    }
    Q.push(make_pair(1,make_pair(0,0)));
    dist[1]=1;
}

void process(void)
{
    int i,j;
    int x,y,w,t;

    while(!Q.empty())
    {
        x=Q.top().first;
        y=Q.top().second.first;
        w=Q.top().second.second;
        Q.pop();
        if(dist[x]<y || !dist[x])
            dist[x]=-1;
        if(x==n && w<=k && y<mn)
        {
            mn=y;
            s=w;
        }
        else if(w<=k && dist[x]>y || w<=k && dist[x]==-1)
        {
            dist[x]=y;
            for(i=1; i<=n; i++)
            {
                if(a[x][i].size()>0)
                {
                    t=a[x][i].size();
                    for(j=0; j<t; j++)
                    {
                        Q.push(make_pair(i,make_pair(y+a[x][i][j].first,w+a[x][i][j].second)));
                    }
                }
            }
        }
    }
    if(mn==99999999)
    {
        fprintf(fp2,"-1");
    }
    else
    {
        fprintf(fp2,"%d",mn);
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
