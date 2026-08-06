#include <stdio.h>
int main()
{
    int product;
    char member;
    float price,total,discount,amount;

    scanf(" %d",&product);
    scanf(" %f",&price);
    scanf(" %c",&member);

    total = product * price;

    switch (member)
    {
        case 'y':
        if (total <= 500)
        {
            discount = 0.10 * total;
        }
        else if (total > 500 && total <= 1000)
        {
            discount = 0.15 * total;
        }
        else 
        {
            discount = 0.20 * total;
        }
        break;

        case 'n':
        if (total <= 500)
        {
            discount = 0.05 * total;
        }
        else if (total > 500 && total <= 1000)
        {
            discount = 0.10 * total;
        }
        else
        {
            discount = 0.15 * total;
        }
        break;
    }

    amount = total - discount;
    printf("total %.2f\n",total);
    printf("discount %.2f\n",discount);
    printf("amount %.2f",amount);

    return 0;
}