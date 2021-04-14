#include <stdio.h>
#include <algorithm>
using namespace std;
#include <queue>
#define N 100
typedef pair<int,int> pp;

FILE *fp1,*fp2;

int r,c;
int a[N+1][N+1];
int s[N+1][N+1];
int ck[N+1][N+1];
queue<pp> Q;

void input(void)
{
    int i,j;

    fscanf(fp1,"%d %d",&r,&c);
    for(i=1; i<=r; i++)
    {
        for(j=1; j<=c; j++)
        {
            fscanf(fp1,"%d",&a[i][j]);
        }
    }
    Q.push(make_pair(1,1));
}

void process(void)
{
    int i,j;
    int x,y;

    while(!Q.empty())
    {
        x=Q.front().first;
        y=Q.front().second;
        Q.pop();
        if(x>=1 && y>=1 && x<=r && y<=c)
        {
            for(i=-1; i<=1; i++)
            {
                if(x+i>=1 && y+1>=1 && x+i<=r && y+1<=c && s[x+i][y+1]<s[x][y]+a[x+i][y+1])
                {
                    s[x+i][y+1]=s[x][y]+a[x+i][y+1];
                    Q.push(make_pair(x+i,y+1));
                }
            }
        }
    }
    fprintf(fp2,"%d",s[r][c]+a[1][1]);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    return 0;
}
