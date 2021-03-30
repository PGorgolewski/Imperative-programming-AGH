#include <stdio.h>

int main() {
    int n,k,min;

    scanf("%d", &n);

    int t1[n][n], t2[n*n], c[n];

    for(int j=0; j<n; j++){
        for(int i=0; i<n; i++){
            scanf("%d", &t1[j][i]);
        }
        c[j] = 0;
    }

    k=0;
    while(1){
        min = -1; // bedzie nam wskazywac wiersz w ktorym bedzie najmniejsza liczba
        for(int i=0; i<n; i++){
            if (c[i] < n) {
                if (min == -1 || t1[i][c[i]] < t1[min][c[min]]) {
                    min = i;
                }
                else if (t1[i][c[i]] == t1[min][c[min]]) {
                    c[i] += 1; //mamy taka sama wartosc
                }
            }
        }
        if (min == -1) break; //wszystkie liczby wykorzystane

        if (k==0 || t2[k-1] != t1[min][c[min]]) { //zabezpieczenie przed ciagami niemalejacymi
            t2[k] = t1[min][c[min]];
            k += 1;
        }
        
        c[min] += 1;
    }

    for(int i=0; i<k; i++){
        printf("%d ", t2[i]);
    }

    return 0;
}