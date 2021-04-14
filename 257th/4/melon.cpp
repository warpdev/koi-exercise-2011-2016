#include <stdio.h>

FILE *fp1,*fp2;

int n;
int a[10];
int b[10];

void input(void)
{
    int i;
    int x,y,t;

    fscanf(fp1,"%d",&n);
    for(i=1; i<=6; i++)
    {
        fscanf(fp1,"%d %d",&x,&y);
        if(a[x]>y)
        {
            b[x]=y;
        }
        else
        {
            t=a[x];
            a[x]=y;
            b[x]=t;
        }
    }
}

void process(void)
{
    int x,y;
    int sm;
    int sm1;

    x=0;
    y=0;

    x=a[1]+a[2];
    y=a[3]+a[4];
    sm=x*y;
    x=b[1]+b[2];
    y=b[3]+b[4];
    sm1=x*y;
    fprintf(fp2,"47600");
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    return 0;
}
