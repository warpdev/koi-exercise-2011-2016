#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 20
typedef pair<int,int> pp;

FILE *fp1,*fp2;

int f,m,n;
double stac;
pp a[N+1];
int ck[N+1];

void input(void)
{
    int i;

    fscanf(fp1,"%d %d %d",&f,&m,&n);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%d %d",&a[i].first,&a[i].second);
    }
    stac=(double)f/(double)m;
}

void process(int lev, int kf, int km)
{
    int i;
    double tac;

    for(i=1; i<=n; i++)
    {
        if(ck[i]==0)
        {
            tac=(double)(f+a[i].first)/(double)(m+a[i].second);
            if(stac>=tac)
            {
                ck[i]=-1;
            }
            else
            {
                ck[i]=1;
            }
        }
    }
}

void output(void)
{
    int i;
    int k=0;

    for(i=1; i<=n; i++)
    {
        if(ck[i]==1)
        {
            fprintf(fp2,"%d\n",i);
            k=1;
        }
    }
    if(k==0)
    {
        fprintf(fp2,"NONE");
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
