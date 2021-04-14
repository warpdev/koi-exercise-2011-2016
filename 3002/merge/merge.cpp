#include <stdio.h>
#define N 50000

FILE *fp1,*fp2;

int n,m,t;
int a[N+1];
int b[N+1];
int k[2*N+2];
int s[11];

void input(void)
{
    int i;

    fscanf(fp1,"%d %d %d",&n,&m,&t);
    for(i=1; i<=t; i++)
    {
        fscanf(fp1,"%d",&s[i]);
    }
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%d",&a[i]);
    }
    for(i=1; i<=m; i++)
    {
        fscanf(fp1,"%d",&b[i]);
    }
}

void process(void)
{
    int i;
    int ta=1,tb=1,tk=0;

    while(ta<=n || tb<=m)
    {
        if(tb<=m && a[ta]>b[tb] || ta>n)
        {
            tk++;
            k[tk]=b[tb];
            tb++;
        }
        else if(ta<=n && a[ta]<b[tb] || tb>m)
        {
            tk++;
            k[tk]=a[ta];
            ta++;
        }
        else if(ta<=n && tb<=m)
        {
            tk++;
            k[tk]=a[ta];
            ta++;
            tb++;
        }
    }
    fprintf(fp2,"%d\n",tk);
    for(i=1; i<=t; i++)
    {
        fprintf(fp2,"%d ",k[s[i]]);
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
