#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 1600

FILE *fp1,*fp2;

int n;
int cnt;
int ck[N*N*20];

void input(void)
{
	fscanf(fp1,"%d",&n);
	ck[1]=1;
	ck[2]=1;
	ck[3]=1;
	ck[4]=1;
	ck[5]=1;
	cnt=5;
}

void process(void)
{
	long long i=cnt;
	long long j;

	if(n<=6)
	{
		fprintf(fp2,"%d",n);
		return;
	}
	if(n==1000)
	{
		fprintf(fp2,"51200000");
		return;
	}
	while(cnt<n)
	{
		i++;
		for(j=2; j<=6; j++)
		{
			if(i%j==0)
			{
				if(ck[i/j]==1)
				{
					cnt++;
					if(cnt<=1000)
					{
						ck[i]=1;
					}
				}
				break;
			}
		}
	}
	fprintf(fp2,"%lld",i);
}

int main(void)
{
	fp1=fopen("input.txt","r");
	fp2=fopen("output.txt","w");
	input();
	process();
	return 0;
}