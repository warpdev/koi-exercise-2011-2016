#include <stdio.h>
#include <stdlib.h>
#define N 80

FILE *fp1,*fp2;

int n;
int a[N+1];

void input(void)
{
    fscanf(fp1,"%d",&n);
}

int ck(int x)
{
    int i,j;
    int t[N+1]={0};

    if(x==1)
    {
        return 1;
    }
    for(i=1; i<=x/2; i++)
    {
        for(j=x; j>=x-i+1; j--)
        {
            if(a[j]!=a[j-i])
            {
                t[i]=1;
                break;
            }
        }
    }
    for(i=1; i<=x/2; i++)
    {
        if(!t[i])
        {
            return 0;
        }
    }
    return 1;
}

void process(int lev)
{
    int i;

    if(lev>n)
    {
        for(i=1; i<=n; i++)
        {
            fprintf(fp2,"%d",a[i]);
        }
        exit(0);
    }
    else
    {
        for(i=1; i<=3; i++)
        {
            a[lev]=i;
            if(ck(lev))
            {
                process(lev+1);
            }
        }
    }
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process(1);
    return 0;
}
