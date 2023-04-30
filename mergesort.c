#include <stdio.h>

void merge(int *A, int left, int right)
{
    int temp[right - left+1];
    for (int i = left; i <= right; ++i)
    {
        temp[i] = A[i];
    }
    int m = (left + right) / 2;
    int i1 = left;
    int i2 = m + 1;
    for (int curr = left; curr <= right; ++curr)
    {
        if (i1 == m + 1)
        {
            A[curr] = temp[i2++];
        }
        else if (i2 > right)
        {
            A[curr] = temp[i1++];
        }
        else if (temp[i1] <= temp[i2])
        {
            A[curr] = temp[i1++];
        }
        else
        {
            A[curr] = temp[i2++];
        }
    }
}

void mergesort(int *A, int left, int right)
{
    if (left < right)
    {
        int m = (left + right) / 2;
        mergesort(A, left, m);
        mergesort(A, m + 1, right);
        merge(A, left, right);
    }
}


int main()
{
    int numCases;
    int lenghtArray;
    int array[];

    scanf("%d", &numCases);
    for (int i = 0; i < numCases; i++)
    {
        scanf("%d", &lenghtArray);

        array[lenghtArray];
        for (int j = 0; j < lenghtArray; j++)
        {
            scanf("%d", &array[j]);
        }

        mergesort(array,0,lenghtArray-1);

    for (int i = 0; i < lenghtArray; i++)
        printf("%d ", &array[i]);
    printf("\n");
        
    }
    
    
    
    return 0;
}