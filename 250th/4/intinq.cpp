#include <stdio.h>
#include <string.h>
#define N 100

FILE *fp1,*fp2;

int n;
int a[N+5][N+N];

void input(void)
{
	int i,j,k;
	char temp[N+N];

	while(1)
	{
		fscanf(fp1,"%s",&temp[1]);
		k=strlen(temp)-1;
		if(k==1 && temp[1]=='0')
		{
			break;
		}
		else
		{
			n++;
			for(i=1; i<=k; i++)
			{
				a[n][N+N-k+i]=temp[i]-48;
			}
		}
	}
}

void process(void)
{
	int i,j,k;

	for(i=N+N; i>=1; i--)
	{
		for(j=2; j<=n; j++)
		{
			a[1][i]+=a[j][i];
		}
		if(a[1][i]/10)
		{
			k=i;
			while(1)
			{
				k--;
				a[1][k]+=a[1][k+1]/10;
				a[1][k+1]%=10;
				if(a[1][k]/10==0)
				{
					break;
				}
			}
		}
	}
}

void output(void)
{
	int i,t=1;

	for(i=1; i<=N+N; i++)
	{
		if(!a[1][i] && t==1)
		{
		}
		else
		{
			t=0;
			fprintf(fp2,"%d",a[1][i]);
		}
	}
	if(t)
	{
		fprintf(fp2,"0");
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