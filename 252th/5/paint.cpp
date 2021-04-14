#include <stdio.h>
#define N 100000

FILE *fp1,*fp2;

int n;
int a[N+1];
int b[N+1];
int cnt1,cnt2;
long long sm1,sm2;

void input(void)
{
	int i,tx;
	char t;
	
	fscanf(fp1,"%d",&n);
	cnt1=0;
	cnt2=0;
	for(i=1; i<=n; i++){
		fscanf(fp1,"%d %c ",&tx,&t);
		if(t=='L'){
			cnt1++;
			a[cnt1]=tx;
		}
		else{
			cnt2++;
			b[cnt2]=tx;
		}
	}
}

void process(void)
{
	int i;

	for(i=1; i<=cnt1; i++){
		sm1+=(long long)a[i];
		if(sm1>2000000000){
			sm1=2000000000;
			break;
		}
	}
	for(i=1; i<=cnt2; i++){
		sm2+=(long long)b[i];
		if(sm2>2000000000){
			sm2=2000000000;
			break;
		}
	}
	if(sm1>sm2){
		fprintf(fp2,"%lld",sm2);
	}
	else{
		fprintf(fp2,"%lld",sm1);
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