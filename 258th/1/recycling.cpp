#include <stdio.h>
#define N 100

FILE *fp1,*fp2;

int n;
int a[N+1][N+1];
int mx=10000000;

void input(void)
{
    int i;
    char t;
    char c;

    while(1)
    {
        n++;
        for(i=1; i<=5; i++)
        {
            fscanf(fp1,"%c/%c,",&t,&c);
            if(t=='#')
            {
                break;
            }
            else if(t=='r')
            {
                if(c=='P')
                {
                    a[n][1]=1;
                }
                else if(c=='G')
                {
                    a[n][1]=2;
                }
                else if(c=='A')
                {
                    a[n][1]=3;
                }
                else if(c=='S')
                {
                    a[n][1]=4;
                }
                else
                {
                    a[n][1]=5;
                }
            }
            else if(t=='o')
            {
                if(c=='P')
                {
                    a[n][2]=1;
                }
                else if(c=='G')
                {
                    a[n][2]=2;
                }
                else if(c=='A')
                {
                    a[n][2]=3;
                }
                else if(c=='S')
                {
                    a[n][2]=4;
                }
                else
                {
                    a[n][2]=5;
                }
            }
            else if(t=='y')
            {
                if(c=='P')
                {
                    a[n][3]=1;
                }
                else if(c=='G')
                {
                    a[n][3]=2;
                }
                else if(c=='A')
                {
                    a[n][3]=3;
                }
                else if(c=='S')
                {
                    a[n][3]=4;
                }
                else
                {
                    a[n][3]=5;
                }
            }
            else if(t=='g')
            {
                if(c=='P')
                {
                    a[n][4]=1;
                }
                else if(c=='G')
                {
                    a[n][4]=2;
                }
                else if(c=='A')
                {
                    a[n][4]=3;
                }
                else if(c=='S')
                {
                    a[n][4]=4;
                }
                else
                {
                    a[n][4]=5;
                }
            }
            else if(t=='b')
            {
                if(c=='P')
                {
                    a[n][5]=1;
                }
                else if(c=='G')
                {
                    a[n][5]=2;
                }
                else if(c=='A')
                {
                    a[n][5]=3;
                }
                else if(c=='S')
                {
                    a[n][5]=4;
                }
                else
                {
                    a[n][5]=5;
                }
            }
        }
        if(t=='#')
        {
            break;
        }
        fscanf(fp1,"%c",&t);
    }
}

void process(void)
{
    int i,j,k;
    int cnt;
    int id;

    for(k=1; k<=n; k++)
    {
        cnt=0;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=5; j++)
            {
                if(a[k][j]!=a[i][j])
                {
                    cnt++;
                }
            }
        }
        if(cnt<mx)
        {
            mx=cnt;
            id=k;
        }
    }
    fprintf(fp2,"%d",id);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
}
