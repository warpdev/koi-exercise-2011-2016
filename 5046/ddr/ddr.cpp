#include <stdio.h>
#include <stdlib.h>
#define N 5

FILE *fp1,*fp2;

int n;
int cnt;
int a[N+1][N+1];
int s[N+1][N+1]={0};
int d[N+1][N+1]={
    0,2,2,2,2,0,
    0,1,3,4,3,0,
    0,3,1,3,4,0,
    0,4,3,1,3,0,
    0,3,4,3,1,0,
};
int mx=9999999;

void process(int x)
{
    int i,j;
    int tmx=9999999;


    for(i=0; i<=4; i++)
    {
        for(j=0; j<=4; j++)
        {
            if(x!=i && s[i][x]>a[i][j]+d[j][x])
            {
                s[i][x]=a[i][j]+d[j][x];
                //printf("%d\n",s[i][x]);
            }
            if(x!=j && s[x][j]>a[i][j]+d[i][x])
            {
                s[x][j]=a[i][j]+d[i][x];
                //printf("%d\n",s[x][j]);
            }
        }
    }
    for(i=0; i<=4; i++)
    {
        for(j=0; j<=4; j++)
        {
            a[i][j]=tmx;
        }
    }
    for(i=0; i<=4; i++)
    {
        for(j=0; j<=4; j++)
        {
            a[i][j]=s[i][j];
        }
    }
    /*for(i=0; i<=4; i++)
    {
        for(j=0; j<=4; j++)
        {
            printf("%7d ",a[i][j]);
        }
        printf("\n");
    }*/
}

void input(void)
{
    int k=1;
    int i,j;

    fscanf(fp1,"%d",&k);
    for(i=0; i<=4; i++)
    {
        for(j=0; j<=4; j++)
        {
            s[i][j]=mx;
            a[i][j]=mx;
        }
    }
    a[0][0]=0;
    while(k!=0)
    {
        cnt++;
        process(k);
        //printf("---%d-------------------\n",k);
        fscanf(fp1,"%d",&k);
        for(i=0; i<=4; i++)
        {
            for(j=0; j<=4; j++)
            {
                s[i][j]=mx;
            }
        }
    }
    for(i=0; i<=4; i++)
    {
        for(j=0; j<=4; j++)
        {
            if(a[i][j])
            {
                if(a[i][j]<mx)
                {
                    mx=a[i][j];
                }
            }
            //rintf("%d ",a[i][j]);
        }
        //printf("\n");
    }
    fprintf(fp2,"%d",mx);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    return 0;
}
