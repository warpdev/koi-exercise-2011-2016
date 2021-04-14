#include <stdio.h>
#include <stdlib.h>

FILE *fp1,*fp2;

int k;
int sm;

void input(void)
{
    fscanf(fp1,"%d",&k);
    if(k<0)
    {
        k=-k;
    }
}

void process(void)
{
    int i;

    if(k==0)
    {
        for(i=1; i<=10; i++)
        {
            sm+=i;
            if(sm>=k)
            {
                if((sm-k)%2==0)
                {
                    fprintf(fp2,"%d",i);
                    exit(0);
                }
            }
        }
    }
    for(i=1; i<=k; i++)
    {
        sm+=i;
        if(sm>=k)
        {
            if((sm-k)%2==0)
            {
                fprintf(fp2,"%d",i);
                exit(0);
            }
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
