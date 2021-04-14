#include <stdio.h>
#include <string.h>
#define N 1000

FILE *fp1,*fp2;

char a[N+4];
int n;

void input(void)
{
    fscanf(fp1,"%s",&a[1]);
    n=strlen(&a[1]);
}

void process(void)
{
    int i;
    int t=0;
    int t1=0;

    for(i=1; i<=n; i++)
    {
        t+=(int)a[i]-48;
    }
    t1=t/1000+(t%1000)/100+(t%100)/10+t%10;
    fprintf(fp2,"%d",t1);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    return 0;
}
