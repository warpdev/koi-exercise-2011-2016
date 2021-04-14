#include <stdio.h>
#define N 100

FILE *fp1,*fp2;

int n;
int a[N+1][N+1];
int s[N+1];
int t[N+1];
char num[20][8]={
'A','c','e',NULL,NULL,NULL,NULL,NULL,
'2',NULL,0,0,0,0,0,0,
'3',NULL,0,0,0,0,0,0,
'4',NULL,0,0,0,0,0,0,
'5',NULL,0,0,0,0,0,0,
'6',NULL,0,0,0,0,0,0,
'7',NULL,0,0,0,0,0,0,
'8',NULL,0,0,0,0,0,0,
'9',NULL,0,0,0,0,0,0,
'1','0',NULL,0,0,0,0,0,
'J','a','c','k',NULL,NULL,NULL,NULL,
'Q','u','e','e','n',NULL,NULL,NULL,
'K','i','n','g',NULL,NULL,NULL,NULL,
0,0,0,0,0,0,0,0
};

char sub[8][10]={
0,0,0,0,0,0,0,0,0,0,
'C','l','u','b','s',0,0,0,0,0,
'D','i','a','m','o','n','d','s',0,0,
'H','e','a','r','t','s',0,0,0,0,
'S','p','a','d','e','s',0,0,0,0
};

void process(int x);

void input(void)
{
    int i,j;
    int tmp;

    fscanf(fp1,"%d",&n);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=52; j++)
        {
            fscanf(fp1,"%d",&a[i][j]);
        }
    }
    for(i=1; i<=52; i++)
    {
        s[i]=i;
    }
    while(1)
    {
        tmp=0;
        fscanf(fp1,"%d",&tmp);
        if(tmp==0)
        {
            break;
        }
        process(tmp);
    }
}

void sf(int k)
{
    int i,j;

    for(i=1; i<=52; i++)
    {
        t[i]=s[i];
    }
    for(i=1; i<=52; i++)
    {
        s[i]=t[a[k][i]];
    }
}

void process(int x)
{
    sf(x);
}

void output(void)
{
    int i;

    for(i=1; i<=52; i++)
    {
        fprintf(fp2,"%s of %s\n",&num[s[i]%13][0],&sub[(s[i]-1)/13+1][0]);
    }
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    output();
    return 0;
}
