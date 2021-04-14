#include <stdio.h>

FILE *fp1,*fp2;

int n;
int s=1;

void input(void)
{
	fscanf(fp1,"%d",&n);
}

void process(void)
{
	int i;

	for(i=1; i<=n; i++){
		s*=2;
		s=s%100;
	}
	fprintf(fp2,"%d",s);
}

int main(void)
{
	fp1=fopen("input.txt","r");
	fp2=fopen("output.txt","w");
	input();
	process();
	return 0;
}