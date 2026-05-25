#include<stdio.h>
typedef struct{
    unsigned int a:4;
    unsigned int b:3;
    unsigned int c:2;
    signed int d:5;

}Num;
int main()
{
    Num n;
    int l,m,o,h;
    printf("the number to store:");
    scanf("%d %d %d %d",&l,&m,&o,&h);

    n.a=l;
    printf("value 1:%d\n",n.a);
    n.b=m;
    printf("value 2:%d\n",n.b);
    n.c=o;
    printf("value 3:%d\n",n.c);
    n.d=h;
    printf("value 4:%d\n",n.d);

    return 0;
}