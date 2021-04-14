#include <stdio.h>
#define N 100000

FILE *fp1,*fp2;

int k,l;
int lef[5000+1];
int frt[5000+1];
int tp;
int ms,ns;
int typ=0;
int top1=0,top2=0;

void input(void)
{
    int i;
    int t;

    fscanf(fp1,"%d %d",&k,&l);
    for(i=1; i<=k; i++)
    {
        fscanf(fp1,"%d",&t);
        if(top1<t)
        {
            top1=t;
        }
        if(t>tp)
        {
            tp=t;
        }
        frt[t]++;
    }
    for(i=1; i<=l; i++)
    {
        fscanf(fp1,"%d",&t);
        if(top2<t){
            top2=t;
        }
        if(t>tp)
        {
            tp=t;
        }
        lef[t]++;
    }
}

void process(void)
{
    int i;

    for(i=1; i<=tp; i++)
    {
        if(lef[i]>frt[i])
        {
            ns+=lef[i]*i;
        }
        else
        {
            ns+=frt[i]*i;
        }
    }
    for(i=tp; i>=1; i--)
    {
        ms+=lef[i]*frt[i];
        lef[i-1]+=lef[i];
        frt[i-1]+=frt[i];
    }
    if(top1!=top2)
    {
        fprintf(fp2,"No solution.");
        typ=1;
    }
}

void output(void)
{
    if(!typ)
    {
        fprintf(fp2,"%d %d",ns,ms);
    }
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    output();
    return 0;
}
