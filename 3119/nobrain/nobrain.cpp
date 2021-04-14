#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
#define N 100

FILE *fp1,*fp2;

char a[N+1],b[N+1];

void input(void)
{
    fscanf(fp1,"%s %s",a,b);
}

void process(void)
{
    int i,k;

    if(strlen(a)==strlen(b))
    {
        if(strcmp(a,b)>=0)
        {
            fprintf(fp2,"MMM BRAINS\n");
        }
        else
        {
            fprintf(fp2,"NO BRAINS\n");
        }
    }
    else
    {
        if(strlen(a)<strlen(b))
        {
            fprintf(fp2,"NO BRAINS\n");
            return;
        }
        else
        {
            fprintf(fp2,"MMM BRAINS\n");
            return;
        }
    }
}

int main(void)
{
    int i;
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    for(i=1; i<=3; i++)
    {
        input();
        process();
    }
    return 0;
}
