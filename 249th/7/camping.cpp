#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 300

FILE *fp1,*fp2;

int t[N*N+10];
int k,n,m;
int a[N+1][N+1];
int cnt;

void input(void)
{
	int i,j,y;

	fscanf(fp1,"%d %d %d",&k,&n,&m);
	n+=k;
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
		{
			fscanf(fp1,"%d",&y);
			if(y)
			{
				cnt++;
				t[cnt]=y;
			}
		}
	}
	sort(t+1,t+cnt+1);
}

void output(void)
{
	if((t[1]+t[cnt])%2==0)
	{
		fprintf(fp2,"%d",(t[1]+t[cnt])/2);
	}
	else
	{
		fprintf(fp2,"0");
	}
}

int main(void)
{
	fp1=fopen("input.txt","r");
	fp2=fopen("output.txt","w");
	input();
	output();
	return 0;
}