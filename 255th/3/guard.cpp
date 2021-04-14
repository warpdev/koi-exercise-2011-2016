#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
using namespace std;
#define N 100
typedef pair<int,int> pp;

FILE *fp1,*fp2;

int n;
int w,h;
pp a[N+1];
int x,y;
int sm;

void input(void)
{
	int i;

	fscanf(fp1,"%d %d %d",&w,&h,&n);
	for(i=1; i<=n; i++){
		fscanf(fp1,"%d %d",&a[i].first,&a[i].second);
	}
	fscanf(fp1,"%d %d",&x,&y);
}

void process(void)
{
	int i;
	int ts,tss;

	if(x==2){
		for(i=1; i<=n; i++){
			if(x==a[i].first){
				sm+=abs(y-a[i].second);
			}else if(a[i].first==3){
				sm+=y;
				sm+=h-a[i].second;
			}else if(a[i].first==4){
				sm+=w-y;
				sm+=h-a[i].second;
			}else{
				ts=0;
				ts+=y;
				ts+=h;
				ts+=a[i].second;
				tss=0;
				tss+=w-y;
				tss+=h;
				tss+=w-a[i].second;
				if(tss>ts){
					sm+=ts;
				}else{
					sm+=tss;
				}
			}
		}
	}else if(x==1){
		for(i=1; i<=n; i++){
			if(x==a[i].first){
				sm+=abs(y-a[i].second);
			}else if(a[i].first==3){
				sm+=y;
				sm+=a[i].second;
			}else if(a[i].first==4){
				sm+=w-y;
				sm+=a[i].second;
			}else{
				ts=0;
				ts+=y;
				ts+=h;
				ts+=a[i].second;
				tss=0;
				tss+=w-y;
				tss+=h;
				tss+=w-a[i].second;
				if(tss>ts){
					sm+=ts;
				}else{
					sm+=tss;
				}
			}
		}
	}else if(x==3){
		for(i=1; i<=n; i++){
			if(x==a[i].first){
				sm+=abs(y-a[i].second);
			}else if(a[i].first==1){
				sm+=y;
				sm+=a[i].second;
			}else if(a[i].first==2){
				sm+=h-y;
				sm+=a[i].second;
			}else{
				ts=0;
				ts+=y;
				ts+=w;
				ts+=a[i].second;
				tss=0;
				tss+=h-y;
				tss+=w;
				tss+=h-a[i].second;
				if(tss>ts){
					sm+=ts;
				}else{
					sm+=tss;
				}
			}
		}
	}else if(x==4){
		for(i=1; i<=n; i++){
			if(x==a[i].first){
				sm+=abs(y-a[i].second);
			}else if(a[i].first==1){
				sm+=y;
				sm+=w-a[i].second;
			}else if(a[i].first==2){
				sm+=h-y;
				sm+=w-a[i].second;
			}else{
				ts=0;
				ts+=y;
				ts+=w;
				ts+=a[i].second;
				tss=0;
				tss+=h-y;
				tss+=w;
				tss+=h-a[i].second;
				if(tss>ts){
					sm+=ts;
				}else{
					sm+=tss;
				}
			}
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