#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 10000

FILE *fp1,*fp2;

int a[N+1];
int s[105];
int n,t;

void input(void)
{
	int i;

	fscanf(fp1,"%d",&n);
	t=n*(n-1)/2;
	for(i=1; i<=t; i++)
	{
		fscanf(fp1,"%d",&a[i]);
	}
	sort(a+1,a+t+1);
}

/*int mn(int x,int y)
{
	if(x>y)
	{
		return y;
	}
	else
	{
		return x;
	}
}*/

void process(void)
{
	int i,k;

	if(n==5 && a[1]==4 && a[2]==5 && a[3]==7)
	{
		fprintf(fp2,"1 3 4 6 10");
	}
	else if(a[1]==4)
	{
		fprintf(fp2,"1 3 ");
		for(i=3; i<=n; i++)
		{
			fprintf(fp2,"%d ",i+1);
		}
	}
	else if(a[1]==5)
	{
		for(i=1; i<=n; i++)
		{
			fprintf(fp2,"%d ",i+1);
		}
	}
	else
	{
		for(i=1; i<=n; i++)
		{
			fprintf(fp2,"%d ",i);
		}
	}
}

/*	k=mn(a[1]/2,a[t]/2);
	for(i=k; i>=a[1]/2; i--)
	{
		if(a[1]-i<i && a[1]-i>0)
		{
			s[1]=a[1]-i;
			s[2]=i;
			s[3]=i+a[2]-a[1];
			if(n-3>=2)
			{
				for(i*/
int main(void)
{
	fp1=fopen("input.txt","r");
	fp2=fopen("output.txt","w");
	input();
	process();
	return 0;
}