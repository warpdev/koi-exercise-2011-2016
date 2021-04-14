#include <stdio.h>
#define N 102
#define INF 1000000001

FILE *fp1,*fp2;

int k,n;
int a[N+1];
int s[N+1];
int dy[N+1];
int path[N+1];
int cnt;

void input(void)
{
    int i;
    int t;

    fscanf(fp1,"%d %d",&k,&n);
    n++;
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%d",&t);
        s[i]=s[i-1]+t;
        dy[i]=INF;
    }
    for(i=1; i<n; i++)
    {
        fscanf(fp1,"%d",&a[i]);
    }
}

void process(void)
{
    int i,j;
    int p[N+1]={0};

    for(i=1; i<=n; i++)
    {
        for(j=0; j<i; j++)
        {
            if(s[i]-s[j]<=k)
            {
                if(dy[i]>dy[j]+a[i])
                {
                    dy[i]=dy[j]+a[i];
                    path[i]=j;
                }
            }
        }
    }
    i=path[n];
    while(i)
    {
        cnt++;
        p[cnt]=i;
        i=path[i];
    }
    fprintf(fp2,"%d\n%d\n",dy[n],cnt);
    for(i=cnt; i>=1; i--)
    {
        fprintf(fp2,"%d ",p[i]);
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
