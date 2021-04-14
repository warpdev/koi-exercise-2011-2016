#include <stdio.h>
#define N 10

FILE *fp1,*fp2;

int n;
int a[N+1][N+1];
int s[N+2][N+2];
int k[N+1][N+1];
int typ;
int dx[8]={1,1,1,0,-1,-1,-1,0};
int dy[8]={-1,0,1,1,1,0,-1,-1};

void input(void)
{
    int i,j;
    char x[N+2];

    fscanf(fp1,"%d ",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%s",&x[1]);
        for(j=1; j<=n; j++)
        {
            if(x[j]=='*')
            {
                a[i][j]=1;
            }
        }
    }
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%s",&x[1]);
        for(j=1; j<=n; j++)
        {
            if(x[j]=='x')
            {
                k[i][j]=1;
            }
        }
    }
}

void process(void)
{
    int i,j,l;

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(a[i][j])
            {
                for(l=0; l<=7; l++)
                {
                    s[i+dy[l]][j+dx[l]]++;
                }
            }
        }
    }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(a[i][j])
            {
                s[i][j]=-1;
                if(k[i][j])
                {
                    typ=1;
                }
            }
        }
    }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(typ && s[i][j]==-1)
            {
                fprintf(fp2,"*");
            }
            else if(k[i][j])
            {
                fprintf(fp2,"%d",s[i][j]);
            }
            else
            {
                fprintf(fp2,".");
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
