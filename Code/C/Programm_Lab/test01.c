#include <stdio.h>
#include <string.h>
int main()
{
    char str[6];
    int i,count=1;

    scanf("%s",str);
    
    if(strlen(str) != 5)
    {
        printf("error");
        return 0;
    }

    for(i=0;i<5;i++)
    {
        if(str[i]<'A' || str[i]>'Z')
        {
            printf("error");
            return 0;
        }
    }

    for(i=0;i<5;i++)
    {
        if(str[i]==str[i+1])
        {
           count++; 
        }
        else
        {
            printf("%d%c",count,str[i]);
            count=1;
        }
    }
    return 0;
}