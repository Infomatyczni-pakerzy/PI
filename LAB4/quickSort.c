#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int i, int j)
{
     int x = a[i];
     a[i] = a[j];
     a[j] = x;
}
int partition(int *a, int p, int r)
{
    int pivot = a[r];
    int i = p-1;
    for(int j=p; j<r; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(a, i, j);
        }
    }
    i++;
    swap(a, i, r);
    return i;
}

void quickSort(int *a, int p, int r)
{
    if (p < r)
    {
        int q = partition(a,p,r);
        quickSort(a, p, q-1);
        quickSort(a, q+1, r);

    }
}

int main() {
    int Z;
    scanf("%d", &Z);

	while (Z--) {
		int n;
		scanf("%d", &n);
		int *a = malloc(n * sizeof(int));
		for(int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}

        quickSort(a, 0, n-1);
        for(int i = 0; i < n; i++) {
            printf("%d\n", a[i]);
        }
        free(a);
    }
}
