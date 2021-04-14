#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
#include <vector>

FILE *fp1,*fp2;

priority_queue<long long,vector<long long>, greater<long long> > Q;
int n;
long long s;

void input(void)
{
	int i,t;

	fscanf(fp1,"%d",&n);
	for(i=1; i<=n; i++){
		fscanf(fp1,"%d",&t);
		Q.push(t);
	}
}

void process(void)
{
	long long a,b;

	if(Q.size()==1){
		fprintf(fp2,"0");
		Q.pop();
	}
	while(!Q.empty()){
		a=Q.top();
		Q.pop();
		b=Q.top();
		Q.pop();
		if(!Q.empty()){
			s+=a+b;
			Q.push(a+b);
		}
		else
		{
			s+=a+b;
			fprintf(fp2,"%lld",s);
		}
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
