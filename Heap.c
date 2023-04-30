#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define max(a, b) \
    ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

typedef struct Heap
{
    int maxSize;
    int listSize;
    int *listArray;
} Heap;

Heap *create_heap(int size)
{
    Heap *h = (Heap *)malloc(sizeof(Heap));
    h->maxSize = size;
    h->listSize = 1;
    h->listArray = (int *)malloc(size * sizeof(int));
    return h;
}

void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void topDown(Heap *h,int indexChild, int indexParent, int child, int parent)
{   
    while (child > parent && indexParent!=0)
    {
        swap(&h->listArray[indexChild],&h->listArray[indexParent]);
        indexChild = indexParent;
        indexParent = floor(indexChild / 2);
        child = h->listArray[indexChild];
        parent = h->listArray[indexParent];
    }
}

void bottomUp(Heap *h)
{
    int n = h->listSize;
    int k, v,j;
    bool heap;
    for (int i = floor(n / 2); i >= 1; i--)
    {
        k = i;
        v = h->listArray[k];
        heap = false;
        while (!heap && 2 * k <= n)
        {
            j = 2 * k;
            if (j < n)
            {
                if (h->listArray[j] < h->listArray[j + 1])
                {
                    j = j + 1;
                }
            }
            if (v >= h->listArray[j])
            {
                heap = true;
            }
            else
            {
                h->listArray[k] = h->listArray[j];
                k = j;
            }
        }
        h->listArray[k] = v;
    }
}

void add(Heap *h, int it)
{
    if (h->listSize >= h->maxSize)
    {
        printf("Erro ao tenta inserir!\n");
    }
    else
    {
        int i = h->listSize;
        int j = floor(i / 2);
        h->listArray[i] = it;
        h->listSize++;
        topDown(h,i, j, h->listArray[i], h->listArray[j]);
        for (int i = 0; i < h->listSize; i++)
        {
        printf(" %d -",h->listArray[i]);        
        }
        printf("\n");
    }
}

void delete (Heap *h)
{
    swap(&h->listArray[1], &h->listArray[h->listSize - 1]);
    free(&h->listArray[h->listSize - 1]);
    int parent = h->listArray[1];
    int child = max(h->listArray[2], h->listArray[3]);
    int indexParent=1, indexChild;
    if (child==h->listArray[2])
    {
        indexChild=2;
    }else
    {
        indexChild=3;
    }
    
    while (child < parent)
    {
        swap(&h->listArray[indexChild], &h->listArray[indexParent]);
        indexParent = indexChild;
        int i = indexParent * 2, j = indexParent * 2 + 1;
        if (h->listArray[i] <= h->listArray[j])
        {
            indexChild = i;
        }
        else
        {
            indexChild = j;
        }
        child = h->listArray[indexChild];
        parent = h->listArray[indexParent];
    }
    printf("Remocao Bem Sucedida!\n");
}

int main()
{
    Heap *h = create_heap(32);
    add(h,2);
    add(h,9);
    add(h,7);
    add(h,6);
    add(h,5);
    add(h,8);
    add(h,10);
    
        return 0;
}