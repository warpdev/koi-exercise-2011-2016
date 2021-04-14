#include <stdio.h>
#include <stdlib.h>
#include <math.h>

FILE *fp1,*fp2;

int s;
int s2;


void input(void)
{
    fscanf(fp1,"%d",&s);
}

int ok(int x)
{
    int i,k,s1;

    k=0;
    for(i=1; i<x; i++)
    {
        if(x%i==0)
        {
            k+=i;
        }
    }
    if(k!=x)
    {
        s1=0;
        for(i=1; i<k; i++)
        {
            if(k%i==0)
            {
                s1+=i;
            }
        }
        if(s1==x)
        {
            s2=k;
            return 1;
        }
    }
    return 0;
}

void process(void)
{
    int i=s;

    while(1)
    {
        if(ok(i))
        {
            break;
        }
        i++;
    }
    fprintf(fp2,"%d %d",i,s2);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    return 0;
}
