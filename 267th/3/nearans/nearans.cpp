#include <stdio.h>
#define N 10000
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;
#include <vector>

FILE *fp1,*fp2;

int n;
int a[N+1];
int x,y;
int s[3][N+1];
int ck[N+1];
queue<int> Q;

void input(void)
{
    int i,x1,y1;

    fscanf(fp1,"%d",&n);
    for(i=1; i<n; i++)
    {
        fscanf(fp1,"%d %d",&x1,&y1);
        a[y1]=x1;
    }
    fscanf(fp1,"%d %d",&x,&y);
}

void process(void)
{
    int i,j,tx;

    Q.push(x);
    while(!Q.empty())
    {
        tx=Q.front();
        Q.pop();
        if(!ck[tx])
        {
            ck[tx]=1;
            Q.push(a[tx]);
        }
    }
    Q.push(y);
    while(!Q.empty())
    {
        tx=Q.front();
        Q.pop();
        if(!ck[tx])
        {
            ck[tx]=1;
            Q.push(a[tx]);
        }
        else
        {
            fprintf(fp2,"%d",tx);
            break;
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
