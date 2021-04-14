#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 10

FILE *fp1,*fp2;

int n;
int a[N+1];
int dy[10000+1];

void input(void)
{
    int i;

    fscanf(fp1,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%d",&a[i]);
    }
    sort(a+1,a+n+1);
    for(i=1; i<=10000; i++)
    {
        dy[i]=10001;
    }
}

void process(void)
{
    int i,j,t,cnt;

    for(i=1; i<=n; i++)
    {
        for(j=a[i]; j<=10000; j++)
        {
            if(dy[j]>dy[j-a[i]]+1)
            {
                dy[j]=dy[j-a[i]]+1;
            }
        }
    }
    for(i=1; i<=10000; i++)
    {
        j=n;
        t=i;
        cnt=0;
        while(j>=1)
        {
            if(t>=a[j])
            {
                cnt+=t/a[j];
                t%=a[j];
            }
            else
            {
                j--;
            }
        }
        if(cnt>dy[i])
        {
            fprintf(fp2,"no\n%d",i);
            return;
        }
    }
    fprintf(fp2,"yes");
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    return 0;
}
