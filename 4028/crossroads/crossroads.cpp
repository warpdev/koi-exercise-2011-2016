#include <stdio.h>
#include <stdlib.h>
#define N 9

FILE *fp1,*fp2;

int n;
int a[N+1];
int b[N+1];
int stk[4];
int top;

void input(void)
{
    int i;
    char t[N+2];

    i=1;
    fscanf(fp1,"%s",&t[1]);
    while(t[i]!=0)
    {
        a[i]=t[i]-48;
        i++;
    }
    n=i;
    n--;
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%1d",&b[i]);
    }
}

void process(void)
{
    int i;
    int k=0;

    for(i=1; i<=n; i++)
    {
        while(stk[top]!=b[i])
        {
            if(top>=3 || k>n)
            {
                fclose(fp2);
                fp2=fopen("output.txt","w");
                fprintf(fp2,"-1");
                exit(0);
            }
            top++;
            k++;
            stk[top]=a[k];
            fprintf(fp2,"D%d ",stk[top]);
        }
        if(stk[top]==b[i])
        {
            fprintf(fp2,"U%d ",stk[top]);
            top--;
        }
        else if(top==3 && a[k+1]==b[i])
        {
            k++;
            fprintf(fp2,"U%d ",a[k]);
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
