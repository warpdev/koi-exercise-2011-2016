#include <stdio.h>
#define N 100

FILE *fp1,*fp2;

int n;
int a[N+1];

void process(int typ,int k)
{
    int i;

    if(typ==1)
    {
        for(i=k; i<=n; i+=k)
        {
            a[i]=1-a[i];
        }
    }
    else
    {
        a[k]=1-a[k];
        for(i=1; i<=n; i++)
        {
            if(k+i<=n && k-i>=1 && a[k+i]==a[k-i])
            {
                a[k+i]=1-a[k+i];
                a[k-i]=1-a[k-i];
            }
            else
            {
                break;
            }
        }
    }
}

void input(void)
{
    int i,j;
    int t;
    int x,y;

    fscanf(fp1,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%d",&a[i]);
    }
    fscanf(fp1,"%d",&t);
    for(i=1; i<=t; i++)
    {
        fscanf(fp1,"%d %d",&x,&y);
        process(x,y);
    }
    for(j=0; j<=n/20-1; j++)
    {
        for(i=j*20+1; i<=(j+1)*20; i++)
        {
            fprintf(fp2,"%d ",a[i]);
        }
        fprintf(fp2,"\n");
    }
    for(i=n-n%20+1; i<=n; i++)
    {
        fprintf(fp2,"%d ",a[i]);
    }
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    return 0;
}
