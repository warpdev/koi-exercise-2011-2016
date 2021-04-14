#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 1000
typedef pair<int,int> pp;
typedef pair<int,pp> ppp;

FILE *fp1,*fp2;

int n,l;
ppp a[N+1];
int w[N+1];
int ck[N+1];
int cnt;

void input(void)
{
	int i;

	fscanf(fp1,"%d %d",&n,&l);
	for(i=0; i<=l; i++)
	{
		w[i]=1;
	}
	for(i=1; i<=n; i++)
	{
		fscanf(fp1,"%d %d %d",&a[i].first,&a[i].second.first,&a[i].second.second);
		w[a[i].first]=0;
	}
}

void process(void)
{
	int i,j;

	for(i=0; i<=l; i++)
	{
		if(w[i])
		{
			cnt++;
			for(j=1; j<=n; j++)
			{
				ck[a[j].first]++;
				if(w[a[j].first]==0 && a[j].second.first==ck[a[j].first])
				{
					w[a[j].first]=1;
					ck[a[j].first]=0;
				}
				else if(w[a[j].first]==1 && a[j].second.second==ck[a[j].first])
				{
					w[a[j].first]=0;
					ck[a[j].first]=0;
				}
			}
		}
		else
		{
			cnt++;
			for(j=1; j<=n; j++)
			{
				ck[a[j].first]++;
				if(w[a[j].first]==0 && a[j].second.first==ck[a[j].first])
				{
					w[a[j].first]=1;
					ck[a[j].first]=0;
				}
				else if(w[a[j].first]==1 && a[j].second.second==ck[a[j].first])
				{
					w[a[j].first]=0;
					ck[a[j].first]=0;
				}
			}
			i--;
		}
	}
}

void output(void)
{
	fprintf(fp2,"%d",cnt-1);
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