#include<stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Left(int a)
{
    return 2*a;
}

int Right(int a)
{
    return 2*a + 1;
}

int Parent(int a)
{
    return a/2; 
}

void Heapify(int Heap[], int i)
{
    int largest;
    int l = Left(i);
    int r = Right(i);
    if(l <= Heap[0] && Heap[l] > Heap[i])
        largest = l;
    else
        largest = i;
    if(r <= Heap[0] && Heap[r] > Heap[largest])
        largest = r;
    if(largest != i)
    {
        swap(&Heap[i], &Heap[largest]);
        Heapify(Heap, largest);
    }
}

void Build_max_heap(int heap[])
{
    int n = heap[0];
    for(int i=(n/2); i>=1; i--)
        Heapify(heap, i);
}

void Heap_sort(int arr[])
{
    Build_max_heap(arr);
    int n = arr[0];
    for(int i = n; i>=2; i--)
    {
        swap(&arr[1], &arr[i]);
        arr[0]--;
        Heapify(arr, 1);
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
        tab[z] = malloc((N[z]+1)*sizeof(int));
        tab[z][0] = N[z];
        for(int i=1; i<=N[z]; i++)
        {
            scanf("%d", &tab[z][i]);
        }
    }

    for(int z=0; z<Z; z++)
    {
        Heap_sort(tab[z]);
        for(int i=1; i<=N[z]; i++)
        {
            printf("%d\n", tab[z][i]);
        }
    }

    for(int z=0; z<Z; z++)
        free(tab[z]);
    free(tab);
    free(N);
}
