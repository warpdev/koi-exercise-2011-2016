#include <stdio.h>
#include <string.h>
#define N 300000

FILE *fp1,*fp2;

int n,k;
int a[N+2];
int ck[20+1];
long long cnt;



void input(void)
{
	int i,j;
	char temp[30];

	fscanf(fp1,"%d %d",&n,&k);
	for(i=1; i<=n; i++)
	{
		fscanf(fp1,"%s",&temp[1]);
		a[i]=strlen(temp);
	}
}

void process(void)
{
	int i,j,t;

	for(i=1; i<=n; i++)
	{
		cnt+=ck[a[i]];
		if(i-k>0)
		{
			ck[a[i-k]]--;
		}
		ck[a[i]]++;
	}
	fprintf(fp2,"%lld",cnt);
}

int main(void)
{
	fp1=fopen("input.txt","r");
	fp2=fopen("output.txt","w");
	input();
	process();
	return 0;
}
