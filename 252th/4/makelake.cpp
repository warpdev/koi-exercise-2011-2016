#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 20000
typedef pair<int,int> pp;
typedef pair<int,pp> ppp;

FILE *fp1,*fp2;

ppp a[N+1];
int s[100+1][100+1];
int r,c,e,n;

void input(void)
{
	int i,j;

	fscanf(fp1,"%d %d %d %d",&r,&c,&e,&n);
	for(i=1; i<=r; i++){
		for(j=1; j<=c; j++){
			fscanf(fp1,"%d",&s[i][j]);
		}
	}
	for(i=1; i<=n; i++){
		fscanf(fp1,"%d %d %d",&a[i].second.first,&a[i].second.second,&a[i].first);
	}
}

int fdmx(int x,int y){
	int i,j,tmx=0;

	for(i=x; i<=x+2; i++){
		for(j=y; j<=y+2; j++){
			if(tmx<s[i][j]){
				tmx=s[i][j];
			}
		}
	}
	return tmx;
}

void process(void)
{
	int i,j,k,l,tx,ty;

	for(i=1; i<=n; i++){
		k=fdmx(a[i].second.first,a[i].second.second)-a[i].first;
		tx=a[i].second.first;
		ty=a[i].second.second;
		for(j=tx; j<=tx+2; j++){
			for(l=ty; l<=ty+2; l++){
				if(s[j][l]>k){
					s[j][l]=k;
				}
			}
		}
	}
	for(i=1; i<=r; i++){
		for(j=1; j<=c; j++){
			if(s[i][j]<e){
				s[i][j]=e-s[i][j];
			}
			else{
				s[i][j]=0;
			}
		}
	}
}

void output(void)
{
	int sm=0;
	int i,j;
	
	for(i=1; i<=r; i++){
		for(j=1; j<=c; j++){
			sm+=s[i][j];
		}
	}
	fprintf(fp2,"%d",72*72*sm);
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