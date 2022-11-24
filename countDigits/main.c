#include <stdio.h>
#include <stdlib.h>

int countDigit(num)
{
    int c=0 , rem ;
    while(num>0)
    {
        num/=10;
        ++c;
    }
    return c;
}
int main()
{
    int n;
    printf("Enter the Number\n");
    scanf("%d" , &n);

    printf("The number of digits = %d " , countDigit(n));
    return 0;
}
