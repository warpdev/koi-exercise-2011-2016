#include <stdio.h>
#define N 100

FILE *fp1,*fp2;

int n,m;
int a[N+1][N+1];
int id[N+1];
int ck[N+1];
int s[N+1];

void input(void)
{
    int i,x,y;

    fscanf(fp1,"%d %d",&n,&m);
    for(i=1; i<=m; i++)
    {
        fscanf(fp1,"%d %d",&x,&y);
        id[x]++;
        a[y][x]=1;
    }
}

void process(void)
{
    int i,j,k;

    for(k=1; k<=n; k++)
    {
        for(i=1; i<=n; i++)
        {
            if(id[i]==0 && !ck[i])
            {
                for(j=1; j<=n; j++)
                {
                    id[j]-=a[i][j];
                }
                ck[i]=1;
                s[k]=i;
                break;
            }
        }
    }
    for(i=n; i>=1; i--)
    {
        fprintf(fp2,"%d ",s[i]);
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
