#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 100

FILE *fp1,*fp2;

int n;
int a[N+1][N+1];
int sx[N+1];
int sy[N+1];
int mx;

void input(void)
{
    int i,j,k;
    int x,y;

    fscanf(fp1,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%d %d",&x,&y);
        sx[i]=x;
        sy[i]=y;
        for(j=x; j<=9+x; j++)
        {
            for(k=y; k<=9+y; k++)
            {
                a[j][k]=1;
            }
        }
    }
    sort(sx+1,sx+n+1);
    sort(sy+1,sy+n+1);
}

void process(void)
{
    int i,j,k,l;
    int sm;

    for(i=sx[1]; i<=sx[n]+10; i++)
    {
        printf("%d\n",i);
        for(j=sy[1]; j<=sy[n]+10; j++)
        {
            if(a[i][j])
            {
                sm=0;
                for(k=i; k<=sx[n]+10; k++)
                {
                    for(l=j; l<=sy[n]+10; l++)
                    {
                        if(a[k][l])
                        {
                            sm++;
                        }
                        else
                        {
                            sm=0;
                            break;
                        }
                    }
                    if(sm==0)
                    {
                        break;
                    }
                }
                if(mx<sm)
                {
                    mx=sm;
                }
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
}
