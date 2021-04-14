#include <stdio.h>
#define N 100

FILE *fp1,*fp2;

int n,e;
int a[N+1][N+1];
int ck[N+1][N+1];

void input(void)
{
    int i,j,k;
    int t;

    fscanf(fp1,"%d %d",&n,&e);

    for(i=1; i<=e; i++)
    {
        fscanf(fp1,"%d",&k);
        for(j=1; j<=k; j++)
        {
            fscanf(fp1,"%d",&t);
            a[i][t]=1;
        }
    }
}

void process(void)
{
    int i,j,k,l;

    for(i=1; i<=e; i++)
    {
        if(a[i][1])
        {
            for(j=1; j<=n; j++)
            {
                if(a[i][j])
                {
                    ck[i][j]=1;
                }
            }
        }
        else
        {
            for(k=1; k<=n; k++)
            {
                ck[i][k]=1;
                if(a[i][k])
                {
                    for(l=k+1; l<=n; l++)
                    {
                        if(a[i][l])
                        {
                            for(j=1; j<=i; j++)
                            {
                                if(ck[j][k]!=ck[j][l])
                                {
                                    ck[j][k]=1;
                                    ck[j][l]=1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    fprintf(fp2,"1\n");
    for(i=2; i<=n; i++)
    {
        k=1;
        for(j=1; j<=e; j++)
        {
            if(ck[j][i]==0)
            {
                k=0;
                break;
            }
        }
        if(k)
        {
            fprintf(fp2,"%d\n",i);
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
