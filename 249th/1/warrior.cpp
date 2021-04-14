#include <stdio.h>

FILE *fp1,*fp2;

long long a,b;

void input(void)
{
	fscanf(fp1,"%lld %lld",&a,&b);
}

void process(void)
{
	if(a>b)
	{
		fprintf(fp2,"%lld",a-b);
	}
	else
	{
		fprintf(fp2,"%lld",b-a);
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
