

#include <stdio.h>
void main()
{
    int i, j, k;
    for(i=1;i<6;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("%d\t",j);
            for(k=j;k>=1;k--)
            {
                if (k-1==0){
            printf("");}
            else
                { printf("%d\t",k-1);}
            }
        }

        printf("\n");
    }
}
