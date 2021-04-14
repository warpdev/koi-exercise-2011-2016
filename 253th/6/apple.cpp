#include <stdio.h>
#define N 100

FILE *fp1,*fp2;

int t,n,m;
int cnt;

void process(int x,int y)
{
	int i,k,j,tm;

	k=x/y;
	for(i=0; i<=k; i++){
		tm=x-(y*i);
		cnt+=tm/2+1;
	}
}

void input(void)
{
	int i;

	fscanf(fp1,"%d",&t);
	for(i=1; i<=t; i++){
		fscanf(fp1,"%d %d",&n,&m);
		cnt=0;
		process(n,m);
		fprintf(fp2,"%d\n",cnt);
	}
}

int main(void)
{
	fp1=fopen("input.txt","r");
	fp2=fopen("output.txt","w");
	input();
	return 0;
}