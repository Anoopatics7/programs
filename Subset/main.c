#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define max 50

int inc[max],w[max],sum,n;
int prom(int i,int wt,int t)
{
    return (((wt+t)>=sum)&& ((wt==sum)|| (wt+w[i+1]<=sum)));
}

void sumset(int i,int wt,int t)
{
    int j;
    if(prom(i,wt,t))
    {
        if(wt==sum)
        {
            printf("\n{\t");
            for(j=0;j<=i;j++)
                if(inc[j])
                printf("%d\t",w[j]);
            printf("}\n");
        }
        else{
            inc[i+1]=true;
            sumset(i+1,wt+w[i+1],t-w[i+1]);
            inc[i+1]=false;
            sumset(i+1,wt,t-w[i+1]);

        }

    }
}

int main(void)
{
    int i,j,tmp,t=0;
    printf("Enter how many numbers to read: ");
    scanf("%d",&n);
    printf("\nEnter the value for all no's: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&w[i]);
        t+=w[i];
    }
    printf("\nEnter sum: ");
    scanf("%d",&sum);
    printf("\nGiven %d numbers as input ",n);
    for(i=0;i<=n;i++)
        printf("%d\t",w[i]);
    if(t<sum)
        printf("\n not possible");
    else{
        for(i=0;i<n;i++)
            inc[i]=0;
        printf("\nsolution is : ");
        sumset(-1,0,t);
    }
    return 0;
}
