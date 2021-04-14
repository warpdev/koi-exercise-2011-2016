#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define N 1000
typedef pair<int,int> pp;

FILE *fp1,*fp2;

int n;
pp a[N+1];
int s[N+1];
int sm;
int cnt;

void input(void)
{
	int i;

	fscanf(fp1,"%d",&n);
	for(i=1; i<=n; i++){
		fscanf(fp1,"%d %d",&a[i].first,&a[i].second);
		s[i]=a[i].first-a[i].second;
	}
	sort(s+1,s+n+1);
}

void process(void)
{
	int i;
	int id,mx;

	mx=99999999;
	for(i=1; i<=n; i++){
		sm+=s[i];
	}
	while(1)
	{
		mx=99999999;
		id=0;
		for(i=n; i>=1; i--){
			if(abs(sm)>abs(sm-(s[i]*2)) && s[i]!=0){
				if(mx>abs(sm-(s[i]*2))){
					mx=abs(sm-(s[i]*2));
					id=i;
				}
			}
		}
		if(!id || sm==0)
		{
			break;
		}
		else
		{
			cnt++;
			sm-=(2*s[id]);
			s[id]=0;
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