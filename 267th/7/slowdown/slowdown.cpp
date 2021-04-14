#include <stdio.h>
#define N 100000
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int,int> pp;

FILE *fp1,*fp2;

int n;
vector<int> a[N+1];
int s[N+1];

int process(int k)
{
    int i,x,y,t;
    int ck[N+1]={0};
    queue<pp> Q;

    Q.push(make_pair(1,0));
    while(!Q.empty())
    {
        x=Q.front().first;
        y=Q.front().second;
        Q.pop();
        if(x==k)
        {
            s[k]=1;
            return y;
        }
        else if(!ck[x])
        {
            ck[x]=1;
            t=a[x].size();
            for(i=0; i<t; i++)
            {
                Q.push(make_pair(a[x][i],y+s[x]));
            }
        }
    }
}

void input(void)
{
    int i,x,y;

    fscanf(fp1,"%d",&n);
    for(i=1; i<n; i++)
    {
        fscanf(fp1,"%d %d",&x,&y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%d",&x);
        fprintf(fp2,"%d\n",process(x));
    }
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    return 0;
}
