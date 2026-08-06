#include <stdio.h>
int main()
{
    char choice;
    float total,length,wide,height;

    scanf(" %c",&choice);
    
    if (choice == 'T' || choice == 't')
    {
        scanf(" %f",&length);
        scanf(" %f",&height);
        total = 0.5 * length * height;
    }
    else if (choice == 'R' || choice == 'r')
    {   
        scanf(" %f",&wide);
        scanf(" %f",&length);
        total = length * wide;
        
    }
    printf("%.2f",total);
    return 0;
}