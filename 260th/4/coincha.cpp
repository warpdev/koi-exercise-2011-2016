#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 7489
#define INF -1

FILE *fp1,*fp2;

int n;
int a[10]={0,1,5,10,25,50};
int dy[N+1];

void input(void)
{
    int i;

    fscanf(fp1,"%d",&n);

    for(i=1; i<=n; i++)
    {
        dy[i]=INF;
    }
}

void process(void)
{
    int i,j;

    for(i=1; i<=5; i++)
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
