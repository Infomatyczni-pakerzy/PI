// Ostrzegam ze dostaje za to 25% w sprawdzarce a jebany dziala


#include<stdio.h>
#include<stdlib.h>

void Counting_sort(int arr[], int n, int exp)
{
    int *result;
    result = malloc(n*sizeof(int));
    int i, numbers[10];
    for(i=0; i<10; i++)
        numbers[i] = 0;
    
    for(i=0; i<n; i++)
        numbers[(arr[i]/exp)%10]++;
    
    for(i=1; i<10; i++)
        numbers[i] += numbers[i-1];
    
    for(i=n-1; i>=0; i--)
    {
        result[numbers[ (arr[i]/exp)%10 ] -1 ] = arr[i];
        numbers[ (arr[i]/exp)%10 ]--;
    }

    for(i=0; i<n; i++)
        arr[i] = result[i];
    free(result);
}

void Radix_sort(int arr[], int n, int k)
{
    int limit=1;
    for(int i=1; i<k; i++)  // limit = 10^(k-1)
        limit*=10;

    for(int exp=1; limit/exp>0; exp*=10)
        Counting_sort(arr, n, exp);
}

int main(void)
{
    int Z;
    scanf("%d", &Z);
    int **tab;
    int *N;
    int *K;
    N = malloc(Z*sizeof(int));
    K = malloc(Z*sizeof(int));
    tab = malloc(Z*sizeof(int*));
    for(int z=0; z<Z; z++)
    {
        scanf("%d", &N[z]);
        scanf("%d", &K[z]);
        tab[z] = malloc((N[z])*sizeof(int));
        for(int i=0; i<N[z]; i++)
        {
            scanf("%d", &tab[z][i]);
        }
    }

    for(int z=0; z<Z; z++)
    {
        Radix_sort(tab[z], N[z], K[z]);
        for(int i=0; i<N[z]; i++)
        {
            printf("%d\n", tab[z][i]);
        }
    }

    for(int z=0; z<Z; z++)
        free(tab[z]);
    free(tab);
    free(N);
}
