#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
#define N 1000

FILE *fp1,*fp2;

int n;
int a[N+1][3];
queue<int> Q;

void input(void)
{
    int i;
    int x,y,w;

    fscanf(fp1,"%d",&n);

    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%d %d %d",&x,&y,&w);
        a[x][1]=y;
        a[x][2]=w;
    }
}

void lin1(int lev)
{
    if(!lev){return;}
    fprintf(fp2,"%d ",lev);
    lin1(a[lev][1]);
    lin1(a[lev][2]);
}

void lin2(int lev)
{
    if(!lev){return;}
    lin2(a[lev][1]);
    fprintf(fp2,"%d ",lev);
    lin2(a[lev][2]);
}

void lin3(int lev)
{
    if(!lev){return;}
    lin3(a[lev][1]);
    lin3(a[lev][2]);
    fprintf(fp2,"%d ",lev);
}

void bfs(void)
{
    int x;

    Q.push(1);
    while(!Q.empty())
    {
        x=Q.front();
        Q.pop();
        if(x!=0)
        {
            fprintf(fp2,"%d ",x);
            Q.push(a[x][1]);
            Q.push(a[x][2]);
        }
    }
}

int main(void)
{
    int i;

    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    lin1(1);
    fprintf(fp2,"\n");
    lin2(1);
    fprintf(fp2,"\n");
    lin3(1);
    fprintf(fp2,"\n");
    bfs();
    return 0;
}
