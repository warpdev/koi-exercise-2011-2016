#include <stdio.h>
#define N 100

FILE *fp1,*fp2;

int nr,nc;
int a[N+1][N+1];
int mx;
int idx,idy;

void input(void)
{
    int i,j;

    fscanf(fp1,"%d %d",&nr,&nc);
    for(i=1; i<=nr; i++)
    {
        for(j=1; j<=nc; j++)
        {
            fscanf(fp1,"%d",&a[i][j]);
        }
    }
}

void process(void)
{
    int i,j,k,l;
    int sm;
    int tx,ty;

    tx=nr-2;
    ty=nc-2;
    for(i=1; i<=tx; i++)
    {
        for(j=1; j<=ty; j++)
        {
            sm=0;
            for(k=i; k<=i+2; k++)
            {
                for(l=j; l<=j+2; l++)
                {
                    sm+=a[k][l];
                }
            }
            if(sm>mx)
            {
                mx=sm;
                idx=i;
                idy=j;
            }
        }
    }
    fprintf(fp2,"%d\n%d %d",mx,idx,idy);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    return 0;
}
