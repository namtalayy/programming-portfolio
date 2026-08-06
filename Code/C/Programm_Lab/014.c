#include <stdio.h>

int main()
{
    int N,C;
    int X,Y;

    scanf("%d",&N);
    scanf("%d",&C);

    X = C / N;
    Y = C % N;

    if(Y == 0)
        printf("Each friend pays %d baht.",X);
    else
        printf("Each friend pays %d baht with %d baht left over.",X,Y);

    return 0;
}