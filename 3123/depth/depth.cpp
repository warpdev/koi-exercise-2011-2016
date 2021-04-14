#include <stdio.h>
#define N 100

FILE *fp1,*fp2;

int r,c;
int a[N+2][N+2];
int ck[N+1][N+1];
int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,-1,1,1,-1};
int mx;

void input(void)
{
    int i,j;

    fscanf(fp1,"%d %d",&r,&c);
    for(i=1; i<=r; i++)
    {
        for(j=1; j<=c; j++)
        {
            fscanf(fp1,"%d",&a[i][j]);
        }
    }
}

void process(void)
{
    int i,j,k;

    for(i=1; i<=r; i++)
    {
        for(j=1; j<=c; j++)
        {
            if(a[i][j])
            {
                for(k=0; k<=7; k++)
                {
                    if(a[i][j]==a[i+dx[k]][j+dy[k]])
                    {
                        if(mx<a[i][j])
                        {
                            mx=a[i][j];
                            break;
                        }
                    }
                }
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
