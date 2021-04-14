#include <stdio.h>
#define N 7

FILE *fp1,*fp2;

int s,n;
int a[N+1];

void input(void)
{
    fscanf(fp1,"%d %d",&s,&n);
}

void process(int x,int lev,int sm)
{
    int i;

    if(sm>s)
    {
        return;
    }
    if(lev==n)
    {
        if(s-sm>x)
        {
            a[lev]=s-sm;
            for(i=1; i<=n; i++)
            {
                fprintf(fp2,"%d ",a[i]);
            }
            fprintf(fp2,"\n");
        }
        return;
    }
    else
    {
        for(i=x+1; i<=s; i++)
        {
            a[lev]=i;
            process(i,lev+1,sm+i);
        }
    }
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process(0,1,0);
    return 0;
}
