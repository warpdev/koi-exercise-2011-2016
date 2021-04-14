#include <stdio.h>
#define N 50

FILE *fp1,*fp2;

int n,r,c,w;
int a[N+1][N+1];

void input(void)
{
    int i,j,k,x,y,tx,ty;

    fscanf(fp1,"%d %d %d %d",&n,&r,&c,&w);
    for(i=1; i<=w; i++)
    {
        fscanf(fp1,"%d %d",&x,&y);
        tx=x*c-c+1;
        ty=y*r-r+1;
        for(j=tx; j<=tx+c-1; j++)
        {
            for(k=ty; k<=ty+r-1; k++)
            {
                a[j][k]=1;
            }
        }
    }
}

void output(void)
{
    int i,j;

    for(i=1; i<=n*c; i++)
    {
        for(j=1; j<=n*r; j++)
        {
            if(a[i][j])
            {
                fprintf(fp2,"* ");
            }
            else
            {
                fprintf(fp2,"  ");
            }
        }
        fprintf(fp2,"\n");
    }
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    output();
    return 0;
}
