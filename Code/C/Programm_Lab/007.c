#include <stdio.h>
#include <math.h>
int main()
{
    int z;
    float x,y;

    scanf("%f %f %d",&x,&y,&z);

    switch (z)
    {
        case 1:
        {
            printf("%.2f\n",x+y);
            break;
        } 

        case 2:
        {
            printf("%.2f",x-y);
            break;
        }

        case 3:
        {
            printf("%.2f",x*y);
            break;
        }

        case 4:
        {
            printf("%.2f",x/y);
            break;
        }

        case 5:
        {
            printf("%d",(int)fmod(x,y));
            break;
        }

        case 6:
        {
            printf("%.2f",pow(x,y));
            break;
        }

        case 7:
        {
            printf("%.2f",(x+y)/2);
            break;
        }

        default:
        {
            printf("error");
            break;
        }
    }

    return 0;
}