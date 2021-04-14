#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 50000
typedef pair<int,int> pp;
typedef pair<int,pp> ppp;

FILE *fp1,*fp2;

int n;
ppp a[N+1];
pp t[N+1];
int ck[N+1];
int cnt;

void input(void)
{
	int i,j;

	fscanf(fp1,"%d",&n);
	for(i=1; i<=n; i++)
	{
		fscanf(fp1,"%d %d %d",&a[i].second.first,&a[i].second.second,&a[i].first);
		for(j=a[i].second.first; j<=a[i].second.second; j++)
		{
			t[j].first++;
			t[j].second=j;
		}
	}
}

void process(void)
{
	pp temp[N+1];
	int i,j;

	for(i=1; i<=n; i++)
	{
		for(j=a[i].second.first; j<=a[i].second.second; j++)
		{
			temp[j].first=t[j].first;
			temp[j].second=j;
			if(ck[j]==1 && a[i].first)
			{
				a[i].first--;
			}
		}
		sort(temp+a[i].second.first,temp+1+a[i].second.second);
		for(j=1; j<=a[i].first; j++)
		{
			ck[temp[j+a[i].second.first-1].second]=1;
			cnt++;
		}
	}
}

void output(void)
{
	fprintf(fp2,"%d",cnt);
}

int main(void)
{
	fp1=fopen("input.txt","r");
	fp2=fopen("output.txt","w");
	input();
	process();
	output();
	return 0;
}
