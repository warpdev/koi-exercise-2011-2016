#include <stdio.h>
#define N 100

FILE *fp1,*fp2;

int n;
int a[N+1][N+1];

void input(void)
{
    fscanf(fp1,"%d",&n);
}

void process(void)
{
    int i,j;
    int t=1;
    int x=1,y=1;

    for(i=1; i<=n; i++)
    {
        if(i%4==1)
        {
            for(j=y; j<=y+n-i; j++)
            {
                a[x][j]=t;
                t++;
                if(t%10==0)
                {
                    t=1;
                }
            }
            y=y+n-i;
            x=x+1;
        }
        else if(i%4==2)
        {
            for(j=x; j<=x+n-i; j++)
            {
                a[j][y]=t;
                t++;
                if(t%10==0)
                {
                    t=1;
                }
            }
            y=y-1;
            x=x+n-i;
        }
        else if(i%4==3)
        {
            for(j=y; j>=y-n+i; j--)
            {
                a[x][j]=t;
                t++;
                if(t%10==0)
                {
                    t=1;
                }
            }
            y=y-n+i;
            x=x-1;
        }
        else
        {
            for(j=x; j>=x-n+i; j--)
            {
                a[j][y]=t;
                t++;
                if(t%10==0)
                {
                    t=1;
                }
            }
            y=y+1;
            x=x-n+i;
        }
    }
}

void output(void)
{
    int i,j;

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(a[i][j]==0)
            {
                fprintf(fp2,"  ");
            }
            else
            {
                fprintf(fp2,"%d ",a[i][j]);
            }
        }
        fprintf(fp2,"\n");
    }
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    output();
    return 0;
}
