#include <stdio.h>
#define N 5000

FILE *fp1,*fp2;

int n;
int a[N+1];
int mx;
int l,r;

void input(void)
{
	int i;

	fscanf(fp1,"%d",&n);
	for(i=1; i<=n; i++)
	{
		fscanf(fp1,"%d",&a[i]);
	}
}

void process(void)
{
	int i,j;
	int cnt=0;

	for(i=5; i<n-1; i++)
	{
		cnt=0;
		for(j=1; j<=n; j++)
		{
			if(j+i<n)
			{
				if(a[j]-a[j+1]==a[j+i]-a[j+i+1])
				{
					cnt++;
				}
				else
				{			
					if(cnt>mx)
					{
						mx=cnt;
					}
					cnt=0;
				}
			}
			if(cnt>i)
			{
				cnt=i;
				break;
			}
		}
		if(cnt>mx)
		{
			mx=cnt;
		}
	}
}

void output(void)
{
	if(mx<4)
	{
		fprintf(fp2,"0");
	}
	else
	{
		if(n%2==1 && mx==n/2)
		{
			mx--;
		}
		fprintf(fp2,"%d",mx+1);
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