#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 100000

FILE *fp1,*fp2;

int n,l;
int a[N+1];
int lef=1;
int cnt;
int ck[N+1];

void input(void)
{
	int i;

	fscanf(fp1,"%d %d",&n,&l);

	for(i=1; i<=n; i++){
		fscanf(fp1,"%d",&a[i]);
	}
	sort(a+1,a+n+1);
}

void process(void)
{
	int i,t;

	for(i=n; i>=1; i--){
		if(ck[i]==0){
			t=l-a[i];
			cnt++;
			ck[i]=1;
			if(a[lef]<=t && ck[lef]==0){
				ck[lef]=1;
				lef++;
			}
		}
	}
}

void output(void)
{
	fprintf(fp2,"%d",cnt);
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