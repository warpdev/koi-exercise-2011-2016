#include <stdio.h>
#define N 10

FILE *fp1,*fp2;

int a[N+1][N+1];

void input(void)
{
    int i,j;
    int k,t;
    int ty=1;
    int ck[N+1]={0};

    a[0][8]=1;
    a[1][2]=1;
    a[1][4]=1;
    a[2][1]=1;
    a[2][3]=1;
    a[2][5]=1;
    a[3][2]=1;
    a[3][6]=1;
    a[4][1]=1;
    a[4][5]=1;
    a[4][7]=1;
    a[5][2]=1;
    a[5][4]=1;
    a[5][6]=1;
    a[5][8]=1;
    a[6][3]=1;
    a[6][5]=1;
    a[6][9]=1;
    a[7][4]=1;
    a[7][8]=1;
    a[8][5]=1;
    a[8][7]=1;
    a[8][9]=1;
    a[9][6]=1;
    a[9][8]=1;
    for(i=1; i<=5; i++)
    {
        ty=1;
        for(j=0; j<=10; j++)
        {
            ck[j]=0;
        }
        for(j=1; j<=7; j++)
        {
            if(j==4)
            {
                fscanf(fp1,"%c");
            }
            fscanf(fp1,"%1d",&k);
            if(ty)
            {
                if(ck[k])
                {
                    fprintf(fp2,"nogood\n");
                    ty=0;
                }
                else if(j!=1 && !a[k][t])
                {
                    fprintf(fp2,"nogood\n");
                    ty=0;
                }
                ck[k]=1;
                t=k;
            }
        }
        if(ty)
        {
            fprintf(fp2,"good\n");
        }
    }
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    return 0;
}
