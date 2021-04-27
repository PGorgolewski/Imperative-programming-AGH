#include <stdio.h>

int findFirst1(int n, int k, int t[n]);

// program rozwaza na kazdym etapie numer sekwencji ktory musi stworzyc
// wykorzystuje do funckje findFirst1, ktora dla danej sekwencji wstawia 1
// na wlasciwa pozycje w tablicy t
int main(){
    int n, k, z;
    scanf("%d %d", &n, &k);

    int t[n];
    for (int i=0; i<n; i++) t[i]=0;

    z = findFirst1(n,k,t);

    if (z == -1){ //liczba sekwencji jest mniejsza od danej k
        printf("-1");
        return 0;
    }

    while(1){
        if (z == 1) break;
        z = findFirst1(n,z,t);
    }

    for (int i=0; i<n; i++) printf("%d", t[i]);

    return 0;
}

int findFirst1(int n, int k, int t[n]){
    int z = 2;
    int a1 = 2, a2 = 3; //war poczatkowe
    // wzor na a(n) = a(n-1) + a(n-2)

    if (k == 1) return 1; // ustawianie jedynek dla warunkow poczatkowych
    else if (k <= 3){
        if (k==2) t[n-1] = 1;
        else t[n-2] = 1;
        return 1;
    }

    while (z < n) {
        z += 1;
        a2 = a1 + a2;
        a1 = a2 - a1;
        if (a2 >= k){
            // nasza sekwencja bedzie miala pierwsza jedynke na pozycji z od konca
            t[n-z] = 1;
            return k - a1; // zwracamy ktora sekwencje nalezy teraz rozwazyc
        }
    }

    return -1;
}   