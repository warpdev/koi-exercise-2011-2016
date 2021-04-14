#include <stdio.h>
#include <algorithm>
using namespace std;
#include <queue>
#define N 75
typedef pair<int,int> pp;

FILE *fp1,*fp2;

int r,c;
queue<pp> Q;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int kx,ky;
int kkx,kky;
int s[8][4][4]={
    0,0,0,0,
    0,0,0,0,
    0,0,0,0,
    0,0,0,0,
    0,0,0,0,
    0,0,0,0,
    0,0,1,1,
    0,0,1,0,
    0,0,0,0,
    0,0,1,0,
    0,0,1,1,
    0,0,0,0,
    0,0,0,0,
    0,0,1,0,
    0,1,1,0,
    0,0,0,0,
    0,0,0,0,
    0,0,0,0,
    0,1,1,0,
    0,0,1,0,
    0,0,0,0,
    0,0,1,0,
    0,0,1,0,
    0,0,1,0,
    0,0,0,0,
    0,0,0,0,
    0,1,1,1,
    0,0,0,0,
    0,0,0,0,
    0,0,1,0,
    0,1,1,1,
    0,0,1,0
};
int a[N+1][N+1];
int k[25+1][25+1];
int ck[N+1][N+1];
int tx,ty;

void input(void)
{
    int i,j,x,y;
    char t[N+1];
    int fx=0,fy=0;

    fscanf(fp1,"%d %d",&r,&c);
    for(i=1; i<=r; i++)
    {
        fscanf(fp1,"%s",&t[1]);
        for(j=1; j<=c; j++)
        {
            if(t[j]=='1')
            {
                k[i][j]=1;
            }
            else if(t[j]=='2')
            {
                k[i][j]=2;
            }
            else if(t[j]=='3')
            {
                k[i][j]=3;
            }
            else if(t[j]=='4')
            {
                k[i][j]=4;
            }
            else if(t[j]=='|')
            {
                k[i][j]=5;
            }
            else if(t[j]=='-')
            {
                k[i][j]=6;
            }
            else if(t[j]=='+')
            {
                k[i][j]=7;
            }
            else if(t[j]=='G')
            {
                kkx=i;
                kky=j;
            }
            else if(t[j]=='A')
            {
                kx=i*3-1;
                ky=j*3-1;
            }
            else
            {
                k[i][j]=0;
            }
        }
    }
    for(i=1; i<=r; i++)
    {
        for(j=1; j<=c; j++)
        {
            for(x=i*3-2; x<=i*3; x++)
            {
                for(y=j*3-2; y<=j*3; y++)
                {
                    a[x][y]=s[k[i][j]][x-3*(i-1)][y-3*(j-1)];
                }
            }
        }
    }
    if(a[kkx*3+1][kky*3-1])
    {
        Q.push(make_pair(kkx*3+1,kky*3-1));
    }
    else if(a[kkx*3-1][kky*3+1])
    {
        Q.push(make_pair(kkx*3-1,kky*3+1));
    }
    else if(a[kkx*3-3][kky*3-1])
    {
        Q.push(make_pair(kkx*3-3,kky*3-1));
    }
    else if(a[kkx*3-1][kky*3-3])
    {
        Q.push(make_pair(kkx*3-1,kky*3-3));
    }
}
void co(void)
{
    int i,j;

    for(i=1; i<=r*3; i++)
    {
        for(j=1; j<=c*3; j++)
        {
            ck[i][j]=0;
        }
    }
}

int ok1(int x,int y)
{
    int i;

    for(i=0; i<=3; i++)
    {
        if(x+(2*dy[i])==kx && y+(2*dx[i])==ky)
        {
            return 0;
        }
    }
    return 1;
}

int ok(int x,int y)
{
    int i;

    for(i=0; i<=3; i++)
    {
        if((x+(2*dy[i]))%3==2 && (y+(2*dx[i]))%3==2)
        {
            tx=x+(2*dy[i]);
            ty=y+(2*dx[i]);
        }
        if(x+(2*dy[i])==kx && y+(2*dx[i])==ky)
        {
            return 0;
        }
    }
    return 1;
}

void process(void)
{
    int i,j;
    int x,y;
    int ix;
    int idx,idy;

    while(!Q.empty())
    {
        x=Q.front().first;
        y=Q.front().second;
        Q.pop();
        if(!ck[x][y] && a[x][y])
        {
            ck[x][y]=1;
            ix=-1;
            for(i=0; i<=3; i++)
            {
                if(x+dy[i]<=r*3 && x+dy[i]>0 && y+dx[i]<=c*3 && y+dx[i]>0)
                {
                    Q.push(make_pair(x+dy[i],y+dx[i]));
                }
                if(a[x+dy[i]][y+dx[i]]!=0)
                {
                    if(!ck[x+dy[i]][y+dx[i]])
                    {
                        ix=100;
                    }
                    ix++;
                }
            }
            if(ix<=0)
            {
                if(ok(x,y))
                {
                    idx=x;
                    idy=y;
                    while(!Q.empty())
                    {
                        Q.pop();
                    }
                    break;
                }
            }
        }
    }
    for(i=1; i<=7; i++)
    {
        for(x=tx-1; x<=tx+1; x++)
        {
            for(y=ty-1; y<=ty+1; y++)
            {
                a[x][y]=s[i][x-tx+2][y-ty+2];
            }
        }
        co();
        if(a[kkx*3+1][kky*3-1])
        {
            Q.push(make_pair(kkx*3+1,kky*3-1));
        }
        else if(a[kkx*3-1][kky*3+1])
        {
            Q.push(make_pair(kkx*3-1,kky*3+1));
        }
        else if(a[kkx*3-3][kky*3-1])
        {
            Q.push(make_pair(kkx*3-3,kky*3-1));
        }
        else if(a[kkx*3-1][kky*3-3])
        {
            Q.push(make_pair(kkx*3-1,kky*3-3));
        }
        while(!Q.empty())
        {
            x=Q.front().first;
            y=Q.front().second;
            Q.pop();
            if(!ck[x][y] && a[x][y])
            {
                ck[x][y]=1;
                ix=-1;
                for(j=0; j<=3; j++)
                {
                    if(x+dy[j]<=r*3 && x+dy[j]>0 && y+dx[j]<=c*3 && y+dx[j]>0)
                    {
                        Q.push(make_pair(x+dy[j],y+dx[j]));
                    }
                    if(a[x+dy[j]][y+dx[j]]!=0)
                    {
                        if(!ck[x+dy[j]][y+dx[j]])
                        {
                            ix=100;
                        }
                        ix++;
                    }
                }
                if(ix<=0)
                {
                    if(ok1(x,y))
                    {
                        while(!Q.empty())
                        {
                            Q.pop();
                        }
                        break;
                    }
                    else
                    {
                        idx=x;
                        idy=y;
                    }
                }
            }
        }
        if(!ok1(idx,idy))
        {
            if(i==5)
            {
                fprintf(fp2,"%d %d |",(tx+1)/3,(ty+1)/3);
            }
            else if(i==6)
            {
                fprintf(fp2,"%d %d -",(tx+1)/3,(ty+1)/3);
            }
            else if(i==7)
            {
                fprintf(fp2,"%d %d +",(tx+1)/3,(ty+1)/3);
            }
            else
            {
                fprintf(fp2,"%d %d %d",(tx+1)/3,(ty+1)/3,i);
            }
            break;
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
