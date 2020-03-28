#include<stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];      // rozne mozliwosci wybrania pivota
    int i = low-1;

    for(int j=low; j<=high-1; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i+1);
}

void Quick_sort(int arr[], int low, int high)
{
    if(low < high)
    {
        int p = partition(arr, low, high);
        Quick_sort(arr, low, p-1);
        Quick_sort(arr, p+1, high);
    }
}

int main(void)
{
    int Z;
    scanf("%d", &Z);
    int **tab;
    int *N;
    N = malloc(Z*sizeof(int));
    tab = malloc(Z*sizeof(int*));
    for(int z=0; z<Z; z++)
    {
        scanf("%d", &N[z]);
        tab[z] = malloc((N[z])*sizeof(int));
        for(int i=0; i<N[z]; i++)
        {
            scanf("%d", &tab[z][i]);
        }
    }

    for(int z=0; z<Z; z++)
    {
        Quick_sort(tab[z], 0, N[z]-1);
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