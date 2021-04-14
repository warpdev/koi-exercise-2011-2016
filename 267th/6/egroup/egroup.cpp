#include <stdio.h>
#define N 30000

FILE *fp1,*fp2;

int n;
int a[N+2];
int k;
int dy[4][N+2];

void input(void)
{
    int i;

    fscanf(fp1,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%d",&a[i]);
    }
}

int mx(int x,int y)
{
    if(x>y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

void process(void)
{
    int i;

    for(i=1; i<=n; i++)
    {
        if(a[i]==1)
        {
            dy[1][i]=dy[1][i-1]+1;
            dy[2][i]=dy[2][i-1];
            dy[3][i]=dy[3][i-1];
        }
        else if(a[i]==2)
        {
            dy[1][i]=dy[1][i-1];
            dy[2][i]=mx(dy[1][i-1],dy[2][i-1])+1;
            dy[3][i]=dy[3][i-1];
        }
        else
        {
            dy[1][i]=dy[1][i-1];
            dy[2][i]=dy[2][i-1];
            dy[3][i]=mx(mx(dy[1][i-1],dy[2][i-1]),dy[3][i-1])+1;
        }
    }
    k=mx(mx(dy[1][n],dy[2][n]),dy[3][n]);
    for(i=1; i<=n; i++)
    {
        dy[1][i]=0;
        dy[2][i]=0;
        dy[3][i]=0;
    }
    for(i=n; i>=1; i--)
    {
        if(a[i]==1)
        {
            dy[1][i]=dy[1][i+1]+1;
            dy[2][i]=dy[2][i+1];
            dy[3][i]=dy[3][i+1];
        }
        else if(a[i]==2)
        {
            dy[1][i]=dy[1][i+1];
            dy[2][i]=mx(dy[1][i+1],dy[2][i+1])+1;
            dy[3][i]=dy[3][i+1];
        }
        else
        {
            dy[1][i]=dy[1][i+1];
            dy[2][i]=dy[2][i+1];
            dy[3][i]=mx(mx(dy[1][i+1],dy[2][i+1]),dy[3][i+1])+1;
        }
    }
    if(k<mx(mx(dy[1][1],dy[2][1]),dy[3][1]))
    {
        k=mx(mx(dy[1][1],dy[2][1]),dy[3][1]);
    }
    fprintf(fp2,"%d",n-k);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    return 0;
}
