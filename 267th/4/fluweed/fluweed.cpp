#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define N 100
typedef pair<int,int> pp;
typedef pair<int,pp> ppp;

FILE *fp1,*fp2;

int nx,ny;
int ck[N+1][N+1];
int cnt;
int dx[8]={1,1,1,0,-1,-1,-1,0};
int dy[8]={-1,0,1,1,1,0,-1,-1};
queue<ppp> Q;

void input(void)
{
    int i,j;
    int tx,ty;
    char t[N+2];

    fscanf(fp1,"%d %d %d %d",&ny,&nx,&tx,&ty);
    Q.push(make_pair(0,make_pair(ty,tx)));
    for(i=nx; i>=1; i--)
    {
        fscanf(fp1,"%s",&t[1]);
        for(j=1; j<=ny; j++)
        {
            if(t[j]=='*')
            {
                ck[i][j]=1;
            }
        }
    }
}

void process(void)
{
    int i,j,x,y,w;

    while(!Q.empty())
    {
        x=Q.front().second.first;
        y=Q.front().second.second;
        w=Q.front().first;
        Q.pop();
        if(!ck[x][y])
        {
            ck[x][y]=1;
            for(i=0; i<=7; i++)
            {
                if(x+dy[i]>=1 && y+dx[i]>=1 && x+dy[i]<=nx && y+dx[i]<=ny)
                {
                    Q.push(make_pair(w+1,make_pair(x+dy[i],y+dx[i])));
                }
            }
            if(cnt<w)
            {
                cnt=w;
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
