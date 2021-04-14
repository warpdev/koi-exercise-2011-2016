#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 3402
typedef pair<int,int> pp;

FILE *fp1,*fp2;

pp a[N+1];
int n,m;
int dy[12880+1];
int mx;

void input(void)
{
	int i;

	fscanf(fp1,"%d %d",&n,&m);
	for(i=1; i<=n; i++)
	{
		fscanf(fp1,"%d %d",&a[i].first,&a[i].second);
	}
}

void process(void)
{
	int i,j;

	for(i=1; i<=n; i++)
	{
		for(j=m; j>=a[i].first; j--)
		{
			if(dy[j]<dy[j-a[i].first]+a[i].second)
			{
				dy[j]=dy[j-a[i].first]+a[i].second;
			}
		}
	}
	for(i=1; i<=m; i++)
	{
		if(mx<dy[i])
		{
			mx=dy[i];
		}
	}
	fprintf(fp2,"%d",mx);	
}

int main(void)
{
	fp1=fopen("input.txt","r");
	fp2=fopen("output.txt","w");
	input();
	process();
	return 0;
}