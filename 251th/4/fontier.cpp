#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define N 100

FILE *fp1,*fp2;

int n;
long long a[N+1];
long long b[N+1];
priority_queue<int> Q; 

void input(void)
{
	int i;

	fscanf(fp1,"%d",&n);
	for(i=1; i<=n; i++)
	{
		fscanf(fp1,"%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(i=1; i<=n-1; i++)
	{
		b[i]=a[i+1]-a[i];
	}
	sort(b+1,b+n);
}

int ckk(int x)
{
	int i;

	for(i=2; i<=n-1; i++)
	{
		if(b[i]%(long long)x!=0)
		{
			return 0;
		}
	}
	return 1;
}

void process(void)
{
	long long i;
	int j,tm=0;

	tm=sqrt(b[1]);
	for(i=1; i<=tm; i++)
	{
		if(b[1]%i==0)
		{
			Q.push(i);
			if(ckk(i))
			{
				if(i!=1)
				{
					fprintf(fp2,"%d ",i);
				}
			}
		}
	}
	while(!Q.empty())
	{
		if(ckk(b[1]/Q.top()))
		{
			if(b[1]/Q.top()!=Q.top())
			{
				fprintf(fp2,"%d ",b[1]/Q.top());
			}
		}
		Q.pop();
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