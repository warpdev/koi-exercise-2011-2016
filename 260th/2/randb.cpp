#include <stdio.h>
#define N 20
#include <algorithm>
using namespace std;
#include <queue>

FILE *fp1,*fp2;

int w,h;
int a[N+1][N+1];
int s[N+1][N+1];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
queue<pair<int,int> > Q;


void input(void)
{
    int i,j;
    char t[N+1];

    fscanf(fp1,"%d %d",&w,&h);
    for(i=1; i<=h; i++)
    {
        fscanf(fp1,"%s",&t[1]);
        for(j=1; j<=w; j++)
        {
            if(t[j]=='.' || t[j]=='@')
            {
                a[i][j]=1;
                if(t[j]=='@')
                {
                    Q.push(make_pair(i,j));
                    a[i][j]=2;
                }
            }
            else if(t[j]=='#')
            {
                a[i][j]=-1;
            }
        }
    }
}

void process(void)
{
    int i,j,k;
    int cnt;
    int x,y;

    for(i=1; i<=h; i++)
    {
        for(j=1; j<=w; j++)
        {
            cnt=0;
            for(k=0; k<=3; k++)
            {
                if(a[i][j]==-1 || a[i+dy[k]][j+dx[k]]==-1)
                {
                    s[i][j]++;
                }
            }
        }
    }
    cnt=0;
    for(i=1; i<=h; i++)
    {
        for(j=1; j<=w; j++)
        {
            if(i==h && j==w || i==h && j==1 || i==1 && j==w || i==1 && j==1)
            {
                if(s[i][j]<2)
                {
                    s[i][j]=1;
                    //cnt++;
                }
                else
                {
                    s[i][j]=0;
                }
            }
            else if(i==h || j==w)
            {
                if(s[i][j]<3)
                {
                    s[i][j]=1;
                    //cnt++;
                }
                else
                {
                    s[i][j]=0;
                }
            }
            else
            {
                if(s[i][j]<4)
                {
                    s[i][j]=1;
                    //cnt++;
                }
                else
                {
                    s[i][j]=0;
                }
            }
        }
    }
    while(!Q.empty())
    {
        x=Q.front().first;
        y=Q.front().second;
        Q.pop();
        if(s[x][y])
        {
            cnt++;
            s[x][y]=0;
            for(i=0; i<=3; i++)
            {
                if(x+dy[i]>0 && x+dy[i]<=h && y+dx[i]>0 && y+dx[i]<=w)
                {
                    Q.push(make_pair(x+dy[i],y+dx[i]));
                }
            }
        }
    }
    if(cnt<=0)
    {
        cnt=1;
    }
    fprintf(fp2,"%d",cnt);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    return 0;
}
