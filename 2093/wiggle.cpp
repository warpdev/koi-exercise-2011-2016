#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 75

FILE *fp1,*fp2;

int n;
char a[N+2];
int dy[N+1];
int dy2[N+1];

void input(void)
{
	int t=1;
	fscanf(fp1,"%s",&a[1]);
	while(a[t]!=0)
	{
		t++;
	}
	n=t-1;
}

void process(void)
{
	int i;

	dy[1]=1;
	dy2[1]=1;
	for(i=1; i<=n-1; i++)
	{
		if(i%2==1)
		{
			if(a[i]<a[i+1])
			{
				dy[i+1]=dy[i]+1;
				dy2[i+1]=1;
			}
			else
			{
				dy[i+1]=1;
				if(a[i]>a[i+1])
				{
					dy2[i+1]=dy2[i]+1;
				}
			}
		}
		else
		{
			if(a[i]>a[i+1])
			{
				dy[i+1]=dy[i]+1;
				dy2[i+1]=1;
			}
			else
			{
				dy[i+1]=1;
				if(a[i]<a[i+1])
				{
					dy2[i+1]=dy2[i]+1;
				}
			}
		}
	}
	sort(dy+1,dy+n+1);
	sort(dy2+1,dy2+n+1);
}

void output(void)
{
	if(dy[n]>dy2[n])
	{
		fprintf(fp2,"%d",dy[n]);
	}
	else
	{
		fprintf(fp2,"%d",dy2[n]);
	}
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
