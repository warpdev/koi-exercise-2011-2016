#include <stdio.h>
#define N 100

FILE *fp1,*fp2;

int n;
int a[N+1][4];
int dy[N+1][7];
int k[7][4]={
    0,0,0,0,
    0,1,0,-1,
    0,1,-1,0,
    0,0,1,-1,
    0,0,-1,1,
    0,-1,1,0,
    0,-1,0,1
};
int t[7][3]={
    0,0,0,
    0,4,5,
    0,3,6,
    0,2,6,
    0,1,5,
    0,1,4,
    0,2,3
};

void input(void)
{
    int i;

    fscanf(fp1,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
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
    int i,j,l;
    int tmx=-111111;

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=6; j++)
        {
            for(l=1; l<=3; l++)
            {
                dy[i][j]+=a[i][l]*k[j][l];
            }
            dy[i][j]+=mx(dy[i-1][t[j][1]],dy[i-1][t[j][2]]);
        }
    }
    for(i=1; i<=6; i++)
    {
        if(tmx<dy[n][i])
        {
            tmx=dy[n][i];
        }
    }
    fprintf(fp2,"%d",tmx);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    return 0;
}
