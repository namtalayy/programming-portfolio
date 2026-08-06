#include <stdio.h>
int main()
{
    int N,i,x;
    float total,sum=0;
    scanf("%d",&N);

    for(i=0;i<N;i++)
    {
        scanf("%d",&x);
        sum+=x;
    }
    total = sum/(float)N;
    printf("%.2f",total);
}