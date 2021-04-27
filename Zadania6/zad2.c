#include <stdio.h>
#include <string.h>
#define N 20 //liczby rzymskie do 1000 wiec na pewno starczy na zapis

char t1[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'}; //globalne tablice do konwertu
char * t2[] = {"CM", "CD", "XC", "XL", "IX", "IV"}; // t2->t4, t1->t3
int t3[] = {1000, 500, 100, 50, 10, 5, 1};
int t4[] = {900, 400, 90, 40, 9, 4};

int romToDec(char * s, unsigned int l);
int decToRom(int n, char * res);

int main(){
    char x1[N], x2[N], res[2*N];
    unsigned int i1, i2;

    scanf("%s %s", x1, x2);
    
    i1 = strlen(x1);
    i2 = strlen(x2);

    decToRom(romToDec(x1, i1)+romToDec(x2, i2), res); //aktualizuje res
    
    printf("%s", res);

    return 0;  
}

// z rzymskiego na dziesiatkowy
int romToDec(char * s, unsigned int l){
    int res = 0;
    int j = 0, i = 0; //j -> iteruje po charach[], i-> po liczbie rzymskiej
    while (i < l){
        if (s[i] == t1[j]){ //sprawdzamy pelne liczby
            res += t3[j];
            i++;
        }
        else if (i < l-1 && s[i] == t2[j][0] && s[i+1] == t2[j][1]){ //sprawdzamy liczby pomniejszone (np IV)
            res += t4[j];
            i += 2;
        }
        else{ //patrzymy dalej -> nasza aktualna rzymska jest < od rozwazanej
            j++;
        }
    }
    return res;
}

int decToRom(int n, char * res){
    int j = 0, i = 0;  //j bedzie iterowac po t[], zas i to iterator i res[]

    while (n > 0){
        if (n >= t3[j]){ //pelna liczba np. M, C
            n -= t3[j];
            res[i] = t1[j];
            i++;
        }
        else if (n >= t4[j]){ //niepelna np CM, IV
            n -= t4[j];
            res[i] = t2[j][0];
            res[i+1] = t2[j][1];
            i += 2;
        }   
        else{ 
            j++;
        }
    }

    res[i] = '\0'; //zakonczenie stringu

    return 0;
}