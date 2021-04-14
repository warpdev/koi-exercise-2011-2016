#include <stdio.h>
#define N 50

FILE *fp1,*fp2;

char a[N+5];
int n;
int sm;

void input(void)
{
    fscanf(fp1,"%s",&a[1]);
    while(1)
    {
        n++;
        if(a[n]==0)
        {
            n--;
            break;
        }
    }
}

void process(void)
{
    int i;

    for(i=2; i<=n; i++)
    {
        if(a[i]==a[i-1])
        {
            sm+=5;
        }
        else
        {
            sm+=10;
        }
    }
    sm+=10;
    fprintf(fp2,"%d",sm);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    return 0;
}
