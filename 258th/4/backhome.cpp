#include <stdio.h>
#define N 5

FILE *fp1,*fp2;

int r,c,k;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int a[N+1][N+1];
int ck[N+1][N+1];
int sm;

void input(void)
{
    int i,j;
    char t[N+5];

    fscanf(fp1,"%d %d %d ",&r,&c,&k);
    for(i=1; i<=r; i++)
    {
        fscanf(fp1,"%s",&t[1]);
        for(j=1; j<=c; j++)
        {
            if(t[j]=='T')
            {
                ck[i][j]=1;
            }
        }
    }
}

void process(int x,int y,int cnt)
{
    int i;
    int tx,ty;

    if(x==1 && y==c)
    {
        if(cnt==k)
        {
            sm++;
        }
        return;
    }
    else
    {
        if(cnt>k)
        {
            return;
        }
        for(i=0; i<=3; i++)
        {
            tx=x+dy[i];
            ty=y+dx[i];
            if(tx>=1 && ty>=1 && tx<=r && ty<=c && ck[tx][ty]==0)
            {
                ck[tx][ty]=1;
                process(tx,ty,cnt+1);
                ck[tx][ty]=0;
            }
        }
    }
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process(r,1,1);
    fprintf(fp2,"%d",sm);
    return 0;
}
