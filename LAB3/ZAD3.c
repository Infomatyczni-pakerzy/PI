#include <stdio.h>
#include <stdlib.h>

int niemal(int n)
{
    while( (n%100)/10 <= n%10 )
    {
        n = n/10;
        if(n < 10)  return 1;
    }
    return 0;
}

int main(void)
{
  int g, n, w;
  int * S;
  scanf("%d",&n);
  S = (int*)calloc(n+1,sizeof(int));
  for(int i=2; i <= n; i++) S[i] = 1;
  g = (int)sqrt(n);
  for(int i=2; i <= g; i++)
    if(S[i])
    {
      w = i * i;
      while( w <= n )
      {
        S[w] = 0;
        w+=i;
      }
    }
  for(int i=2; i <= n; i++) if( S[i] && niemal(i) ) printf("%d\n",i);
  free(S);
}