#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 300
#define INF -1

FILE *fp1,*fp2;

int n,c;
int a[10];
int dy[N+1];
int ck[N+1];

void input(void)
{
    int i;

    fscanf(fp1,"%d %d",&n,&c);
    for(i=1; i<=c; i++)
    {
        fscanf(fp1,"%d",&a[i]);
    }
    for(i=1; i<=n; i++)
    {
        dy[i]=INF;
    }
    sort(a+1,a+c+1);
}

void process(void)
{
    int i,j;

    for(i=1; i<=c; i++)
    {
        for(j=a[i]; j<=n; j++)
        {
            if(dy[j-a[i]]!=INF)
            {
                dy[j]++;
                dy[j]+=dy[j-a[i]];
            }
        }
    }
    fprintf(fp2,"%d",dy[n]+1);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    return 0;
}
