#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 100
typedef pair<int,int> pp;
typedef pair<int,pp> ppp;

FILE *fp1,*fp2;

int n;
ppp a[N+1];
int ts,tf,sm;
int ck[N+1];

void input(void)
{
	int i;

	fscanf(fp1,"%d",&n);
	for(i=1; i<=n; i++)
	{
		fscanf(fp1,"%d %d",&a[i].second.first,&a[i].second.second);
		a[i].first=a[i].second.first+a[i].second.second;
		ts+=a[i].second.first;
		tf+=a[i].second.second;
		sm+=a[i].first;
	}
	sort(a+1,a+1+n);
}

void process(void)
{
	int i;

	for(i=1; i<=n; i++)
	{
		if(a[i].second.first<=0 && a[i].second.second<=0)
		{
			sm-=a[i].first;
			ts-=a[i].second.first;
			tf-=a[i].second.second;
			ck[i]=1;
		}
	}
	if(ts<0)
	{
		for(i=1; i<=n; i++)
		{
			if(!ck[i])
			{
				if(a[i].second.first<0)
				{
					if((tf-a[i].second.second)>=0 || tf<0)
					{
						sm-=a[i].first;
						ts-=a[i].second.first;
						tf-=a[i].second.second;
						ck[i]=1;
					}
				}
			}
			if(ts>=0)
			{
				break;
			}
		}
	}
	if(tf<0)
	{
		for(i=1; i<=n; i++)
		{
			if(!ck[i])
			{
				if(a[i].second.second<0)
				{
					if((ts-a[i].second.first)>=0)
					{
						sm-=a[i].first;
						ts-=a[i].second.first;
						tf-=a[i].second.second;
						ck[i]=1;
					}
				}
			}
			if(tf>=0)
			{
				break;
			}
		}
	}
	fprintf(fp2,"%d",sm);
}

int main(void)
{
	fp1=fopen("input.txt","r");
	fp2=fopen("output.txt","w");
	input();
	process();
	return 0;
}