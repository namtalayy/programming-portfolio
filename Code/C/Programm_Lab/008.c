#include <stdio.h>

float calTax(int income)
{
    if(income<=50000)
        return income*0.01;
    else if(income<=75000)
        return 500 + (income-50000)*0.02;
    else if(income<=100000)
        return 1000 + (income-75000)*0.03;
    else if(income<=250000)
        return 1750 + (income-100000)*0.04;
    else if(income<=500000)
        return 7750 + (income-250000)*0.05;
    else
        return 20250 + (income-500000)*0.06;
}

int main()
{
    int income;

    if(scanf("%d",&income)!=1) return 0;
    printf("%.2f",calTax(income));

    return 0;
}