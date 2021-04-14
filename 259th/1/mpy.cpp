#include <stdio.h>

FILE *fp1,*fp2;

int a[5];
int b[5];

void input(void)
{
    int ta,tb;
    int t;
    int i;

    fscanf(fp1,"%d %d",&ta,&tb);

    a[1]=ta/100;
    a[2]=(ta%100)/10;
    a[3]=ta%10;
    b[1]=tb/100;
    b[2]=(tb%100)/10;
    b[3]=tb%10;
    fprintf(fp2,"   %d\n   %d\n",ta,tb);
    fprintf(fp2,"------\n");
    t=b[3]*ta;
    for(i=1; i<=2; i++)
    {
        fprintf(fp2," ");
    }
    if(t==0)
    {
        for(i=1; i<=3; i++)
        {
            fprintf(fp2," ");
        }
    }
    else if(t/1000==0)
    {
        fprintf(fp2," ");
    }
    fprintf(fp2,"%d\n",t);
    t=b[2]*ta;
    fprintf(fp2," ");
    if(t==0)
    {
        for(i=1; i<=3; i++)
        {
            fprintf(fp2," ");
        }
    }
    else if(t/1000==0)
    {
        fprintf(fp2," ");
    }
    fprintf(fp2,"%d\n",t);
    t=b[1]*ta;
    if(t==0)
    {
        for(i=1; i<=3; i++)
        {
            fprintf(fp2," ");
        }
    }
    else if(t/1000==0)
    {
        fprintf(fp2," ");
    }
    fprintf(fp2,"%d\n",t);
    fprintf(fp2,"------\n");
    t=ta*tb;
    if(t/100000==0)
    {
        fprintf(fp2," ");
    }
    fprintf(fp2,"%d",t);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    return 0;

}
