#include <stdio.h>
#define N 500

FILE *fp1,*fp2;

int f,n=500;
int k=1,t;
int cnt;
int a[N+1][N+1];
int s[1100];
int sm[N+1];

void input(void)
{
    int i;
    int x,y;

    fscanf(fp1,"%d",&f);
    for(i=1; i<=f; i++)
    {
        fscanf(fp1,"%d %d",&x,&y);
        a[x][y]++;
        a[y][x]++;
        sm[x]++;
        sm[y]++;
    }
    for(i=1; i<=n; i++)
    {
        if(sm[i]%2==1)
        {
            k=i;
            break;
        }
    }
}

void process(int x)
{
    int i;

    for(i=1; i<=n; i++)
    {
        if(a[x][i])
        {
            a[x][i]--;
            a[i][x]--;
            process(i);
        }
    }
    cnt++;
    s[cnt]=x;
}

void output(void)
{
    int i;

    for(i=f+1; i>=1; i--)
    {
        fprintf(fp2,"%d\n",s[i]);
    }
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process(k);
    output();
    return 0;
}
