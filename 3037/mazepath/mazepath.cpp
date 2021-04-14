#include <stdio.h>
#include <algorithm>
using namespace std;
#include <queue>
#define N 100
typedef pair<int,int> pp;
typedef pair<pp,pp> ppp;

FILE *fp1,*fp2;

int n;
int a[N+2][N+2];
int s[N+2][N+2];
pp path[N+2][N+2];
pp p[N*N+10];
queue<ppp> Q;
int dx[5]={1,0,-1,0,1};
int dy[5]={0,1,0,-1,1};

void input(void)
{
    int i,j;

    fscanf(fp1,"%d",&n);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            fscanf(fp1,"%d",&a[i][j]);
            s[i][j]=100000000;
        }
    }
    Q.push(make_pair(make_pair(1,4),make_pair(1,1)));
}

void process(void)
{
    int i,j,x,y,w,d;

    while(!Q.empty())
    {
        w=Q.front().first.first;
        d=Q.front().first.second;
        x=Q.front().second.first;
        y=Q.front().second.second;
        Q.pop();
        if(!a[x][y] && s[x][y]>w)
        {
            s[x][y]=w;
            path[x][y].first=x-dy[d];
            path[x][y].second=y-dx[d];
            for(i=0; i<=3; i++)
            {
                if(x+dy[i]<=n && x+dy[i]>=1 && y+dx[i]<=n && y+dx[i]>=1)
                {
                    Q.push(make_pair(make_pair(w+1,i),make_pair(x+dy[i],y+dx[i])));
                }
            }
        }
    }
}

void output(void)
{
    int i,cnt=0,x,y,tx,ty;

    x=n;
    y=n;
    while(x || y)
    {
        //printf("%d %d\n",x,y);
        cnt++;
        p[cnt].first=x;
        p[cnt].second=y;
        tx=x;
        ty=y;
        x=path[tx][ty].first;
        y=path[tx][ty].second;
    }
    fprintf(fp2,"%d\n",s[n][n]);
    for(i=cnt; i>=1; i--)
    {
        fprintf(fp2,"%d %d\n",p[i].first,p[i].second);
    }
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    output();
    return 0;
}
