#include <stdio.h>
#include <math.h>
int main() {
    float r, a;
    scanf("%f", &r);
    r = r / 2;
    a = M_PI * pow(r, 2);
    printf("%.2f\n", a);
    return 0;
}