#include <stdio.h>

FILE *fp1,*fp2;

int a,b,t;
int s,k;
int mn=999999999;
int mx;

void input(void)
{
	fscanf(fp1,"%d %d %d",&a,&b,&t);
}

void process(void)
{
	int i,p,ty;
	int ts;

	if(a>t && b>t){
		fprintf(fp2,"0 %d",t);
		return;
	}
	if(a>b){
		p=t/b;
		ty=1;
	}else{
		p=t/a;
		ty=2;
	}
	for(i=p; i>=0; i--){
		if(ty==1){
			ts=t-(i*b);
			if(ts%a<mn){
				mn=ts%a;
				mx=i+(ts/a);
			}
		}else{
			ts=t-(i*a);
			if(ts%b<mn){
				mn=ts%b;
				mx=i+(ts/b);
			}
		}
	}
	if(mn==0){
		fprintf(fp2,"%d",mx);
	}else{
		fprintf(fp2,"%d %d",mx,mn);
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
