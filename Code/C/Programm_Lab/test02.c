#include <stdio.h>
int main()
{
    char size,type,top;
    int price=0,num;

    scanf(" %c %c",&size,&type);
    scanf(" %c",&top);

    int ramen[3][2] = {
        {60,80},
        {80,100},
        {100,120}
    };

    int s,t;

    if(size=='S') s=0;
    else if(size=='M') s=1;
    else if(size=='L') s=2;
    else {printf("error"); return 0;}

    if(type=='R') t=0;
    else if(type=='T') t=1;
    else {printf("error"); return 0;}

    price = ramen[s][t];

    if(top=='N')
    {
        printf("%d",price);
    }
    else if(top=='P')
    {
        scanf("%d",&num);
        printf("%d",price+num*15);
    }
    else if(top=='E')
    {
        scanf("%d",&num);
        printf("%d",price+num*10);
    }
    else {
        printf("error");
    }
}