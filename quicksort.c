#include <stdio.h>

void swap(int *a,int *b){
    int aux=*a;
    *a=*b;
    *b=aux;
}

int hoarePartition(int A[], int l, int r)
{
    int p = A[l];
    int i = l;
    int j = r + 1;
    int aux;
    
    
    do{
        do{
            i=i+1;
        }while(!(A[i]>=p || i>=r));

        do{
            j = j-1;

        }while(!(A[j]<=p));
        // swap A[i] and A[j];
        swap(&A[i],&A[j]);
    }while(!(i>=j));

    // swap A[i] and A[j];
    swap(&A[i],&A[j]);
    // swap A[l] and A[j];
    swap(&A[l],&A[j]);

    return j;
}

void quicksort(int A[], int l, int r)
{
    if (l < r)
    {
        int s = hoarePartition(A, l, r);
        quicksort(A, l, s - 1);

        quicksort(A, s + 1, r);

    }
}

// Print the array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program
int main()
{
    int arr[] = {6, 5, 12, 10, 9, 1};
    int size = sizeof(arr) / sizeof(arr[0]);


    quicksort(arr, 0, size - 1);

    printf("Sorted array: \n");
    printArray(arr, size);
}