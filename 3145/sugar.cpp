#include <stdio.h>

FILE *fp1,*fp2;

int n;
int k;

void input(void)
{
	fscanf(fp1,"%d",&n);
}

void process(void)
{
	int i;

	k=n/5;

	for(i=k; i>=0; i--){
		if((n-i*5)%3==0){
			fprintf(fp2,"%d",i+(n-i*5)/3);
			return;
		}
	}
	if(n%3==0){
		fprintf(fp2,"%d",n/3);
	}else{
		fprintf(fp2,"-1");
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
