#include <stdio.h>
#include <stdlib.h>

#define N 100

int main(void)
{
    int n, l, B=0;
    do 
    {
		scanf("%d", &n);
	} 
    while(n <= 0 || n > N); // czytanie n z [1,100]
    
    for(int i=0; i<n*n; i++)
    {
        scanf("%d", &l);
        if(l != 0 && i/n < i%n)     // i/n - wiersz     i%n - kolumna
            B=1;
    }
    if(B)   printf("NO");
    else    printf("YES");
}
