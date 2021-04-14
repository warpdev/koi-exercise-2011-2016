#include <stdio.h>
#include <stdlib.h>
#define N 15000

FILE *fp1,*fp2;

int n,m;
int a[30+1];
int b[10+1];
int dy[N+1];
int t;

void input(void)
{
    int i;

    fscanf(fp1,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%d",&a[i]);
        t+=a[i];
    }
    fscanf(fp1,"%d",&m);
    for(i=1; i<=m; i++)
    {
        fscanf(fp1,"%d",&b[i]);
    }
    dy[0]=1;
}

void process(void)
{
    int i,j;

    for(i=1; i<=n; i++)
    {
        for(j=0; j<=t; j++)
        {
            if(dy[j]==1)
            {
                if(dy[abs(j-a[i])]==0)
                {
                    dy[abs(j-a[i])]=2;
                }
                if(dy[j+a[i]]==0)
                {
                    dy[j+a[i]]=2;
                }
            }
        }
        for(j=0; j<=t; j++)
        {
            if(dy[j]==2)
            {
                dy[j]=1;
            }
        }
    }
    for(i=1; i<=m; i++)
    {
        if(dy[b[i]])
        {
            fprintf(fp2,"Y ");
        }
        else
        {
            fprintf(fp2,"N ");
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
