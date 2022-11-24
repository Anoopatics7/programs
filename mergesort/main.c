#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define MAX 500
int A[MAX] , B[MAX];

void merge(int,int,int);
void mergeSort(int,int);

int main(void)
{
    int n,i,j;
    int low , high , mid;
    clock_t s, e;
    double  cpu_exe_t;
    printf("\nPlease enter the size of the array: ");
    scanf("%d",&n);
    low=0;
    high=n-1;

    for(i=0;i<n;i++)
        A[i]=rand()%100;

    printf("\nThe array elements are: \n");
    for(i=0;i<n;i++)
        printf("%d\t",A[i]);
    s=clock();
    for(j=0;j<1000;j++)            //Delay loops
    for(i=0;i<1000;i++)
    mergeSort(low,high);
    e=clock();
    cpu_exe_t=(double)(e-s)/CLK_TCK;
    printf("\nThe sorted array is :\n");
    for(i=0;i<n;i++)
        printf("%d\t",B[i]);
    printf("\nCPU execution time is %lf\n",cpu_exe_t);
    return 0;
}
void mergeSort(int low ,int high)
{
    if(low<high)
    {
        //mid = (low+high)/2;
        int mid = low + (high-low)/2;   //To avoid integer overflow
        mergeSort(low,mid);
        mergeSort(mid+1,high);
        merge(low,mid,high);
    }
}
void merge(int low ,int mid ,int high)
{
    int i=low , j=mid+1 , k=low;
    while(i<=mid && j<=high)
    {
        if(A[i]<=A[j]){
            B[k++]=A[i++];
        }
        else{
            B[k++]=A[j++];
        }
    }
    while(i<=mid){
        B[k++]=A[i++];
    }
    while(j<=high){
        B[k++]=A[j++];
    }
}
