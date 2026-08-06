#include <stdio.h>
int main()
{
    int eleunit;
    char x;
    float total;
    
    printf("");
    scanf("%c",&x);
    printf("");
    scanf("%d",&eleunit);

    switch(x)
    {
        case 'd':
        {
            if(eleunit < 200)
            total = eleunit * 2.50;
            else if(eleunit >= 200)
            total = eleunit * 2.75;
        }break;

        case 'h':
        {
            if(eleunit < 200)
            total = eleunit * 1.75;
            else if(eleunit >= 200)
            total = eleunit * 2.00;
            
        }break;

        default: printf("Invalid input");
    }

    printf("%.2f",total);

    return 0;
}