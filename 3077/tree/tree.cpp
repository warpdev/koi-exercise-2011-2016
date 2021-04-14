#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
#define N 26
typedef pair<int,int> pp;

FILE *fp1,*fp2;

int n;
int lev[N+1];
int a[N+1][N+1];
int ck[N+1];
int cnt,sm;
int mx;
queue<pp> Q;

void input(void)
{
    int i;
    char x,y;

    fscanf(fp1,"%d ",&n);

    for(i=1; i<n; i++)
    {
        fscanf(fp1,"%c %c ",&x,&y);
        a[x-64][y-64]=1;
    }
}

void process(void)
{
    int i;
    int x,y;
    int typ;

    Q.push(make_pair(1,1));
    while(!Q.empty())
    {
        typ=1;
        x=Q.front().first;
        y=Q.front().second;
        Q.pop();
        if(!ck[x])
        {
            ck[x]=1;
            lev[x]=y;
            if(mx<y)
            {
                mx=y;
            }
            for(i=1; i<=n; i++)
            {
                if(a[x][i])
                {
                    typ=0;
                    Q.push(make_pair(i,y+1));
                }
            }
            if(typ)
            {
                cnt++;
            }
        }
    }
    for(i=1; i<=n; i++)
    {
        sm+=lev[i];
    }
    fprintf(fp2,"%d\n%d\n%d",mx,sm,cnt);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    return 0;
}
