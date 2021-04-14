#include <stdio.h>
#define N 100

FILE *fp1,*fp2;

int n;
int a[N+1][N+1];
int ck[N+1];
int cnt;

void input(void)
{
    int x,y;

    fscanf(fp1,"%d",&n);

    while(1)
    {
        fscanf(fp1,"%d %d",&x,&y);
        if(!x)
        {
            break;
        }
        a[x][y]=1;
        a[y][x]=1;
    }
}

void slv(int x)
{
    int i;

    for(i=1; i<=n; i++)
    {
        if(a[x][i] && !ck[i])
        {
            ck[i]=cnt;
            slv(i);
        }
    }
}

void process(void)
{
    int i,j;

    for(i=1; i<=n; i++)
    {
        if(!ck[i])
        {
            cnt++;
            ck[i]=cnt;
            slv(i);
        }
    }
    fprintf(fp2,"%d\n",cnt);
    for(i=1; i<=cnt; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(ck[j]==i)
            {
                fprintf(fp2,"%d ",j);
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
    process();
    return 0;
}
