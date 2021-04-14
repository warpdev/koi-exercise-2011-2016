#include <stdio.h>
#define M 10

FILE *fp1,*fp2;

int m,f;
int cnt;
char t[100];
int ck[100];
char a[M+M][100];

void input(void)
{
    int i;

    fscanf(fp1,"%d %d",&m,&f);
    for(i=1; i<=m; i++)
    {
        fscanf(fp1,"%s",&a[i][1]);
    }
    for(i=1; i<=f; i++)
    {
        fscanf(fp1,"%s",&a[i+m][1]);
    }
}

void process(int lev,int x, int y)
{
    int i,j;

    if(lev>25)
    {
        for(i=1; i<=m+f; i++)
        {
            for(j=1; j<=25; j++)
            {
                if(t[j]!=a[i][j])
                {
                    break;
                }
            }
            if(j>25)
            {
                cnt++;
                return;
            }
        }
        return;
    }
    if(a[x][lev]==a[y][lev])
    {
        t[lev]=a[x][lev];
        process(lev+1,x,y);
    }
    else
    {
        t[lev]=a[x][lev];
        process(lev+1,x,y);
        t[lev]=a[y][lev];
        process(lev+1,x,y);
    }
}

void starter(void)
{
    int i,j;

    for(i=1; i<=m; i++)
    {
        for(j=m+1; j<=m+f; j++)
        {
            cnt=0;
            process(1,i,j);
            cnt-=2;
            if(cnt<0)
            {
                cnt=0;
            }
            fprintf(fp2,"%d ",cnt);
        }
        fprintf(fp2,"\n");
    }
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    starter();
    return 0;
}
