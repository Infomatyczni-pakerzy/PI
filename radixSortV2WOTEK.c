#include<stdio.h>
#include<stdlib.h>

void sortIthPos(char** tab, int n, int pos)
{
    int *count = malloc(10*sizeof(int));
    char** result = malloc(n*sizeof(char*));

    for(int i = 0; i < 10; i++)count[i] = 0;
    //counting numbers
    for(int i = 0; i < n; i++)count[tab[i][pos]- '0']++;
    //counting numbers before i-th number
    for(int i = 1; i < 10; i++)count[i] += count[i - 1];

    for(int i = n - 1; i >= 0; i--)
    {
        int temp = tab[i][pos]- '0';
        result[count[temp] - 1] = tab[i];
        count[temp]--;
    }
    //copying results to the original tab
    for(int i = 0; i < n; i++)tab[i] = result[i];
    //freeing memory
    free(result);
    free(count);


}

void radixSort(char** tab, int n, int k) {
    for(int i = k-1; i >= 0; i--) sortIthPos(tab, n, i);
}

int main()
{
    int Z;
    scanf("%d", &Z);
	while (Z--)
    {
		int n,k;
		scanf("%d", &n);
		scanf("%d", &k);
        char **a = malloc(n*sizeof(char*));
		for(int i=0; i<n; i++)
        {
			a[i] = malloc((k+1)*sizeof(char));
            scanf("%s", a[i]);
		}
        radixSort(a, n, k);

        for(int i = 0; i < n; i++)
        {
            printf("%s\n", a[i]);
            free(a[i]);
        }
        free(a);
    }
}
