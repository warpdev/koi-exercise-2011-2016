#include <stdio.h>
#include <stdlib.h>
#define N 10

FILE *fp1,*fp2;

int a[N+1];
int t[N+1];
int s[N+1];
int mx;

void input(void)
{
	int i;
	char temp[N+1];

	fscanf(fp1,"%s",&temp[1]);
	for(i=1; i<=9; i++)
	{
		if(temp[i]=='b')
		{
			t[i]=1;
		}
		else
		{
			t[i]=0;
		}
	}
}

int ck(void)
{
	int i;

	for(i=1; i<=9; i++)
	{
		if(a[i])
		{
			return 0;
		}
	}
	return 1;
}

void changer(int i)
{
	if(i==1)
	{
		a[1]=1-a[1];
		a[2]=1-a[2];
		a[4]=1-a[4];
		a[5]=1-a[5];
	}
	if(i==2)
	{
		a[1]=1-a[1];
		a[2]=1-a[2];
		a[3]=1-a[3];
		a[4]=1-a[4];
		a[5]=1-a[5];
		a[6]=1-a[6];
	}
	if(i==3)
	{
		a[2]=1-a[2];
		a[3]=1-a[3];
		a[5]=1-a[5];
		a[6]=1-a[6];
	}
	if(i==4)
	{
		a[1]=1-a[1];
		a[2]=1-a[2];
		a[4]=1-a[4];
		a[5]=1-a[5];
		a[7]=1-a[7];
		a[8]=1-a[8];
	}
	if(i==5)
	{
		a[1]=1-a[1];
		a[2]=1-a[2];
		a[3]=1-a[3];
		a[4]=1-a[4];
		a[5]=1-a[5];
		a[6]=1-a[6];
		a[7]=1-a[7];
		a[8]=1-a[8];
		a[9]=1-a[9];
	}
	if(i==6)
	{
		a[2]=1-a[2];
		a[3]=1-a[3];
		a[5]=1-a[5];
		a[6]=1-a[6];
		a[8]=1-a[8];
		a[9]=1-a[9];
	}
	if(i==7)
	{
		a[4]=1-a[4];
		a[5]=1-a[5];
		a[7]=1-a[7];
		a[8]=1-a[8];
	}
	if(i==8)
	{
		a[4]=1-a[4];
		a[5]=1-a[5];
		a[6]=1-a[6];
		a[7]=1-a[7];
		a[8]=1-a[8];
		a[9]=1-a[9];
	}
	if(i==9)
	{
		a[5]=1-a[5];
		a[6]=1-a[6];
		a[8]=1-a[8];
		a[9]=1-a[9];
	}
}

void process(int lev)
{
	int i,j;

	if(lev>9)
    {
        for(i=1; i<=9; i++)
        {
            a[i]=t[i];
        }
        for(i=1; i<=9; i++)
        {
            if(s[i])
            {
                changer(i);
            }
        }
        if(ck())
        {
            for(i=1; i<=9; i++)
            {
                if(s[i])
                {
                    fprintf(fp2,"%d",i);
                }
            }
            exit(0);
        }
    }
    else
    {
        for(i=0; i<=1; i++)
        {
            s[lev]=i;
            process(lev+1);
        }
    }
}

int main(void)
{
	fp1=fopen("input.txt","r");
	fp2=fopen("output.txt","w");
	input();
	process(1);
	return 0;
}
