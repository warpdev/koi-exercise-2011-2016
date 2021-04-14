#include <stdio.h>
#define N 102
#include <algorithm>
using namespace std;

FILE *fp1,*fp2;

int x,y;
int cx,cy;
int n;
int mx;
int a[N+1];
int b[N+1];

void input(void)
{
    int i,t,tx;

    fscanf(fp1,"%d %d %d",&x,&y,&n);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%d %d",&t,&tx);
        if(t)
        {
            cy++;
            b[cy]=tx;
        }
        else
        {
            cx++;
            a[cx]=tx;
        }
    }
    cx++;
    cy++;
    a[cx]=y;
    b[cy]=x;
    sort(a+1,a+cx+1);
    sort(b+1,b+cy+1);
}

void process(void)
{
    int i,j;

    for(i=0; i<cx; i++)
    {
        for(j=0; j<cy; j++)
        {
            if(mx<(a[i+1]-a[i])*(b[j+1]-b[j]))
            {
                mx=(a[i+1]-a[i])*(b[j+1]-b[j]);
            }
        }
    }
    fprintf(fp2,"%d",mx);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    return 0;
}
