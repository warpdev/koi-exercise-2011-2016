#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
#define N 350
typedef pair<int,int> pp;
typedef pair<int,pp> ppp;

FILE *fp1,*fp2;

int h,n;
pp a[N+1];
pp b[N+1];
int dy[100005];

void input(void)
{
	int i;

	fscanf(fp1,"%d %d",&h,&n);
	for(i=1; i<=n; i++)
	{
		fscanf(fp1,"%d %d",&b[i].second,&b[i].first);
	}
	sort(b+1,b+n+1);
	for(i=1; i<=n; i++)
	{
		a[i].first=b[n-i+1].second;
		a[i].second=b[n-i+1].first;
	}
	dy[0]=1;
}

void process(void)
{
	int i,j;

	for(i=1; i<=n; i++)
	{
		for(j=h; j>=0; j--)
		{
			if(dy[j] && j+a[i].first<=h)
			{
				dy[j+a[i].first]=1;
			}
		}
		if(dy[h]==1)
		{
			fprintf(fp2,"%d",a[i].second);
			return;
		}
	}
	fprintf(fp2,"0");
}


int main(void)
{
	fp1=fopen("input.txt","r");
	fp2=fopen("output.txt","w");
	input();
	process();
	return 0;
}