#include <stdio.h>
#define N 500
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
typedef pair<int,int> pp;

FILE *fp1,*fp2;

int n;
int id1,id2;
int mx;
pp a[N+1];

void input(void)
{
    int i;

    fscanf(fp1,"%d",&n);
    for(i=1; i<=n; i++){
        fscanf(fp1,"%d %d",&a[i].first,&a[i].second);
    }
}


void process(void)
{
    int i,j;
    int t;
    int s;

    for(i=1; i<=n; i++){
        for(j=i+1; j<=n; j++){
            s=0;
            t=abs(a[j].first-a[i].first);
            s+=t*t;
            t=abs(a[j].second-a[i].second);
            s+=t*t;
            if(s>mx){
                mx=s;
                id1=i;
                id2=j;
            }
        }
    }
    fprintf(fp2,"%d %d",id1,id2);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    return 0;
}
