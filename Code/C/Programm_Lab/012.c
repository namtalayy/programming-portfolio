#include <stdio.h>
int main()
{
    int n,i;
    int temp[100];
    float sum=0,avg;

    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%d",&temp[i]);

    for(i=0;i<n;i++)
        sum += temp[i];

    avg = sum/n;

    printf("%.2f",avg);

    return 0;
}