#include <stdio.h>
#define N 1000

FILE *fp1,*fp2;

int n;
int a[N+1][N+1];
int dy[N+1][N+1];
int mx;

void input(void)
{
    int i,j;

    fscanf(fp1,"%d",&n);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=i; j++)
        {
            fscanf(fp1,"%d",&a[i][j]);
        }
    }
    dy[1][1]=a[1][1];
}

void process(void)
{
    int i,j;

    for(i=1; i<n; i++)
    {
        for(j=1; j<=i; j++)
        {
            if(dy[i+1][j]<dy[i][j]+a[i+1][j])
            {
                dy[i+1][j]=dy[i][j]+a[i+1][j];
            }
            if(dy[i+1][j+1]<dy[i][j]+a[i+1][j+1])
            {
                dy[i+1][j+1]=dy[i][j]+a[i+1][j+1];
            }
        }
    }
    for(i=1; i<=n; i++)
    {
        if(mx<dy[n][i])
        {
            mx=dy[n][i];
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
