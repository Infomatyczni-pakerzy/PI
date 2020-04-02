#include<stdio.h>
#include<stdlib.h>

void color(int** tab,int n,int x,int y,int colid)
{
    if(tab[x][y] != 0) return ;
    tab[x][y] = colid;
    int temp1 [4] = {1,-1,0,0};
    int temp2 [4] = {0,0,1,-1};
    for(int i=0;i<4;i++)
    {
        int newcol = x + temp1[i];
        int newrow = y + temp2[i];
        if (-1<newcol && newcol < n && -1<newrow && newrow < n)
        {
            color(tab,n,newcol,newrow,colid);
        }
    }
}

int main()
{
    int n,k;
    scanf("%d", &n);
    scanf("%d", &k);
    int **tab = malloc(n*sizeof(int*));
    //skan danych do tablicy
    for (int i=0;i<n;i++)
    {
        tab[i] = malloc(n*sizeof(int));
        for(int j=0;j<n;j++)
        {
            scanf("%d", &tab[i][j]);
        }
    }
    //skan pikseli do pokolorowania
    for(int i=0;i<k;i++)
    {
        int x,y,colid;
        scanf("%d", &x);
        scanf("%d", &y);
        scanf("%d", &colid);
        color(tab,n,x,y,colid);
    }


    //printowanie tablicy
    for (int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}
