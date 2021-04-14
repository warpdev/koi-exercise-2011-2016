#include <stdio.h>

FILE *fp1,*fp2;

int a,b;

void input(void)
{
    fscanf(fp1,"%d %d",&a,&b);
}

void process(void)
{
    if(a%10>b%10)
    {
        fprintf(fp2,"%d%d%d",a%10,((a%100)-a%10)/10,a/100);
    }
    else if(a%10<b%10)
    {
        fprintf(fp2,"%d%d%d",b%10,((b%100)-b%10)/10,b/100);
    }
    else
    {
        if((b%100)-b%10>(a%100)-a%10)
        {
            fprintf(fp2,"%d%d%d",b%10,((b%100)-b%10)/10,b/100);
        }
        else if((b%100)-b%10<(a%100)-a%10)
        {
            fprintf(fp2,"%d%d%d",a%10,((a%100)-a%10)/10,a/100);
        }
        else
        {
            if(a/100>b/100)
            {
                fprintf(fp2,"%d%d%d",a%10,((a%100)-a%10)/10,a/100);
            }
            else
            {
                fprintf(fp2,"%d%d%d",b%10,((b%100)-b%10)/10,b/100);
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
