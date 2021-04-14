#include <stdio.h>
#include <algorithm>
using namespace std;
#include <queue>
#define N 150
typedef pair<int,int> pp;
typedef pair<int,pp> ppp;

FILE *fp1,*fp2;

int n,m;
int a[N+1][N+1];
int s[N+1][N+1];
int dx[8]={2,2,1,-1,-2,-2,-1,1};
int dy[8]={-1,1,2,2,1,-1,-2,-2};
int hx,hy;
queue<ppp> Q;

void input(void)
{
	int i,j;
	char temp[N+3];

	fscanf(fp1,"%d %d",&n,&m);
	for(i=1; i<=n; i++){
		fscanf(fp1,"%s",&temp[1]);
		for(j=1; j<=m; j++){
			if(temp[j]=='.' || temp[j]=='H'){
				a[i][j]=1;
				if(temp[j]=='H'){
					hx=i;
					hy=j;
				}
			}else if(temp[j]=='K'){
				a[i][j]=1;
				Q.push(make_pair(0,make_pair(i,j)));
			}else{
				a[i][j]=0;
			}
		}
	}
}

void process(void)
{
	int i,x,y,w,tx,ty;

	while(!Q.empty()){
		x=Q.front().second.first;
		y=Q.front().second.second;
		w=Q.front().first;
		Q.pop();
		if(a[x][y]==1){
			if(s[x][y]==0){
				s[x][y]=w;
				for(i=0; i<=7; i++){
					tx=x+dy[i];
					ty=y+dx[i];
					if(tx>=1 && ty>=1 && tx<=n && ty<=m){
						Q.push(make_pair(w+1,make_pair(tx,ty)));
					}
				}
			}
		}
	}
}

void output(void)
{
	fprintf(fp2,"%d",s[hx][hy]);
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