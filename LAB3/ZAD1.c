#include<stdio.h>

void encrypt(char*);

int main(void)
{
    char tekst[101];
    fgets(tekst, 100, stdin);
    encrypt(tekst);
	printf("%s\n", tekst);
}

void encrypt(char* tekst)
{
    int start=0, key=0;
    while(tekst[start]==' ' && start<100)
        start++;

	// UPDATE do while ponizej: zamiast tego dlugiego warunku moze byc tez:
	// (tekst[start] != ' ' && tekst[start] != '\0' && tekst[start] != '\n' )
	
    while( ( ( ( (int)tekst[start] <= 90) && ( (int)tekst[start] >= 65) ) || ( ( (int)tekst[start] <= 122) && ( (int)tekst[start] >= 97) )) && start<100 )
        {
            key++;
            start++;
        }
    
    for(int i=0; i<100; i++)
    {
        if(tekst[i] == ' ')
            continue;
        if((int)tekst[i] <= 90 && (int)tekst[i] >= 65)      // jezeli tekst[i] to duza litera
            tekst[i] = (char)(65+(tekst[i]+key-65)%26);
        else if((int)tekst[i] <= 122 && (int)tekst[i] >= 97)    // jezeli test[i] to mala litera
            tekst[i] = (char)(97+(tekst[i]+key-97)%26);
    }
}
