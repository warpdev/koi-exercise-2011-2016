#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stdlib.h>
using namespace std;
#define N 50
typedef pair<int,int> pp;
typedef pair<pp,int> ppp;

FILE *fp1,*fp2;

int m,n;
int a[N+1][N+1];
int ck[N+1][N+1];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
queue<ppp> Q;
int kx,ky;

void input(void)
{
    int i,j;
    char t[N+5];

    fscanf(fp1,"%d %d",&m,&n);
    for(i=1; i<=m; i++)
    {
        fscanf(fp1,"%s",&t[1]);
        for(j=1; j<=n; j++)
        {
            if(t[j]=='@' || t[j]=='+')
            {
                ck[i][j]=1;
            }
            else if(t[j]=='1')
            {
                Q.push(make_pair(make_pair(i,j),0));
            }
            else if(t[j]=='2')
            {
                kx=i;
                ky=j;
            }
        }
    }
}

void process(void)
{
    int i,j;
    int x,y,w;
    int tx,ty;

    while(!Q.empty())
    {
        x=Q.front().first.first;
        y=Q.front().first.second;
        w=Q.front().second;
        Q.pop();
        if(x==kx && y==ky)
        {
            fprintf(fp2,"%d",w-1);
            exit(0);
        }
        if(!ck[x][y])
        {
            ck[x][y]=1;
            for(i=0; i<=3; i++)
            {
                tx=x+dy[i];
                ty=y+dx[i];
                if(tx>=1 && tx<=m && ty>=1 && ty<=n)
                {
                    Q.push(make_pair(make_pair(tx,ty),w+1));
                }
            }
        }
    }
    fprintf(fp2,"-1");
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    return 0;
}
