#include <stdio.h>
#include <stdlib.h>


int minof(int a, int b)
{
    if(a < b)
        return a;
    if(b < a)
        return b;
    else
        return a;
}

int maxof(int a, int b)
{
    if(a > b)
        return a;
    if(b > a)
        return b;
    else
        return a;
}


int find_min(int *A, int n)
{
    if(n == 0)             //BASE CASE IS TO RETURN A[0] at 1 as we can't safely do a N-1 past the next return
        return A[0];
    else
        return minof(A[n], find_min(A, n-1)); //Find the min between A[n-1] and recursive function
}

int sum_array(int *A, int n)
{
    if(n == 0)
        return A[n];
    else
        return A[n] + sum_array(A, n-1);
}

void selection sort(int *A, int n)
{
    //Selection sort swaps elements when it finds a minimum




}








void print_array(int *A, int size)
{
    int i;

    for(i = 0; i < size; i++)
    {
        printf("arr[%d] = %d\n", i, A[i]);
    }
}

int main()
{
    int arr[6] = {15, 5, 10, 20, 30, 25};

    print_array(arr, 6);
    printf("\n\n");


    printf("MIN IS: %d\n", find_min(arr, 5));
    printf("SUM IS: %d\n\n", sum_array(arr, 5));





    print_array(arr, 6);


    return 0;
}
