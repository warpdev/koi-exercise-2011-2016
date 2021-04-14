#include <stdio.h>
#include <stdlib.h>
#define N 20

FILE *fp1,*fp2;

int n,m;
int a[N+1];
int s[N+1];
int bs=9999999;
int x,y;

void input(void)
{
    int i;

    fscanf(fp1,"%d",&n);
    for(i=1; i<=n; i++)
    {
        a[i]=1;
    }
    fscanf(fp1,"%d %d",&x,&y);
    a[x]=0;
    a[y]=0;
    fscanf(fp1,"%d",&m);
    for(i=1; i<=m; i++)
    {
        fscanf(fp1,"%d",&s[i]);
    }
}

void process(int lev, int lef,int rig,int sm)
{
    if(lev>m)
    {
        if(bs>sm)
        {
            bs=sm;
            return;
        }
    }
    else
    {
        process(lev+1,s[lev],rig,sm+abs(s[lev]-lef));
        process(lev+1,lef,s[lev],sm+abs(rig-s[lev]));
    }
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process(1,x,y,0);
    fprintf(fp2,"%d",bs);
    return 0;
}
