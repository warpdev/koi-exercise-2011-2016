#include <stdio.h>
#define N 7

FILE *fp1,*fp2;

char a[N+9][N+9];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int cnt;

void input(void)
{
    int i;

    /*for(i=1; i<=7; i++)
    {
        a[1][i]='o';
        a[2][i]='o';
        a[6][i]='o';
        a[7][i]='o';
    }*/
    for(i=1; i<=2; i++)
    {
        fscanf(fp1,"%s",&a[i][3]);
    }
    for(i=3; i<=5; i++)
    {
        fscanf(fp1,"%s",&a[i][1]);
    }
    for(i=6; i<=7; i++)
    {
        fscanf(fp1,"%s",&a[i][3]);
    }
    /*for(i=1; i<=2; i++)
    {
        a[1][i]='o';
        a[2][i]='o';
        a[6][i]='o';
        a[7][i]='o';
    }*/
}

void process(void)
{
    int i,j,k,tx,ty,x,y;

    for(i=1; i<=7; i++)
    {
        for(j=1; j<=7; j++)
        {
            if(a[i][j]=='.')
            {
                for(k=0; k<=3; k++)
                {
                    tx=i+dy[k];
                    ty=j+dx[k];
                    x=tx+dy[k];
                    y=ty+dx[k];
                    if(tx>0 && ty>0 && tx<=7 && ty<=7 && x>0 && y>0 && x<=7 && y<=7)
                    {
                        if(a[tx][ty]=='o' && a[x][y]=='o')
                        {
                            cnt++;
                        }
                    }
                }
            }
        }
    }
    fprintf(fp2,"%d",cnt);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    return 0;
}
