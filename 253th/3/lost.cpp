#include <stdio.h>
#define N 8000

FILE *fp1,*fp2;

int n;
int a[N+1];
int s[N+1];

void input(void)
{
	int i;

	fscanf(fp1,"%d",&n);
	for(i=1; i<n; i++){
		fscanf(fp1,"%d",&a[i+1]);
	}
}

void process(void)
{
	int i,lev=1,j;

	while(lev<=n){
		for(i=n; i>=1; i--){
			if(a[i]==0){
				s[i]=lev;
				for(j=i; j<=n; j++){
					a[j]--;
				}
				lev++;
				break;
			}
		}
	}
}

void output(void)
{
	int i;

	for(i=1; i<=n; i++){
		fprintf(fp2,"%d\n",s[i]);
	}
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