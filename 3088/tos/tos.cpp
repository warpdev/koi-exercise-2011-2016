#include <stdio.h>
#define N 1000

FILE *fp1,*fp2;

int f,n,m;
int a[N+1];
int s[N+1];
int t;

void input(void)
{
    int i;

    fscanf(fp1,"%d %d %d",&f,&n,&m);
}

void process(void)
{
    int i,j,k;
    int tt;
    int sm;
    int p;

    for(i=n; i<=m; i++)
    {
        p=i;
        sm=0;
        for(j=8; j>=1; j--)
        {
            tt=1;
            sm*=10;
            for(k=1; k<=j; k++)
            {
                tt*=f;
            }
            if(p/tt)
            {
                sm+=p/tt;
                p%=tt;
            }
        }
        sm*=10;
        sm+=p;
        fprintf(fp2,"%8d ",sm);
        p=i*i;
        sm=0;
        for(j=8; j>=1; j--)
        {
            tt=1;
            sm*=10;
            for(k=1; k<=j; k++)
            {
                tt*=f;
            }
            if(p/tt)
            {
                sm+=p/tt;
                p%=tt;
            }
        }
        sm*=10;
        sm+=p;
        fprintf(fp2,"%8d\n",sm);
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
