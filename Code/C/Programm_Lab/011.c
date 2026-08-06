#include <stdio.h>
int main()
{
    int n,m;
    int a[20][20];
    int i,j,x,y,sum,max=0;

    scanf("%d %d",&n,&m);

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&a[i][j]);
        
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            sum = 0;

            for(x=i-1;x<=i+1;x++)
            {
                for(y=j-1;y<=j+1;y++)
                {
                    if(x>=0 && x<n && y>=0 && y<m)
                    sum += a[x][y];
                }
            }
            if(sum>max)
            max=sum;
        }
    }
    printf("%d",max);
    return 0;
}