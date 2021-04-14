#include <stdio.h>
#include <algorithm>
using namespace std;
#include <vector>
#define N 5

FILE *fp1,*fp2;

int n;
int a[N+1][N+1];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int ck[N+1][N+1];
int mx;
vector<int> s;

void input(void)
{
	int i,j;
	char temp[N+6];
	
	fscanf(fp1,"%d",&n);
	for(i=1; i<=n; i++)
	{
		fscanf(fp1,"%s",&temp[1]);
		for(j=1; j<=n; j++)
		{
			if(temp[j]=='(')
			{
				a[i][j]=1;
			}
			else
			{
				a[i][j]=0;
			}
		}
	}
}

int rgt(void)
{
	int i,t,sm=0,typ=1;

	t=s.size()-1;

	if((t+1)%2==1)
	{
		return 0;
	}
	for(i=0; i<=t; i++)
	{
		if(!s[i])
		{
			typ=0;
		}
		if(typ==1)
		{
			sm+=s[i];
		}
		else if(typ==0 && s[i]==1)
		{
			return 0;
		}
	}
	if(sm==(t+1)/2)
	{
		return 1;
	}
	return 0;
}

void process(int x,int y,int w)
{
	int i,tx,ty;

	if(rgt())
	{
		if(mx<w)
		{
			mx=w;
		}
	}
	for(i=0; i<=3; i++)
	{
		tx=x+dy[i];
		ty=y+dx[i];
		if(tx>=1 && ty>=1 && tx<=n && ty<=n)
		{
			if(!ck[tx][ty])
			{
				ck[tx][ty]=1;
				s.push_back(a[tx][ty]);
				process(tx,ty,w+1);
				s.pop_back();
				ck[tx][ty]=0;
			}
		}
	}
}

void output(void)
{
	fprintf(fp2,"%d",mx);
}

int main(void)
{
	fp1=fopen("input.txt","r");
	fp2=fopen("output.txt","w");
	input();
	if(a[1][1])
	{
		ck[1][1]=1;
		s.push_back(1);
		process(1,1,1);
	}
	output();
	return 0;
}