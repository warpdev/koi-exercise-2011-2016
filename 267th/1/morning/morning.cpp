#include <stdio.h>
#define N 100

FILE *fp1,*fp2;

int n;
int s[N+1];
int dy[N+1];
int mx;

void input(void)
{
    int i,x,y;

    fscanf(fp1,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%d %d",&x,&y);
        if(x || y)
        {
            s[i]=1;
        }
    }
}

void process(void)
{
    int i;

    for(i=1; i<=n; i++)
    {
        if(s[i])
        {
            dy[i]=0;
        }
        else
        {
            dy[i]=dy[i-1]+1;
        }
        if(mx<dy[i])
        {
            mx=dy[i];
        }
    }
    fprintf(fp2,"%d",2*mx);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    return 0;
}
