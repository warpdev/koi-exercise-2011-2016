#include <stdio.h>
#define N 100

FILE *fp1,*fp2;

int n;
int dy[N+1];
int a[N+1];
int sm;

void input(void)
{
    int i;

    fscanf(fp1,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%d",&a[i]);
    }
}

void process(void)
{
    int i;

    for(i=1; i<=n; i++)
    {
        if(a[i]==1)
        {
            dy[i]=dy[i-1]+1;
        }
        else
        {
            dy[i]=0;
        }
    }
    for(i=1; i<=n; i++)
    {
        sm+=dy[i];
    }
    fprintf(fp2,"%d",sm);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    return 0;
}
