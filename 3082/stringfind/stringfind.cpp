#include <stdio.h>
#include <string.h>
#define N 50

FILE *fp1,*fp2;

int n,m,k;
char a[N+5][N+5];
char s[N+5][N+5];
int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,-1,1,1,-1};

void input(void)
{
    int i;

    fscanf(fp1,"%d %d",&n,&m);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%s",&a[i][1]);
    }
    fscanf(fp1,"%d",&k);
    for(i=1; i<=k; i++)
    {
        fscanf(fp1,"%s",&s[i][1]);
    }
}

int ok(int x,int y,int id,int w)
{
    int i,j=1;

    for(i=0; i<=7; i++)
    {
        if(x+dy[i]*(w-1)>0 && x+dy[i]*(w-1)<=n && y+dx[i]*(w-1)>0 && y+dx[i]*(w-1)<=m)
        {
            for(j=1; j<=w; j++)
            {
                if(s[id][j]!=a[x+dy[i]*(j-1)][y+dx[i]*(j-1)])
                {
                    j=1;
                    break;
                }
            }
            if(j>w)
            {
                return 1;
            }
        }
    }
    return 0;
}

void process(void)
{
    int i,j,t;
    int tl;
    int typ=0;

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            if(a[i][j]>=97)
            {
                a[i][j]-=32;
            }
        }
    }
    for(i=1; i<=k; i++)
    {
        for(j=1; j<=strlen(&s[i][1]); j++)
        {
            if(s[i][j]>=97)
            {
                s[i][j]-=32;
            }
        }
    }
    for(t=1; t<=k; t++)
    {
        typ=0;
        tl=strlen(&s[t][1]);
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                if(a[i][j]==s[t][1])
                {
                    if(ok(i,j,t,tl))
                    {
                        fprintf(fp2,"%d %d\n",i,j);
                        typ=1;
                        break;
                    }
                }
            }
            if(typ)
            {
                break;
            }
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
