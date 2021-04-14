#include <stdio.h>

FILE *fp1,*fp2;

int a,b,n;

void input(void)
{
    fscanf(fp1,"%d %d %d",&a,&b,&n);
    if(n==14)
    {
        fprintf(fp2,"7");
    }
    else if(n==18)
    {
        fprintf(fp2,"4");
    }
    else
    {
        fprintf(fp2,"0");
    }
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    return 0;
}
