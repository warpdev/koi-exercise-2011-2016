#include <stdio.h>

FILE *fp1,*fp2;

int n,sm;

void input(void)
{
	fscanf(fp1,"%d",&n);
}

void process(void)
{
	int i;

	for(i=1; i<n; i++){
		if(i%3==0 || i%5==0){
			sm+=i;
		}
	}
	fprintf(fp2,"%d",sm);
}

int main(void)
{
	fp1=fopen("input.txt","r");
	fp2=fopen("output.txt","w");
	input();
	process();
	return 0;
}
