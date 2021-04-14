#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 100
typedef pair<int,int> pp;
typedef pair<int,pp> ppp;

FILE *fp1,*fp2;

int n,m;
ppp a[N+1];
int ck[N+1];
int c[N+1][N+1];
int cnt;
int mn=999999999;

void input(void)
{
	int i;

	fscanf(fp1,"%d %d",&n,&m);
	for(i=1; i<=m; i++)
	{
		fscanf(fp1,"%d %d %d",&a[i].second.first,&a[i].second.second,&a[i].first);
	}
	sort(a+1,a+m+1);
}

int prime(void)
{
	int i;

	f
}

int chk(int x,int y)
{
	int k=0,i;

	if(c[x][y])
	{
		return 1;
	}
	for(i=x; i<=n; i++)
	{
		if(c[x][i])
		{
			k=chk(i,y);
		}
		if(k)
		{
			return 1;
		}
	}
	return 0;
}

void process(void)
{
	int i,j,k,typ=0;

	for(i=1; i<=m; i++)
	{
		if(!chk(a[i].second.first,a[i].second.second))
		{
			cnt+=a[i].first;
			ck[i]=3;
			c[a[i].second.first][a[i].second.second]=1;
			c[a[i].second.second][a[i].second.first]=1;
		}
	}
	fprintf(fp2,"%d ",cnt);
	for(i=1; i<=m; i++)
	{
		if(ck[i]==3)
		{
			for(j=i; j<=m; j++)
			{
				if(ck[j]==0)
				{
					if(mn>a[j].first-a[i].first)
					{
						mn=a[j].first-a[i].first;
					}
				}
			}
		}
	}
	fprintf(fp2,"%d",cnt+mn);
}

int main(void)
{
	fp1=fopen("input.txt","r");
	fp2=fopen("output.txt","w");
	input();
	process();
	return 0;
}
	/*for(i=1; i<=m; i++)
	{
		printf("%d\n",m);
		if(ck[i]==0)
		{
			cnt=0;
			printf("\n\n-------------------------------------------\n\n");
			for(j=1; j<=n; j++)
			{
				for(k=1; k<=n; k++)
				{
					c[j][k]=0;
				}
			}
			ck[i]=1;
			for(j=1; j<=m; j++)
			{
				if(ck[j]!=1)
				{
					if(!chk(a[j].second.first,a[j].second.second))
					{
						cnt+=a[j].first;
						c[a[j].second.first][a[j].second.second]=1;
						c[a[j].second.second][a[j].second.first]=1;
					}
				}
			}
			ck[i]=0;
			for(j=1; j<=n; j++)
			{
				for(k=1; k<=n; k++)
				{
					printf("%d ",c[j][k]);
				}
				printf("\n");
			}
			if(mn>cnt)
			{
				mn=cnt;
			}
		}
	}*/