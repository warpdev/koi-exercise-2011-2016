#include <stdio.h>
#include <algorithm>
using namespace std;
#include <vector>
#include <queue>
#define N 1000

FILE *fp1,*fp2;

int n;
int a[N+1];
int sm;
int smm;
priority_queue<int,vector<int>,greater<int> > Q;
priority_queue<int,vector<int>,greater<int> > cr;

void input(void)
{
    int i;

    fscanf(fp1,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%d",&a[i]);
        Q.push(a[i]);
    }
    sort(a+1,a+n+1);
}

void process(void)
{
    int i;
    int x,y;
    queue<int> tq;
    int t;

    if(n==1)
    {
        fprintf(fp2,"%d",a[n]);
        return;
    }
    while(!Q.empty())
    {
        x=Q.top();
        Q.pop();
        y=Q.top();
        Q.pop();
        sm+=y;
        cr.push(x);
        cr.push(y);
        if(!Q.empty())
        {
            x=cr.top();
            cr.pop();
            sm+=x;
            Q.push(x);
        }
    }
    while(!cr.empty())
    {
        cr.pop();
    }
    for(i=1; i<=n; i++)
    {
        Q.push(a[i]);
    }
    while(!Q.empty() && Q.size()>=2)
    {
        x=Q.top();
        Q.pop();
        y=Q.top();
        Q.pop();
        smm+=y;
        cr.push(x);
        cr.push(y);
        if(!Q.empty() && Q.size()>=2)
        {
            x=cr.top();
            cr.pop();
            smm+=x;
            Q.push(x);
            t=Q.size()-2;
            for(i=1; i<=t; i++)
            {
                tq.push(Q.top());
                Q.pop();
            }
            x=Q.top();
            Q.pop();
            y=Q.top();
            Q.pop();
            smm+=y;
            cr.push(x);
            cr.push(y);
            for(i=1; i<=t; i++)
            {
                Q.push(tq.front());
                tq.pop();
            }
            x=cr.top();
            cr.pop();
            smm+=x;
            Q.push(x);
        }
    }
    if(Q.size()==1)
    {
        smm+=cr.top();
        cr.pop();
        x=Q.top();
        Q.pop();
        y=Q.top();
        Q.pop();
        smm+=y;
    }
    else if(Q.size()==2)
    {
        x=Q.top();
        Q.pop();
        y=Q.top();
        Q.pop();
        smm+=y;
    }
    if(sm>smm)
    {
        fprintf(fp2,"%d",smm);
    }
    else
    {
        fprintf(fp2,"%d",sm);
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
