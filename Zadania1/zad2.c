#include <stdio.h>
#include <math.h>

int greaterDigits(int n);
int first(int n);

int main() {
    int n;
    scanf("%d", &n);

    for(int i=2; i<=n; i++){
        if (greaterDigits(i)==0){
            continue;
        };

        if(first(i) == 1) {
            printf("%d\n",i);
        };
    };

    return 0;
};

int first(int n) { //zwraca 0 gdy nie jest pierwsza, 1 gdy jest
     if (n == 2 || n == 3) {
            return 1;
        };

    if (n%2 == 0 || n%3 == 0) {
        return 0;
    };

    int q = sqrt(n);
    for(int j=6; j<=q+1; j+=6){
            if (n%(j-1) == 0 || n%(j+1) == 0){
            return 0;
            };
    };

    return 1;
};

int greaterDigits(int n) { //zwraca 0 gdy cyfry nie tworzą ciągu niemalejącego, 1 gdy tworzą
    int last, prev;
    
    if (n<10){
        return 1;
    };

    last = n % 10;
    n /= 10;
    prev = n % 10;
    while(n>0) {
        if (prev > last) {
            return 0;
        };

        last = prev;
        n /= 10;
        prev = n % 10;
    };

    return 1;
};

