#include <stdio.h>
#define N 512

FILE *fp1,*fp2;

int n;
int a[N+1][N+1];

void input(void)
{
    int i,j;

    fscanf(fp1,"%d",&n);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            fscanf(fp1,"%1d",&a[i][j]);
        }
    }
}

void process(int x1,int y1,int x2,int y2)
{
    int i,j,k;

    k=a[x1][y1];
    for(i=x1; i<=x2; i++)
    {
        for(j=y1; j<=y2; j++)
        {
            if(k!=a[i][j])
            {
                fprintf(fp2,"(");
                process(x1,y1,(x1+x2-1)/2,(y1+y2-1)/2);
                process(x1,(y1+y2-1)/2+1,(x1+x2-1)/2,y2);
                process((x1+x2-1)/2+1,y1,x2,(y1+y2-1)/2);
                process((x1+x2-1)/2+1,(y1+y2-1)/2+1,x2,y2);
                fprintf(fp2,")");
                return;
            }
        }
    }
    fprintf(fp2,"%d",k);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process(1,1,n,n);
    return 0;
}
