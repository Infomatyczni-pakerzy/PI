#include <stdio.h>
#include <stdlib.h>



int main()
{
    int n;
    scanf("%d", &n);
    int t[n];
    int indeks=0,suma1=0,sumac=0;
    for(int i=0; i<n; i++)
    {
        scanf("%d", &t[i]);
        sumac += t[i];
    }
    while(suma1*2+t[indeks] != sumac) suma1 += t[indeks++];
    printf("%d", indeks);
}
