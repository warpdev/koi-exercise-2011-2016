#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
#define N 10000
typedef pair<int,int> pp;

FILE *fp1,*fp2;

int n,s;
int a[N+1];
int sm[N+1];
pp dy[N+1];
int path[501][N+1];
int ck[N+1];
int mx=9999999,id;

void input(void)
{
    int i,t=0;

    fscanf(fp1,"%d",&n);
    i=0;
    n*=100;
    while(1)
    {
        i++;
        fscanf(fp1,"%d",&a[i]);
        t+=a[i];
        if(t>2*n || a[i]==0)
        {
            i--;
            break;
        }
    }
    s=i;
    printf("%d\n",s);
    for(i=1; i<=s; i++)
    {
        sm[i]=sm[i-1]+a[i];
    }
}

void process(void)
{
    int i,j,t;
    int x,y;

    for(i=1; i<=s; i++)
    {
        if(n>sm[i])
        {
            t=sm[i];
        }
        else
        {
            t=n;
        }
        for(j=t; j>=a[i]; j--)
        {
            if(j-a[i]==0 && sm[i]-j<=n || i>dy[j-a[i]].first && sm[i]-j<=n)
            {
                dy[j].first=i;
                dy[j].second=sm[i]-j;
                path[i][j]=dy[j-a[i]].first;
                //path[j].second=j-a[i];
            }
        }
    }
    for(i=n; i>=1; i--)
    {
        if(dy[i].first)
        printf("%d %d %d %d\n",i,dy[i].first,dy[i].second,path[dy[i].first][i]);
        if(id==dy[i].first && abs(dy[i].second-i)<mx)
        {
            id=dy[i].first;
            mx=abs(dy[i].second-i);
            x=i;
        }
        else if(id<dy[i].first)
        {
            id=dy[i].first;
            mx=abs(dy[i].second-i);
            x=i;
        }
    }
    //ck[id]=1;
    ck[dy[x].first]=1;
    while(x)
    {
        ck[path[dy[x].first][x]]=1;
        printf("%d %d %d\n",dy[x].first,x,path[dy[x].first][x]);
        x=x-a[dy[x].first];
    }
    fprintf(fp2,"%d\n",id);
    for(i=1; i<=id; i++)
    {
        if(ck[i])
        {
            fprintf(fp2,"port\n");
        }
        else
        {
            fprintf(fp2,"starboard\n");
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
