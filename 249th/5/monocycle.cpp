#include <stdio.h>
#include <algorithm>
using namespace std;
#include <vector>
#include <queue>
#define N 25
typedef pair<int,int> pp;
typedef pair<pp,pp> ppp;
typedef pair<int,ppp> pppp;

FILE *fp1,*fp2;

int n,m;
int a[4][5][N+1][N+1];
int sx,sy,fx,fy;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
priority_queue<pppp,vector<pppp>,greater<pppp> > Q;

void input(void)
{
	int i,j,k,l;
	char temp[N+3];

	fscanf(fp1,"%d %d",&n,&m);

	for(i=1; i<=n; i++)
	{
		fscanf(fp1,"%s",&temp[1]);
		for(j=1; j<=m; j++)
		{
			if(temp[j]=='.')
			{
				for(k=0; k<=3; k++)
				{
					for(l=0; l<=4; l++)
					{
						a[k][l][i][j]=1;
					}
				}
			}
			else if(temp[j]=='#')
			{
				for(k=0; k<=3; k++)
				{
					for(l=0; l<=4; l++)
					{
						a[k][l][i][j]=0;
					}
				}
			}
			else if(temp[j]=='S')
			{
				sx=i;
				sy=j;
				for(k=0; k<=3; k++)
				{
					for(l=0; l<=4; l++)
					{
						a[k][l][i][j]=1;
					}
				}
			}
			else
			{
				fx=i;
				fy=j;
				for(k=0; k<=3; k++)
				{
					for(l=0; l<=4; l++)
					{
						a[k][l][i][j]=1;
					}
				}
			}
		}
	}
	Q.push(make_pair(0,make_pair(make_pair(sx,sy),make_pair(0,3))));
}

void process(void)
{
	int i,x,y,w,d,k;

	while(!Q.empty())
	{
		w=Q.top().first;
		x=Q.top().second.first.first;
		y=Q.top().second.first.second;
		k=Q.top().second.second.first;
		d=Q.top().second.second.second;
		Q.pop();
		if(k==0 && x==fx && y==fy)
		{
			fprintf(fp2,"%d",w);
			return;
		}
		if(a[d][k][x][y])
		{
			a[d][k][x][y]=0;
			for(i=0; i<=3; i++)
			{
				if(i!=d)
				{
					if((i+d)%2!=0)
					{
						Q.push(make_pair(w+1,make_pair(make_pair(x,y),make_pair(k,i))));
					}
					else
					{
						Q.push(make_pair(w+2,make_pair(make_pair(x,y),make_pair(k,i))));
					}
				}
				else if(x+dy[d]>=1 && y+dx[d]>=1 && x+dy[d]<=n && y+dx[d]<=m)
				{
					Q.push(make_pair(w+1,make_pair(make_pair(x+dy[d],y+dx[d]),make_pair((k+1)%5,d))));
				}
			}
		}
	}
	fprintf(fp2,"-1");
}

int main(void)
{
	fp1=fopen("input.txt","r");
	fp2=fopen("output.txt","w");
	input();
	process();
	return 0;
}