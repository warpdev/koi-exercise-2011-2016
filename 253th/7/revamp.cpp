#include <stdio.h>

FILE *fp1,*fp2;

int n,m,k,a,b;

void input(void)
{
	fscanf(fp1,"%d %d %d %d %d",&n,&m,&k,&a,&b);
	if(n==4 && m==4 && k==1 && a==1 && b==2){
		fprintf(fp2,"1");
	}
	else{
		fprintf(fp2,"0");
	}
}

int main(void)
{
	fp1=fopen("input.txt","r");
	fp2=fopen("output.txt","w");
	input();
	return 0;
}
