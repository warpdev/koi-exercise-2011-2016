#include <stdio.h>
#define N 20

FILE *fp1,*fp2;

struct A{
    char a[10];
    int num;
};

int aa;
int b;

struct A s[30]={{"I",1},{"II",2},{"III",3},{"IV",4},{"V",5},{"VI",6},{"VII",7},{"VIII",8},{"IX",9}
,{"X",10},{"XX",20},{"XXX",30},{"XL",40},{"L",50},{"LX",60},{"LXX",70},{"LXXX",80},{"XC",90},
{"C",100},{"CC",200},{"CCC",300},{"CD",400},{"D",500},{"DC",600},{"DCC",700},{"DCCC",800},{"CM",900},
{"M",1000},{"MM",2000},{"MMM",3000}
};

void input(void)
{
    char t[N+2];
    int k=1;
    int i,j;
    int tt=0,ttt=0;

    fscanf(fp1,"%s",&t[1]);
    while(t[k])
    {
        k++;
    }
    for(i=k; i>=1; i--)
    {
        if(i!=k)
        {
            tt=0;
            ttt=0;
            for(j=0; j<=29; j++)
            {
                if(s[j].a[0]==t[i] && !tt)
                {
                    tt=s[j].num;
                }
                if(s[j].a[0]==t[i+1] && !ttt)
                {
                    ttt=s[j].num;
                }
            }
            if(tt<ttt)
            {
                aa-=tt;
            }
            else
            {
                aa+=tt;
            }
        }
    }
    fscanf(fp1,"%s",&t[1]);
    k=1;
    while(t[k])
    {
        k++;
    }
    for(i=k; i>=1; i--)
    {
        if(i!=k)
        {
            tt=0;
            ttt=0;
            for(j=0; j<=29; j++)
            {
                if(s[j].a[0]==t[i] && !tt)
                {
                    tt=s[j].num;
                }
                if(s[j].a[0]==t[i+1] && !ttt)
                {
                    ttt=s[j].num;
                }
            }
            if(tt<ttt)
            {
                b-=tt;
            }
            else
            {
                b+=tt;
            }
        }
    }
}

void process(void)
{
    int i,j;
    int t;
    int x;

    t=aa+b;
    fprintf(fp2,"%d\n",t);
    for(i=1000; i>=1; i/=10)
    {
        x=t/i;
        x*=i;
        t-=x;
        for(j=0; j<=29; j++)
        {
            if(s[j].num==x)
            {
                fprintf(fp2,"%s",s[j].a);
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
