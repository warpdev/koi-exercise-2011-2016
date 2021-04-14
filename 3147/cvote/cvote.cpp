#include <stdio.h>
#define N 3

FILE *fp1,*fp2;

int n;
int a[N+1];
int ck[N+1][N+1];

void input(void)
{
    int i;
    int x,y,w;

    fscanf(fp1,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%d %d %d",&x,&y,&w);
        a[1]+=x;
        a[2]+=y;
        a[3]+=w;
        ck[1][x]++;
        ck[2][y]++;
        ck[3][w]++;
    }
}

void process(void)
{
    int i,mx=0,id;

    for(i=1; i<=3; i++)
    {
        if(mx<a[i])
        {
            mx=a[i];
            id=i;
        }
    }
    for(i=1; i<=3; i++)
    {
        if(mx==a[i] && i!=id)
        {
            if(ck[id][3]<ck[i][3])
            {
                id=i;
                break;
            }
            else if(ck[id][3]==ck[i][3])
            {
                if(ck[id][2]==ck[i][2])
                {
                    fprintf(fp2,"0 %d",mx);
                    return;
                }
                else if(ck[id][2]<ck[i][2])
                {
                    id=i;
                    break;
                }
            }
        }
    }
    fprintf(fp2,"%d %d",id,mx);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    return 0;
}
