#include <stdio.h>
#define N 50000

FILE *fp1,*fp2;

int n;
int a[N+1];
int dy[4][N+1];
int s[N+1];
int m;

void input(void)
{
    int i;

    fscanf(fp1,"%d", &n);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%d",&a[i]);
    }
    fscanf(fp1,"%d",&m);
}

void process(void)
{
    int i,j,k,t;

    for(i=1; i<=n; i++)
    {
        s[i]=s[i-1]+a[i];
    }
    for(i=1; i<=3; i++)
    {
        for(j=i*m; j<=n; j++)
        {
            t=s[j]-s[j-m];
            if(dy[i][j-1]<dy[i-1][j-m]+t)
            {
                dy[i][j]=dy[i-1][j-m]+t;
            }
            else
            {
                dy[i][j]=dy[i][j-1];
            }
        }
    }
}

void output(void)
{
    fprintf(fp2,"%d",dy[3][n]);
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
