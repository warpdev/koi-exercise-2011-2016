#include <stdio.h>
#define N 1000

FILE *fp1,*fp2;

int a[N+1];
int n;

void process(void)
{
    int i,j;
    int t=1;

    if(n==1)
    {
        fprintf(fp2,"2\n");
        return;
    }
    else if(n==2)
    {
        fprintf(fp2,"7\n");
        return;
    }
    else
    {
        for(i=3; i<=n; i++)
        {
            t=1;
            a[i]=2;
            for(j=1; j<=i; j++)
            {
                t*=2;
            }
            a[i]+=t;
        }
    }
    fprintf(fp2,"%d\n",(a[n]+2)%10);
}

void input(void)
{
    int i;

    for(i=1; i<=3; i++)
    {
        fscanf(fp1,"%d",&n);
        process();
    }
}


int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    return 0;
}
