#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
#define N 1000
typedef pair<int,int> pp;

FILE *fp1,*fp2;

int r,c;
int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,-1,1,1,-1};
int a[N+1][N+1];
int cnt;

void input(void)
{
    int i,j;

    fscanf(fp1,"%d %d",&r,&c);
    for(i=1; i<=r; i++)
    {
        for(j=1; j<=c; j++)
        {
            fscanf(fp1,"%d",&a[i][j]);
        }
    }
}

void cln(int x,int y)
{
    int i,tx,ty,kx,ky;
    queue<pp> Q;

    Q.push(make_pair(x,y));
    while(!Q.empty())
    {
        kx=Q.front().first;
        ky=Q.front().second;
        Q.pop();
        if(a[kx][ky])
        {
            a[kx][ky]=0;
            for(i=0; i<=7; i++)
            {
                tx=kx+dy[i];
                ty=ky+dx[i];
                if(tx>=1 && ty>=1 && tx<=r && ty<=c)
                {
                    Q.push(make_pair(tx,ty));
                }
            }
        }
    }
}

void process(void)
{
    int i,j;

    for(i=1; i<=r; i++)
    {
        for(j=1; j<=c; j++)
        {
            if(a[i][j])
            {
                cln(i,j);
                cnt++;
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
