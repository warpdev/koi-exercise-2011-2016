#include <stdio.h>
#define N 50

FILE *fp1,*fp2;

int n;
int a[N+1][N+1];
int mx[N+1];
int mn=9999;

void input(void)
{
    int i;
    int x=0,y=0;

    fscanf(fp1,"%d",&n);
    do
    {
        a[x][y]=1;
        a[y][x]=1;
        fscanf(fp1,"%d %d",&x,&y);
    }while(x!=-1 && y!=-1);
}

void process(void)
{
    int i,j,k,o;

    for(o=1; o<=n; o++)
    {
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                if(a[i][j])
                {
                    for(k=1; k<=n; k++)
                    {
                        if(k!=i && a[j][k])
                        {
                            if(!a[i][k] || a[i][k]>a[j][k]+a[i][j])
                            {
                                a[i][k]=a[j][k]+a[i][j];
                            }
                        }
                    }
                }
            }
        }
    }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(mx[i]<a[i][j])
            {
                mx[i]=a[i][j];
            }
        }
        if(mn>mx[i])
        {
            mn=mx[i];
        }
    }
}

void output(void)
{
    int i;

    fprintf(fp2,"%d\n",mn);
    for(i=1; i<=n; i++)
    {
        if(mn==mx[i])
        {
            fprintf(fp2,"%d ",i);
        }
    }
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
