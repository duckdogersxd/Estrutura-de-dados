// Binary Search
#include <stdio.h>

int binarySearch(int A[],int l, int r, int K){
    if r>=l {
        int m = (l+r)/2;
        if (k==A[m])
        {
            return m;
        }
        else if (K<A[m])
        {
            return binarySearch(A,l,m-1,K);
        }
        else{
            return binarySearch(A,m+1,r,K);
        }  
    }
    else{
        return -1;
    }
}

int main()
{
    int vetor[] = {2,5,7,18,22,50,65};

    printf("%d",binarySearch(vetor,0,6,50));
}