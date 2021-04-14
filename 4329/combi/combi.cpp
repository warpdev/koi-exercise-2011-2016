#include <stdio.h>
#define N 100

FILE *fp1,*fp2;

int n,m,t;
unsigned int s=1;
int a[N+1];
int b[N+1];

void input(void)
{
    fscanf(fp1,"%d %d",&n,&m);
    t=n-m;
}

void process(void)
{
    int i,j,x;

    for(i=2; i<=n; i++)
    {
        x=i;
        for(j=2; j<=x; j++)
        {
            if(x%j==0)
            {
                a[j]++;
                x/=j;
                j--;
            }
        }
    }
    for(i=2; i<=m; i++)
    {
        x=i;
        for(j=2; j<=x; j++)
        {
            if(x%j==0)
            {
                b[j]++;
                x/=j;
                j--;
            }
        }
    }
    for(i=2; i<=t; i++)
    {
        x=i;
        for(j=2; j<=x; j++)
        {
            if(x%j==0)
            {
                b[j]++;
                x/=j;
                j--;
            }
        }
    }
    for(i=1; i<=100; i++)
    {
        a[i]-=b[i];
    }
    for(i=1; i<=100; i++)
    {
        if(a[i])
        {
            s*=i;
            a[i]--;
            i--;
        }
    }
    fprintf(fp2,"%u",s);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    return 0;
}
