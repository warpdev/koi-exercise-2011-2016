#include <stdio.h>
#include <algorithm>
using namespace std;
#include <vector>
#include <queue>
#define N 500
typedef pair<int,int> pp;
typedef pair<int,pp> ppp;

FILE *fp1,*fp2;

int n,c;
int fx,fy;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int a[N+1][N+1];
priority_queue<ppp,vector<ppp>,greater<ppp> > Q;
int ck[N+1][N+1];

void input(void)
{
	int i,j;
	char t[N+2];
	
	fscanf(fp1,"%d %d",&n,&c);

	for(i=1; i<=n; i++)
	{
		fscanf(fp1,"%s",&t[1]);
		for(j=1; j<=n; j++)
		{
			if(t[j]=='*')
			{
				a[i][j]=c+1;
			}
			else
			{
				a[i][j]=1;
				if(t[j]=='S')
				{
					Q.push(make_pair(0,make_pair(i,j)));
				}
				if(t[j]=='T')
				{
					fx=i;
					fy=j;
				}
			}
		}
	}
}

void process(void)
{
	int i,x,y,w,tx,ty;

	while(!Q.empty())
	{
		x=Q.top().second.first;
		y=Q.top().second.second;
		w=Q.top().first;
		Q.pop();
		if(x==fx && y==fy)
		{
			fprintf(fp2,"%d",w);
			break;
		}
		if(ck[x][y]==0)
		{
			ck[x][y]=1;
			for(i=0; i<=3; i++)
			{
				tx=x+dy[i];
				ty=y+dx[i];
				if(tx<=n && tx>=1 && ty<=n && ty>=1)
				{
					Q.push(make_pair(a[tx][ty]+w,make_pair(tx,ty)));
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