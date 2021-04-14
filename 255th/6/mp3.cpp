#include <stdio.h>
#include <algorithm>
using namespace std;
#include <queue>
#include <vector>
#define N 20
typedef pair<int,int> pp;

FILE *fp1,*fp2;

int n;
priority_queue<pp,vector<pp>,greater<pp> > Q;
pp a[N+1];
int ck[5][1281];
int mx;

void input(void)
{
	int i,t,tt;

	fscanf(fp1,"%d",&n);
	for(i=1; i<=n; i++){
		fscanf(fp1,"%d %d",&t,&tt);
		Q.push(make_pair(t,tt));
		a[i].first=t;
		a[i].second=tt;
	}
}

void process(void)
{
	int i,s,k;

	while(!Q.empty()){
		s=Q.top().first;
		k=Q.top().second;
		Q.pop();
		if(mx==1280){
			break;
		}
		if(s<=1280 && ck[k][s]!=1)
		{
			ck[k][s]=1;
			if(mx<s){
				mx=s;
			}
			for(i=1; i<=n; i++){
				if(a[i].second!=k){
					Q.push(make_pair(a[i].first+s,a[i].second));
				}
			}
		}
	}
	fprintf(fp2,"%d",mx);
}

int main(void)
{
	fp1=fopen("input.txt","r");
	fp2=fopen("output.txt","w");
	input();
	process();
	return 0;
}