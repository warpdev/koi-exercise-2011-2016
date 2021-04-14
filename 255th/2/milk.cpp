#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 5000
typedef pair<int,int> pp;

FILE *fp1,*fp2;
pp a[N+1];
int n,m;
int sm;

void input(void)
{
	int i;

	fscanf(fp1,"%d %d",&n,&m);
	for(i=1; i<=m; i++){
		fscanf(fp1,"%d %d",&a[i].first,&a[i].second);
	}
	sort(a+1,a+m+1);
}

void process(void)
{
	int i,fl;

    if(n==0){
        fprintf(fp2,"0");
        return;
    }
	fl=n;
	for(i=1; i<=m; i++)
	{
		if(fl<=a[i].second){
			sm+=fl*a[i].first;
			fprintf(fp2,"%d",sm);
			break;
		}else{
			sm+=a[i].second*a[i].first;
			fl-=a[i].second;
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
