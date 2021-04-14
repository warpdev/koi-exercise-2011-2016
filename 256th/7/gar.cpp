#include <stdio.h>
#define N 250

FILE *fp1,*fp2;

int w,h;
int n,o;
int a[N+1][N+1];
int s[N+1][N+1];
int c[N+1];
int r[N+1];
int d[N+2];
int mx=99999999,mxx=999999999;
int sm;

void input(void)
{
    int i;
    int x,y;

    fscanf(fp1,"%d %d %d %d",&w,&h,&n,&o);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%d %d",&x,&y);
        a[x][y]++;
    }
}

void process(void)
{
    int i,j,k;
    int lef,rig,t;

    for(i=1; i<=h; i++)
    {
        for(j=1; j<=w; j++)
        {
            s[i][j]=99999999;
        }
    }
    for(k=1; k<=h; k++)
    {
        for(i=1; i<=w; i++)
        {
            d[i]=0;
        }
        for(i=k; i<=h; i++)
        {
            for(j=1; j<=w; j++)
            {
                d[j]+=a[i][j];
            }
            lef=1;
            rig=1;
            while(rig<=w)
            {
                t=0;
                for(j=lef; j<=rig; j++)
                {
                    t+=d[j];
                }
                if(t==o)
                {
                    if(s[k][lef]>(rig-lef+1+i-k+1)*2)
                    {
                       // printf("%d %d %d\n",t,lef,rig);
                        s[k][lef]=(rig-lef+1+i-k+1)*2;
                        r[i]=(rig-lef+1+i-k+1)*2;
                        c[rig]=(rig-lef+1+i-k+1)*2;
                    }
                    lef++;
                }
                else if(t>o)
                {
                    lef++;
                }
                else
                {
                    rig++;
                }
            }
        }
    }
    for(i=1; i<=h; i++)
    {
        for(j=1; j<=w; j++)
        {
            printf("%d ",s[i][j]);
            if(mx>s[i][j])
            {
                mx=s[i][j];
            }
        }
        printf("\n");
    }
        printf("\n");
    sm+=mx;
    lef=h+1;
    for(i=1; i<=h; i++)
    {
       // printf("%d ",r[i]);
        if(mx==r[i])
        {
            lef=i+1;
            break;
        }
    }
       // printf("\n");
    for(i=lef; i<=h; i++)
    {
        for(j=1; j<=w; j++)
        {
            if(mxx>s[i][j])
            {
                mxx=s[i][j];
            }
        }
    }
       // printf("\n");
    lef=w+1;
    for(i=1; i<=w; i++)
    {
       // printf("%d ",c[i]);
        if(mx==c[i])
        {
            lef=i+1;
            break;
        }
    }
        printf("\n");
    for(i=1; i<=h; i++)
    {
        for(j=lef; j<=w; j++)
        {
            printf("%d ",s[i][j]);
            if(mxx>s[i][j])
            {
                mxx=s[i][j];
            }
        }
    }
    sm+=mxx;
    fprintf(fp2,"%d",sm);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    return 0;
}
