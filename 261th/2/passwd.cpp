#include <stdio.h>
#include <stdlib.h>
#define N 15

FILE *fp1,*fp2;

int n,c;
int alck[30];
int a[N+1];
int cnt;

void input(void)
{
    int i;
    char t;

    fscanf(fp1,"%d %d ",&n,&c);
    for(i=1; i<=c; i++)
    {
        fscanf(fp1,"%c ",&t);
        //printf("%d %d %d %d %d\n",'a'-96,'e'-96,'i'-96,'o'-96,'u'-96);
        alck[t-96]++;
    }
}

void process(int lev,int k)
{
    int i;
    int tcnt;

    if(lev>n)
    {
        tcnt=0;
        for(i=1; i<=n; i++)
        {
            if(a[i]==1 || a[i]==5 || a[i]==9 || a[i]==15 || a[i]==21)
            {
                tcnt++;
            }
        }
        if(tcnt<1 || (n-tcnt)<2)
        {
            return;
        }
        for(i=1; i<=n; i++)
        {
            fprintf(fp2,"%c",a[i]+96);
        }
        fprintf(fp2,"\n");
        cnt++;
        if(cnt>=25000)
        {
            exit(0);
        }
        return;
    }
    for(i=k; i<=26; i++)
    {
        if(alck[i])
        {
            alck[i]--;
            a[lev]=i;
            process(lev+1,i);
            alck[i]++;
        }
    }
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process(1,1);
    return 0;
}
