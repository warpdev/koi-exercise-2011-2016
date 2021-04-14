#include <stdio.h>
#define N 24

FILE *fp1,*fp2;

int n;
int cnt;

void input(void)
{
    fscanf(fp1,"%d",&n);
}

void process(int lev,int sm)
{
    int i;

    if(lev==n)
    {
        if(sm==n+1)
        {
            cnt++;
        }
    }
    else
    {
        for(i=0; i<=1; i++)
        {
            if(i)
            {
                process(lev+1,sm-lev);
            }
            else
            {
                process(lev+1,sm+lev);
            }
        }
    }
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process(2,0);
    fprintf(fp2,"%d",cnt);
    return 0;
}
