#include <stdio.h>
#define N 50

FILE *fp1,*fp2;

int n;
int a[50][7][9];
int rslt[N+1][N+1];
int mx,mxx,mxy;

void input(void)
{
	int i,j,k;
	char temp[N];

	fscanf(fp1,"%d",&n);
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=5; j++)
		{
			fscanf(fp1,"%s",&temp[1]);
			for(k=1; k<=7; k++)
			{
				if(temp[k]=='X')
				{
					a[i][j][k]=0;
				}
				else
				{
					a[i][j][k]=1;
				}
			}
		}
	}
}

void process(void)
{
	int i,j,k,l;

	for(i=1; i<=n; i++)
	{
		for(j=i+1; j<=n; j++)
		{
			for(k=1; k<=5; k++)
			{
				for(l=1; l<=7; l++)
				{
					if(a[i][k][l]==a[j][k][l])
					{
						rslt[i][j]++;
					}
				}
			}
			if(mx<rslt[i][j])
			{
				mx=rslt[i][j];
				mxx=i;
				mxy=j;
			}

		}
	}
	fprintf(fp2,"%d %d",mxx,mxy);
}

int main(void)
{
	fp1=fopen("input.txt","r");
	fp2=fopen("output.txt","w");
	input();
	process();
	return 0;
}
