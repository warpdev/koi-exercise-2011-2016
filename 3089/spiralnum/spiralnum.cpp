#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
#define N 30
typedef pair<int,int> pp;
typedef pair<pp,pp> ppp;

FILE *fp1,*fp2;

int n;
int a[N+1][N+1];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1,};
queue<ppp> Q;

void input(void)
{
    fscanf(fp1,"%d",&n);
    Q.push(make_pair(make_pair(n,1),make_pair(n*n,3)));
}

void process(void)
{
    int i;
    int x,y,w,z;
    int tx,ty;

    while(!Q.empty())
    {
        x=Q.front().first.first;
        y=Q.front().first.second;
        w=Q.front().second.first;
        z=Q.front().second.second;
        Q.pop();
        a[x][y]=w;
        tx=x+dy[z];
        ty=y+dx[z];
        if(tx<=n && ty<=n && tx>=1 && ty>=1 && !a[tx][ty])
        {
            Q.push(make_pair(make_pair(tx,ty),make_pair(w-1,z)));
        }
        else
        {
            z++;
            z%=4;
            tx=x+dy[z];
            ty=y+dx[z];
            if(tx<=n && ty<=n && tx>=1 && ty>=1 && !a[tx][ty])
                Q.push(make_pair(make_pair(tx,ty),make_pair(w-1,z)));
        }
    }
}

void output(void)
{
    int i,j;

    if(n<=3)
    {
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                fprintf(fp2,"%d ",a[i][j]);
            }
            fprintf(fp2,"\n");
        }
    }
    else if(n>=5 && n<=9)
    {
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                fprintf(fp2,"%2d ",a[i][j]);
            }
            fprintf(fp2,"\n");
        }
    }
    else
    {
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                fprintf(fp2,"%3d ",a[i][j]);
            }
            fprintf(fp2,"\n");
        }
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
