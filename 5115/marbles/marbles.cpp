#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 100000
typedef pair<long long,long long> pp;

FILE *fp1,*fp2;

long long n;
pp a[3];
long long typ;
int s[N+2];

void input(void)
{
    fscanf(fp1,"%d %d %d %d %d",&n,&a[1].second,&a[1].first,&a[2].second,&a[2].first);
    if(((double)a[1].first/(double)a[1].second)>((double)a[2].first/(double)a[2].second))
    {
        typ=a[1].second;
        a[1].second=a[2].second;
        a[2].second=typ;
        typ=a[1].first;
        a[1].first=a[2].first;
        a[2].first=typ;
        typ=1;
    }
}

void process(void)
{
    int i,t;
    long long k;

    if(a[2].first>N)
    {
        k=n;
        t=0;
        while(1)
        {
            if(k<0)
            {
                fprintf(fp2,"failed\n");
                break;
            }
            if(k%a[1].first)
            {
                k-=a[2].first;
                t++;
            }
            else
            {
                if(typ)
                {
                    fprintf(fp2,"%d %d\n",t,(int)(k/a[1].first));
                }
                else
                {
                    fprintf(fp2,"%d %d\n",(int)(k/a[1].first),t);
                }
                break;
            }
        }
    }
    else
    {
        if(((double)a[1].first/(double)a[1].second)<((double)a[2].first/(double)a[2].second))
        {
            typ=a[1].second;
            a[1].second=a[2].second;
            a[2].second=typ;
            typ=a[1].first;
            a[1].first=a[2].first;
            a[2].first=typ;
            typ=1;
        }
        k=n;
        t=0;
        while(1)
        {
            if(s[k%a[1].first] && k%a[1].first)
            {
                fprintf(fp2,"failed\n");
                break;
            }
            else if(!(k%a[1].first))
            {
                if(typ)
                {
                    fprintf(fp2,"%d %d\n",t,(int)(k/a[1].first));
                }
                else
                {
                    fprintf(fp2,"%d %d\n",(int)(k/a[1].first),t);
                }
                break;
            }
            else
            {
                s[k%a[1].first]=1;
            }
            t++;
            k-=a[2].first;
        }
    }
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    input();
    process();
    return 0;
}
