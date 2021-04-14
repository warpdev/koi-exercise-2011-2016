#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
#include <vector>
#define N 50
typedef pair<int,int> pp;
typedef pair<int,pp> ppp;

FILE *fp1,*fp2;

int n;
queue<pp> Q;
int a[N+1][N+1];
int s[N+1][N+1];
pp path[N+1][N+1];
pp p[N*N+N];
int dx[5]={1,0,-1,0};
int dy[5]={0,1,0,-1};
int fx,fy;
int cnt;
int sx,sy;

void input(void)
{
    int i,j;
    int x,y;

    fscanf(fp1,"%d",&n);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            fscanf(fp1,"%d",&a[i][j]);
            if(!a[i][j])
            {
                a[i][j]=999999;
            }
            s[i][j]=999999;
        }
    }
    fscanf(fp1,"%d %d",&sy,&sx);
     fscanf(fp1,"%d %d",&fy,&fx);
}

void process(void)
{
    int i,j;
    int x,y;
    int tx,ty;

    s[sx][sy]=0;
    Q.push(make_pair(sx,sy));

    while(!Q.empty())
    {
        x=Q.front().first;
        y=Q.front().second;
        Q.pop();

        for(i=0; i<=3; i++)
        {
            tx=x+dy[i];
            ty=y+dx[i];
            if(tx>0 && tx<=n && ty>0 && ty<=n && s[tx][ty]>s[x][y]+a[x][y])
            {
                s[tx][ty]=s[x][y]+a[x][y];
                path[tx][ty].first=x;
                path[tx][ty].second=y;
                Q.push(make_pair(tx,ty));
            }
        }
    }
    if(s[fx][fy]==999999)
    {
        fprintf(fp2,"-1");
        return;
    }
    x=fx;
    y=fy;
    while(1)
    {
        cnt++;
        p[cnt].first=x;
        p[cnt].second=y;
        if(x==sx && y==sy)
        {
            break;
        }
        tx=path[x][y].first;
        ty=path[x][y].second;
        x=tx;
        y=ty;
    }
    fprintf(fp2,"%d\n",cnt);
    for(i=cnt; i>=1; i--)
    {
        fprintf(fp2,"%d %d\n",p[i].second,p[i].first);
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
