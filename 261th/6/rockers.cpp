#include <stdio.h>
#define N 20

FILE *fp1,*fp2;

int n,t,m;
int a[N+1];
int s;

void input(void)
{
    int i;

    fscanf(fp1,"%d %d %d",&n,&t,&m);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%d",&a[i]);
        s+=a[i];
    }
    s/=n;
    fprintf(fp2,"%d",(t*m)/s);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    return 0;
}
