#include <stdio.h>

FILE *fp1,*fp2;

int mx;
int n;

void input(void)
{
	fscanf(fp1,"%d",&n);
}

void process(void)
{
	if(n>mx)
	{
		mx=n;
	}
	while(n!=1)
	{
		if(n>mx)
		{
			mx=n;
		}
		if(n%2==0)
		{
			n=n/2;
		}
		else
		{
			n=n*3+1;
		}
	}
}

void output(void)
{
	fprintf(fp2,"%d",mx);
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