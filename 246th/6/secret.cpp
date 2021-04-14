#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 200
typedef pair<int,int> pp;
typedef pair<int,pp> ppp;
 
FILE *fp1,*fp2;

int n,p,t;
int a[N+1];

void input(void)
{
	int i,x,y;

	fscanf(fp1,"%d %d %d",&n,&p,&t);
	for(i=1; i<=p; i++)
	{
		fscanf(fp1,"%d %d %d",&x,&y,&a[i]);
	}
	sort(a+1,a+1+p);
}

void process(void)
{
	if(n*t/2>p)
	{
		fprintf(fp2,"%d",a[p]);
	}
	else
	{
		fprintf(fp2,"%d",a[n*t/2]);
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