#include <stdio.h>
#include <string.h>
#define N 10

FILE *fp1,*fp2;

int n;
char a[N+1][20];
int x[N+1];
int y[N+1];

void input(void)
{
    int i,j,k;
    char temp[20];
    int t,id;
    int ts;

    fscanf(fp1,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%s",&a[i][1]);
    }
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%s",&temp[1]);
        for(j=1; j<=n; j++)
        {
            if(!strcmp(&temp[1],&a[j][1]))
            {
                id=j;
                break;
            }
        }
        fscanf(fp1,"%d %d",&x[id],&t);
        if(t!=0)
        {
            y[id]+=x[id]%t;
            ts=x[id]/t;
            for(j=1; j<=t; j++)
            {
                fscanf(fp1,"%s",&temp[1]);
                for(k=1; k<=n; k++)
                {
                    if(!strcmp(&temp[1],&a[k][1]))
                    {
                        y[k]+=ts;
                        break;
                    }
                }
            }
        }
        else
        {
            y[id]+=x[id];
        }
    }
}

void output(void)
{
    int i;

    for(i=1; i<=n; i++)
    {
        fprintf(fp2,"%s %d\n",&a[i][1],y[i]-x[i]);
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
