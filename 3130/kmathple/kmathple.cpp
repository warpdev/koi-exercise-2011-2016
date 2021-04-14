#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
#define N 150
typedef pair<int,int> pp;
typedef pair<pp,int> ppp;

FILE *fp1,*fp2;

int a[N+1][N+1];
int x,y;
int dx[8]={1,2,2,1,-1,-2,-2,-1};
int dy[8]={2,1,-1,-2,-2,-1,1,2};
int hx,hy;
queue<ppp> Q;
int ck[N+1][N+1];

void input(void)
{
    int i,j;
    char t[N+1];

    fscanf(fp1,"%d %d",&x,&y);
    for(i=1; i<=y; i++)
    {
        fscanf(fp1,"%s",&t[1]);
        for(j=1; j<=x; j++)
        {
            if(t[j]!='*')
            {
                a[i][j]=1;
            }
            if(t[j]=='K')
            {
                Q.push(make_pair(make_pair(i,j),0));
            }
            if(t[j]=='H')
            {
                hx=i;
                hy=j;
            }
        }
    }
}

void process(void)
{
    int i,j;
    int tx,ty,w;

    while(!Q.empty())
    {
        tx=Q.front().first.first;
        ty=Q.front().first.second;
        w=Q.front().second;
        Q.pop();
        if(!ck[tx][ty] && a[tx][ty])
        {
            ck[tx][ty]=1;
            if(tx==hx && ty==hy)
            {
                fprintf(fp2,"%d",w);
                break;
            }
            for(i=0; i<=7; i++)
            {
                if(tx+dy[i]<=y && tx+dy[i]>=1 && ty+dx[i]<=x && ty+dx[i]>=1)
                {
                    Q.push(make_pair(make_pair(tx+dy[i],ty+dx[i]),w+1));
                }
            }
        }
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
