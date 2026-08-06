#include <stdio.h>
int main()
{
    float x,min,max;
    int i=0;

    for(i=0;i<5;i++)
    {
        printf("");
        scanf("%f",&x);

        if(i==0)
        {
        min=x;
        max=x;
        }

        if(x<min)
        {
        min=x;
        }
        else if(x>max)
        {
        max=x;
        }

    }    

    printf("%.2f\n",max);
    printf("%.2f\n",min);

    return 0;
}