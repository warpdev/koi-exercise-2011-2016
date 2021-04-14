#include <stdio.h>
#define N 5

FILE *fp1;

int a[N+1][N+1]={
    0,0,0,0,0,0,
    0,0,1,1,0,1,
    0,1,0,1,0,1,
    0,1,1,0,1,1,
    0,0,0,1,0,1,
    0,1,1,1,1,0
};
int s[2*N+1];

void process(int lev,int k)
{
    int i;
    int ck[N+1]={0,1,2,2,2,2};

    s[lev]=k;
    if(lev>8)
    {
        for(i=1; i<=8; i++)
        {
            fprintf(fp1,"%d",s[i]);
        }
        fprintf(fp1,"2\n");
        return;
    }
    for(i=1; i<=5; i++)
    {
        if(a[k][i] && ck[i])
        {
            a[k][i]=0;
            a[i][k]=0;
            ck[i]--;
            process(lev+1,i);
            a[k][i]=1;
            a[i][k]=1;
            ck[i]++;
        }
    }
}

int main(void)
{
    fp1=fopen("output.txt","w");
    process(1,1);
    return 0;
}
