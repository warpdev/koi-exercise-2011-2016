#include <stdio.h>
#define N 20

FILE *fp1,*fp2;

int n,t;
int a[N+1];
int cnt;

void input(void)
{
    int i;

    fscanf(fp1,"%d %d",&n,&t);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%d",&a[i]);
    }
}

void process(int sm,int lev)
{
    int i;

    if(sm>t)
    {
        return;
    }
    if(sm==t)
    {
        cnt++;
        return;
    }
    else
    {
        for(i=lev+1; i<=n; i++)
        {
            process(sm+a[i],i);
        }
    }
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process(0,0);
    fprintf(fp2,"%d",cnt);
    return 0;
}
