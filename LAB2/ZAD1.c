#include <stdio.h>
#include <stdlib.h>

#define N 1000

int main(void)
{
    int n, o=0, e=0, index=0;
    do 
    {
		scanf("%d", &n);
	} 
    while(n <= 0 || n > N); // czytanie n z [1,1000]
    int T1[N], T2[N], T3[N];

    for(int i=0; i<n; i++)
    {
        scanf("%d", &T1[i]);
        if(T1[i]%2==0)
        {
            T2[e] = T1[i];
            index = e;
            while(index>0 && T2[index] < T2[index-1])
            {
                T2[index] = T2[index-1];
                T2[index-1] = T1[i];
                index-=1;
            }
            e++;
        }
        else
        {
            T3[o] = T1[i];
            index = o;
            while(index>0 && T3[index] < T3[index-1])
            {
                T3[index] = T3[index-1];
                T3[index-1] = T1[i];
                index-=1;
            }
            o++;
        }
    }
    printf("%1d %2d\n",e,o);

    for(int i=0; i<e; i++)
        printf("%d\n", T2[i]);
    for(int i=0; i<o; i++)
        printf("%d\n", T3[i]);
}
