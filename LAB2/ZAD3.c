#include <stdio.h>
#include <stdlib.h>

void autoSort_Fill(int *t,int N);
int merge(int* t1, int* t2, int* t3, int m, int n);

int main(void)
{
	int m, n;
	scanf("%d %d", &m, &n);

	int *t1;
    int *t2;
    int *t3;

    t1 = (int*)calloc(m,sizeof(int));
    t2 = (int*)calloc(n,sizeof(int));
    t3 = (int*)calloc(m+n,sizeof(int));

    autoSort_Fill(t1,m);
    autoSort_Fill(t2,n);

	int L = merge(t1, t2, t3, m, n);

	for(int i=0; i<L; i++)
        printf("%d\n",t3[i]);
    
    free(t1);
    free(t2);
    free(t3);
}

void autoSort_Fill(int *t,int N)
{
    int temp, p;
    for(int i=0; i<N; i++)
    {
        scanf("%d", &t[i]);
        p = i;
        temp = t[i];
        while(p > 0 && t[p] < t[p-1])
        {
            t[p] = t[p-1];
            t[p-1] = temp;
            p--;
        }
    }
}

int merge(int* t1, int* t2, int* t3, int m, int n)
{
    int p1=0,p2=0,p3=0;
    if(t1[p1] <= t2[p2])
    {
        t3[p3] = t1[p1];
        p1++;
        p3++;
    }
    else
    {
        t3[p3] = t2[p2];
        p2++;
        p3++;
    }

    while(p1<m && p2<n)
    {
        if(t1[p1] <= t2[p2])
        {
            if(t1[p1] != t3[p3-1])
            {
                t3[p3] = t1[p1];
                p3++;
            }
            p1++;
        }
        else
        {
            if(t2[p2] != t3[p3-1])
            {
                t3[p3] = t2[p2];
                p3++;
            }
            p2++;
        }
    }
    
    while(p1 < m)
    {
        if(t1[p1] != t3[p3-1])
        {
            t3[p3] = t1[p1];
            p3++;
        }
        p1++;
    }

        while(p2 < n)
    {
        if(t2[p2] != t3[p3-1])
        {
            t3[p3] = t2[p2];
            p3++;
        }
        p2++;
    }

    realloc(t3,p3*sizeof(int));
    return p3;
}
