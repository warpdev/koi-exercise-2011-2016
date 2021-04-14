#include <stdio.h>
#define N 100

FILE *fp1,*fp2;

int n;
int m;
int a[N+1][N+1];
int ck[N+1];
int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,-1,1,1,-1};

void input(void)
{
    int i,j;
    int x,y;

    fscanf(fp1,"%d %d",&n,&m);
    for(i=1; i<=m; i++)
    {
        fscanf(fp1,"%d %d",&x,&y);
        a[x][y]=-9;
        for(j=0; j<=7; j++)
        {
            if(x+dy[j]>0 && y+dx[j]>0 && x+dy[j]<=n && y+dx[j]<=n)
            {
                a[x+dy[j]][y+dx[j]]++;
            }
        }
    }
}

void process(void)
{
    int i,j;

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(a[i][j]>0)
            {
                ck[a[i][j]]++;
            }
        }
    }
    for(i=n; i>=1; i--)
    {
        if(ck[i])
        {
            fprintf(fp2,"%d %d\n",i,ck[i]);
        }
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
