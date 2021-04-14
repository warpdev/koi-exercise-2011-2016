#include <stdio.h>

FILE *fp1,*fp2;

long long a,b,c,x,y,w;

void input(void)
{
    long long t;

    fscanf(fp1,"%lld %lld %lld %lld %lld %lld",&a,&x,&b,&y,&c,&w);
    if(a>b)
    {
        t=a;
        a=b;
        b=t;
        t=x;
        x=y;
        y=t;
    }
    if(b>c)
    {
        t=b;
        b=c;
        c=t;
        t=y;
        y=w;
        w=t;
    }
    if(a>b)
    {
        t=a;
        a=b;
        b=t;
        t=x;
        x=y;
        y=t;
    }
}

void process(void)
{
    long long k=0;
    int tx,ty;

    if(a%b==0 && (x-y)%b || b%a==0 && (y-x)%a)
    {
        fprintf(fp2,"-1");
        return;
    }
    else if(a%c==0 && (x-w)%c || c%a==0 && (w-x)%a)
    {
        fprintf(fp2,"-1");
        return;
    }
    else if(b%c==0 && (y-w)%c || c%b==0 && (w-y)%b)
    {
        fprintf(fp2,"-1");
        return;
    }
    else
    {
        while(1)
        {
            tx=(k*a+x-y)%b;
            ty=(k*a+x-w)%c;
            if(k*a+x>a*b*c)
            {
                fprintf(fp2,"-1");
                return;
            }
            if((k*a+x-y)%b==0 && (k*a+x-w)%c==0)
            {
                fprintf(fp2,"%lld",k*a+x);
                return;
            }
            k++;
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
