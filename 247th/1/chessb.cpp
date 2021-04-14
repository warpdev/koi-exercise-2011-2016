#include <stdio.h>
#define N 10

FILE *fp1,*fp2;

int r,c,a,b;
int k[N*N+3];

void input(void)
{
	fscanf(fp1,"%d %d %d %d",&r,&c,&a,&b);
}

void process(void)
{
	int i,j,l,m,typ=1,typ2=1;

	for(i=1; i<=r; i++)
	{
		for(j=1; j<=a; j++)
		{
			typ2=typ;
			for(l=1; l<=c; l++)
			{
				for(m=1; m<=b; m++)
				{
					if(typ2)
					{
						fprintf(fp2,"X");
					}
					else
					{
						fprintf(fp2,".");
					}
				}
				typ2=1-typ2;
			}
			fprintf(fp2,"\n");
		}
		typ=1-typ;
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