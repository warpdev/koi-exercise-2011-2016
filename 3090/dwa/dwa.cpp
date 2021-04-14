#include <stdio.h>
#define N 9

FILE *fp1,*fp2;

int a[N+1];
int sm;

void input(void)
{
    int i;

    for(i=1; i<=9; i++)
    {
        fscanf(fp1,"%d",&a[i]);
        sm+=a[i];
    }
    sm-=100;
}

void process(void)
{
    int i,j;

    for(i=1; i<=9; i++)
    {
        for(j=1; j<=9; j++)
        {
            if(i!=j && sm==(a[i]+a[j]))
            {
                a[i]=0;
                a[j]=0;
                break;
            }
        }
        if(a[i]==0)
        {
            break;
        }
    }
    for(i=1; i<=9; i++)
    {
        if(a[i])
        {
            fprintf(fp2,"%d\n",a[i]);
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
