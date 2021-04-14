#include <stdio.h>
#define N 30
#include <algorithm>
#include <stdlib.h>
using namespace std;

FILE *fp1,*fp2;

int n,s;
int a[N+1][N+1];
int path[N+1];
int ppath[N+1];
int mx;
int ck[N+1];

void input(void)
{
    int i,j,k,l;
    int ttt;
    int tmp[N+1];

    fscanf(fp1,"%d %d",&n,&s);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=s; j++)
        {
            fscanf(fp1,"%d",&tmp[j]);
        }
        sort(tmp+1,tmp+s+1);
        for(l=0; l<=n-1; l++)
        {
            if(a[l][1]<=tmp[1] && tmp[1]<a[l+1][1])
            {
                ttt=l+1;
                break;
            }
        }
        if(l>=i)
        {
            ttt=i;
        }
        for(l=n; l>=ttt; l--)
        {
            for(k=1; k<=s+1; -k++)
            {
                a[l][k]=a[l-1][k];
            }
        }
        for(k=1; k<=s; k++)
        {
            a[ttt][k]=tmp[k];
            a[0][k]=0;
        }
        a[ttt][s+1]=i;
    }
    for(i=1; i<=n; i++)
    {

        for(k=1; k<=s; k++)
        {
            a[0][k]=0;
        }
    }
}

void process(int lev,int x)
{
    int i,j;

    if(mx>lev && x>lev)
    {
        return;
    }
    if(lev>n)
    {
        fprintf(fp2,"%d\n",n);
        for(i=1; i<=n; i++)
        {
            fprintf(fp2,"%d ",path[i]);
        }
        exit(0);
    }
    else
    {
        if(mx<lev)
        {
            mx=lev-1;
            for(i=1; i<=lev; i++)
            {
                ppath[i]=path[i];
            }
        }
        for(i=x; i<=n; i++)
        {
            if(ck[i]==0)
            {
                for(j=1; j<=s; j++)
                {
                    if(a[x][j]>=a[i][j])
                    {
                        break;
                    }
                }
                if(j>s)
                {
                    ck[i]=1;
                    path[lev]=a[i][s+1];
                    process(lev+1,i);
                    ck[i]=0;
                }
            }
        }
    }
}

void output(void)
{
    int i;

    fprintf(fp2,"%d\n",mx);
    for(i=1; i<=mx; i++)
    {
        fprintf(fp2,"%d ",ppath[i]);
    }
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process(1,0);
    output();
    return 0;
}
