#include <stdio.h>
#define N 100

FILE *fp1,*fp2;

int f,v;
int p[N+1];
int a[N+1][N+1];
int dy[N+1][N+1];
int path[N+1][N+1];
int ck[N+1][N+1];

void input(void)
{
    int i,j;

    fscanf(fp1,"%d %d",&f,&v);
    for(i=1; i<=f; i++)
    {
        for(j=1; j<=v; j++)
        {
            fscanf(fp1,"%d",&a[i][j]);
        }
    }
}

void process(void)
{
    int i,j,x,k;

    for(i=1; i<=f; i++)
    {
        for(j=i; j<=v; j++)
        {
            if(a[i][j]+dy[i-1][j-1]<dy[i][j-1])
            {
                dy[i][j]=dy[i][j-1];
                if(ck[i][j-1])
                {
                    path[i][j]=j-1;
                }
                else
                {
                    path[i][j]=path[i][j-1];
                }
            }
            else
            {
                dy[i][j]=a[i][j]+dy[i-1][j-1];
                path[i][j]=j-1;
                ck[i][j]=1;
            }
        }
    }
    fprintf(fp2,"%d\n",dy[f][v]);
    x=v;
    k=f;
    while(f>0)
    {
        if(ck[f][x])
        {
            p[f]=x;
            x=path[f][x];
            f--;
        }
        else
        {
            x=path[f][x];
            p[f]=x;
            f--;
        }
    }
    for(i=1; i<=k; i++)
    {
        fprintf(fp2,"%d ",p[i]);
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
