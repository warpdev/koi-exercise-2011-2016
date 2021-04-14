#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 10000
typedef pair<int,int> pp;
typedef pair<int,pp> ppp;

FILE *fp1,*fp2;

int k,n,c;
int cnt1,cnt2;
ppp a[50000+1];
ppp b[50000+1];
int s[N+1];
int sm;

void input(void)
{
	int i,tx,ty,tw;

	fscanf(fp1,"%d %d %d",&k,&n,&c);
	for(i=1; i<=k; i++){
		fscanf(fp1,"%d %d %d",&tx,&ty,&tw);
		if(tx>ty)
		{
			cnt2++;
			b[cnt2].first=tx;
			b[cnt2].second.first=ty;
			b[cnt2].second.second=tw;
		}
		else
		{
			cnt1++;
			a[cnt1].first=tx;
			a[cnt1].second.first=ty;
			a[cnt1].second.second=tw;
		}
	}
	sort(a+1,a+cnt1+1);
	sort(b+1,b+cnt2+1);
}

void process(void)
{
	int i,j,t;

	for(i=1; i<=cnt1; i++){
		if(s[a[i].first]<c){
			if(s[a[i].first]+a[i].second.second>c){
				t=c-s[a[i].first];
			}
			else{
				t=a[i].second.second;
			}
			for(j=a[i].first; j<=a[i].second.first-1; j++){
				s[j]+=t;
			}
			sm+=t;
		}
	}
	for(i=1; i<=n; i++){
		s[i]=0;
	}
	for(i=cnt2; i>=1; i--){
		if(s[b[i].first]<c){
			if(s[b[i].first]+b[i].second.second>c){
				t=c-s[b[i].first];
			}
			else{
				t=b[i].second.second;
			}
			for(j=b[i].second.first+1; j<=b[i].first; j++){
				s[j]+=t;
			}
			sm+=t;
		}
	}
	fprintf(fp2,"%d\n",sm);
}

int main(void)
{
	fp1=fopen("input.txt","r");
	fp2=fopen("output.txt","w");
	input();
	process();
	return 0;
}