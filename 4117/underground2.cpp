#include <stdio.h>
#define N 250

FILE *fp1,*fp2;

int n,m;
int a[N+1][N+1];
int k[N+1];
int mx;
int idx,idy,iddx,iddy;

void input(void)
{
	int i,j;

	fscanf(fp1,"%d %d",&n,&m);
	for(i=1; i<=n; i++){
		for(j=1; j<=m; j++){
			fscanf(fp1,"%d",&a[i][j]);
		}
	}
}

void process(void)
{
	int i,j,l;
	int ts=0;
	int tx,ty;

	for(l=1; l<=n; l++){
		for(i=1; i<=m; i++){
			k[i]=0;
		}
		for(i=l; i<=n; i++){
			for(j=1; j<=m; j++){
				k[j]+=a[i][j];
			}
			ts=0;
			tx=l;
			ty=1;
			for(j=1; j<=m; j++){
				ts+=k[j];
				if(mx<ts){
					idx=tx;
					idy=ty;
					mx=ts;
					iddx=i;
					iddy=j;
				}
				if(ts<=0){
					ty=j+1;
					ts=0;
				}
			}
		}
	}
}

void output(void)
{
	fprintf(fp2,"%d %d %d %d\n%d",idx,idy,iddx,iddy,mx);
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