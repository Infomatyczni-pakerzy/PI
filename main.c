#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int len = 10;

void CSort(char** tabZ, char** tabR, int d, int sizeZ, int digits)
{
    int Range[len];
    for(int i = 0; i < len; i++) Range[i] = 0;
    for(int i = 0; i < sizeZ; i++) Range[tabZ[i][d] - '0']++;
    for(int i = 1; i < len; i++) Range[i] = Range[i] + Range[i - 1];
    for(int i = sizeZ - 1; i >= 0; i--)
    {
        for(int j = 0; j < digits; j++) { tabR[Range[tabZ[i][d] - '0'] - 1][j] = tabZ[i][j]; }
        Range[tabZ[i][d] - '0']--;
    }
}

int main()
{
    int Z;
    scanf("%d", &Z);
    char*** tabZ = calloc(Z, sizeof(char**)); //tablica zawierajaca Z zestawów
    char*** tabR = calloc(Z, sizeof(char**)); //tablica z wynikiem (result)
    int* tmpK = calloc(Z, sizeof(int)); // tablica przechowujaca ilosci cyfr w liczbach
    int* sizeZ = calloc(Z, sizeof(int)); // tablica zawierająca rozmiary zestawów
    int n, k;

    for(int i = 0; i < Z; i++)
    {
        scanf("%d", &n);
        scanf("%d", &k);
        tabZ[i] = calloc(n, sizeof(char*));
        tabR[i] = calloc(n, sizeof(char*));
        sizeZ[i] = n;
        tmpK[i] = k;
        for(int j = 0; j < n; j++)
        {
            tabZ[i][j] = calloc(k, sizeof(char));
            tabR[i][j] = calloc(k, sizeof(char));

            scanf("%s", tabZ[i][j]);
        }
    }

    //Radix Sort
    for(int i = 0; i < Z; i++)
    {

        for(int j = tmpK[i] - 1; j >= 0; j--)
        {
            CSort(tabZ[i], tabR[i], j, sizeZ[i], tmpK[i]);
            for(int m = 0; m < sizeZ[i]; m++)
            {
                for(int n = 0; n < tmpK[i]; n++) tabZ[i][m][n] = tabR[i][m][n];
            }
        }
        for(int l = 0; l < sizeZ[i]; l++) printf("%s\n", tabR[i][l]);
    }

    return 0;
}
