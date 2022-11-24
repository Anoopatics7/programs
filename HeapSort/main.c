#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#define MAX 10000

void exchange (int *p, int *q)
{
    int t;
    t = *p;
    *p = *q;
    *q = t;
}
void HeapSort(int *A, int n)
{
    int i;
    for(i=n/2; i>=1; i--)
        Heapify(A,n,i);
    for(i=n; i>=2; i--)
    {
         exchange(&A[i], &A[1]);
         Heapify(A,i-1,1);
    }
}

void Heapify(int *A, int n, int i)
{
    int largest, l, r;
    largest = i;
    l = 2*i; r = 2*i+1;
    if(l<=n && A[l]>A[largest])
        largest = l;
    if(r<=n && A[r] > A[largest])
        largest = r;
    if(largest != i)
    {
        exchange(&A[largest] ,&A[i]);
        Heapify(A, n, largest);
    }
}
int main(void)
{
    int i,n,A[MAX],k,j;
    srand(time(0));
    time_t start,end;
    double cpu_exec_time;


    printf("Heap Sort..\n");
    printf("Enter the value of n: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        start = clock();
    for(j=0;j<1000000;j++)
    {
        for(k=0;k<n;k++)
            A[k] = rand() % 100+1;
        HeapSort(A,n);
    }
        end = clock();
        cpu_exec_time = (double) (end - start) / CLOCKS_PER_SEC;

        printf("Sorted array: ");
        for(i=1;i<=n;i++)
            printf("%d\t",A[i]);
        printf("\n Execution time = %lf\n", cpu_exec_time);
    return 0;
}
