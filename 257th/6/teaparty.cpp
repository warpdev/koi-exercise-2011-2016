#include <stdio.h>

FILE *fp1,*fp2;

int n;

void input(void)
{
    fscanf(fp1,"%d",&n);
    if(n%2==1)
    {
        fprintf(fp2,"%d",(n/2)*(n/2));
    }
    else
    {
        fprintf(fp2,"%d",(n/2)*(n/2-1));
    }
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    return 0;
}
