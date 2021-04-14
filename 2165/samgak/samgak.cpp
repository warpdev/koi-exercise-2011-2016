#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 50

FILE *fp1,*fp2;

int n;
int a[N+1];
int cnt;

void input(void)
{
    int i;

    fscanf(fp1,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%d",&a[i]);
    }
    sort(a+1,a+n+1);
}

void process(void)
{
    int i,j,k;

    for(i=1; i<=n; i++)
    {
        for(j=i+1; j<=n; j++)
        {
            for(k=j+1; k<=n; k++)
            {
                if(a[i]+a[j]>a[k])
                {
                    cnt++;
                }
                else
                {
                    break;
                }
            }
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
