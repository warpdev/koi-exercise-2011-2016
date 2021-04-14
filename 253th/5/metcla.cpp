#include <stdio.h>
#include <algorithm>
using namespace std;
#include <queue>
#include <vector>
#define N 300
typedef pair<int,int> pp;
typedef pair<int,pp> ppp;

FILE *fp1,*fp2;

int m;
ppp a[50001];
int s[N+1][N+1];
int ck[N+1][N+1];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
priority_queue<ppp,vector<ppp>,greater<ppp> > Q;

void input(void)
{
	int i;

	fscanf(fp1,"%d",&m);
	for(i=1; i<=m; i++){
		fscanf(fp1,"%d %d %d",&a[i].second.first,&a[i].second.second,&a[i].first);
	}
	sort(a+1,a+m+1);
	Q.push(make_pair(0,make_pair(0,0)));
}

void process(void)
{
	int i,tx,ty,j,k,t,x,y,w,typ=1;

	k=1;
	while(k<=m){
		for(i=k; i<=m; i++){
			if(i!=k && a[i-1].first!=a[i].first){
				t=a[k].first;
				if(i==k){
					k=i+1;
				}
				else{
					k=i;
				}
				break;
			}
			else{
				s[a[i].second.first][a[i].second.second]=1;
				for(j=0; j<=3; j++){
					tx=a[i].second.first+dy[j];
					ty=a[i].second.second+dx[j];
					if(tx>=0 && ty>=0 && tx<=N && ty<=N){
						s[tx][ty]=1;
					}
				}
				if(k==m){
					t=a[k].first;
					k=m+1;
				}
			}
		}
		while(!Q.empty()){
			x=Q.top().second.first;
			y=Q.top().second.second;
			w=Q.top().first;
			Q.pop();
			if(!s[x][y] && w<=t){
				s[x][y]=w+1;
			}
			else{
				for(i=0; i<=3; i++){
					tx=x+dy[i];
					ty=y+dx[i];
					if(tx>=0 && ty>=0 && tx<=N && ty<=N && w<t){
						Q.push(make_pair(w+1,make_pair(tx,ty)));
					}
				}
			}
		}
		for(i=0; i<=300; i++){
			for(j=0; j<=300; j++){
				if(s[i][j]!=0 && s[i][j]!=1 && ck[i][j]==0){
					Q.push(make_pair(s[i][j]-1,make_pair(i,j)));
				}
			}
		}
		if(k==m && typ){
			k--;
			typ=0;
		}
	}
}

void output(void)
{
	if(Q.empty()){
		fprintf(fp2,"-1");
	}
	else{
		fprintf(fp2,"%d",Q.top().first);
	}
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
