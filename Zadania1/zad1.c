#include <stdio.h>
#include <math.h>

int main() {
    int m, n, q, counter, sum;
    int tab[43]; //Znaleziono do tej pory 43 liczby doskonałe, najwieksza ma 18 mln cyfr

    scanf("%d %d", &m, &n);

    if (m < 6) {
        m = 6;  //Najmniejsza liczba doskonała 
    };

    counter = 0;

    for(int i = m; i <= n; i++){ //iterujemy po przedziale [m,n]
        q = sqrt(i);
        sum = 1; //dodajemy 1 jako dzielnik m, bo m >= 6

        for(int j = 2; j <= q; j++){ //sprawdzamy sumę dzialników (bez jej samej) każdej liczby z przedziału
            if (i % j == 0){
                sum += j + i/j;
            };
        };

        if (q*q == i){
            sum -= q; //Jezeli byla to liczba kwadratowa, dwa razy dodalismy jej pierwisatek
        }

        if (sum == i){
            tab[counter] = i;
            counter++;
        };
    };

    printf("%d\n", counter);
    for(int i=0; i<counter; i++){
        printf("%d ",tab[i]);
    };

    return 0;
}