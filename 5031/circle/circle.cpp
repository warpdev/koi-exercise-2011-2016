#include <stdio.h>
#define N 100

FILE *fp1,*fp2;

int n,mx;
int a[N+1][N+1];
int dy[N+1][N+1];

void input(void)
{
    int i,x,y;

    fscanf(fp1,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%d %d",&x,&y);
        a[x][y]=1;
        a[y][x]=1;
        if(mx<x)
        {
            mx=x;
        }
        if(mx<y)
        {
            mx=y;
        }
        //printf("%d %d\n",x,y);
    }
}

void process(void)
{
    int i,j,s,k,tmx=0;

    for(s=1; s<=mx; s++)
    {
        for(i=1; i<=mx-s+1; i++)
        {
            //printf("%d",i);
            j=s+i;
            tmx=0;
            //if(a[i][j])
                    //printf("%d %d %d %d\n",i,j,a[i][j],dy[i][j]);
            for(k=i; k<=j-1; k++)
            {
                if(dy[i][j]<dy[i][k]+dy[k][j]+a[i][j])
                {
                    dy[i][j]=dy[i][k]+dy[k][j]+a[i][j];
                }
            }
        }
    }
        //printf("%d\n",dy[5][11]);
    fprintf(fp2,"%d",dy[1][mx]);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    return 0;
}
