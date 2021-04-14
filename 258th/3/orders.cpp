#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
#define N 200

FILE *fp1,*fp2;

char a[N+5];
int n;
int ck[N+5];
char s[N+5];
vector<char> rs[N+5];

void input(void)
{
    while(1)
    {
        n++;
        fscanf(fp1,"%c",&a[n]);
        if(a[n]=='\n')
        {
            n--;
            break;
        }
    }
    sort(a+1,a+n+1);
}

void process(int lev)
{
    int i;

    if(lev>n)
    {
        for(i=1; i<=n; i++)
        {
            fprintf(fp2,"%c",s[i]);
        }
        fprintf(fp2,"\n");
        return;
    }
    for(i=1; i<=n; i++)
    {
        if(ck[i]==0)
        {
            ck[i]=1;
            s[lev]=a[i];
            process(lev+1);
            ck[i]=0;
            while(a[i]==a[i+1])
            {
                i++;
            }
        }
    }
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process(1);
    return 0;
}
