#include <stdio.h>
int main()
{
    float t,w,b;

    scanf("%f %f",&t,&w);

    t = t/100;//cm to m
    b = w/(t*t);
    printf("%.2f\n",b);

    if(b>=40)printf("Fattest");
    else if(b>=35.0)printf("Fat level II");
    else if(b>=28.5)printf("Fat level I");
    else if(b>=23.5)printf("Overweight");
    else if(b>=18.5)printf("Normally");
    else printf("Underweight");

    return 0;
}