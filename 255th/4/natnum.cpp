#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
using namespace std;
#define N 20000

FILE *fp1,*fp2;

int n;
int a[N+1];
int mn=200000001;
int id;

void input(void)
{
	int i;

	fscanf(fp1,"%d",&n);
	for(i=1; i<=n; i++){
		fscanf(fp1,"%d",&a[i]);
	}
	sort(a+1,a+n+1);
}

void process(void)
{
	int i,j,k,ts=0;

	k=a[n];
	for(i=a[1]; i<=k; i++){
		ts=0;
		for(j=1; j<=n; j++){
			ts+=abs(a[j]-i);
		}
		if(ts<mn){
			mn=ts;
			id=i;
		}
		else
		{
			break;
		}
	}
	fprintf(fp2,"%d",id);
}

int main(void)
{
	fp1=fopen("input.txt","r");
	fp2=fopen("output.txt","w");
	input();
	process();
	return 0;
}
