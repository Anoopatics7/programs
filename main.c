//Program for incrementing digits of a number

#include <stdio.h>
#include <stdlib.h>
int incrementer(num)
{
    int sum=0,rem;
    while(num>0)
    {
        rem = num %10;
        sum=(sum*10)+(rem+1);
        num/=10;
    }
    num=sum;
    sum=0;
    while(num>0)
    {
        rem = num %10;
        sum=(sum*10)+(rem);
        num/=10;
    }
    return sum;
}
int main()
{
    int n;
    printf("Enter the number to be incremented!\n");
    scanf("%d" , &n);
    int ans=incrementer(n);
    printf("The incremented No : %d " ,ans );

    return 0;
}
