#include <stdio.h>
#define N 100

FILE *fp1,*fp2;

int n;
int a[N+1];
int rig,lef;
int scr[3];
int tun=0;

void input(void)
{
    int i;

    fscanf(fp1,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(fp1,"%d",&a[i]);
    }
    rig=n;
    lef=1;
}

int fidmx(int x,int y)
{
    if(x>y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

void process(void)
{
    int i;

    while(lef<=rig)
    {
        if(fidmx(a[rig-1],a[lef])>fidmx(a[rig],a[lef+1]))
        {
            scr[tun]+=a[rig];
            rig--;
            tun=1-tun;
        }
        else if(fidmx(a[rig-1],a[lef])<fidmx(a[rig],a[lef+1]))
        {
            scr[tun]+=a[lef];
            lef++;
            tun=1-tun;
        }
        else
        {
            if(a[rig]>a[lef])
            {
                scr[tun]+=a[rig];
                rig--;
                tun=1-tun;
            }
            else
            {
                scr[tun]+=a[lef];
                lef++;
                tun=1-tun;
            }
        }
        if(rig-lef<=1)
        {
            break;
        }
    }
    if(rig-lef<=1)
    {
        if(a[rig]>a[lef])
        {
            scr[tun]+=a[rig];
            tun=1-tun;
            scr[tun]+=a[lef];
        }
        else
        {
            scr[tun]+=a[lef];
            tun=1-tun;
            scr[tun]+=a[rig];
        }
    }
    fprintf(fp2,"%d %d",scr[0],scr[1]);
}

int main(void)
{
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    input();
    process();
    return 0;
}
