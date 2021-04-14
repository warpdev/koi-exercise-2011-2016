#include <stdio.h>
#include <string.h>
#define N 6

FILE *fp1,*fp2;

char a[N+3][N+3];
int ck[N+1];
char t[N+3][5];

void input(void)
{
	int i;
	
	for(i=1; i<=N; i++)
	{
		fscanf(fp1,"%s",&a[i][1]);
	}
}

void process(void)
{
	int i,j,k,l,o,p;

	for(i=1; i<=N; i++)
	{
		ck[i]=1;
		for(j=1; j<=3; j++)
		{
			t[j][1]=a[i][j];
		}
		for(j=1; j<=N; j++)
		{
			if(!ck[j])
			{
				ck[j]=1;
				for(k=1; k<=3; k++)
				{
					t[k][2]=a[j][k];
				}
				for(k=1; k<=N; k++)
				{
					if(!ck[k])
					{
						ck[k]=1;
						for(l=1; l<=3; l++)
						{
							t[l][3]=a[k][l];
						}
						for(l=1; l<=3; l++)
						{
							for(o=1; o<=N; o++)
							{
								if(ck[o]==0 && strcmp(&a[o][1],&t[l][1])==0)
								{
									ck[o]=1;
									break;
								}
							}
						}
						for(l=1; l<=N; l++)
						{
							if(ck[l]==0)
							{
								break;
							}
						}
						if(ck[l]==0 && l<=N)
						{
							for(l=1; l<=N; l++)
							{
								if(l!=i && l!=j && l!=k)
								{
									ck[l]=0;
								}
							}
						}
						else
						{
							for(l=1; l<=3; l++)
							{
								for(o=1; o<=3; o++)
								{
									fprintf(fp2,"%c",t[o][l]);
								}
								fprintf(fp2,"\n");
							}
							return;
						}
						ck[k]=0;
					}
				}
				ck[j]=0;
			}
		}
		ck[i]=0;
	}
	fprintf(fp2,"0");
}

int main(void)
{
	fp1=fopen("input.txt","r");
	fp2=fopen("output.txt","w");
	input();
	process();
	return 0;
}
