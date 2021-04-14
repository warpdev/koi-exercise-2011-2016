#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
#define N 100
typedef pair<int,int> pp;
FILE *fp1,*fp2;

int r,c;
int a[N+1][N+1];
int ck[N+1][N+1];
int dx[4]= {1,0,-1,0};
int dy[4]= {0,1,0,-1};
int fx,fy;
queue<pp> Q;

void input(void)
{
    int i,j;
    char t;

    fscanf(fp1,"%d %d ",&r,&c);
    for(i=1; i<=r; i++)
    {
        for(j=1; j<=c; j++)
        {
            fscanf(fp1,"%c",&t);
            if(t=='.' || t=='C' || t=='B')
            {
                a[i][j]=1;
            }
            else
            {
                a[i][j]=0;
            }
            if(t=='C')
            {
                Q.push(make_pair(i,j));
            }
            else if(t=='B')
            {
                fx=i;
                fy=j;
            }
           // printf("%d ",a[i][j]);
        }
     //   printf("\n");
        fscanf(fp1,"%c",&t);
    }
}

void process(void)
{
    int i,j;
    int x,y;
    int tx,ty;

    while(!Q.empty())
    {
        x=Q.front().first;
        y=Q.front().second;
        Q.pop();
       // printf("A");
        if(x==fx && y==fy)
        {
            fprintf(fp2,"%d",a[x][y]-1);
            break;
        }
        if(!ck[x][y])
        {
            ck[x][y]=1;
            for(i=0; i<=3; i++)
            {
                tx=x+dy[i];
                ty=y+dx[i];
                if(tx<=r && ty<=c && tx>=1 && ty>=1)
                {
                    if(a[tx][ty])
                    {
                        Q.push(make_pair(tx,ty));
                        a[tx][ty]=a[x][y]+1;
                    }
                }
            }
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
