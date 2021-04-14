#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 7

FILE *fp1,*fp2;

int n;
char a[N+3];
char t[N+3];
int k;

void input(void)
{
    int i;

    fscanf(fp1,"%d ",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%c ",&a[i]);
    }
    sort(a+1,a+n+1);
}

void slv(int lev,int x)
{
    int i;

    if(lev>k)
    {
        if(k>1)
        {
            fprintf(fp2," {");
            for(i=1; i<k; i++)
            {
                fprintf(fp2,"%c,",t[i]);
            }
            fprintf(fp2,"%c}",t[k]);
        }
        else
        {
            fprintf(fp2," {%c}",t[k]);
        }
    }
    else
    {
        for(i=x; i<=n; i++)
        {
            t[lev]=a[i];
            slv(lev+1,i+1);
        }
    }
}

void process(void)
{
    fprintf(fp2,"0 : {}\n");
    for(k=1; k<=n; k++)
    {
        fprintf(fp2,"%d :",k);
        slv(1,1);
        fprintf(fp2,"\n");
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
