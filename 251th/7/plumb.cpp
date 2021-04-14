#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 350
typedef pair<int,int> pp;

FILE *fp1,*fp2;

int d,n;
int sm;
pp a[N+1];
int dy[100000+1];

void input(void)
{
	int i;

	fscanf(fp1,"%d %d",&d,&n);
	for(i=1; i<=n; i++)
	{
		fscanf(fp1,"%d %d",&a[i].second,&a[i].first);
		sm+=a[i].second;
	}
	if(sm>d)
	{
		sm=d;
	}
	sort(a+1,a+n+1);
}

int mx(int x,int y)
{
	if(x==0)
	{
		return y;
	}
	if(x>y)
	{
		return y;
	}
	else
	{
		return x;
	}
}

void process(void)
{
	int i,j;

	for(j=1; j<=n; j++)
	{
		for(i=sm; i>=a[j].second; i--)
		{
			if(dy[i]<mx(dy[i-a[j].second],a[j].first))
			{
				dy[i]=mx(dy[i-a[j].second],a[j].first);
				if(i==45){
					printf("%d %d %d\n",a[j].second,i-a[j].second,a[j].first);
				}
			}
		}
	}
	for(i=1; i<=d; i++){
		printf("%d\n",dy[i]);
	}
}

void output(void)
{
	fprintf(fp2,"%d",dy[d]);
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