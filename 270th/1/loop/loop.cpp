#include <stdio.h>
#define N 100

FILE *fp1,*fp2;

int n;
int a[N+1];
int ck[N+1];
int cnt;

void input(void)
{
    int i;

    fscanf(fp1,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%d",&a[i]);
    }
}

void f(int x)
{
    if(ck[x])
    {
        return;
    }
    else
    {
        ck[x]=1;
        f(a[x]);
    }
}

void process(void)
{
    int i;

    for(i=1; i<=n; i++)
    {
        if(ck[i]==0)
        {
            f(i);
            cnt++;
        }
    }
    fprintf(fp2,"%d",cnt);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    return 0;
}
