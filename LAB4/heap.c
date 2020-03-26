#include<stdio.h>
#include<stdlib.h>

 int parent(int x)
 {
     return (x-1)/2;
 }
 int left(int x)
 {
     return 2*x + 1;
 }
 int right(int x)
 {
     return 2*x + 2;
 }
 void swap(int *a, int i, int j)
 {
     int x = a[i];
     a[i] = a[j];
     a[j] = x;
 }
void heapify(int *a, int i, int n)
{
    int l = left(i);
    int r = right(i);
    int largest = i;
    if (l < n && a[l] > a[largest])
    {
        largest = l;
    }
    if (r < n && a[r] > a[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(a,largest,i);
        heapify(a,largest,n);
    }

}

void heapSort(int *a, int n)
{
    for(int i = n/2; i>-1; i--)
    {
        heapify(a,i,n);
    }
    for(int i = n-1; i>0; i--)
    {

        swap(a,i,0);
        heapify(a,0,i);
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

        heapSort(a, n);
        for(int i = 0; i < n; i++) {
            printf("%d\n", a[i]);
        }
        free(a);
    }
}

