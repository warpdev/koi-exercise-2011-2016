#include <stdio.h>
#define N 100000

FILE *fp1,*fp2;

int m,n;
int a[N+1];
int k[5];
int sm;

void input(void)
{
    int i;
    char t;

    fscanf(fp1,"%d %d %d %d %d ",&m,&n,&k[1],&k[2],&k[3]);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%c ",&t);
        if(t=='u')
        {
            a[i]=1;
        }
        else if(t=='f')
        {
            a[i]=2;
        }
        else if(t=='d')
        {
            a[i]=3;
        }
    }
}

void process(void)
{
    int i,j;

    for(i=0; i<=n; i++)
    {
        sm+=k[a[i]]+k[4-a[i]];
        if(sm>m)
        {
            fprintf(fp2,"%d",i-1);
            break;
        }
    }
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
}
