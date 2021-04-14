#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define N 100000

FILE *fp1,*fp2;

queue<int> Q;
int n;
int a[N+1][5];
int cnt[N+1];
int ck[N+1];

void input(void)
{
    int i,j;
    int t;

    fscanf(fp1,"%d",&n);
    for(i=1; i<=n; i++)
    {
        ck[i]=1;
        Q.push(i);
        fscanf(fp1,"%d",&t);
        cnt[i]=t;
        for(j=1; j<=t; j++)
        {
            fscanf(fp1,"%d",&a[i][j]);
        }
    }
}

int ckc(int y)
{
    int i;
    int tcnt=0;

   /* if(cnt[y]==1 || cnt[y]==0)
    {
        return 0;
    }*/
    for(i=1; i<=3; i++)
    {
        if(ck[y]==ck[a[y][i]])
        {
            tcnt++;
        }
        if(tcnt>1)
        {
            return 1;
        }
    }
    return 0;
}

void process(void)
{
    int i;
    int x;

    while(!Q.empty())
    {
        x=Q.front();
        Q.pop();
        if(ckc(x))
        {
            Q.push(x);
            ck[x]=3-ck[x];
        }
       // if(Q.size()%10000==0)
        //printf("%d\n",Q.size());
        /*for(i=1; i<=n; i++)
        {
            printf("%d ",ck[i]);
        }
        printf("\n");*/

    }
    for(i=1; i<=n; i++)
    {
        if(ckc(i))
        {
            Q.push(i);
        }
    }
}

void output(void)
{
    int i;
    int tcnt=0;

    for(i=1; i<=n; i++)
    {
        if(ck[n]!=ck[i])
        {
            tcnt++;
        }
    }
    if(tcnt==0)
    {
        ck[1]=3-ck[n];
    }
    for(i=1; i<=n; i++)
    {
        if(ck[i]==1)
        {
            fprintf(fp2,"%d ",i);
        }
    }
    fprintf(fp2,"\n");
    for(i=1; i<=n; i++)
    {
        if(ck[i]==2)
        {
            fprintf(fp2,"%d ",i);
        }
    }
}

int main(void)
{
    int i;
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    while(!Q.empty())
    {
        process();
    }
    output();
    return 0;
}
