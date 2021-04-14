#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 10

FILE *fp1,*fp2;

double a[N+1][5];
double x[2*N+4];
double y[2*N+4];
int ck[2*N+4][2*N+4];
int n;
double sm;

void input(void)
{
    int i;

    fscanf(fp1,"%d",&n);
    for(i=1; i<=2*n; i++)
    {
        fscanf(fp1,"%lf %lf",&x[i],&y[i]);
        a[(i+1)/2][1+(i+1)%2+(i+1)%2]=x[i];
        a[(i+1)/2][2+(i+1)%2+(i+1)%2]=y[i];
    }
    sort(x+1,x+n+n+1);
    sort(y+1,y+n+n+1);
}

int fidx(double k)
{
    int i;

    for(i=1; i<=2*n; i++)
    {
        if(k==x[i])
        {
            return i;
        }
    }
}

int fidy(double k)
{
    int i;

    for(i=1; i<=2*n; i++)
    {
        if(k==y[i])
        {
            return i;
        }
    }
}

void process(void)
{
    int i,j,k;

    for(k=1; k<=n; k++)
    {
        for(i=fidx(a[k][1]); i<fidx(a[k][3]); i++)
        {
            for(j=fidy(a[k][2]); j<fidy(a[k][4]); j++)
            {
                if(!ck[i][j])
                {
                    ck[i][j]=1;
                    sm+=(x[i+1]-x[i])*(y[j+1]-y[j]);
                }
            }
        }
    }
    fprintf(fp2,"%.2lf",sm);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    return 0;
}
