#include <stdio.h>
#define N 100

FILE *fp1,*fp2;

int m,n;
int a[N+1][N+1];
int mx;

void input(void)
{
    int i,j;

    fscanf(fp1,"%d %d",&m,&n);
    for(i=1; i<=m; i++)
    {
        for(j=1; j<=n; j++)
        {
            fscanf(fp1,"%d",&a[i][j]);
        }
    }
}

void process(void)
{
    int i,j,k;
    int t[N+1];
    int ts[N+1];
    int tmx;

    for(i=1; i<=m; i++)
    {
        for(j=0; j<=n; j++)
        {
            t[j]=0;
            ts[j]=0;
        }
        for(j=i; j<=m; j++)
        {
            tmx=0;
            for(k=1; k<=n; k++)
            {
                ts[k]=0;
                t[k]+=a[j][k];
            }
            for(k=1; k<=n; k++)
            {
                if(!t[k])
                {
                    ts[k]=ts[k-1]+1;
                    if(ts[k]>tmx)
                    {
                        tmx=ts[k];
                    }
                }
            }
            if(tmx*(j-i+1)>mx)
            {
                mx=tmx*(j-i+1);
            }
        }
    }
    fprintf(fp2,"%d",mx);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    return 0;
}
