#include <stdio.h>
#include <algorithm>
using namespace std;
#include <vector>
#include <queue>
#define N 100
typedef pair<int,int> pp;
typedef pair<pp,pp> ppp;
#define INF 100000000

FILE *fp1,*fp2;

int n,m;
int a[4][N+1][N+1];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int fx,fy,fw;
int sx,sy,sw;
priority_queue<ppp,vector<ppp>,greater<ppp> > Q;

void input(void)
{
	int i,j;

	fscanf(fp1,"%d %d",&n,&m);
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=m; j++)
		{
			a[0][i][j]=0;
			a[1][i][j]=0;
			a[2][i][j]=0;
			a[3][i][j]=0;
		}
	}
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=m; j++)
		{
			fscanf(fp1,"%d",&a[0][i][j]);
			a[1][i][j]=a[0][i][j];
			a[2][i][j]=a[0][i][j];
			a[3][i][j]=a[0][i][j];
		}
	}
	fscanf(fp1,"%d %d %d %d %d %d",&fx,&fy,&fw,&sx,&sy,&sw);
	if(sw==1)
	{
		sw=0;
	}
	else if(sw==3)
	{
		sw=1;
	}
	else if(sw==4)
	{
		sw=3;
	}
	if(fw==1)
	{
		fw=0;
	}
	else if(fw==3)
	{
		fw=1;
	}
	else if(fw==4)
	{
		fw=3;
	}
	Q.push(make_pair(make_pair(0,fx),make_pair(fy,fw)));
	a[sw][sx][sy]=0;
}

void process(void)
{
	int i,j,x,y,w,d;

	while(!Q.empty())
	{
		w=Q.top().first.first;
		x=Q.top().first.second;
		y=Q.top().second.first;
		d=Q.top().second.second;
		Q.pop();
		if(!a[d][x][y])
		{
			a[d][x][y]=1;
			if(x==sx && y==sy && d==sw)
			{
				fprintf(fp2,"%d",w);
				return;
			}
			for(i=1; i<=3; i++)
			{
				if(a[d][x+(dy[d]*i)][y+(dx[d]*i)])
				{
					break;
				}
				if(x+(dy[d]*i)>=1 && y+(dx[d]*i)>=1 && y+(dx[d]*i)<=m && x+(dy[d]*i)<=n)
				{
					Q.push(make_pair(make_pair(w+1,x+(dy[d]*i)),make_pair(y+(dx[d]*i),d)));
				}
			}
			for(i=0; i<=3; i++)
			{
				if(d!=i)
				{
					if((i+d)%2)
					{
						Q.push(make_pair(make_pair(w+1,x),make_pair(y,i)));
					}
					else
					{
						Q.push(make_pair(make_pair(w+2,x),make_pair(y,i)));
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