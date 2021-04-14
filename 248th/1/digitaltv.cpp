#include <stdio.h>
#define N 100

FILE *fp1,*fp2;

int n;
char tmp[N+2];
int tv1,tv2,c;
char mt1[15]={'0','M','A','T','H','P','L','E','T','V','1'};
char mt2[15]={'0','M','A','T','H','P','L','E','T','V','2'};

void input(void)
{
	int i,j,t;

	fscanf(fp1,"%d",&n);
	for(i=1; i<=n; i++)
	{
		fscanf(fp1,"%s",&tmp[1]);
		for(j=1; j<=10; j++)
		{
			t=1;
			if(!(tmp[j]==mt1[j]))
			{
				t=0;
				break;
			}
		}
		if(t)
		{
			tv1=i;
		}
		else
		{
			for(j=1; j<=10; j++)
			{
				t=1;
				if(!(tmp[j]==mt2[j]))
				{
					t=0;
					break;
				}
			}
			if(t)
			{
				tv2=i;
			}
		}
	}
	c=1;
}

void process(void)
{
	int i,t=0;

	if(c!=tv1)
	{
		if(tv1-c==1)
		{
			if(c==tv2)
			{
				tv2=tv1;
			}
			t=tv1;
			tv1=c;
			c=t;
			fprintf(fp2,"3");
		}
		else
		{
			for(i=1; i<=tv1-c; i++)
			{
				fprintf(fp2,"1");
			}
			for(i=1; i<=tv1-1; i++)
			{
				fprintf(fp2,"4");
				if(tv1-i==tv2)
				{
					tv2=tv1-i+1;
				}
			}
			c=1;
		}
	}
	if(tv2!=2)
	{
		if(tv2>c)
		{
			if(tv2-2==1)
			{
				for(i=c; i<2; i++)
				{
					fprintf(fp2,"1");
				}
				fprintf(fp2,"3");
			}
			else
			{
				for(i=c; i<tv2; i++)
				{
					fprintf(fp2,"1");
				}
				for(i=2; i<tv2; i++)
				{
					fprintf(fp2,"4");
				}
			}
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