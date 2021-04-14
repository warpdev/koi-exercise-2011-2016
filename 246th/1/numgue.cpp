#include <stdio.h>
#define N 4

FILE *fp1,*fp2;

char a[N+2];
char b[N+2];
int cnta,cntb;

void input(void)
{
	fscanf(fp1,"%s",&a[1]);
	fscanf(fp1,"%s",&b[1]);
}

void process(void)
{
	int i,j;

	for(i=1; i<=N; i++)
	{
		if(a[i]==b[i])
		{
			cnta++;
		}
		else
		{
			for(j=1; j<=N; j++)
			{
				if(a[i]==b[j])
				{
					cntb++;
				}
			}
		}
	}
}

void output(void)
{
	fprintf(fp2,"%dA%dB",cnta,cntb);
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
