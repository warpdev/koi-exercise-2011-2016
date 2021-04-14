#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 10000

FILE *fp1,*fp2;

int n=1;
long long a[N+1];

void input(void)
{
    char t;

    while(1)
    {
        t=0;
        fscanf(fp1,"%c",&t);
        if(t>=48)
        {
            a[n]=t-48;
            while(1)
            {
                fscanf(fp1,"%c",&t);
                if(t>=48)
                {
                    a[n]*=10;
                    a[n]+=t-48;
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            break;
        }
        n++;
    }
}

void process(void)
{
    int i;

    n--;
    for(i=1; i<=n; i++)
    {
        printf("%d\n",i);
        sort(a+1,a+i+1);
        if(i%2==0)
        {
            fprintf(fp2,"%lld\n",(a[(i+1)/2]+a[(i+1)/2+1])/2);
        }
        else
        {
            fprintf(fp2,"%lld\n",a[(i+1)/2]);
        }
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
