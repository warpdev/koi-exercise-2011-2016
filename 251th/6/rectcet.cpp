#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
#define N 3000
typedef pair<int,int> pp;

FILE *fp1,*fp2;

int r,c,n;
int lef[N+1];
int rig[N+1];
int h[N+1];
int k;
int mx;
vector<int> v[30000+5];

void input(void)
{
	int i,tx,ty;

	fscanf(fp1,"%d %d %d",&r,&c,&n);

	for(i=1; i<=n; i++)
	{
		fscanf(fp1,"%d %d",&tx,&ty);
		v[tx].push_back(ty);
	}
	for(i=1; i<=n; i++)
	{
		sort(v[i].begin(),v[i].end());
	}
	for(i=1; i<=c; i++)
	{
		lef[i]=0;
		rig[i]=c+1;
		h[i]=0;
	}
}

void process(void)
{
	int i,j,s;

	for(i=1; i<=r; i++)
	{
		k=0;
		for(j=1; j<=c; j++)
		{
			if(v[i].size() && v[i][k]==j)
			{
				lef[j]=0;
				rig[j]=c+1;
				h[j]=0;
				k++;
			}
			else
			{
				if(v[i].size()==0)
				{
					h[j]++;
				}
				else if(v[i].size()-1<k)
				{
					if(lef[j]<v[i][k-1])
					{
						lef[j]=v[i][k-1];
					}
					if(rig[j]>c+1 || rig[j]==0)
					{
						rig[j]=c+1;
					}
					h[j]++;
				}
				else
				{
					if(k>0)
					{
						if(lef[j]<v[i][k-1])
						{
							lef[j]=v[i][k-1];
						}
						if(rig[j]>v[i][k] || rig[j]==0)
						{
							rig[j]=v[i][k];
						}
						h[j]++;
					}
					else
					{
						if(lef[j]<=0)
						{
							lef[j]=0;
						}
						if(rig[j]>v[i][k] || rig[j]==0)
						{
							rig[j]=v[i][k];
						}
						h[j]++;
					}
				}
			}
			s=(rig[j]-lef[j]-1)*h[j];
			if(mx<s)
			{
				mx=s;
			}
		}
	}
}

void output(void)
{
	if(n==0)
	{
		mx=r*c;
	}
	fprintf(fp2,"%d",mx);
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