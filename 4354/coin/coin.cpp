#include <stdio.h>
#define N 1000000

FILE *fp1,*fp2;

int m;
int k[4]={0,1};
int a[N+1];
int s[51];

void input(void)
{
    int i;

    fscanf(fp1,"%d %d %d",&k[2],&k[3],&m);
    for(i=1; i<=m; i++)
    {
        fscanf(fp1,"%d",&s[i]);
    }
}

void process(void)
{
    int i,j;
    int ta,tb,tc;

    for(i=1; i<=N; i++)
    {
        ta=tb=tc=0;
        for(j=1; j<=3; j++)
        {
            if(i-k[j]>=0)
            {
                if(j==1)
                {
                    ta=a[i-k[j]];
                }
                else if(j==2)
                {
                    tb=a[i-k[j]];
                }
                else
                {
                    tc=a[i-k[j]];
                }
            }
        }
        a[i]=!(ta&tb&tc);
    }
    for(i=1; i<=m; i++)
    {
        fprintf(fp2,"%c",66-a[s[i]]);
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
