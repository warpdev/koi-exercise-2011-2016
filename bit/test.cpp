#include <stdio.h>

//int main(void)
//{
//    int a=0xa7;
//    int b =0x7fffffff;
//    int c=032;
//
//    printf("16진수 0xa7 : %d \n",a);
//    printf("16진수 0x7fffffff : %d \n",b);
//    b++;
//    printf("%d\n",b);
//    printf("8진수 032 : %d \n",c);
//    return 0;
//}
////////////////////////////////////////////
//int main(void)
//{
//    int i;
//    float f=0;
//    double g=0;
//
//    for(i=1; i<100; i++)
//    {
//        f+=0.1;
//        g+=0.1;
//    }
//
//    printf("%f \n",f);
//    printf("%f \n",g);
//    return 0;
//////////////////////////////////}
//
//int main(void)
//{
//    int a=15;
//    int b=20;
//    int i,c;
//
//    c=a&b;
//    printf("a&b=%d\n",c);
//
//    c=a|b;
//    printf("a|b=%d\n",c);
//
//    c=a^b;
//    printf("a^b=%d\n",c);
//
//    c=~a;
//    printf("~a=%d\n",c);
//
//    c=a<<2;
//    printf("a<<2=%d\n",c);
//
//    a=-10;
//    c=a>>2;
//    printf("a>>2=%d\n",c);
//
//    for(i=31; i>=0; i--)
//    {
//        if(c&(1<<i))
//        {
//            printf("%d",1);
//        }else{
//        printf("%d",0);
//        }
//
//    }
//    printf("\n");
//    return 0;
////////////////////}
//////
//////int main(void)
//////{
//////    int a,b;
//////
//////    scanf("%d",&a);
//////    b=~a+1;
//////    printf("%d",b);
//////    return 0;
//////}
//////////////////////////////////

int main(void)
{
    int a;

    scanf("%d",&a);
    printf("%d",a<<1);

    return 0;
}
