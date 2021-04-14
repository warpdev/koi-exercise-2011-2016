#include <stdio.h>
#include <math.h>
#include <stdlib.h>

FILE *fp1,*fp2;

int n;
int a[8+1];
int sqr[8+1]={1,10,100,1000,10000,100000,1000000,10000000};

void input(void)
{
	fscanf(fp1,"%d",&n);
}

int isck(int x)
{
	int i,k,cnt=0;

	k=sqrt(x);
	for(i=1; i<=k; i++)
	{
		if(x%i==0)
		{
			cnt++;
		}
	}
	if(cnt==1)
	{
		return 1;
	}
	return 0;
}

void process(int lev)
{
	int i,j,k;

	if(lev>n){
		for(i=1; i<lev; i++){
			fprintf(fp2,"%d",a[i]);
		}
		fprintf(fp2,"\n");
	}
	else{
		for(i=1; i<=9; i++)
		{
			if(lev==1)
			{
				if(i!=1)
				{
					k=i;
					a[lev]=i;
					if(isck(k)){
						process(lev+1);
					}
				}
			}
			else
			{
				k=0;
				a[lev]=i;
				for(j=1; j<=lev; j++){
					k+=a[j]*sqr[lev-j];
				}
				if(isck(k)){
					process(lev+1);
				}
			}
		}
	}
}

int main(void){
	fp1=fopen("input.txt","r");
	fp2=fopen("output.txt","w");
	input();
	process(1);
	return 0;
}